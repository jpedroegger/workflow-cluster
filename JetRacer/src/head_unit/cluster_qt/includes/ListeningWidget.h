#ifndef LISTENINGWIDGET_H
#define LISTENINGWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QVector>
#include "Colors.h"

class ListeningWidget : public QWidget {
    Q_OBJECT

public:
    ListeningWidget(QWidget *parent = nullptr, int x = 0, int y = 0, int width = 0, int height = 0);
    void    changeColor(int  array_index);
    void    toggleToggle(QString mode);
protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updatePosition();

private:
    int x;
    int step;
    QVector<int> trail;
    QTimer timer;
    QString toggle;
    QColor  main_color;
    QColor  accent_color;
    QColor  alphabet_color;
    Color  color1;
};

#endif