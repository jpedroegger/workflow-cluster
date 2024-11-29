#include "includes/BatteryWidget.h"

BatteryWidget::BatteryWidget(QWidget* parent)
    : QWidget(parent), currentSpeed(100)
{
    // Set up a timer to simulate speed changes (optional)
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &BatteryWidget::updateSpeed);
    timer->start(800); // Update speed every 100ms
}

void BatteryWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int centerX = width() / 2;
    int centerY = height() / 2;
    int radius = std::min(width(), height()) / 2 - 20;
    // Draw circular scale
    drawScale(painter, centerX, centerY, radius);
    // Draw needle
    drawCentralNumber(painter, centerX, centerY);
}

void BatteryWidget::drawScale(QPainter& painter, int centerX, int centerY, int radius) {
    // Draw outer circle
    painter.setPen(QPen(Qt::black, 15));
    int smaller_r = radius - 10;
    painter.setPen(QPen(Qt::black, 15));
    
    // Draw tick marks and labels
    int minSpeed = 0, maxSpeed = 100, step = 10;
    double startAngle = -45; // Start angle for 0 speed (bottom left)
    double endAngle = 225;     // End angle for max speed (bottom right)
    QFont font("Arial", 20, QFont::Bold);  // Example: Arial, size 10, bold
    painter.setPen(QPen(Qt::white, 6));
    painter.setFont(font);
    for (int speed = minSpeed; speed <= maxSpeed; speed += step / 2) {
        double angle = startAngle + (endAngle - startAngle) * (double(speed) / maxSpeed);
        double rad = qDegreesToRadians(angle);
        int xOuter = centerX - std::cos(rad) * radius;
        int yOuter = centerY - std::sin(rad) * radius;
        int xInner = centerX - std::cos(rad) * (radius - 6);
        int yInner = centerY - std::sin(rad) * (radius - 6);
        // Draw tick mark
        painter.setPen(QPen(Qt::white, 6));
        // Draw label
        int xLabel = centerX - std::cos(rad) * (radius - 55) - 8;
        int yLabel = centerY - std::sin(rad) * (radius - 55);
    }
        drawBars(painter, centerX, centerY, radius, startAngle, endAngle, 100);
    painter.setPen(QPen(Qt::black, 15));
    painter.drawEllipse(centerX - radius, centerY - radius, 2 * radius, 2 * radius);
    smaller_r -=  80;
    painter.drawEllipse(centerX - smaller_r, centerY - smaller_r, 2 * smaller_r, 2 * smaller_r);
}

void BatteryWidget::drawBars(QPainter& painter, int centerX, int centerY, int radius, double startAngle, double endAngle, int speed) {
    int numBars = speed / 2; // Total number of bars (from 0 to 100)
    int barWidth = 6;  // Width of each bar
    int innerRadius = radius - 80; // Inner radius for bars
    int outerRadius = radius - 5; // Outer radius for bars

    int activeBars = static_cast<int>(currentSpeed); // Bars below the needle

    for (int i = 0; i <= numBars; ++i) {
        double angle = startAngle + (endAngle - startAngle) * (double(i) / numBars);
        double rad = qDegreesToRadians(angle);

        int xOuter = centerX - std::cos(rad) * outerRadius;
        int yOuter = centerY - std::sin(rad) * outerRadius;
        int xInner = centerX - std::cos(rad) * innerRadius;
        int yInner = centerY - std::sin(rad) * innerRadius;

        // Determine bar color based on the value
        QColor barColor = (i * 2 <= activeBars) ? calculateBarColor(i * 2) : QColor(50, 50, 50); // Gray for inactive bars

        // Draw the bar
        painter.setPen(QPen(barColor, barWidth, Qt::SolidLine, Qt::RoundCap));
        painter.drawLine(xInner, yInner, xOuter, yOuter);
    }
}

QColor BatteryWidget::calculateBarColor(int value) {
    if (value < 5) {
        return QColor(139, 0, 0); // Dark red
    } else if (value < 50) {
        // Gradient from dark red to yellow
        int red = 139 + (255 - 139) * (value - 5) / 45;
        int green = (255 - 139) * (value - 5) / 45;
        return QColor(red, green, 0);
    } else if (value < 80) {
        // Gradient from yellow to green
        int red = 255 - (255 * (value - 50) / 30);
        int green = 255;
        return QColor(red, green, 0);
    } else {
        // Green
        return QColor(0, 255, 0);
    }
}

/*void BatteryWidget::drawNeedle(QPainter& painter, int centerX, int centerY, int radius) {
    double startAngle = -45; // Start angle for 0 speed (bottom left)
    double endAngle = 225;     // End angle for max speed (bottom right)
    // Calculate the angle based on current speed in clockwise direction
    double angle = startAngle + (endAngle - startAngle) * (double(currentSpeed) / 100);
    double rad = qDegreesToRadians(angle);
    int xStart = centerX - std::cos(rad) * (radius - 80);
    int yStart = centerY - std::sin(rad) * (radius - 80);
    int xEnd = centerX - std::cos(rad) * (radius - 5);
    int yEnd = centerY - std::sin(rad) * (radius - 5);
    QPen pen(Qt::red, 4);
    painter.setPen(pen);
    // Draw the needle
    painter.drawLine(xStart, yStart, xEnd, yEnd);
}*/

void BatteryWidget::drawCentralNumber(QPainter& painter, int centerX, int centerY) {
    // Set font and color for the speed number
    QFont font("Arial", 40, QFont::Bold);  // Large font for the speed
    painter.setFont(font);
    painter.setPen(QPen(Qt::white));
    QString speedText = QString::number(currentSpeed);
    // Calculate the bounding box for the speed text
    QFontMetrics metrics(font);
    QRect textRect = metrics.boundingRect(speedText);
    // Center the speed text
    int x = centerX - textRect.width() / 2;
    int y = centerY + textRect.height() / 2 - 20;
    painter.drawText(x, y, speedText);
    // Set a smaller font and adjust position for "KPH"
    QFont smallFont("Arial", 14, QFont::Bold);  // Smaller font for the unit
    painter.setFont(smallFont);
    // Adjust the position to render "KPH" just below the speed number
    QFontMetrics smallMetrics(smallFont);
    int kphWidth = smallMetrics.horizontalAdvance("%");
    int kphX = centerX - kphWidth / 2; // Center-align "KPH"
    int kphY = y + textRect.height() - 30;  // Position "KPH" below the speed text
    // Draw "KPH"
    painter.drawText(kphX, kphY, "%");
}

void BatteryWidget::updateSpeed() {
    // Simulate a speed increase for demonstration purposes
    currentSpeed = (currentSpeed - 0.1); // Cycle speed between 0 and 160
    if (currentSpeed <= 0)
        currentSpeed = 100;
    update(); // Trigger a repaint
}

BatteryWidget::~BatteryWidget() {}
