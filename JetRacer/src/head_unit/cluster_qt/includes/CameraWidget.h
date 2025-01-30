#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QPushButton>

class CameraWidget : public QWidget {
    Q_OBJECT

public:
    CameraWidget(QWidget *parent = nullptr, int x = 0, int y = 0,
                int width = 0, int height = 0);
    ~CameraWidget();

private:
    QCamera              *camera;
    QMediaCaptureSession capture_session;
    QVideoWidget         *video_widget;
};

#endif
