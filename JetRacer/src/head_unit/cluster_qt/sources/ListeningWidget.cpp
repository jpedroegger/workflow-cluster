#include "../includes/ListeningWidget.h"

ListeningWidget::ListeningWidget(QWidget *parent, int x, int y, int width, int height)
    : QWidget(parent), x(0)
{
    
    color1 = Color();
    main_color = color1.main_color;
    accent_color = color1.accent_color;
    alphabet_color = color1.alphabet_color;

    setFocusPolicy(Qt::StrongFocus);
    setGeometry(x, y, width, height);
    step = 2;
    toggle = "on";
    connect(&timer, &QTimer::timeout, this, &ListeningWidget::updatePosition);
    timer.start(2);
}

void ListeningWidget::updatePosition()
{
    if (toggle != "on")
    {
        x = 0;
        step = 2;
        return ;
    }
    trail.append(x);
    x += step;
    if (x > width() || x < 0)
    {
        step *= -1;
        trail.clear();
    }
    update();
}

void ListeningWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    double max = width() / 2;
    for (int i = 0; i < trail.size(); ++i) {
        int alpha = static_cast<int>(255.0 * (i / max));  
        QColor color(main_color.red(), main_color.green(), main_color.blue(), alpha);
        painter.setPen(QPen(color, 8));
        painter.drawPoint(trail[i], height() / 2);
    }
    painter.setPen(QPen(main_color, 8));
    painter.drawPoint(x, height() / 2);
}

void    ListeningWidget::changeColor(int  array_index)
{
    main_color = color1.main_color_array[array_index];
    accent_color = color1.accent_color_array[array_index];
    alphabet_color = color1.alphabet_color_array[array_index];   
    update();
}

void    ListeningWidget::toggleToggle(QString mode)
{
    toggle = mode;
}