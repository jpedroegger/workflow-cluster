#include "../includes/CPUTempWidget.h"

CPUTempWidget::CPUTempWidget(QWidget* parent, std::string input, int x, int y, int width, int height)
    : QWidget(parent), currentSpeed(0)
{
    color1 = Color();
    index = color1.counter;
    main_color = color1.main_color;
    accent_color = color1.accent_color;
    alphabet_color = color1.alphabet_color;
    unit = "ºC";
    setFocusPolicy(Qt::StrongFocus);
    image_array[0] = QPixmap("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/cpu_p.png");
    image_array[1] = QPixmap("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/cpu_r.png");
    image_array[2] = QPixmap("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/cpu_i.png");
    image_array[3] = QPixmap("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/cpu_g.png");
    image = image_array[index];
    setGeometry(x, y, width, height);
}


void CPUTempWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int centerX = (width() - 50) / 2;
    int centerY = (height() - 50) / 2;
    int radius = std::min((width() - 50), (height() - 50)) / 2 - 20;

    drawScale(painter, centerX, centerY, radius);

    drawNeedle(painter, centerX, centerY, radius);
    drawCentralNumber(painter, centerX, centerY);
}

void CPUTempWidget::drawScale(QPainter& painter, int centerX, int centerY, int radius) {

    painter.setPen(QPen(main_color, 8));
    painter.drawEllipse(centerX - radius, centerY - radius, 2 * radius, 2 * radius);

}

void CPUTempWidget::drawNeedle(QPainter& painter, int centerX, int centerY, int radius) {
    double startAngle = -45;
    double endAngle = 225;    

    double angle = startAngle + (endAngle - startAngle) * (double(currentSpeed) / 160);
    double rad = qDegreesToRadians(angle);
    int xStart = centerX - std::cos(rad) * (radius - 3);
    int yStart = centerY - std::sin(rad) * (radius - 3);
    int xEnd = centerX - std::cos(rad) * (radius + 1);
    int yEnd = centerY - std::sin(rad) * (radius + 1);
    painter.setPen(QPen(accent_color, 5));

    painter.drawLine(xStart, yStart, xEnd, yEnd);
}

void CPUTempWidget::drawCentralNumber(QPainter& painter, int centerX, int centerY) {

    QFont font("Arial", 20, QFont::Bold); 
    painter.setFont(font);
    painter.setPen(QPen(alphabet_color));
    QString speedText = QString::number(currentSpeed);

    QFontMetrics metrics(font);
    QRect textRect = metrics.boundingRect(speedText);

    int x = centerX - textRect.width() / 2;
    int y = centerY + textRect.height() / 2 - 10;
    painter.drawText(x, y, speedText);

    QFont smallFont("Arial", 10, QFont::Bold); 
    painter.setFont(smallFont);

    QFontMetrics smallMetrics(smallFont);
    int kphWidth = smallMetrics.horizontalAdvance(unit);
    int kphX = centerX - kphWidth / 2;
    int kphY = y + textRect.height() - 20; 

    painter.drawText(kphX, kphY, unit);
    image = image_array[index];
    if (!image.isNull()) {
        int imgWidth = 25; 
        int imgHeight = 25;
        int imgX = centerX - imgWidth / 2;
        int imgY = kphY + 20;
        painter.drawPixmap(imgX, imgY, imgWidth, imgHeight, image);
    }
}

void CPUTempWidget::keyPressEvent(QKeyEvent* event)
{

    if (event->key() == Qt::Key_Space) {
        currentSpeed += 2; 
        if (currentSpeed > 160) {
            currentSpeed = 160; 
        }
        update(); 
    }

    
    if (event->key() == Qt::Key_Down) {
        currentSpeed -= 2; 
        if (currentSpeed <= 0) {
            currentSpeed = 0; 
        }
        update(); 
    }
}


void CPUTempWidget::updateSpeed() {
    update();
}

void    CPUTempWidget::changeColor(int  array_index)
{
    main_color = color1.main_color_array[array_index];
    accent_color = color1.accent_color_array[array_index];
    alphabet_color = color1.alphabet_color_array[array_index];
    index = array_index;
    update();
}

void    CPUTempWidget::changeUnits(void)
{
    if (unit == "ºC"){
        unit = "ºF";
        currentSpeed = currentSpeed * 9 / 5 + 32;
    } else {
        unit = "ºC";
        currentSpeed = (currentSpeed - 32) * 5 / 9;
    }
    update();
}

CPUTempWidget::~CPUTempWidget() {}
