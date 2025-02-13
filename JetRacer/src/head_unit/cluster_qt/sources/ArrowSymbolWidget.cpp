#include "../includes/ArrowSymbolWidget.h"

ArrowSymbolWidget::ArrowSymbolWidget(QWidget* parent, int x, int y, int width, int height)
    : QWidget(parent)
{
    color1 = Color();
    main_color = color1.main_color;
    accent_color = color1.accent_color;
    alphabet_color = color1.alphabet_color;

    setFocusPolicy(Qt::StrongFocus);
    setGeometry(x, y, width, height);
    angle = 240;
    step = 5;
    direction = "forward";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ArrowSymbolWidget::variangle);
    timer->start(500); // 200 ms delay
}

ArrowSymbolWidget::~ArrowSymbolWidget() {}


void ArrowSymbolWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2 - 50, height() / 2);
    QPixmap image = QPixmap("/workspace/JetRacer/src/head_unit/cluster_qt/assets/icons/car.png");

    int imageWidth = 100;
    int imageHeight = 150;
    int image_x = -imageWidth / 2;
    int image_y = -imageWidth / 2;

    painter.drawPixmap(0, 0, imageWidth, imageHeight, image);
    if (direction == "forward")
        forwardArrows(painter);
    else
        backwardsArrows(painter);

}

void ArrowSymbolWidget::forwardArrows(QPainter& painter)
{
    float radius = 150;
    float smaller = radius / 2;
    float angle_y_offset_left = - angle * angle / 257.2 + 126;
    float angle_y_offset_right = angle * angle / 430 - 75.35;
    float curvature = angle * (M_PI / 180.0);
    float final_x = radius * std::sin(curvature);
    float final_y = radius * std::cos(curvature);
    float offset = 100;
    if (angle < 180)
        angle_y_offset_right = 0;
    else
        angle_y_offset_left = 0;

    QPainterPath path;
    path.moveTo(0, 0);

    QRectF controlRect(-radius, -radius, 2 * radius, 2 * radius);
    path.quadTo(QPointF(0, -smaller - angle_y_offset_left), QPointF(final_x, final_y - angle_y_offset_left));
    painter.setPen(QPen(main_color, 8));
    painter.drawPath(path);

    QPainterPath rightPath;
    rightPath.moveTo(offset, 0);
    rightPath.quadTo(QPointF(offset, -smaller - angle_y_offset_right), QPointF(offset + final_x, final_y - angle_y_offset_right));

    painter.drawPath(rightPath);
}

void ArrowSymbolWidget::backwardsArrows(QPainter& painter)
{
    float radius = 150;
    float smaller = radius / 2;
    float angle_y_offset_left = - angle * angle / 257.2 + 126;
    float angle_y_offset_right = angle * angle / 430 - 75.35;
    float offset_x = 100;
    float offset_y = 120;
    float curvature = angle * (M_PI / 180.0);
    float final_x = -1 * radius * std::sin(curvature);
    float final_y = -1 * radius * std::cos(curvature);
    if (angle < 180)
        angle_y_offset_right = 0;
    else
        angle_y_offset_left = 0;

    QPainterPath path;
    path.moveTo(0, offset_y);
    path.quadTo(QPointF(0, offset_y + smaller + angle_y_offset_right), QPointF(final_x, offset_y + final_y + angle_y_offset_right));
    painter.setPen(QPen(main_color, 8));
    painter.drawPath(path);

    QPainterPath rightPath;
    rightPath.moveTo(offset_x, offset_y);
    rightPath.quadTo(QPointF(offset_x, offset_y + smaller + angle_y_offset_left), QPointF(offset_x + final_x, offset_y + final_y + angle_y_offset_left));

    painter.drawPath(rightPath);
}

void   ArrowSymbolWidget::variangle(void)
{
    angle -= step;
    if (angle < 120 || angle > 240)
    {
        step *= -1;
        if (angle > 240 && direction == "forward")
            direction = "backwards";
        else if (angle > 240 && direction == "backwards")
            direction = "forward";
    }
    update();
}


void ArrowSymbolWidget::changeDirection(double ang, QString dir)
{
    if (angle == ang && direction == dir)
        return ;
    angle = ang;
    direction = dir;
    update();
}

void    ArrowSymbolWidget::changeColor(int  array_index)
{
    main_color = color1.main_color_array[array_index];
    accent_color = color1.accent_color_array[array_index];
    alphabet_color = color1.alphabet_color_array[array_index];   
    update();
}