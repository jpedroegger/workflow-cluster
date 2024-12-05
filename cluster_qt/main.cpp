#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QKeyEvent>
#include <cmath> // For sin and cos

#include <QStackedWidget>
#include <QToolBar>
#include <QGestureEvent>
#include <QSwipeGesture>

#include "includes/ArrowSymbolWidget.h"
#include "includes/EventManager.h"
#include "includes/SpeedometerWidget.h"
#include "includes/FanSpeedWidget.h"
#include "includes/BatteryWidget.h"
#include "includes/TopBar.h"
#include "includes/Blinkers.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Set a main window where the pages will be included
    QWidget *mainWindow = new QWidget;

    // Set the pages
    QWidget *mainPage = new QWidget;
    QWidget *secondPage = new QWidget;

    // Set a stack of Widgets to store the pages
    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(mainPage);
    stackedWidget->addWidget(secondPage);

    // Creating the objects for the window
    TopBar* topBar = new TopBar(mainPage);
    Blinkers* leftB = new Blinkers(mainPage, "left", "off");
    Blinkers* rightB = new Blinkers(mainPage, "right", "off");
    SpeedometerWidget* speedometer1 = new SpeedometerWidget(mainPage);
    FanSpeedWidget* fanspeed = new FanSpeedWidget(mainPage);
    BatteryWidget* battery2 = new BatteryWidget(mainPage);
    ArrowSymbolWidget* arrowSymbol = new ArrowSymbolWidget(mainPage, "zero");

    speedometer1->resize(900, 900);
    speedometer1->setFixedSize(400, 400);
    battery2->resize(900, 900);
    battery2->setFixedSize(400, 400);
    arrowSymbol->setFixedSize(400, 400);

    // Set a manager to handle keyboard events
    EventManager eventManager(arrowSymbol, speedometer1, leftB, rightB, stackedWidget);
    app.installEventFilter(&eventManager);

    // Create layouts
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QVBoxLayout* mainPageLayout = new QVBoxLayout(); // Main vertical layout
    QHBoxLayout* mainContentLayout = new QHBoxLayout(); // Horizontal layout for speedometers
    QVBoxLayout* secondPageLayout = new QVBoxLayout(); // Main vertical layout

    mainPageLayout->addWidget(topBar, 0, Qt::AlignCenter); // Add the TopBar widget at the top
    mainPageLayout->addWidget(fanspeed, 0); // Add the TopBar widget at the top

    // Adding objects to the second page
    // secondPageLayout->addWidget(battery2, 1);
    // secondPage->setLayout(secondPageLayout);

    // Add the horizontal layout to the main vertical layout
    mainContentLayout->addWidget(leftB, 1);
    mainContentLayout->addWidget(speedometer1, 1);
    mainContentLayout->addWidget(arrowSymbol, 1);
    mainContentLayout->addWidget(battery2, 1);
    mainContentLayout->addWidget(rightB, 1);
    // Add Layout to the main Page
    mainPageLayout->addLayout(mainContentLayout, 1);
    // Set the layout for the main page
    mainPage->setLayout(mainPageLayout);

    //Add a navigation tool for pages
    QToolBar* toolBar = new QToolBar;
    QAction* page1Action = toolBar->addAction("Main");
    QAction* page2Action = toolBar->addAction("Second");
    // Connect the labels to trigger the pages
    QObject::connect(page1Action, &QAction::triggered, [&]() {
        stackedWidget->setCurrentIndex(0);
    });
    QObject::connect(page2Action, &QAction::triggered, [&]() {
        stackedWidget->setCurrentIndex(1);
    });

    mainLayout->addWidget(toolBar);
    mainLayout->addWidget(stackedWidget);

    // Set layout for the main window
    mainWindow->setLayout(mainLayout);
    mainWindow->resize(1468, 768);
    mainWindow->setStyleSheet("background-color: #0D2126");
    mainWindow->grabGesture(Qt::SwipeGesture);
    mainWindow->show();

    // Simulate changes to TopBar images
    QTimer::singleShot(2000, [&]() { topBar->setImageState(0, true); });
    QTimer::singleShot(3000, [&]() { topBar->setImageState(1, true); });
    QTimer::singleShot(4000, [&]() { topBar->setImageState(2, true); });
    QTimer::singleShot(6000, [&]() { topBar->setImageState(4, true); });
    QTimer::singleShot(7000, [&]() { topBar->setImageState(3, true); });
    QTimer::singleShot(8000, [&]() { topBar->setImageState(5, true); }); // Revert to default

    return app.exec();
}
