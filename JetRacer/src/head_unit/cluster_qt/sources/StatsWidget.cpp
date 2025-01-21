#include "../includes/StatsWidget.h"

StatsWidget::StatsWidget(QWidget *parent)
    : QWidget(parent)
{
    setDistance(0);
    setAverage(0);
    setConsumed(0);
    setObstacles(0);
    color1 = Color();
    unit = "Km";
    main_color = color1.main_color;
    accent_color = color1.accent_color;
    alphabet_color = color1.alphabet_color;
    names << "Distance Traveled:" << "Average Speed:" << "Battery Consumed:" << "Obstacles Detected:";
    setFixedSize(800, 800);
}


void    StatsWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Set up font for text
    painter.setFont(QFont("Arial", 20, QFont::Bold));

    int rectWidth = 370;
    int rectHeight = 170;
    int spacing = 20;

    // Draw two rows, each with two rectangles
    values << distance << average << consumed << obstacles;
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 2; ++col)
        {
            int x = col * (rectWidth + spacing) + spacing;
            int y = row * (rectHeight + spacing) + spacing + 200;

            // Draw rectangle
            painter.setPen(QPen(main_color, 8));
            painter.drawRect(x, y, rectWidth, rectHeight);

            painter.setPen(QPen(alphabet_color));
            painter.drawText(x + 20, y + 40, names[row * 2 + col]);
            painter.drawText(x + 20, y + 80, values[row * 2 + col]);
        }
    }
    QWidget::paintEvent(event);
}

void    StatsWidget::changeColor(int  array_index)
{
    main_color = color1.main_color_array[array_index];
    accent_color = color1.accent_color_array[array_index];
    alphabet_color = color1.alphabet_color_array[array_index];   
    update();
}

void    StatsWidget::setDistance(int dist)
{
    distance_int = dist;
    distance = distance_int + " " + unit;
}

void    StatsWidget::setAverage(int avg)
{
    average_int = avg;
    average = average_int + " " + unit + " Per Hour";
}

void    StatsWidget::setConsumed(int con)
{
    consumed = con + "%";
}

void    StatsWidget::setObstacles(int obs)
{
    obstacles = obs + "";
}

void    StatsWidget::changeUnits(void)
{
    if (unit == "Km"){
        unit = "Mi";
        distance_int *= 0.6214;
        distance = distance_int + " " + unit;
        average_int *= 0.6214;
        average = average_int + " " + unit + " Per Hour";
    } else {
        unit = "Km";
        distance_int *= 1.609;
        distance = distance_int + " " + unit;
        average_int *= 1.609;
        average = average_int + " " + unit + " Per Hour";
    }
    update();
}
