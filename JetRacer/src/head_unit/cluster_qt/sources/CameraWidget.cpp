#include "../includes/CameraWidget.h"

CameraWidget::CameraWidget(QWidget *parent, int x, int y, int width, int height)
    : QWidget(parent),
      camera(new QCamera(this)),
      videoWidget(new QVideoWidget(this)) {

    // Set up the capture session
    captureSession.setCamera(camera);
    captureSession.setVideoOutput(videoWidget);

    // Layout for the widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(videoWidget); // Display the camera feed
    setGeometry(x, y, width, height);
    setLayout(layout);
}

CameraWidget::~CameraWidget() {
    delete camera;
}
