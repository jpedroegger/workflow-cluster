#ifndef CPUTTEMPWIDGET_H
#define CPUTTEMPWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>  // Include for key events
#include "Colors.h"

class CPUTempWidget : public QWidget {

    public:
        CPUTempWidget(QWidget* parent = nullptr, int x = 0, int y = 0, int width = 0, int height = 0);
        ~CPUTempWidget() override;
        void changeColor(int array_index);
        void changeUnits();
        QColor  main_color;
        QColor  accent_color;
        QColor  alphabet_color;
    protected:
        void paintEvent(QPaintEvent* event) override;
        void keyPressEvent(QKeyEvent* event) override;  // Added keyPressEvent

    private:
        int currentSpeed;
        int index;

        Color color1;
        QString unit;
        QPixmap image;             // First image
        QPixmap image_array[4];

        void drawScale(QPainter& painter, int center_x, int center_y, int radius);
        void drawNeedle(QPainter& painter, int center_x, int center_y, int radius);
        void drawCentralNumber(QPainter& painter, int center_x, int center_y);

    private slots:
        void updateSpeed();
};

#endif // CPUTempWidget_H
