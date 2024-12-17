#include "includes/BatteryAndSpeedWidget.h"

BatteryAndSpeedWidget::BatteryAndSpeedWidget(QWidget* parent)
    : QWidget(parent), currentLevel(100), currentSpeed(0)
{
    setFocusPolicy(Qt::StrongFocus);  // Ensure the widget can receive key events
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &BatteryAndSpeedWidget::updateLevel);
    timer->start(800); // Update Level every 100ms
}

void BatteryAndSpeedWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int centerX = width() / 2;
    int centerY = height() / 2;
    int radius = std::min(width(), height()) / 2 - 20;
    drawCentralNumber(painter, centerX + 100, centerY);
    drawScale(painter, centerX, centerY, radius);
}

void BatteryAndSpeedWidget::drawScale(QPainter& painter, int centerX, int centerY, int radius) {


    double startAngle = -45; // Start angle for 0 Level (bottom left)
    double endAngle = 225;     // End angle for max Level (bottom right)
    QFont font("Arial", 20, QFont::Bold);  // Example: Arial, size 10, bold
    painter.setPen(QPen(Qt::white, 6));
    painter.setFont(font);
    drawBars(painter, centerX, centerY, radius, startAngle, endAngle, 100);
    painter.setPen(QPen(Qt::black, 15));

    // Define bounding rectangle for the arc
    QRect rect(centerX, centerY, radius * 1.5, radius * 0.75); // x, y, width, height
    // Draw the arc
    int startAngle1 = 135 * 16;    // Start at 0 degrees (3 o'clock)
    int spanAngle1 = 90 * 16;   // Sweep 180 degrees (half-circle)
    painter.drawArc(rect, startAngle1, spanAngle1);
}

void BatteryAndSpeedWidget::drawBars(QPainter& painter, int centerX, int centerY, int radius, double startAngle, double endAngle, int Level) {
    int numBars = Level / 2; // Total number of bars (from 0 to 100)
    int barWidth = 6;  // Width of each bar
    int innerRadius = radius - 80; // Inner radius for bars
    int outerRadius = radius - 5; // Outer radius for bars

    int activeBars = static_cast<int>(currentLevel); // Bars below the needle

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

QColor BatteryAndSpeedWidget::calculateBarColor(int value) {
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

void BatteryAndSpeedWidget::updateLevel() {
    // Command to get the battery level -- CURRENTLY WORKING ON ARCH, NEEDS TO BE ALTERED
    const std::string command = "upower -i $(upower -e | grep BAT) | grep -E \"percentage\" | awk '{print $2}'";

    // Create a pipe to read the command's output
    std::array<char, 128> buffer;
    std::string result;

    // Open the process using popen
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("Failed to run command");
    }

    // Read the output into the result string
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    // Remove any trailing whitespace or newline characters
    result.erase(result.find_last_not_of(" \t\n\r") + 1);

    // Convert the result to a float or integer if needed
    currentLevel = 47; // or std::stoi(result) if it's an integer

    update(); // Trigger a repaint
}

BatteryAndSpeedWidget::~BatteryAndSpeedWidget() {}

void BatteryAndSpeedWidget::drawCentralNumber(QPainter& painter, int centerX, int centerY) {
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
    int kphWidth = smallMetrics.horizontalAdvance("KPH");
    int kphX = centerX - kphWidth / 2; // Center-align "KPH"
    int kphY = y + textRect.height() - 30;  // Position "KPH" below the speed text
    // Draw "KPH"
    painter.drawText(kphX, kphY, "KPH");
}

void BatteryAndSpeedWidget::accelerate(int forward_key)
{
    if (forward_key == Qt::Key_Space) {
        currentSpeed += 2;  // Increase speed by 2
        if (currentSpeed > 160) {
            currentSpeed = 160;  // Cap speed at 160
        }
        update();  // Trigger a repaint to reflect the updated speed
    }

    // Check if the Up Arrow key is pressed
    if (forward_key == Qt::Key_Down) {
        currentSpeed -= 2;  // Increase speed by 2
        if (currentSpeed <= 0) {
            currentSpeed = 0;  // Cap speed at 160
        }
        update();  // Trigger a repaint to reflect the updated speed
    }
}

void BatteryAndSpeedWidget::updateSpeed() {
    update(); // Trigger a repaint
}

