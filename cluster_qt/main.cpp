#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <cmath> // For sin and cos

#include "includes/ArrowSymbolWidget.h"
#include "includes/SpeedometerWidget.h"
#include "includes/BatteryWidget.h"
#include "includes/TopBar.h"
#include "includes/Blinkers.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Create the main window
    QWidget mainWindow;

    // Create the TopBar
    TopBar* topBar = new TopBar(&mainWindow);

    Blinkers* leftB = new Blinkers(&mainWindow, "left");
    Blinkers* rightB = new Blinkers(&mainWindow, "right");


    SpeedometerWidget* speedometer1 = new SpeedometerWidget(&mainWindow);
    BatteryWidget* battery2 = new BatteryWidget(&mainWindow);

    ArrowSymbolWidget* arrowSymbol = new ArrowSymbolWidget(&mainWindow, "left");
    arrowSymbol->setFixedSize(400, 400);



    speedometer1->resize(900, 900);
    speedometer1->setFixedSize(400, 400);
    battery2->resize(900, 900);
    battery2->setFixedSize(400, 400);

 
    // Create layouts
    QVBoxLayout* mainLayout = new QVBoxLayout(); // Main vertical layout
    QHBoxLayout* contentLayout = new QHBoxLayout(); // Horizontal layout for speedometers

    // Add the TopBar to the main layout
    mainLayout->addWidget(topBar, 0, Qt::AlignCenter); // Add the TopBar widget at the top


    // Add the horizontal layout to the main vertical layout
    contentLayout->addWidget(leftB, 1);
    contentLayout->addWidget(speedometer1, 1);
    contentLayout->addWidget(arrowSymbol, 1);
    contentLayout->addWidget(battery2, 1);
    contentLayout->addWidget(rightB, 1);

    mainLayout->addLayout(contentLayout, 1);
    // Set the layout for the main window
    mainWindow.setLayout(mainLayout);

    // Resize the main window and show it
    mainWindow.resize(1468, 768); // Adjusted to accommodate the image and speedometers
    mainWindow.setStyleSheet("background-color: #0D2126"); // Replace Qt::blue with your desired color
    mainWindow.show();

    // Simulate changes to TopBar images
    QTimer::singleShot(2000, [&]() { topBar->setImageState(0, true); });
    QTimer::singleShot(3000, [&]() { topBar->setImageState(1, true); });
    QTimer::singleShot(4000, [&]() { topBar->setImageState(2, true); });
    QTimer::singleShot(6000, [&]() { topBar->setImageState(4, true); });
    QTimer::singleShot(7000, [&]() { topBar->setImageState(3, true); });
    QTimer::singleShot(8000, [&]() { topBar->setImageState(5, true); }); // Revert to default

    return app.exec();
}
