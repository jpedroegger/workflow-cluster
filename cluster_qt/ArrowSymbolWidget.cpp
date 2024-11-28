#include "includes/ArrowSymbolWidget.h"

ArrowSymbolWidget::ArrowSymbolWidget() { }

ArrowSymbolWidget::ArrowSymbolWidget(QWidget* parent) : QWidget(parent) { }

void ArrowSymbolWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    // Enable anti-aliasing for smoother lines
    painter.setRenderHint(QPainter::Antialiasing);
    // Set pen and brush for drawing
    QPen pen(Qt::black, 10); // Black color, width 1
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush); // Fill arrowheads with black

    int centerX = width() / 2;
    int centerY = height() / 2;
    int stemLength = 100; // Length of the vertical stem
    int arrowSize = 10;   // Size of the arrowheads

    // Draw the central vertical arrow
    painter.drawLine(centerX, centerY, centerX, centerY - stemLength);
    drawArrowhead(painter, centerX, centerY - stemLength, 90, arrowSize);

    painter.drawLine(centerX, centerY, centerX, centerY + stemLength);
    drawArrowhead(painter, centerX, centerY + stemLength, 270, arrowSize);

    QPainterPath leftCurve;
    leftCurve.moveTo(centerX, centerY + 40); // Start at the center
    leftCurve.cubicTo(centerX - 50, centerY - 40, centerX - 70, centerY - 50, centerX - 120, centerY - 60); // More curved, but within 100 pixels
    painter.drawPath(leftCurve);
    drawArrowhead(painter, centerX - 120, centerY - 55, 135, arrowSize); // Arrowhead pointing left
    
    // Right Curved Arrow (more curved, moving upward and right, within 100 pixels from center)
    QPainterPath rightCurve;
    rightCurve.moveTo(centerX, centerY + 40); // Start at the center
    rightCurve.cubicTo(centerX + 50, centerY - 40, centerX + 70, centerY - 50, centerX + 120, centerY - 60); // More curved, but within 100 pixels
    painter.drawPath(rightCurve);
    drawArrowhead(painter, centerX + 120, centerY - 55, 45, arrowSize); // Arrowhead pointing right


}

void ArrowSymbolWidget::drawArrowhead(QPainter& painter, int x, int y, double angle, int size)
{
    QPolygon arrowHead;
    double radAngle = qDegreesToRadians(angle);
    double radLeft = qDegreesToRadians(angle + 150);  // Left wing of the arrowhead
    double radRight = qDegreesToRadians(angle - 150); // Right wing of the arrowhead

    arrowHead << QPoint(x, y);
    arrowHead << QPoint(x + std::cos(radLeft) * size, y + std::sin(radLeft) * size);
    arrowHead << QPoint(x + std::cos(radRight) * size, y + std::sin(radRight) * size);

    painter.drawPolygon(arrowHead);
}

ArrowSymbolWidget::~ArrowSymbolWidget() {}
