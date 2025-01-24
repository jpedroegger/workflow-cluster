#ifndef ARROWSYMBOLWIDGET_H
#define ARROWSYMBOLWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QKeyEvent>  // Include for key events
#include "Colors.h"

class ArrowSymbolWidget : public QWidget
{
    public:
        ArrowSymbolWidget(QWidget* parent = nullptr, std::string input = "none");
        ~ArrowSymbolWidget();

        void setDrawVerticalArrows(bool enabled);
        void setdrawLeftUpperCurve(bool enabled);
        void setdrawRightUpperCurve(bool enabled);
        void changeColor(int  array_index);
        void changeDirection(int movement_key);
        QColor  main_color;
        QColor  accent_color;
        QColor  alphabet_color;

    protected:
        ArrowSymbolWidget();
        void paintEvent(QPaintEvent* event) override;

    private:
        void drawVerticalArrows(QPainter& painter, std::string color);
        void drawLeftUpperCurve(QPainter& painter, std::string color);
        void drawRightUpperCurve(QPainter& painter, std::string color);
        void drawLeftLowerCurve(QPainter& painter, std::string color);
        void drawRightLowerCurve(QPainter& painter, std::string color);
        void drawArrowhead(QPainter& painter, int x, int y, double angle, int size, std::string color);

        bool m_drawVerticalArrows;
        bool m_drawLeftUpperCurve;
        bool m_drawRightUpperCurve;
        bool m_drawLeftLowerCurve;
        bool m_drawRightLowerCurve;
        bool m_greenLU;
        bool m_greenRU;
        bool m_greenLL;
        bool m_greenRL;
        bool m_greenV;
        Color color1;
};

#endif // ARROWSYMBOLWIDGET_H