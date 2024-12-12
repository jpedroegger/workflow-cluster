#include "includes/CameraWidget.h"

CameraWidget::CameraWidget(QWidget *parent)
    : QWidget(parent),
      camera(new QCamera(this)),
      viewfinder(new QCameraViewfinder(this)),
      startButton(new QPushButton("Start Camera", this)),
      stopButton(new QPushButton("Stop Camera", this)),
      layout(new QVBoxLayout(this)) {

    // Set up the layout
    layout->addWidget(viewfinder);
    layout->addWidget(startButton);
    layout->addWidget(stopButton);
    setLayout(layout);

    // Configure the camera
    camera->setViewfinder(viewfinder);

    // Connect the buttons to the camera controls
    connect(startButton, &QPushButton::clicked, this, &CameraWidget::startCamera);
    connect(stopButton, &QPushButton::clicked, this, &CameraWidget::stopCamera);

    // Start the camera initially
    camera->start();
}

CameraWidget::~CameraWidget() {
    // Clean up camera resources
    camera->stop();
    delete camera;
}

void CameraWidget::startCamera() {
    camera->start();
}

void CameraWidget::stopCamera() {
    camera->stop();
}
