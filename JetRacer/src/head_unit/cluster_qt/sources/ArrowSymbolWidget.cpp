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


    if (m_draw_left_upper_curve) {
        if (m_green_l_u == false)
            drawLeftUpperCurve(painter, "black");
        else
            drawLeftUpperCurve(painter, "green");
    }

    if (m_draw_right_upper_curve) {
        if (m_green_r_u == false) 
            drawRightUpperCurve(painter, "black");
        else
            drawRightUpperCurve(painter, "green");

    }

    if (m_draw_left_lower_curve) {
        if (m_green_l_u == false)
            drawLeftLowerCurve(painter, "black");
        else
            drawLeftLowerCurve(painter, "green");
    }
    if (m_draw_right_lower_curve) {
        if (m_green_r_u == false) 
            drawRightLowerCurve(painter, "black");
        else
            drawRightLowerCurve(painter, "green");

    }
    if (m_draw_vertical_arrows) {
        if (m_green_v == false)
            drawVerticalArrows(painter, "black");
        else
            drawVerticalArrows(painter, "green");

    }
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