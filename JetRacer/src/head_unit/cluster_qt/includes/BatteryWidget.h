#ifndef BATTERYWIDGET_H
#define BATTERYWIDGET_H

#include "Colors.h"
#include <QPainter>
#include <QTimer>
#include <QWidget>

class BatteryWidget : public QWidget
{

    public:
        BatteryWidget(QWidget* parent = nullptr, int x = 0, int y = 0,
                     int width = 0, int height = 0);
        ~BatteryWidget();

        void   changeColor(int  array_index);
        QColor main_color;
        QColor accent_color;
        QColor alphabet_color;

        void   setCurrentLevel(int level);

    protected:
        void   paintEvent(QPaintEvent* event) override;

    private:
        int    current_level;
        Color  color1;
        QColor calculateBarColor(int value);
        void   drawScale(QPainter& painter, int centerX, int centerY, int radius);
        void   drawCentralNumber(QPainter& painter, int centerX, int centerY);
        void   drawBars(QPainter& painter, int centerX, int centerY, int radius,
                        double startAngle, double endAngle, int Level);

    private slots:
        void   updateLevel();
};

#endif
