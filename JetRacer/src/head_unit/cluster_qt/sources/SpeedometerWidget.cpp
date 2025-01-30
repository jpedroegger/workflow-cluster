/**
 * @file SpeedometerWidget.cpp
 * @brief Object responsible for drawing the Speedometer widget present in the
 * cluster, and updating it's values as published by EventManager.
 */

#include "../includes/SpeedometerWidget.h"

SpeedometerWidget::SpeedometerWidget(QWidget* parent, int x, int y, int width, int height)
    : QWidget(parent), current_speed(0)
{
    color1 = Color();
    unit = "DPS";
    maxSpeed = 220;
    main_color = color1.main_color;
    accent_color = color1.accent_color;
    alphabet_color = color1.alphabet_color;
    setGeometry(x, y, width, height);
    setFocusPolicy(Qt::StrongFocus);
}

void SpeedometerWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int centerX = width() / 2;
    int centerY = height() / 2;
    int radius = std::min(width(), height()) / 2 - 20;
    drawScale(painter, centerX, centerY, radius);
    drawNeedle(painter, centerX, centerY, radius);
    drawCentralNumber(painter, centerX, centerY);
}

void SpeedometerWidget::drawScale(QPainter& painter, int centerX, int centerY,
                                  int radius)
{
    painter.setPen(QPen(main_color, 15));
    painter.drawEllipse(centerX - radius, centerY - radius, 2 * radius,
                        2 * radius);
    painter.setPen(QPen(accent_color, 15));
    int smaller_r = radius - 10;
    painter.drawEllipse(centerX - smaller_r, centerY - smaller_r, 2 * smaller_r,
                        2 * smaller_r);
    painter.setPen(QPen(main_color, 15));
    smaller_r -= 80;
    painter.drawEllipse(centerX - smaller_r, centerY - smaller_r, 2 * smaller_r,
                        2 * smaller_r);
    int minSpeed = 0, step = 20;
    double startAngle = -45; // Start angle for 0 speed (bottom left)
    double endAngle = 225;   // End angle for max speed (bottom right)
    QFont font("Arial", 20);
    painter.setPen(QPen(alphabet_color, 6));
    painter.setFont(font);
    for (int speed = minSpeed; speed <= maxSpeed; speed += step / 2)
    {
        double angle =
            startAngle + (endAngle - startAngle) * (double(speed) / maxSpeed);
        double rad = qDegreesToRadians(angle);
        int xOuter = centerX - std::cos(rad) * radius;
        int yOuter = centerY - std::sin(rad) * radius;
        int xInner = centerX - std::cos(rad) * (radius - 6);
        int yInner = centerY - std::sin(rad) * (radius - 6);
        if (speed == 50 || speed == 70 || speed == 120)
            painter.setPen(QPen(Qt::red, 6));
        else if (speed / 10 % 2 != 0)
            painter.setPen(QPen(Qt::gray, 6));
        painter.drawLine(xOuter, yOuter, xInner, yInner);
        painter.setPen(QPen(alphabet_color, 2));
        int xLabel = centerX - std::cos(rad) * (radius - 55) - 8;
        int yLabel = centerY - std::sin(rad) * (radius - 55);
        if (speed / 10 % 2 == 0)
            painter.drawText(xLabel - 10, yLabel + 5, QString::number(speed));
    }
}

void SpeedometerWidget::drawNeedle(QPainter& painter, int centerX, int centerY,
                                   int radius)
{
    double startAngle = -45; // Start angle for 0 speed (bottom left)
    double endAngle = 225;   // End angle for max speed (bottom right)
    double angle =
        startAngle + (endAngle - startAngle) * (double(current_speed) / maxSpeed);
    double rad = qDegreesToRadians(angle);
    int xStart = centerX - std::cos(rad) * (radius - 80);
    int yStart = centerY - std::sin(rad) * (radius - 80);
    int xEnd = centerX - std::cos(rad) * (radius - 5);
    int yEnd = centerY - std::sin(rad) * (radius - 5);
    painter.setPen(QPen(Qt::red, 4));
    painter.drawLine(xStart, yStart, xEnd, yEnd);
}

void SpeedometerWidget::drawCentralNumber(QPainter& painter, int centerX,
                                          int centerY)
{

    QFont font("Arial", 30, QFont::Bold);
    painter.setFont(font);
    painter.setPen(QPen(alphabet_color));
    QString speedText = QString::number(current_speed);

    QFontMetrics metrics(font);
    QRect textRect = metrics.boundingRect(speedText);

    int x = centerX - textRect.width() / 2;
    int y = centerY + textRect.height() / 2 - 20;
    painter.drawText(x, y, speedText);

    QFont smallFont("Arial", 14, QFont::Bold);
    painter.setFont(smallFont);

    QFontMetrics smallMetrics(smallFont);
    int kphWidth = smallMetrics.horizontalAdvance(unit);
    int kphX = centerX - kphWidth / 2;
    int kphY =
        y + textRect.height() - 30;

    painter.drawText(kphX, kphY, unit);
}

void SpeedometerWidget::accelerate(int forward_key)
{
    // FUTURE ROS2
}


void    SpeedometerWidget::changeColor(int  array_index)
{
    main_color = color1.main_color_array[array_index];
    accent_color = color1.accent_color_array[array_index];
    alphabet_color = color1.alphabet_color_array[array_index];   
    update();
}

void    SpeedometerWidget::changeUnits(void)
{
    if (unit == "DPS"){
        unit = "FPS";
        maxSpeed = 160;
        current_speed *= 0.6214;
    } else {
        unit = "DPS";
        maxSpeed = 220;
        current_speed *= 1.609;
    }
    update();
}

QString SpeedometerWidget::getUnit()
{
    return unit;
}


void SpeedometerWidget::setCurrentSpeed(int speed)
{
    if (speed == current_speed || (unit == "MPH" && speed * 0.614 == current_speed))
        return ;
    if (unit == "MPH")
        current_speed = 0.6214 * speed;
    else
        current_speed = speed;
    update();
}

int SpeedometerWidget::getCurrentSpeed() const { return current_speed; }

SpeedometerWidget::~SpeedometerWidget() {}
