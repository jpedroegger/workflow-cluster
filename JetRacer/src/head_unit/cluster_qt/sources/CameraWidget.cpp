#include "../includes/CameraWidget.h"

CameraWidget::CameraWidget(QWidget *parent, std::string input, int x, int y, int width, int height)
    : QWidget(parent),
      camera(new QCamera(this)),
      videoWidget(new QVideoWidget(this)) {

    // Set up the capture session
    captureSession.setCamera(camera);
    captureSession.setVideoOutput(videoWidget);

    // Layout for the widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(videoWidget); // Display the camera feed
    setLayout(layout);
    setGeometry(x, y, width, height);
}

CameraWidget::~CameraWidget() {
    delete camera;
}
