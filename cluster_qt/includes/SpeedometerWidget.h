#ifndef SPEEDOMETERWIDGET_H
#define SPEEDOMETERWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

class SpeedometerWidget : public QWidget {

    public:
        SpeedometerWidget(QWidget* parent = nullptr);
        ~SpeedometerWidget();
    protected:
        void paintEvent(QPaintEvent* event) override;

    private:
        int currentSpeed;
        void drawScale(QPainter& painter, int centerX, int centerY, int radius);
        void drawNeedle(QPainter& painter, int centerX, int centerY, int radius);
        void drawCentralNumber(QPainter& painter, int centerX, int centerY);

    private slots:
        void updateSpeed();
};

#endif // SPEEDOMETERWIDGET_H
