#include "includes/FanSpeedWidget.h"

FanSpeedWidget::FanSpeedWidget(QWidget* parent)
    : QWidget(parent), currentSpeed(0)
{
    setFocusPolicy(Qt::StrongFocus);  // Ensure the widget can receive key events
}


void FanSpeedWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int centerX = (width() - 50) / 2;
    int centerY = (height() - 50) / 2;
    int radius = std::min((width() - 50), (height() - 50)) / 2 - 20;
    // Draw circular scale
    drawScale(painter, centerX, centerY, radius);
    // Draw needle
    drawNeedle(painter, centerX, centerY, radius);
    drawCentralNumber(painter, centerX, centerY);
}

void FanSpeedWidget::drawScale(QPainter& painter, int centerX, int centerY, int radius) {
    // Draw outer circle
    painter.setPen(QPen(Qt::black, 8));
    painter.drawEllipse(centerX - radius, centerY - radius, 2 * radius, 2 * radius);

}

void FanSpeedWidget::drawNeedle(QPainter& painter, int centerX, int centerY, int radius) {
    double startAngle = -45; // Start angle for 0 speed (bottom left)
    double endAngle = 225;     // End angle for max speed (bottom right)
    // Calculate the angle based on current speed in clockwise direction
    double angle = startAngle + (endAngle - startAngle) * (double(currentSpeed) / 160);
    double rad = qDegreesToRadians(angle);
    int xStart = centerX - std::cos(rad) * (radius - 3);
    int yStart = centerY - std::sin(rad) * (radius - 3);
    int xEnd = centerX - std::cos(rad) * (radius + 1);
    int yEnd = centerY - std::sin(rad) * (radius + 1);
    QPen pen(Qt::gray, 5);
    painter.setPen(pen);
    // Draw the needle
    painter.drawLine(xStart, yStart, xEnd, yEnd);
}

void FanSpeedWidget::drawCentralNumber(QPainter& painter, int centerX, int centerY) {
    // Set font and color for the speed number
    QFont font("Arial", 20, QFont::Bold);  // Large font for the speed
    painter.setFont(font);
    painter.setPen(QPen(Qt::white));
    QString speedText = QString::number(currentSpeed);
    // Calculate the bounding box for the speed text
    QFontMetrics metrics(font);
    QRect textRect = metrics.boundingRect(speedText);
    // Center the speed text
    int x = centerX - textRect.width() / 2;
    int y = centerY + textRect.height() / 2 - 10;
    painter.drawText(x, y, speedText);
    // Set a smaller font and adjust position for "KPH"
    QFont smallFont("Arial", 5, QFont::Bold);  // Smaller font for the unit
    painter.setFont(smallFont);
    // Adjust the position to render "KPH" just below the speed number
    QFontMetrics smallMetrics(smallFont);
    int kphWidth = smallMetrics.horizontalAdvance("FAN\nRPM");
    int kphX = centerX - kphWidth / 2; // Center-align "KPH"
    int kphY = y + textRect.height() - 20;  // Position "KPH" below the speed text
    // Draw "KPH"
    painter.drawText(kphX, kphY, "FAN\nRPM");
    QPixmap image("assets/icons/fan.png"); // Update with the correct path
    if (!image.isNull()) {
        int imgWidth = 25;  // Adjust as needed
        int imgHeight = 25; // Adjust as needed
        int imgX = centerX - imgWidth / 2; // Center-align the image
        int imgY = kphY + 30; // Position image below the "FAN RPM" text
        painter.drawPixmap(imgX, imgY, imgWidth, imgHeight, image);
    }
}

void FanSpeedWidget::keyPressEvent(QKeyEvent* event)
{
    // Check if the Up Arrow key is pressed
    if (event->key() == Qt::Key_Space) {
        currentSpeed += 2;  // Increase speed by 2
        if (currentSpeed > 160) {
            currentSpeed = 160;  // Cap speed at 160
        }
        update();  // Trigger a repaint to reflect the updated speed
    }

        // Check if the Up Arrow key is pressed
    if (event->key() == Qt::Key_Down) {
        currentSpeed -= 2;  // Increase speed by 2
        if (currentSpeed <= 0) {
            currentSpeed = 0;  // Cap speed at 160
        }
        update();  // Trigger a repaint to reflect the updated speed
    }
}


void FanSpeedWidget::updateSpeed() {
    update(); // Trigger a repaint
}

FanSpeedWidget::~FanSpeedWidget() {}
