#ifndef FANSPEEDWIDGET_H
#define FANSPEEDWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>  // Include for key events
#include "Colors.h"

class FanSpeedWidget : public QWidget {

    public:
        FanSpeedWidget(QWidget* parent = nullptr, int x = 0, int y = 0, int width = 0, int height = 0);
        ~FanSpeedWidget();
        void changeColor(int array_index);
        QColor  main_color;
        QColor  accent_color;
        QColor  alphabet_color;
    protected:
        void paintEvent(QPaintEvent* event) override;
        void keyPressEvent(QKeyEvent* event) override;  // Added keyPressEvent

    private:
        int currentSpeed;
        Color color1;
        QPixmap image;             // First image
        QPixmap image_array[4]; 
        int index = 0;
        void drawScale(QPainter& painter, int centerX, int centerY, int radius);
        void drawNeedle(QPainter& painter, int centerX, int centerY, int radius);
        void drawCentralNumber(QPainter& painter, int centerX, int centerY);

    private slots:
        void updateSpeed();
};

#endif // SPEEDOMETERWIDGET_H
