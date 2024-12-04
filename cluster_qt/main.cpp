#include "includes/Cluster.h"

int main(int argc, char* argv[])
{
    QApplication        app(argc, argv);
    QWidget             mainWindow;

    TopBar*             topBar = new TopBar(&mainWindow);
    Blinkers*           leftB = new Blinkers(&mainWindow, "left", "off");
    Blinkers*           rightB = new Blinkers(&mainWindow, "right", "off");
    SpeedometerWidget*  speedometer1 = new SpeedometerWidget(&mainWindow);
    FanSpeedWidget*     fanspeed = new FanSpeedWidget(&mainWindow);
    BatteryWidget*      battery2 = new BatteryWidget(&mainWindow);
    ArrowSymbolWidget*  arrowSymbol = new ArrowSymbolWidget(&mainWindow, "zero");
    EventManager        eventManager(arrowSymbol, speedometer1, leftB, rightB);
    QVBoxLayout*        mainLayout = new QVBoxLayout();
    QHBoxLayout*        contentLayout = new QHBoxLayout();
    
    //arrowSymbol->setFixedSize(400, 400);
    app.installEventFilter(&eventManager);
    
    //speedometer1->resize(900, 900);
    //speedometer1->setFixedSize(400, 400);
    //battery2->resize(900, 900);
    //battery2->setFixedSize(400, 400);
 
    fanspeed->setFixedSize(150,150);
    //mainLayout->addWidget(topBar, 0, Qt::AlignCenter);
    mainLayout->addWidget(fanspeed, 0);

    //contentLayout->addWidget(leftB, 1);
    //contentLayout->addWidget(speedometer1, 1);
    //contentLayout->addWidget(arrowSymbol, 1);
    //contentLayout->addWidget(battery2, 1);
    //contentLayout->addWidget(rightB, 1);

    //mainLayout->addLayout(contentLayout, 1);
    
    mainWindow.setLayout(mainLayout);

    mainWindow.resize(1468, 768);
    mainWindow.setStyleSheet("background-color: #0D2126");
    mainWindow.show();

    QTimer::singleShot(2000, [&]() { topBar->setImageState(0, true); });
    QTimer::singleShot(3000, [&]() { topBar->setImageState(1, true); });
    QTimer::singleShot(4000, [&]() { topBar->setImageState(2, true); });
    QTimer::singleShot(6000, [&]() { topBar->setImageState(4, true); });
    QTimer::singleShot(7000, [&]() { topBar->setImageState(3, true); });
    QTimer::singleShot(8000, [&]() { topBar->setImageState(5, true); });

    return app.exec();
}