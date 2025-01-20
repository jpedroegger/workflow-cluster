#include "../includes/StatsWidget.h"

StatsWidget::StatsWidget(QWidget *parent)
    : QWidget(parent)
{
    color1 = Color();
    main_color = color1.main_color;
    accent_color = color1.accent_color;
    alphabet_color = color1.alphabet_color;
    // Main layout for the widget

    // Add two rows to the layout
    names << "Distance Traveled:" << "Average Speed:" << "Battery Consumed:" << "Civilians Killed:";
    values << "4322 M" << "53 MPS" << "24.2%" << "120";

    setFixedSize(800, 800); // Square size
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
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 2; ++col)
        {
            int x = col * (rectWidth + spacing) + spacing;
            int y = row * (rectHeight + spacing) + spacing + 200;

            // Draw rectangle
            painter.setPen(QPen(main_color, 5));
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