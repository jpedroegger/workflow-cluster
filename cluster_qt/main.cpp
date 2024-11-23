#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <cmath> // For sin and cos

#include "ArrowSymbolWidget.h"
#include "SpeedometerWidget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    // Create the main window
    QWidget mainWindow;
    // Create two SpeedometerWidgets
    SpeedometerWidget* speedometer1 = new SpeedometerWidget(&mainWindow);
    SpeedometerWidget* speedometer2 = new SpeedometerWidget(&mainWindow);
    ArrowSymbolWidget* arrowSymbol = new ArrowSymbolWidget(&mainWindow);

    // Set sizes for both speedometers
    speedometer1->resize(900, 900);
    speedometer2->resize(900, 900);

    // Create a QLabel for the image
    QLabel* imageLabel = new QLabel(&mainWindow);
    QPixmap symbol("/header.png"); // Replace with your image path

    imageLabel->setPixmap(symbol);
    imageLabel->setAlignment(Qt::AlignHCenter); // Center-align the image

    // Create layouts
    QVBoxLayout* mainLayout = new QVBoxLayout(); // Main vertical layout
    QHBoxLayout* speedometerLayout = new QHBoxLayout(); // Horizontal layout for speedometers

    // Add the image label to the main layout
    mainLayout->addWidget(imageLabel, 0);
    // Add the speedometers to the horizontal layout
    speedometerLayout->addWidget(speedometer1, 1);
    speedometerLayout->addWidget(speedometer2, 1);
    mainLayout->addWidget(arrowSymbol, 1);
    // Add the horizontal layout to the main vertical layout
    mainLayout->addLayout(speedometerLayout, 1);
    // Set the layout for the main window
    mainWindow.setLayout(mainLayout);
    // Resize the main window and show it
    mainWindow.resize(1368, 768); // Adjusted to accommodate the image and speedometers
    mainWindow.show();

    return app.exec();
}
