#include "../includes/StatsWidget.h"


/**
 * @brief Constructs a StatsWidget with the specified parameters.
 *
 * This constructor initializes the statistics widget, sets its geometry, and configures
 * its colors and default values.
 *
 * @param parent The parent widget.
 * @param x The x-coordinate of the widget's position.
 * @param y The y-coordinate of the widget's position.
 * @param width The width of the widget.
 * @param height The height of the widget.
 */
StatsWidget::StatsWidget(QWidget *parent, int x, int y, int width, int height)
    : QWidget(parent), width(width), height(height)
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
    setGeometry(x, y, width, height);
}

/**
 * @brief Handles the painting of the statistics widget.
 *
 * This method is overridden from QWidget and is called whenever the widget needs to be redrawn.
 * @param event The paint event.
 */
void    StatsWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setFont(QFont("Arial", 15, QFont::Bold));

    int spacing = 20;
    int rectWidth = width / 2 - spacing;
    int rectHeight = height / 2 - spacing - 50;

    values.clear();
    values << distance << average << consumed << obstacles;
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 2; col++)
        {
            int x = 10 + col * (rectWidth + spacing);
            int y = 10 + row * (rectHeight + spacing);

            painter.setPen(QPen(main_color, 8));
            painter.drawRect(x, y, rectWidth, rectHeight);

            painter.setPen(QPen(alphabet_color));
            painter.drawText(x + 20, y + 40, names[row * 2 + col]);
            painter.drawText(x + 20, y + 80, values[row * 2 + col]);
        }
    }
    QWidget::paintEvent(event);

}

/**
 * @brief Changes the color scheme of the statistics widget.
 *
 * This method updates the colors of the widget based on the provided
 * array index.
 *
 * @param array_index The index of the color scheme in the array.
 */
void    StatsWidget::changeColor(int  array_index)
{
    main_color = color1.main_color_array[array_index];
    accent_color = color1.accent_color_array[array_index];
    alphabet_color = color1.alphabet_color_array[array_index];   
    update();
}

/**
 * @brief A Setter that updates the distance traveled statistic.
 *
 * This method updates the distance value and converts it to the current unit.
 *
 * @param dist The distance value to set.
 */
void    StatsWidget::setDistance(int dist)
{
    if (unit == "Mi")
        distance_int = dist * 0.6214;
    else
        distance_int = dist;
    distance = QString::number(distance_int) + " " + unit;
}

/**
 * @brief A Setter that updates the average speed statistic.
 *
 * This method updates the average speed value and converts it to the current unit.
 *
 * @param avg The average speed value to set.
 */
void    StatsWidget::setAverage(int avg)
{
    if (unit == "Mi")
        average_int = avg * 0.6214;
    else
        average_int = avg;
    average = QString::number(average_int) + " " + unit + " Per Hour";
}

/**
 * @brief A Setter that updates the battery consumed statistic.
 *
 * This method updates the battery consumed value as a percentage.
 *
 * @param con The battery consumed value to set.
 */
void    StatsWidget::setConsumed(int con)
{
    consumed = QString::number(con) + "%";
}

/**
 * @brief A Setter that updates the obstacles detected statistic.
 *
 * This method updates the number of obstacles detected.
 *
 * @param obs The number of obstacles detected.
 */
void    StatsWidget::setObstacles(int obs)
{
    obstacles = QString::number(obs) + "";
}

/**
 * @brief Toggles between units.
 *
 * This method switches the unit of measurement for distance and average speed and updates the
 * displayed values accordingly.
 */
void    StatsWidget::changeUnits(void)
{
    if (unit == "Km"){
        unit = "Mi";
        distance_int *= 0.6214;
        distance = QString::number(distance_int) + " " + unit;
        average_int *= 0.6214;
        average = QString::number(average_int) + " " + unit + " Per Hour";
    } else {
        unit = "Km";
        distance_int *= 1.609;
        distance = QString::number(distance_int) + " " + unit;
        average_int *= 1.609;
        average = QString::number(average_int) + " " + unit + " Per Hour";
    }
    update();
}
