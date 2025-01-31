#include "../includes/ArrowSymbolWidget.h"

ArrowSymbolWidget::ArrowSymbolWidget(QWidget* parent, std::string input, int x, int y, int width, int height)
    : QWidget(parent)
{
    color1 = Color();
    main_color = color1.main_color;
    accent_color = color1.accent_color;
    alphabet_color = color1.alphabet_color;

    m_green_l_u = false;
    m_green_r_u = false;
    m_green_l_l = false;
    m_green_r_l = false;
    m_green_v = false;
    m_draw_vertical_arrows = true;
    m_draw_left_upper_curve = true;
    m_draw_right_upper_curve = true;
    m_draw_left_lower_curve = true;
    m_draw_right_lower_curve = true;
    if (input == "front")
        m_green_v = true;
    else if (input == "left")
        m_green_l_u = true;
    else if (input == "right")
        m_green_r_u = true;
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(x, y, width, height);
    angle = 0;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ArrowSymbolWidget::variangle);
    timer->start(200); // 200 ms delay
}

ArrowSymbolWidget::~ArrowSymbolWidget() {}


void ArrowSymbolWidget::setDrawVerticalArrows(bool enabled)
{
    m_draw_vertical_arrows = enabled;
    update();
}

void ArrowSymbolWidget::setdrawLeftUpperCurve(bool enabled)
{
    m_draw_left_upper_curve = enabled;
    update();
}

void ArrowSymbolWidget::setdrawRightUpperCurve(bool enabled)
{
    m_draw_right_upper_curve = enabled;
    update();
}

void ArrowSymbolWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(width() / 2, height() - 50);  // Start from the center bottom

        int length = 150;  // Length of curve arc
        float curvature = angle * (M_PI / 180.0);  // Convert degrees to radians

        QPainterPath path;
        path.moveTo(0, 0);

        // Calculate endpoint based on curvature and length
        float endX = length * std::sin(curvature);
        float endY = -length * std::cos(curvature);

        QRectF controlRect(-length, -length, 2 * length, 2 * length);
        path.quadTo(QPointF(endX / 2, -40 * std::sin(curvature)), QPointF(endX, endY));

        painter.setPen(QPen(Qt::blue, 2));
        painter.drawPath(path);

}



void   ArrowSymbolWidget::variangle(void)
{
    angle += 5;  // Increase angle step by step
    if (angle > 360) 
        angle = 0;  // Reset after a full circle
    update();  // Trigger a repaint
}


void ArrowSymbolWidget::drawVerticalArrows(QPainter& painter, std::string color)
{
    int centerX = width() / 2;
    int centerY = height() / 2 - 30;
    int stemLength = 100;
    int arrowSize = 10;

    if (color == "black")
        painter.setPen(QPen(main_color,10));
    else
        painter.setPen(QPen(accent_color,10));

    painter.drawLine(centerX, centerY + 40 , centerX, centerY - stemLength);
    drawArrowhead(painter, centerX, centerY - stemLength - 30, 270, arrowSize, color);

    painter.drawLine(centerX, centerY + 40, centerX, centerY + stemLength + 60);
    drawArrowhead(painter, centerX, centerY + stemLength + 90, 90, arrowSize, color);
}

void ArrowSymbolWidget::drawLeftUpperCurve(QPainter& painter, std::string color)
{
    int centerX = width() / 2;
    int centerY = height() / 2 - 30;
    int arrowSize = 10;

    if (color == "black")
        painter.setPen(QPen(main_color,10));
    else
        painter.setPen(QPen(accent_color,10));

    QPainterPath leftCurve;
    leftCurve.moveTo(centerX, centerY + 40);
    leftCurve.cubicTo(centerX - 30, centerY - 40, centerX - 30, centerY - 50, centerX - 80, centerY - 60);
    painter.drawPath(leftCurve);
    drawArrowhead(painter, centerX - 80, centerY - 50, 45, arrowSize, color);
}

void ArrowSymbolWidget::drawRightUpperCurve(QPainter& painter, std::string color)
{
    int centerX = width() / 2;
    int centerY = height() / 2 - 30;
    int arrowSize = 10;

    if (color == "black")
        painter.setPen(QPen(main_color,10));
    else
        painter.setPen(QPen(accent_color,10));

    QPainterPath rightCurve;
    rightCurve.moveTo(centerX, centerY + 40);
    rightCurve.cubicTo(centerX + 30, centerY - 40, centerX + 30, centerY - 50, centerX + 80, centerY - 60);
    painter.drawPath(rightCurve);
    drawArrowhead(painter, centerX + 80, centerY - 50, 135, arrowSize, color);
}

void ArrowSymbolWidget::drawLeftLowerCurve(QPainter& painter, std::string color)
{
    int centerX = width() / 2;
    int centerY = height() / 2 - 30 + 70;
    int arrowSize = 10;

    if (color == "black")
        painter.setPen(QPen(main_color,10));
    else
        painter.setPen(QPen(accent_color,10));

    QPainterPath leftCurve;
    leftCurve.moveTo(centerX, centerY - 40);
    leftCurve.cubicTo(centerX - 30, centerY + 40, centerX - 30, centerY + 50, centerX - 80, centerY + 60);
    painter.drawPath(leftCurve);
    drawArrowhead(painter, centerX - 80, centerY + 70, 45, arrowSize, color);
}

void ArrowSymbolWidget::drawRightLowerCurve(QPainter& painter, std::string color)
{
    int centerX = width() / 2;
    int centerY = height() / 2 - 30 + 70;
    int arrowSize = 10;

    if (color == "black")
        painter.setPen(QPen(main_color,10));
    else
        painter.setPen(QPen(accent_color,10));

    QPainterPath rightCurve;
    rightCurve.moveTo(centerX, centerY - 40);
    rightCurve.cubicTo(centerX + 30, centerY + 40, centerX + 30, centerY + 50, centerX + 80, centerY + 60);
    painter.drawPath(rightCurve);
    drawArrowhead(painter, centerX + 80, centerY + 70, 135, arrowSize, color);
}

void ArrowSymbolWidget::drawArrowhead(QPainter& painter, int x, int y, double angle, int size, std::string color)
{
    QPolygon arrowHead;
    double radAngle = qDegreesToRadians(angle);
    double radLeft = qDegreesToRadians(angle + 150);
    double radRight = qDegreesToRadians(angle - 150);

    if (color == "black")
        painter.setPen(QPen(main_color,10));
    else
        painter.setPen(QPen(accent_color,10));

    size += 20;
    arrowHead << QPoint(x + std::cos(radRight) * size, y + std::sin(radRight) * size);
    arrowHead << QPoint(x + std::cos(radLeft) * size, y + std::sin(radLeft) * size);
    arrowHead << QPoint(x, y);

    painter.drawPolygon(arrowHead);
}

void ArrowSymbolWidget::changeDirection(int movement_key)
{
   // FUTURE ROS2 CODE
}

void    ArrowSymbolWidget::changeColor(int  array_index)
{
    main_color = color1.main_color_array[array_index];
    accent_color = color1.accent_color_array[array_index];
    alphabet_color = color1.alphabet_color_array[array_index];   
    update();
}