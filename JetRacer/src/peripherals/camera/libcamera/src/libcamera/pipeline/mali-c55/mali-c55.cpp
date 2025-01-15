/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2024, Ideas on Board Oy
 *
 * Pipeline Handler for ARM's Mali-C55 ISP
 */

#include <algorithm>
#include <array>
#include <map>
#include <memory>
#include <set>
#include <string>

#include <linux/media-bus-format.h>
#include <linux/media.h>

#include <libcamera/base/log.h>

#include <libcamera/camera.h>
#include <libcamera/formats.h>
#include <libcamera/geometry.h>
#include <libcamera/stream.h>

#include <libcamera/ipa/core_ipa_interface.h>

#include "libcamera/internal/bayer_format.h"
#include "libcamera/internal/camera.h"
#include "libcamera/internal/camera_sensor.h"
#include "libcamera/internal/device_enumerator.h"
#include "libcamera/internal/media_device.h"
#include "libcamera/internal/pipeline_handler.h"
#include "libcamera/internal/v4l2_subdevice.h"
#include "libcamera/internal/v4l2_videodevice.h"

namespace {

bool isFormatRaw(const libcamera::PixelFormat &pixFmt)
{
	return libcamera::PixelFormatInfo::info(pixFmt).colourEncoding ==
	       libcamera::PixelFormatInfo::ColourEncodingRAW;
}

} /* namespace */

namespace libcamera {

LOG_DEFINE_CATEGORY(MaliC55)

const std::map<libcamera::PixelFormat, unsigned int> maliC55FmtToCode = {
	/* \todo Support all formats supported by the driver in libcamera. */

	{ formats::RGB565, MEDIA_BUS_FMT_RGB121212_1X36 },
	{ formats::RGB888, MEDIA_BUS_FMT_RGB121212_1X36 },
	{ formats::YUYV, MEDIA_BUS_FMT_YUV10_1X30 },
	{ formats::UYVY, MEDIA_BUS_FMT_YUV10_1X30 },
	{ formats::R8, MEDIA_BUS_FMT_YUV10_1X30 },
	{ formats::NV12, MEDIA_BUS_FMT_YUV10_1X30 },
	{ formats::NV21, MEDIA_BUS_FMT_YUV10_1X30 },

	/* RAW formats, FR pipe only. */
	{ formats::SGBRG16, MEDIA_BUS_FMT_SGBRG16_1X16 },
	{ formats::SRGGB16, MEDIA_BUS_FMT_SRGGB16_1X16 },
	{ formats::SBGGR16, MEDIA_BUS_FMT_SBGGR16_1X16 },
	{ formats::SGRBG16, MEDIA_BUS_FMT_SGRBG16_1X16 },
};

constexpr Size kMaliC55MinInputSize = { 640, 480 };
constexpr Size kMaliC55MinSize = { 128, 128 };
constexpr Size kMaliC55MaxSize = { 8192, 8192 };
constexpr unsigned int kMaliC55ISPInternalFormat = MEDIA_BUS_FMT_RGB121212_1X36;

class MaliC55CameraData : public Camera::Private
{
public:
	MaliC55CameraData(PipelineHandler *pipe, MediaEntity *entity)
		: Camera::Private(pipe), entity_(entity)
	{
	}

	int init();

	/* Deflect these functionalities to either TPG or CameraSensor. */
	const std::vector<Size> sizes(unsigned int mbusCode) const;
	const Size resolution() const;

	int pixfmtToMbusCode(const PixelFormat &pixFmt) const;
	const PixelFormat &bestRawFormat() const;

	void updateControls();

	PixelFormat adjustRawFormat(const PixelFormat &pixFmt) const;
	Size adjustRawSizes(const PixelFormat &pixFmt, const Size &rawSize) const;

	std::unique_ptr<CameraSensor> sensor_;

	MediaEntity *entity_;
	std::unique_ptr<V4L2Subdevice> csi_;
	std::unique_ptr<V4L2Subdevice> sd_;
	Stream frStream_;
	Stream dsStream_;

private:
	void initTPGData();

	std::string id_;
	std::vector<unsigned int> tpgCodes_;
	std::vector<Size> tpgSizes_;
	Size tpgResolution_;
};

int MaliC55CameraData::init()
{
	int ret;

	sd_ = std::make_unique<V4L2Subdevice>(entity_);
	ret = sd_->open();
	if (ret) {
		LOG(MaliC55, Error) << "Failed to open sensor subdevice";
		return ret;
	}

	/* If this camera is created from TPG, we return here. */
	if (entity_->name() == "mali-c55 tpg") {
		initTPGData();
		return 0;
	}

	/*
	 * Register a CameraSensor if we connect to a sensor and create
	 * an entity for the connected CSI-2 receiver.
	 */
	sensor_ = CameraSensorFactoryBase::create(entity_);
	if (!sensor_)
		return ret;

	const MediaPad *sourcePad = entity_->getPadByIndex(0);
	MediaEntity *csiEntity = sourcePad->links()[0]->sink()->entity();

	csi_ = std::make_unique<V4L2Subdevice>(csiEntity);
	if (csi_->open()) {
		LOG(MaliC55, Error) << "Failed to open CSI-2 subdevice";
		return false;
	}

	return 0;
}

void MaliC55CameraData::initTPGData()
{
	/* Replicate the CameraSensor implementation for TPG. */
	V4L2Subdevice::Formats formats = sd_->formats(0);
	if (formats.empty())
		return;

	tpgCodes_ = utils::map_keys(formats);
	std::sort(tpgCodes_.begin(), tpgCodes_.end());

	for (const auto &format : formats) {
		const std::vector<SizeRange> &ranges = format.second;
		std::transform(ranges.begin(), ranges.end(), std::back_inserter(tpgSizes_),
			       [](const SizeRange &range) { return range.max; });
	}

	tpgResolution_ = tpgSizes_.back();
}

const std::vector<Size> MaliC55CameraData::sizes(unsigned int mbusCode) const
{
	if (sensor_)
		return sensor_->sizes(mbusCode);

	V4L2Subdevice::Formats formats = sd_->formats(0);
	if (formats.empty())
		return {};

	std::vector<Size> sizes;
	const auto &format = formats.find(mbusCode);
	if (format == formats.end())
		return {};

	const std::vector<SizeRange> &ranges = format->second;
	std::transform(ranges.begin(), ranges.end(), std::back_inserter(sizes),
		       [](const SizeRange &range) { return range.max; });

	std::sort(sizes.begin(), sizes.end());

	return sizes;
}

const Size MaliC55CameraData::resolution() const
{
	if (sensor_)
		return sensor_->resolution();

	return tpgResolution_;
}

/*
 * The Mali C55 ISP can only produce 16-bit RAW output in bypass modes, but the
 * sensors connected to it might produce 8/10/12/16 bits. We simply search the
 * sensor's supported formats for the one with a matching bayer order and the
 * greatest bitdepth.
 */
int MaliC55CameraData::pixfmtToMbusCode(const PixelFormat &pixFmt) const
{
	auto it = maliC55FmtToCode.find(pixFmt);
	if (it == maliC55FmtToCode.end())
		return -EINVAL;

	BayerFormat bayerFormat = BayerFormat::fromMbusCode(it->second);
	if (!bayerFormat.isValid())
		return -EINVAL;

	V4L2Subdevice::Formats formats = sd_->formats(0);
	unsigned int sensorMbusCode = 0;
	unsigned int bitDepth = 0;

	for (const auto &[code, sizes] : formats) {
		BayerFormat sdBayerFormat = BayerFormat::fromMbusCode(code);
		if (!sdBayerFormat.isValid())
			continue;

		if (sdBayerFormat.order != bayerFormat.order)
			continue;

		if (sdBayerFormat.bitDepth > bitDepth) {
			bitDepth = sdBayerFormat.bitDepth;
			sensorMbusCode = code;
		}
	}

	if (!sensorMbusCode)
		return -EINVAL;

	return sensorMbusCode;
}

/*
 * Find a RAW PixelFormat supported by both the ISP and the sensor.
 *
 * The situation is mildly complicated by the fact that we expect the sensor to
 * output something like RAW8/10/12/16, but the ISP can only accept as input
 * RAW20 and can only produce as output RAW16. The one constant in that is the
 * bayer order of the data, so we'll simply check that the sensor produces a
 * format with a bayer order that matches that of one of the formats we support,
 * and select that.
 */
const PixelFormat &MaliC55CameraData::bestRawFormat() const
{
	static const PixelFormat invalidPixFmt = {};

	for (const auto &fmt : sd_->formats(0)) {
		BayerFormat sensorBayer = BayerFormat::fromMbusCode(fmt.first);

		if (!sensorBayer.isValid())
			continue;

		for (const auto &[pixFmt, rawCode] : maliC55FmtToCode) {
			if (!isFormatRaw(pixFmt))
				continue;

			BayerFormat bayer = BayerFormat::fromMbusCode(rawCode);
			if (bayer.order == sensorBayer.order)
				return pixFmt;
		}
	}

	LOG(MaliC55, Error) << "Sensor doesn't provide a compatible format";
	return invalidPixFmt;
}

void MaliC55CameraData::updateControls()
{
	if (!sensor_)
		return;

	IPACameraSensorInfo sensorInfo;
	int ret = sensor_->sensorInfo(&sensorInfo);
	if (ret) {
		LOG(MaliC55, Error) << "Failed to retrieve sensor info";
		return;
	}

	ControlInfoMap::Map controls;
	Rectangle ispMinCrop{ 0, 0, 640, 480 };
	controls[&controls::ScalerCrop] =
		ControlInfo(ispMinCrop, sensorInfo.analogCrop,
			    sensorInfo.analogCrop);

	controlInfo_ = ControlInfoMap(std::move(controls), controls::controls);
}

/*
 * Make sure the provided raw pixel format is supported and adjust it to
 * one of the supported ones if it's not.
 */
PixelFormat MaliC55CameraData::adjustRawFormat(const PixelFormat &rawFmt) const
{
	/* Make sure the RAW mbus code is supported by the image source. */
	int rawCode = pixfmtToMbusCode(rawFmt);
	if (rawCode < 0)
		return bestRawFormat();

	const auto rawSizes = sizes(rawCode);
	if (rawSizes.empty())
		return bestRawFormat();

	return rawFmt;
}

Size MaliC55CameraData::adjustRawSizes(const PixelFormat &rawFmt, const Size &size) const
{
	/* Expand the RAW size to the minimum ISP input size. */
	Size rawSize = size.expandedTo(kMaliC55MinInputSize);

	/* Check if the size is natively supported. */
	int rawCode = pixfmtToMbusCode(rawFmt);
	if (rawCode < 0)
		return {};

	const auto rawSizes = sizes(rawCode);
	auto sizeIt = std::find(rawSizes.begin(), rawSizes.end(), rawSize);
	if (sizeIt != rawSizes.end())
		return rawSize;

	/* Or adjust it to the closest supported size. */
	uint16_t distance = std::numeric_limits<uint16_t>::max();
	Size bestSize;
	for (const Size &sz : rawSizes) {
		uint16_t dist = std::abs(static_cast<int>(rawSize.width) -
					 static_cast<int>(sz.width)) +
				std::abs(static_cast<int>(rawSize.height) -
					 static_cast<int>(sz.height));
		if (dist < distance) {
			dist = distance;
			bestSize = sz;
		}
	}

	return bestSize;
}

class MaliC55CameraConfiguration : public CameraConfiguration
{
public:
	MaliC55CameraConfiguration(MaliC55CameraData *data)
		: CameraConfiguration(), data_(data)
	{
	}

	Status validate() override;

	V4L2SubdeviceFormat sensorFormat_;

private:
	static constexpr unsigned int kMaxStreams = 2;

	const MaliC55CameraData *data_;
};

CameraConfiguration::Status MaliC55CameraConfiguration::validate()
{
	Status status = Valid;

	if (config_.empty())
		return Invalid;

	/* Only 2 streams available. */
	if (config_.size() > kMaxStreams) {
		config_.resize(kMaxStreams);
		status = Adjusted;
	}

	bool frPipeAvailable = true;
	StreamConfiguration *rawConfig = nullptr;
	for (StreamConfiguration &config : config_) {
		if (!isFormatRaw(config.pixelFormat))
			continue;

		if (rawConfig) {
			LOG(MaliC55, Error)
				<< "Only a single RAW stream is supported";
			return Invalid;
		}

		rawConfig = &config;
	}

	/*
	 * The C55 can not upscale. Limit the configuration to the ISP
	 * capabilities and the sensor resolution.
	 */
	Size maxSize = kMaliC55MaxSize.boundedTo(data_->resolution());
	if (rawConfig) {
		/*
		 * \todo Take into account the Bayer components ordering once
		 * we support rotations.
		 */
		PixelFormat rawFormat =
			data_->adjustRawFormat(rawConfig->pixelFormat);

		if (!rawFormat.isValid())
			return Invalid;

		if (rawFormat != rawConfig->pixelFormat) {
			LOG(MaliC55, Debug)
				<< "RAW format adjusted to " << rawFormat;
			rawConfig->pixelFormat = rawFormat;
			status = Adjusted;
		}

		Size rawSize =
			data_->adjustRawSizes(rawFormat, rawConfig->size);
		if (rawSize != rawConfig->size) {
			LOG(MaliC55, Debug)
				<< "RAW sizes adjusted to " << rawSize;
			rawConfig->size = rawSize;
			status = Adjusted;
		}

		maxSize = rawSize;

		const PixelFormatInfo &info = PixelFormatInfo::info(rawConfig->pixelFormat);
		rawConfig->stride = info.stride(rawConfig->size.width, 0, 4);
		rawConfig->frameSize = info.frameSize(rawConfig->size, 4);

		rawConfig->setStream(const_cast<Stream *>(&data_->frStream_));
		frPipeAvailable = false;
	}

	/*
	 * Adjust processed streams.
	 *
	 * Compute the minimum sensor size to be later used to select the
	 * sensor configuration.
	 */
	Size minSensorSize = kMaliC55MinInputSize;
	for (StreamConfiguration &config : config_) {
		if (isFormatRaw(config.pixelFormat))
			continue;

		/* Adjust format and size for processed streams. */
		const auto it = maliC55FmtToCode.find(config.pixelFormat);
		if (it == maliC55FmtToCode.end()) {
			LOG(MaliC55, Debug)
				<< "Format adjusted to " << formats::RGB565;
			config.pixelFormat = formats::RGB565;
			status = Adjusted;
		}

		Size size = std::clamp(config.size, kMaliC55MinSize, maxSize);
		if (size != config.size) {
			LOG(MaliC55, Debug)
				<< "Size adjusted to " << size;
			config.size = size;
			status = Adjusted;
		}

		if (minSensorSize < size)
			minSensorSize = size;

		if (frPipeAvailable) {
			config.setStream(const_cast<Stream *>(&data_->frStream_));
			frPipeAvailable = false;
		} else {
			config.setStream(const_cast<Stream *>(&data_->dsStream_));
		}
	}

	/* Compute the sensor format. */

	/* If there's a RAW config, sensor configuration follows it. */
	if (rawConfig) {
		sensorFormat_.code = data_->pixfmtToMbusCode(rawConfig->pixelFormat);
		sensorFormat_.size = rawConfig->size.expandedTo(minSensorSize);

		return status;
	}

	/* If there's no RAW config, compute the sensor configuration here. */
	PixelFormat rawFormat = data_->bestRawFormat();
	if (!rawFormat.isValid())
		return Invalid;

	sensorFormat_.code = data_->pixfmtToMbusCode(rawFormat);

	uint16_t distance = std::numeric_limits<uint16_t>::max();
	const auto sizes = data_->sizes(sensorFormat_.code);
	Size bestSize;
	for (const auto &size : sizes) {
		if (minSensorSize.width > size.width ||
		    minSensorSize.height > size.height)
			continue;

		uint16_t dist = std::abs(static_cast<int>(minSensorSize.width) -
					 static_cast<int>(size.width)) +
				std::abs(static_cast<int>(minSensorSize.height) -
					 static_cast<int>(size.height));
		if (dist < distance) {
			dist = distance;
			bestSize = size;
		}
	}
	sensorFormat_.size = bestSize;

	LOG(MaliC55, Debug) << "Computed sensor configuration " << sensorFormat_;

	return status;
}

class PipelineHandlerMaliC55 : public PipelineHandler
{
public:
	PipelineHandlerMaliC55(CameraManager *manager);

	std::unique_ptr<CameraConfiguration> generateConfiguration(Camera *camera,
								   Span<const StreamRole> roles) override;
	int configure(Camera *camera, CameraConfiguration *config) override;

	int exportFrameBuffers(Camera *camera, Stream *stream,
			       std::vector<std::unique_ptr<FrameBuffer>> *buffers) override;

	int start(Camera *camera, const ControlList *controls) override;
	void stopDevice(Camera *camera) override;

	int queueRequestDevice(Camera *camera, Request *request) override;

	void imageBufferReady(FrameBuffer *buffer);

	bool match(DeviceEnumerator *enumerator) override;

private:
	struct MaliC55Pipe {
		std::unique_ptr<V4L2Subdevice> resizer;
		std::unique_ptr<V4L2VideoDevice> cap;
		MediaLink *link;
		Stream *stream;
	};

	enum {
		MaliC55FR,
		MaliC55DS,
		MaliC55NumPipes,
	};

	MaliC55CameraData *cameraData(Camera *camera)
	{
		return static_cast<MaliC55CameraData *>(camera->_d());
	}

	MaliC55Pipe *pipeFromStream(MaliC55CameraData *data, Stream *stream)
	{
		if (stream == &data->frStream_)
			return &pipes_[MaliC55FR];
		else if (stream == &data->dsStream_)
			return &pipes_[MaliC55DS];
		else
			LOG(MaliC55, Fatal) << "Stream " << stream << " not valid";
		return nullptr;
	}

	MaliC55Pipe *pipeFromStream(MaliC55CameraData *data, const Stream *stream)
	{
		return pipeFromStream(data, const_cast<Stream *>(stream));
	}

	void resetPipes()
	{
		for (MaliC55Pipe &pipe : pipes_)
			pipe.stream = nullptr;
	}

	int configureRawStream(MaliC55CameraData *data,
			       const StreamConfiguration &config,
			       V4L2SubdeviceFormat &subdevFormat);
	int configureProcessedStream(MaliC55CameraData *data,
				     const StreamConfiguration &config,
				     V4L2SubdeviceFormat &subdevFormat);

	void applyScalerCrop(Camera *camera, const ControlList &controls);

	void registerMaliCamera(std::unique_ptr<MaliC55CameraData> data,
				const std::string &name);
	bool registerTPGCamera(MediaLink *link);
	bool registerSensorCamera(MediaLink *link);

	MediaDevice *media_;
	std::unique_ptr<V4L2Subdevice> isp_;

	std::array<MaliC55Pipe, MaliC55NumPipes> pipes_;

	bool dsFitted_;
};

PipelineHandlerMaliC55::PipelineHandlerMaliC55(CameraManager *manager)
	: PipelineHandler(manager), dsFitted_(true)
{
}

std::unique_ptr<CameraConfiguration>
PipelineHandlerMaliC55::generateConfiguration(Camera *camera,
					      Span<const StreamRole> roles)
{
	MaliC55CameraData *data = cameraData(camera);
	std::unique_ptr<CameraConfiguration> config =
		std::make_unique<MaliC55CameraConfiguration>(data);
	bool frPipeAvailable = true;

	if (roles.empty())
		return config;

	/* Check if one stream is RAW to reserve the FR pipe for it. */
	if (std::find(roles.begin(), roles.end(), StreamRole::Raw) != roles.end())
		frPipeAvailable = false;

	for (const StreamRole &role : roles) {
		struct MaliC55Pipe *pipe;

		/* Assign pipe for this role. */
		if (role == StreamRole::Raw) {
			pipe = &pipes_[MaliC55FR];
		} else {
			if (frPipeAvailable) {
				pipe = &pipes_[MaliC55FR];
				frPipeAvailable = false;
			} else {
				pipe = &pipes_[MaliC55DS];
			}
		}

		Size size = std::min(Size{ 1920, 1080 }, data->resolution());
		PixelFormat pixelFormat;

		switch (role) {
		case StreamRole::StillCapture:
			size = data->resolution();
			[[fallthrough]];
		case StreamRole::VideoRecording:
			pixelFormat = formats::NV12;
			break;

		case StreamRole::Viewfinder:
			pixelFormat = formats::RGB565;
			break;

		case StreamRole::Raw:
			pixelFormat = data->bestRawFormat();
			if (!pixelFormat.isValid()) {
				LOG(MaliC55, Error)
					<< "Camera does not support RAW formats";
				return nullptr;
			}

			size = data->resolution();
			break;

		default:
			LOG(MaliC55, Error)
				<< "Requested stream role not supported: " << role;
			return nullptr;
		}

		std::map<PixelFormat, std::vector<SizeRange>> formats;
		for (const auto &maliFormat : maliC55FmtToCode) {
			PixelFormat pixFmt = maliFormat.first;
			bool isRaw = isFormatRaw(pixFmt);

			/* RAW formats are only supported on the FR pipe. */
			if (pipe != &pipes_[MaliC55FR] && isRaw)
				continue;

			if (isRaw) {
				/* Make sure the mbus code is supported. */
				int rawCode = data->pixfmtToMbusCode(pixFmt);
				if (rawCode < 0)
					continue;

				const auto sizes = data->sizes(rawCode);
				if (sizes.empty())
					continue;

				/* And list all sizes the sensor can produce. */
				std::vector<SizeRange> sizeRanges;
				std::transform(sizes.begin(), sizes.end(),
					       std::back_inserter(sizeRanges),
					       [](const Size &s) {
						       return SizeRange(s);
					       });

				formats[pixFmt] = sizeRanges;
			} else {
				/* Processed formats are always available. */
				Size maxSize = std::min(kMaliC55MaxSize,
							data->resolution());
				formats[pixFmt] = { kMaliC55MinSize, maxSize };
			}
		}

		StreamFormats streamFormats(formats);
		StreamConfiguration cfg(streamFormats);
		cfg.pixelFormat = pixelFormat;
		cfg.bufferCount = 4;
		cfg.size = size;

		config->addConfiguration(cfg);
	}

	if (config->validate() == CameraConfiguration::Invalid)
		return nullptr;

	return config;
}

int PipelineHandlerMaliC55::configureRawStream(MaliC55CameraData *data,
					       const StreamConfiguration &config,
					       V4L2SubdeviceFormat &subdevFormat)
{
	Stream *stream = config.stream();
	MaliC55Pipe *pipe = pipeFromStream(data, stream);

	if (pipe != &pipes_[MaliC55FR]) {
		LOG(MaliC55, Fatal) << "Only the FR pipe supports RAW capture.";
		return -EINVAL;
	}

	/* Enable the debayer route to set fixed internal format on pad #0. */
	V4L2Subdevice::Routing routing = {};
	routing.emplace_back(V4L2Subdevice::Stream{ 0, 0 },
			     V4L2Subdevice::Stream{ 1, 0 },
			     V4L2_SUBDEV_ROUTE_FL_ACTIVE);

	int ret = pipe->resizer->setRouting(&routing, V4L2Subdevice::ActiveFormat);
	if (ret)
		return ret;

	unsigned int rawCode = subdevFormat.code;
	subdevFormat.code = kMaliC55ISPInternalFormat;
	ret = pipe->resizer->setFormat(0, &subdevFormat);
	if (ret)
		return ret;

	/* Enable the bypass route and apply RAW formats there. */
	routing.clear();
	routing.emplace_back(V4L2Subdevice::Stream{ 2, 0 },
			     V4L2Subdevice::Stream{ 1, 0 },
			     V4L2_SUBDEV_ROUTE_FL_ACTIVE);
	ret = pipe->resizer->setRouting(&routing, V4L2Subdevice::ActiveFormat);
	if (ret)
		return ret;

	subdevFormat.code = rawCode;
	ret = pipe->resizer->setFormat(2, &subdevFormat);
	if (ret)
		return ret;

	ret = pipe->resizer->setFormat(1, &subdevFormat);
	if (ret)
		return ret;

	return 0;
}

int PipelineHandlerMaliC55::configureProcessedStream(MaliC55CameraData *data,
						     const StreamConfiguration &config,
						     V4L2SubdeviceFormat &subdevFormat)
{
	Stream *stream = config.stream();
	MaliC55Pipe *pipe = pipeFromStream(data, stream);

	/* Enable the debayer route on the resizer pipe. */
	V4L2Subdevice::Routing routing = {};
	routing.emplace_back(V4L2Subdevice::Stream{ 0, 0 },
			     V4L2Subdevice::Stream{ 1, 0 },
			     V4L2_SUBDEV_ROUTE_FL_ACTIVE);

	int ret = pipe->resizer->setRouting(&routing, V4L2Subdevice::ActiveFormat);
	if (ret)
		return ret;

	subdevFormat.code = kMaliC55ISPInternalFormat;
	ret = pipe->resizer->setFormat(0, &subdevFormat);
	if (ret)
		return ret;

	/*
	 * Compute the scaler-in to scaler-out ratio: first center-crop to align
	 * the FOV to the desired resolution, then scale to the desired size.
	 */
	Size scalerIn = subdevFormat.size.boundedToAspectRatio(config.size);
	int xCrop = (subdevFormat.size.width - scalerIn.width) / 2;
	int yCrop = (subdevFormat.size.height - scalerIn.height) / 2;
	Rectangle ispCrop = { xCrop, yCrop, scalerIn };
	ret = pipe->resizer->setSelection(0, V4L2_SEL_TGT_CROP, &ispCrop);
	if (ret)
		return ret;

	Rectangle ispCompose = { 0, 0, config.size };
	ret = pipe->resizer->setSelection(0, V4L2_SEL_TGT_COMPOSE, &ispCompose);
	if (ret)
		return ret;

	/*
	 * The source pad format size comes directly from the sink
	 * compose rectangle.
	 */
	subdevFormat.size = ispCompose.size();
	subdevFormat.code = maliC55FmtToCode.find(config.pixelFormat)->second;
	return pipe->resizer->setFormat(1, &subdevFormat);
}

int PipelineHandlerMaliC55::configure(Camera *camera,
				      CameraConfiguration *config)
{
	resetPipes();

	int ret = media_->disableLinks();
	if (ret)
		return ret;

	/* Link the graph depending if we are operating the TPG or a sensor. */
	MaliC55CameraData *data = cameraData(camera);
	if (data->csi_) {
		const MediaEntity *csiEntity = data->csi_->entity();
		ret = csiEntity->getPadByIndex(1)->links()[0]->setEnabled(true);
	} else {
		ret = data->entity_->getPadByIndex(0)->links()[0]->setEnabled(true);
	}
	if (ret)
		return ret;

	MaliC55CameraConfiguration *maliConfig =
		static_cast<MaliC55CameraConfiguration *>(config);
	V4L2SubdeviceFormat subdevFormat = maliConfig->sensorFormat_;
	ret = data->sd_->getFormat(0, &subdevFormat);
	if (ret)
		return ret;

	if (data->csi_) {
		ret = data->csi_->setFormat(0, &subdevFormat);
		if (ret)
			return ret;

		ret = data->csi_->getFormat(1, &subdevFormat);
		if (ret)
			return ret;
	}

	/*
	 * Propagate the format to the ISP sink pad and configure the input
	 * crop rectangle (no crop at the moment).
	 *
	 * \todo Configure the CSI-2 receiver.
	 */
	ret = isp_->setFormat(0, &subdevFormat);
	if (ret)
		return ret;

	Rectangle ispCrop(0, 0, subdevFormat.size);
	ret = isp_->setSelection(0, V4L2_SEL_TGT_CROP, &ispCrop);
	if (ret)
		return ret;

	/*
	 * Configure the resizer: fixed format the sink pad; use the media
	 * bus code associated with the desired capture format on the source
	 * pad.
	 *
	 * Configure the crop and compose rectangles to match the desired
	 * stream output size
	 *
	 * \todo Make the crop/scaler configurable
	 */
	for (const StreamConfiguration &streamConfig : *config) {
		Stream *stream = streamConfig.stream();
		MaliC55Pipe *pipe = pipeFromStream(data, stream);

		/*
		 * Enable the media link between the pipe's resizer and the
		 * capture video device
		 */

		ret = pipe->link->setEnabled(true);
		if (ret) {
			LOG(MaliC55, Error) << "Couldn't enable resizer's link";
			return ret;
		}

		if (isFormatRaw(streamConfig.pixelFormat))
			ret = configureRawStream(data, streamConfig, subdevFormat);
		else
			ret = configureProcessedStream(data, streamConfig, subdevFormat);
		if (ret) {
			LOG(MaliC55, Error) << "Failed to configure pipeline";
			return ret;
		}

		/* Now apply the pixel format and size to the capture device. */
		V4L2DeviceFormat captureFormat;
		captureFormat.fourcc = pipe->cap->toV4L2PixelFormat(streamConfig.pixelFormat);
		captureFormat.size = streamConfig.size;

		ret = pipe->cap->setFormat(&captureFormat);
		if (ret)
			return ret;

		pipe->stream = stream;
	}

	data->updateControls();

	return 0;
}

int PipelineHandlerMaliC55::exportFrameBuffers(Camera *camera, Stream *stream,
					       std::vector<std::unique_ptr<FrameBuffer>> *buffers)
{
	MaliC55Pipe *pipe = pipeFromStream(cameraData(camera), stream);
	unsigned int count = stream->configuration().bufferCount;

	return pipe->cap->exportBuffers(count, buffers);
}

int PipelineHandlerMaliC55::start([[maybe_unused]] Camera *camera, [[maybe_unused]] const ControlList *controls)
{
	for (MaliC55Pipe &pipe : pipes_) {
		if (!pipe.stream)
			continue;

		Stream *stream = pipe.stream;

		int ret = pipe.cap->importBuffers(stream->configuration().bufferCount);
		if (ret) {
			LOG(MaliC55, Error) << "Failed to import buffers";
			return ret;
		}

		ret = pipe.cap->streamOn();
		if (ret) {
			LOG(MaliC55, Error) << "Failed to start stream";
			return ret;
		}
	}

	return 0;
}

void PipelineHandlerMaliC55::stopDevice([[maybe_unused]] Camera *camera)
{
	for (MaliC55Pipe &pipe : pipes_) {
		if (!pipe.stream)
			continue;

		pipe.cap->streamOff();
		pipe.cap->releaseBuffers();
	}
}

void PipelineHandlerMaliC55::applyScalerCrop(Camera *camera,
					     const ControlList &controls)
{
	MaliC55CameraData *data = cameraData(camera);

	const auto &scalerCrop = controls.get<Rectangle>(controls::ScalerCrop);
	if (!scalerCrop)
		return;

	if (!data->sensor_) {
		LOG(MaliC55, Error) << "ScalerCrop not supported for TPG";
		return;
	}

	Rectangle nativeCrop = *scalerCrop;

	IPACameraSensorInfo sensorInfo;
	int ret = data->sensor_->sensorInfo(&sensorInfo);
	if (ret) {
		LOG(MaliC55, Error) << "Failed to retrieve sensor info";
		return;
	}

	/*
	 * The ScalerCrop rectangle re-scaling in the ISP crop rectangle
	 * comes straight from the RPi pipeline handler.
	 *
	 * Create a version of the crop rectangle aligned to the analogue crop
	 * rectangle top-left coordinates and scaled in the [analogue crop to
	 * output frame] ratio to take into account binning/skipping on the
	 * sensor.
	 */
	Rectangle ispCrop = nativeCrop.translatedBy(-sensorInfo.analogCrop
							       .topLeft());
	ispCrop.scaleBy(sensorInfo.outputSize, sensorInfo.analogCrop.size());

	/*
	 * The crop rectangle should be:
	 * 1. At least as big as ispMinCropSize_, once that's been
	 *    enlarged to the same aspect ratio.
	 * 2. With the same mid-point, if possible.
	 * 3. But it can't go outside the sensor area.
	 */
	Rectangle ispMinCrop{ 0, 0, 640, 480 };
	Size minSize = ispMinCrop.size().expandedToAspectRatio(nativeCrop.size());
	Size size = ispCrop.size().expandedTo(minSize);
	ispCrop = size.centeredTo(ispCrop.center())
		      .enclosedIn(Rectangle(sensorInfo.outputSize));

	/*
	 * As the resizer can't upscale, the crop rectangle has to be larger
	 * than the larger stream output size.
	 */
	Size maxYuvSize;
	for (MaliC55Pipe &pipe : pipes_) {
		if (!pipe.stream)
			continue;

		const StreamConfiguration &config = pipe.stream->configuration();
		if (isFormatRaw(config.pixelFormat)) {
			LOG(MaliC55, Debug) << "Cannot crop with a RAW stream";
			return;
		}

		Size streamSize = config.size;
		if (streamSize.width > maxYuvSize.width)
			maxYuvSize.width = streamSize.width;
		if (streamSize.height > maxYuvSize.height)
			maxYuvSize.height = streamSize.height;
	}

	ispCrop.size().expandTo(maxYuvSize);

	/*
	 * Now apply the scaler crop to each enabled output. This overrides the
	 * crop configuration performed at configure() time and can cause
	 * square pixels if the crop rectangle and scaler output FOV ratio are
	 * different.
	 */
	for (MaliC55Pipe &pipe : pipes_) {
		if (!pipe.stream)
			continue;

		/* Create a copy to avoid setSelection() to modify ispCrop. */
		Rectangle pipeCrop = ispCrop;
		ret = pipe.resizer->setSelection(0, V4L2_SEL_TGT_CROP, &pipeCrop);
		if (ret) {
			LOG(MaliC55, Error)
				<< "Failed to apply crop to "
				<< (pipe.stream == &data->frStream_ ?
				    "FR" : "DS") << " pipe";
			return;
		}
	}
}

int PipelineHandlerMaliC55::queueRequestDevice(Camera *camera, Request *request)
{
	int ret;

	for (auto &[stream, buffer] : request->buffers()) {
		MaliC55Pipe *pipe = pipeFromStream(cameraData(camera), stream);

		ret = pipe->cap->queueBuffer(buffer);
		if (ret)
			return ret;
	}

	/*
	 * Some controls need to be applied immediately, as in example,
	 * the ScalerCrop one.
	 *
	 * \todo Move it buffer queue time (likely after the IPA has filled in
	 * the parameters buffer) once we have plumbed the IPA loop in.
	 */
	applyScalerCrop(camera, request->controls());

	return 0;
}

void PipelineHandlerMaliC55::imageBufferReady(FrameBuffer *buffer)
{
	Request *request = buffer->request();

	if (completeBuffer(request, buffer))
		completeRequest(request);
}

void PipelineHandlerMaliC55::registerMaliCamera(std::unique_ptr<MaliC55CameraData> data,
						const std::string &name)
{
	std::set<Stream *> streams{ &data->frStream_ };
	if (dsFitted_)
		streams.insert(&data->dsStream_);

	std::shared_ptr<Camera> camera = Camera::create(std::move(data),
							name, streams);
	registerCamera(std::move(camera));
}

/*
 * The only camera we support through direct connection to the ISP is the
 * Mali-C55 TPG. Check we have that and warn if not.
 */
bool PipelineHandlerMaliC55::registerTPGCamera(MediaLink *link)
{
	const std::string &name = link->source()->entity()->name();
	if (name != "mali-c55 tpg") {
		LOG(MaliC55, Warning) << "Unsupported direct connection to "
				      << link->source()->entity()->name();
		/*
		 * Return true and just skip registering a camera for this
		 * entity.
		 */
		return true;
	}

	std::unique_ptr<MaliC55CameraData> data =
		std::make_unique<MaliC55CameraData>(this, link->source()->entity());

	if (data->init())
		return false;

	registerMaliCamera(std::move(data), name);

	return true;
}

/*
 * Register a Camera for each sensor connected to the ISP through a CSI-2
 * receiver.
 *
 * \todo Support more complex topologies, such as video muxes.
 */
bool PipelineHandlerMaliC55::registerSensorCamera(MediaLink *ispLink)
{
	MediaEntity *csi2 = ispLink->source()->entity();
	const MediaPad *csi2Sink = csi2->getPadByIndex(0);

	for (MediaLink *link : csi2Sink->links()) {
		MediaEntity *sensor = link->source()->entity();
		unsigned int function = sensor->function();

		if (function != MEDIA_ENT_F_CAM_SENSOR)
			continue;

		std::unique_ptr<MaliC55CameraData> data =
			std::make_unique<MaliC55CameraData>(this, sensor);
		if (data->init())
			return false;

		data->properties_ = data->sensor_->properties();
		data->updateControls();

		registerMaliCamera(std::move(data), sensor->name());
	}

	return true;
}

bool PipelineHandlerMaliC55::match(DeviceEnumerator *enumerator)
{
	const MediaPad *ispSink;

	/*
	 * We search for just the ISP subdevice and the full resolution pipe.
	 * The TPG and the downscale pipe are both optional blocks and may not
	 * be fitted.
	 */
	DeviceMatch dm("mali-c55");
	dm.add("mali-c55 isp");
	dm.add("mali-c55 resizer fr");
	dm.add("mali-c55 fr");

	media_ = acquireMediaDevice(enumerator, dm);
	if (!media_)
		return false;

	isp_ = V4L2Subdevice::fromEntityName(media_, "mali-c55 isp");
	if (isp_->open() < 0)
		return false;

	MaliC55Pipe *frPipe = &pipes_[MaliC55FR];
	frPipe->resizer = V4L2Subdevice::fromEntityName(media_, "mali-c55 resizer fr");
	if (frPipe->resizer->open() < 0)
		return false;

	frPipe->cap = V4L2VideoDevice::fromEntityName(media_, "mali-c55 fr");
	if (frPipe->cap->open() < 0)
		return false;

	frPipe->link = media_->link("mali-c55 resizer fr", 1, "mali-c55 fr", 0);
	if (!frPipe->link) {
		LOG(MaliC55, Error) << "No link between fr resizer and video node";
		return false;
	}

	frPipe->cap->bufferReady.connect(this, &PipelineHandlerMaliC55::imageBufferReady);

	dsFitted_ = !!media_->getEntityByName("mali-c55 ds");
	if (dsFitted_) {
		LOG(MaliC55, Debug) << "Downscaler pipe is fitted";

		MaliC55Pipe *dsPipe = &pipes_[MaliC55DS];

		dsPipe->resizer = V4L2Subdevice::fromEntityName(media_, "mali-c55 resizer ds");
		if (dsPipe->resizer->open() < 0)
			return false;

		dsPipe->cap = V4L2VideoDevice::fromEntityName(media_, "mali-c55 ds");
		if (dsPipe->cap->open() < 0)
			return false;

		dsPipe->link = media_->link("mali-c55 resizer ds", 1,
					    "mali-c55 ds", 0);
		if (!dsPipe->link) {
			LOG(MaliC55, Error) << "No link between ds resizer and video node";
			return false;
		}

		dsPipe->cap->bufferReady.connect(this, &PipelineHandlerMaliC55::imageBufferReady);
	}

	ispSink = isp_->entity()->getPadByIndex(0);
	if (!ispSink || ispSink->links().empty()) {
		LOG(MaliC55, Error) << "ISP sink pad error";
		return false;
	}

	/*
	 * We could have several links pointing to the ISP's sink pad, which
	 * will be from entities with one of the following functions:
	 *
	 * MEDIA_ENT_F_CAM_SENSOR - The test pattern generator
	 * MEDIA_ENT_F_VID_IF_BRIDGE - A CSI-2 receiver
	 * MEDIA_ENT_F_IO_V4L - An input device
	 *
	 * The last one will be unsupported for now. The TPG is relatively easy,
	 * we just register a Camera for it. If we have a CSI-2 receiver we need
	 * to check its sink pad and register Cameras for anything connected to
	 * it (probably...there are some complex situations in which that might
	 * not be true but let's pretend they don't exist until we come across
	 * them)
	 */
	bool registered;
	for (MediaLink *link : ispSink->links()) {
		unsigned int function = link->source()->entity()->function();

		switch (function) {
		case MEDIA_ENT_F_CAM_SENSOR:
			registered = registerTPGCamera(link);
			if (!registered)
				return registered;

			break;
		case MEDIA_ENT_F_VID_IF_BRIDGE:
			registered = registerSensorCamera(link);
			if (!registered)
				return registered;

			break;
		case MEDIA_ENT_F_IO_V4L:
			LOG(MaliC55, Warning) << "Memory input not yet supported";
			break;
		default:
			LOG(MaliC55, Error) << "Unsupported entity function";
			return false;
		}
	}

	return true;
}

REGISTER_PIPELINE_HANDLER(PipelineHandlerMaliC55, "mali-c55")

} /* namespace libcamera */
