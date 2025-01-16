#ifndef SPEEDOMETERWIDGET_H
#define SPEEDOMETERWIDGET_H

#include <QKeyEvent> // Include for key events
#include <QPainter>
#include <QTimer>
#include <QWidget>

class SpeedometerWidget : public QWidget
{

    public:
        SpeedometerWidget(QWidget* parent = nullptr);
        ~SpeedometerWidget();

        void accelerate(int forward_key);
        int getCurrentSpeed(void) const;
        void setCurrentSpeed(int speed);

    protected:
        void paintEvent(QPaintEvent* event) override;

    private:
        int currentSpeed;
        void drawScale(QPainter& painter, int centerX, int centerY, int radius);
        void drawNeedle(QPainter& painter, int centerX, int centerY,
                        int radius);
        void drawCentralNumber(QPainter& painter, int centerX, int centerY);

    private slots:
        void updateSpeed();
};

#endif
