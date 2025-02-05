#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QPushButton>


/**
 * @brief The CameraWidget class is a custom QWidget that displays a live camera feed.
 * @details This widget encapsulates a QCamera, QMediaCaptureSession, and QVideoWidget to provide
 * a simple interface for displaying a camera feed in a Qt application. It supports
 * customization of position and size.
 */
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
