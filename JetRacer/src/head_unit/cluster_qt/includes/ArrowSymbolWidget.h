#ifndef ARROWSYMBOLWIDGET_H
#define ARROWSYMBOLWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QKeyEvent>
#include "Colors.h"
#include <QTimer>

class ArrowSymbolWidget : public QWidget
{
    public:
        ArrowSymbolWidget(QWidget* parent = nullptr, int x = 0, int y = 0, int width = 0, int height = 0);
        ~ArrowSymbolWidget();

        void    changeColor(int  array_index);
        void    changeDirection(QString dir);
        void    changeAngle(double ang);
        void    variangle(void);
        QColor  main_color;
        QColor  accent_color;
        QColor  alphabet_color;
        double  angle;
        double  step;
        QString direction;

    protected:
        void    paintEvent(QPaintEvent* event) override;

    private:
        void    forwardArrows(QPainter& painter);
        void    backwardsArrows(QPainter& painter);

        Color  color1;
};

#endif