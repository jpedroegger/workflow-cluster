#ifndef BATTERYWIDGET_H
#define BATTERYWIDGET_H

#include "Colors.h"
#include <QPainter>
#include <QTimer>
#include <QWidget>


/**
 * @brief This class is a custom QWidget that displays battery level information.
 * @details This widget provides a graphical representation of the current battery level.
 */
class BatteryWidget : public QWidget
{

    public:
        BatteryWidget(QWidget* parent = nullptr, int x = 0, int y = 0, int width = 0, int height = 0);
        ~BatteryWidget() override;

        void    changeColor(int  array_index);
        void    setCurrentLevel(int battery);
        
        QColor  main_color;
        QColor  accent_color;
        QColor  alphabet_color;

    protected:
        void    paintEvent(QPaintEvent* event) override;

    private:
        int     currentLevel;
        Color   color1;
        void    drawScale(QPainter& painter, int center_x, int center_y, int radius);
        void    drawCentralNumber(QPainter& painter, int center_x, int center_y);
        QColor  calculateBarColor(int value);
        void    drawBars(QPainter& painter, int center_x, int center_y, int radius,
                      double start_angle, double end_angle, int level);

    private slots:
        void    updateLevel();
};

#endif // BATTERYWIDGET_H
