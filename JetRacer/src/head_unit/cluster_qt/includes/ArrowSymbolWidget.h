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
        ArrowSymbolWidget(QWidget* parent = nullptr, std::string input = "none",
                          int x = 0, int y = 0, int width = 0, int height = 0);
        ~ArrowSymbolWidget();

        void   setDrawVerticalArrows(bool enabled);
        void   setdrawLeftUpperCurve(bool enabled);
        void   setdrawRightUpperCurve(bool enabled);
        void   setdrawLeftLowerCurve(bool enabled);
        void   setdrawRightLowerCurve(bool enabled);
        void   changeColor(int  array_index);
        void   changeDirection(int movement_key);
        void   variangle(void);
        QColor main_color;
        QColor accent_color;
        QColor alphabet_color;
        double angle;

    protected:
        void   paintEvent(QPaintEvent* event) override;

    private:
        void   drawVerticalArrows(QPainter& painter, std::string color);
        void   drawLeftUpperCurve(QPainter& painter, std::string color);
        void   drawRightUpperCurve(QPainter& painter, std::string color);
        void   drawLeftLowerCurve(QPainter& painter, std::string color);
        void   drawRightLowerCurve(QPainter& painter, std::string color);
        void   drawArrowhead(QPainter& painter, int x, int y, double angle,
                             int size, std::string color);

        bool   m_draw_vertical_arrows;
        bool   m_draw_left_upper_curve;
        bool   m_draw_right_upper_curve;
        bool   m_draw_left_lower_curve;
        bool   m_draw_right_lower_curve;
        bool   m_green_l_u;
        bool   m_green_r_u;
        bool   m_green_l_l;
        bool   m_green_r_l;
        bool   m_green_v;
        Color  color1;
};

#endif