#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class TopBar : public QWidget
{
    public:
        TopBar();
        TopBar(QWidget* parent = nullptr);
        ~TopBar();
    protected:
    private:
};

#endif // TOPBAR_H
