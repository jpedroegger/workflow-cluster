#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QPushButton>
#include <QVBoxLayout>

class CameraWidget : public QWidget {
    Q_OBJECT

public:
    explicit CameraWidget(QWidget *parent = nullptr);
    ~CameraWidget();

private slots:
    void startCamera();
    void stopCamera();

private:
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QPushButton *startButton;
    QPushButton *stopButton;
    QVBoxLayout *layout;
};

#endif // CAMERA_WIDGET_H
