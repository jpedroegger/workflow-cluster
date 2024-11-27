#include "includes/ArrowSymbolWidget.h"

ArrowSymbolWidget::ArrowSymbolWidget() { }

ArrowSymbolWidget::ArrowSymbolWidget(QWidget* parent) : QWidget(parent) { }

void ArrowSymbolWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    // Enable anti-aliasing for smoother lines
    painter.setRenderHint(QPainter::Antialiasing);
    // Set pen and brush for drawing
    QPen pen(Qt::gray, 10); // Black color, width 1
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

    // Draw the left curved arrow
    // Left Curved Arrow (moving left and away from center)
    // Left Curved Arrow (more curved, moving upward and left, within 100 pixels from center)
    QPainterPath leftCurve;
    leftCurve.moveTo(centerX, centerY); // Start at the center
    leftCurve.cubicTo(centerX - 50, centerY - 80, centerX - 70, centerY - 120, centerX - 100, centerY - 140); // More curved, but within 100 pixels
    painter.drawPath(leftCurve);
    drawArrowhead(painter, centerX - 100, centerY - 140, 135, arrowSize); // Arrowhead pointing left
    
    // Right Curved Arrow (more curved, moving upward and right, within 100 pixels from center)
    QPainterPath rightCurve;
    rightCurve.moveTo(centerX, centerY); // Start at the center
    rightCurve.cubicTo(centerX + 50, centerY - 80, centerX + 70, centerY - 120, centerX + 100, centerY - 140); // More curved, but within 100 pixels
    painter.drawPath(rightCurve);
    drawArrowhead(painter, centerX + 100, centerY - 140, 45, arrowSize); // Arrowhead pointing right


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
