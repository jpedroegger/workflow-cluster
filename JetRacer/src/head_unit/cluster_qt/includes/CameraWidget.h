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
    explicit CameraWidget(QWidget *parent = nullptr, int x = 0, int y = 0, int width = 0, int height = 0);
    ~CameraWidget();

private:
    QCamera *camera;                       // Camera object
    QMediaCaptureSession captureSession;   // Capture session
    QVideoWidget *videoWidget;             // Video display widget
};


#endif // CAMERA_WIDGET_H
