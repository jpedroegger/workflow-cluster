#ifndef ARROWSYMBOLWIDGET_H
#define ARROWSYMBOLWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class ArrowSymbolWidget : public QWidget
{
    public:
        ArrowSymbolWidget();
        ArrowSymbolWidget(QWidget* parent = nullptr);
        ~ArrowSymbolWidget();
    protected:
        void paintEvent(QPaintEvent* event) override;
    private:
        void drawArrowhead(QPainter& painter, int x, int y, double angle, int size);
};

#endif // ARROWSYMBOLWIDGET_H
