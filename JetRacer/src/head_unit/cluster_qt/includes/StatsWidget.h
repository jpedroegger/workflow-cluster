#ifndef STATSWIDGET_H
#define STATSWIDGET_H

#include "Colors.h"
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>

class StatsWidget : public QWidget
{

    public:
        StatsWidget(QWidget *parent = nullptr, int x = 0, int y = 0,
                    int width = 0, int height = 0);

        void        changeColor(int  array_index);
        void        changeUnits(void);
        void        setDistance(int dist);
        void        setAverage(int avg);
        void        setConsumed(int con);
        void        setObstacles(int obs);
        QColor      main_color;
        QColor      accent_color;
        QColor      alphabet_color;

    private:
        int         width;
        int         height;
        void        paintEvent(QPaintEvent *event) override;
        QStringList names;
        QStringList values;

        QString     distance;
        QString     average;
        QString     consumed;
        QString     obstacles;

        int         distance_int;
        int         average_int;
        QString     unit;

        Color       color1;

};

#endif
