#include "../includes/BatteryAndSpeedWidget.h"

BatteryAndSpeedWidget::BatteryAndSpeedWidget(QWidget* parent, std::string input, int x, int y, int width, int height)
    : QWidget(parent), currentSpeed(0)
{
    color1 = Color();
    unit = "DPS";
    index = color1.counter;
    main_color = color1.main_color;
    accent_color = color1.accent_color;
    alphabet_color = color1.alphabet_color;
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(x, y, width, height);
}

void BatteryAndSpeedWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    image_array[0] = QPixmap("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/battery_p.png");
    image_array[1] = QPixmap("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/battery_r.png");
    image_array[2] = QPixmap("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/battery_i.png");
    image_array[3] = QPixmap("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/battery_g.png");
    image = image_array[index];
    painter.setRenderHint(QPainter::Antialiasing);
    int centerX = 40;
    int centerY = height() / 2;
    int radius = std::max(width(), height()) / 2 - 20;

    int imageWidth = 25;
    int imageHeight = 25;
    int imageX = centerX - 25 - imageWidth / 2;
    int imageY = centerY + imageWidth / 2;

    painter.drawPixmap(imageX, imageY, imageWidth, imageHeight, image);

    drawCentralNumber(painter, centerX + 100, centerY);
    drawBatteryNumber(painter, imageX + 15, imageY + 55);
    drawScale(painter, centerX, centerY, radius);
}

void BatteryAndSpeedWidget::drawScale(QPainter& painter, int centerX,
                                      int centerY, int radius)
{
    double startAngle = -40;
    double endAngle = 40;
    QFont font("Arial", 20, QFont::Bold);
    painter.setPen(QPen(alphabet_color, 6));
    painter.setFont(font);
    drawBars(painter, centerX + 150, centerY + 30, radius * 1.2, startAngle,
             endAngle, 100);
}

void BatteryAndSpeedWidget::drawBars(QPainter& painter, int centerX,
                                     int centerY, int radius, double startAngle,
                                     double endAngle, int Level)
{
    int numBars = Level / 2;
    int barWidth = 6;
    int innerRadius = radius - 80;
    int outerRadius = radius - 70;
    int activeBars = static_cast<int>(currentLevel);

    for (int i = 0; i <= numBars; ++i)
    {
        double angle =
            startAngle + (endAngle - startAngle) * (double(i) / numBars);
        double rad = qDegreesToRadians(angle);

        int xOuter = centerX - std::cos(rad) * outerRadius;
        int yOuter = centerY - std::sin(rad) * outerRadius;
        int xInner = centerX - std::cos(rad) * innerRadius;
        int yInner = centerY - std::sin(rad) * innerRadius;

        QColor barColor = (i * 2 <= activeBars) ? calculateBarColor(i * 2)
                                                : QColor(50, 50, 50);

        painter.setPen(QPen(barColor, barWidth, Qt::SolidLine, Qt::SquareCap));
        painter.drawLine(xInner, yInner, xOuter, yOuter);
    }
}

QColor BatteryAndSpeedWidget::calculateBarColor(int value)
{
    if (value < 5)
        return QColor(139, 0, 0);
    else if (value < 50)
    {
        int red = 139 + (255 - 139) * (value - 5) / 45;
        int green = (255 - 139) * (value - 5) / 45;
        return QColor(red, green, 0);
    }
    else if (value < 80)
    {
        int red = 255 - (255 * (value - 50) / 30);
        int green = 255;
        return QColor(red, green, 0);
    }
    else
        return QColor(0, 255, 0);
}

void BatteryAndSpeedWidget::updateLevel()
{
    update();
}

BatteryAndSpeedWidget::~BatteryAndSpeedWidget() {}

void BatteryAndSpeedWidget::drawCentralNumber(QPainter& painter,
                                            int centerX, int centerY)
{
    QFont font("Arial", 80, QFont::Bold);
    painter.setFont(font);
    painter.setPen(QPen(alphabet_color));
    QString speedText = QString::number(currentSpeed);
    QFontMetrics metrics(font);
    QRect textRect = metrics.boundingRect(speedText);

    int x = centerX - textRect.width() / 2;
    int y = centerY + textRect.height() / 2 - 20;
    painter.drawText(x, y, speedText);

    QFont smallFont("Arial", 28, QFont::Bold);
    painter.setFont(smallFont);

    QFontMetrics smallMetrics(smallFont);
    int kphWidth = smallMetrics.horizontalAdvance(unit);
    int kphX = centerX - kphWidth / 2;
    int kphY = y + textRect.height() - 60;

    painter.drawText(kphX, kphY, unit);
}

void BatteryAndSpeedWidget::drawBatteryNumber(QPainter& painter,
                                            int centerX, int centerY)
{
    QFont font("Arial", 10, QFont::Bold);
    painter.setFont(font);
    painter.setPen(QPen(alphabet_color));
    QString speedText = QString::number(currentLevel) + " %";

    QFontMetrics metrics(font);
    QRect textRect = metrics.boundingRect(speedText);

    int x = centerX - textRect.width() / 2;
    int y = centerY + textRect.height() / 2 - 20;
    painter.drawText(x, y, speedText);
}

void BatteryAndSpeedWidget::accelerate(int forward_key)
{
    if (forward_key == Qt::Key_Space)
    {
        currentSpeed += 2;
        if (currentSpeed > 160)
            currentSpeed = 160;
        update();
    }

    if (forward_key == Qt::Key_Down)
    {
        currentSpeed -= 2;
        if (currentSpeed <= 0)
            currentSpeed = 0;
        update();
    }
}

void    BatteryAndSpeedWidget::changeColor(int  array_index)
{
    main_color = color1.main_color_array[array_index];
    accent_color = color1.accent_color_array[array_index];
    alphabet_color = color1.alphabet_color_array[array_index];
    index = array_index;
    update();
}

void    BatteryAndSpeedWidget::setCurrentLevel(int battery)
{
    if (battery == currentLevel)
        return ;
    currentLevel = battery;
    update();
}
void    BatteryAndSpeedWidget::changeUnits(void)
{
    if (unit == "DPS"){
        unit = "FPS";
        currentSpeed *= 0.6214;
    } else {
        unit = "DPS";
        currentSpeed *= 1.609;
    }
    update();
}

void BatteryAndSpeedWidget::setCurrentSpeed(int speed)
{
    if (speed == currentSpeed
    || (unit == "DPS" && speed * 0.6214 == currentSpeed))
        return ;
    if (unit == "FPS")
        currentSpeed = 0.6214 * speed;
    else
        currentSpeed = speed;
    update();
}
