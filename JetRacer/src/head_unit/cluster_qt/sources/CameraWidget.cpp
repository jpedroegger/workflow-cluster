#include "../includes/CameraWidget.h"

CameraWidget::CameraWidget(QWidget *parent, int x, int y, int width, int height)
    : QWidget(parent),
      camera(new QCamera(this)),
      video_widget(new QVideoWidget(this)) {

    capture_session.setCamera(camera);
    capture_session.setVideoOutput(video_widget);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(video_widget);
    setLayout(layout);
    setGeometry(x, y, width, height);
}

CameraWidget::~CameraWidget() {
    delete camera;
}
