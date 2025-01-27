#ifndef BATTERANDSPEEDYWIDGET_H
#define BATTERANDSPEEDYWIDGET_H

#include "Colors.h"
#include <QPainter>
#include <QTimer>
#include <QWidget>

class BatteryAndSpeedWidget : public QWidget
{

    public:
        BatteryAndSpeedWidget(QWidget* parent = nullptr, int x = 0, int y = 0, int width = 0, int height = 0);
        ~BatteryAndSpeedWidget();

        void setCurrentSpeed(int speed);
        void setCurrentLevel(int battery);

        void accelerate(int forward_key);

        void changeColor(int  array_index);
        void changeUnits(void);

        QColor main_color;
        QColor accent_color;
        QColor alphabet_color;

    protected:
        void paintEvent(QPaintEvent* event) override;

    private:
        int currentLevel;
        int currentSpeed;
        int imageX;
        int imageY;
        int index = 0;

        QString unit;
        Color color1;
        QPixmap image_array[4];
        QPixmap image;
        void drawScale(QPainter& painter, int centerX, int centerY, int radius);
        void drawCentralNumber(QPainter& painter, int centerX, int centerY);
        void drawBatteryNumber(QPainter& painter, int centerX, int centerY);
        QColor calculateBarColor(int value);
        void drawBars(QPainter& painter, int centerX, int centerY, int radius,
                      double startAngle, double endAngle, int Level);

    private slots:
        void updateLevel();
        void updateSpeed();
};

#endif
