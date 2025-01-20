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
        StatsWidget(QWidget *parent = nullptr);
        void changeColor(int  array_index);
        QColor main_color;
        QColor accent_color;
        QColor alphabet_color;

    private:
        void paintEvent(QPaintEvent *event) override;
        QStringList names;
        QStringList values;
        Color color1;

};

#endif // STATSWIDGET_H
