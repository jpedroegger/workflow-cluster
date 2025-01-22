#include "../includes/Cluster.h"
#include <QMenu>

int main(int argc, char* argv[])
{
    //rclcpp::init(argc, argv);
    QApplication app(argc, argv);

    QWidget* mainWindow = new QWidget;
    QWidget* mode1Page = new QWidget;
    QWidget* mode2Page = new QWidget;

    QStackedWidget* stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(mode1Page); // Mode 1
    stackedWidget->addWidget(mode2Page); // Mode 2

    // Mode 1
    TopBar*                 topBar = new TopBar(mode1Page);
    Blinkers*               leftB = new Blinkers(mode1Page, "left", "off");
    Blinkers*               rightB = new Blinkers(mode1Page, "right", "off");
    SpeedometerWidget*      speedometer = new SpeedometerWidget(mode1Page);
    BatteryWidget*          battery = new BatteryWidget(mode1Page);
    FanSpeedWidget*         fanspeed = new FanSpeedWidget(mode1Page);
    CPUTempWidget*          cputemp = new CPUTempWidget(mode1Page);
    ArrowSymbolWidget*      arrowSymbol = new ArrowSymbolWidget(mode1Page, "zero");

    // Mode 2
    StatsWidget*            stats = new StatsWidget(mode2Page);
    TopBar*                 topBar2 = new TopBar(mode2Page);
    Blinkers*               rightB2 = new Blinkers(mode2Page, "right", "off");
    Blinkers*               leftB2 = new Blinkers(mode2Page, "left", "off");
    BatteryAndSpeedWidget*  bas = new BatteryAndSpeedWidget(mode2Page);
    FanSpeedWidget*         fanspeed2 = new FanSpeedWidget(mode2Page);
    CPUTempWidget*          cputemp2 = new CPUTempWidget(mode2Page);

    SettingsWidget*         settings = new SettingsWidget(mainWindow);

    // Ros node
    //auto node = std::make_shared<RosNode>();

    EventManager eventManager(arrowSymbol, speedometer, battery, bas, leftB, rightB,
                              leftB2, rightB2, stats, topBar, topBar2, stackedWidget,
                              mainWindow);
    app.installEventFilter(&eventManager);

    // bas->resize(900, 900);
    // bas->setFixedSize(400, 400);

    // mode1ContentLayout->addWidget(leftB, 1);
    // mode1ContentLayout->addWidget(speedometer, 1);
    // mode1ContentLayout->addWidget(arrowSymbol, 1);
    // mode1ContentLayout->addWidget(battery, 1);
    // mode1ContentLayout->addWidget(rightB, 1);

    // mode1ContentLayout->addWidget(settings, 0, Qt::AlignBottom); // Button

    // mode1Layout->addLayout(mode1ContentLayout, 1);
    // mode1Layout->addWidget(fanspeed, 0, Qt::AlignBottom);
    // mode1Layout->addWidget(cputemp, 0, Qt::AlignBottom);
    // mode1Layout->addWidget(topBar, 0, Qt::AlignBottom);


    // mode1Page->setLayout(mode1Layout);

    // // Layout for Mode 2
    // QVBoxLayout* mode2Layout = new QVBoxLayout();
    // QHBoxLayout* mode2ContentLayout = new QHBoxLayout();

    // mode2ContentLayout->addWidget(leftB2, 1);
    // mode2ContentLayout->addWidget(bas, 2, Qt::AlignCenter);
    // mode2ContentLayout->addWidget(stats, 2);
    // mode2ContentLayout->addWidget(rightB2, 1);

    // mode2Layout->addLayout(mode2ContentLayout, 1);
    // mode2Layout->addWidget(fanspeed2, 0, Qt::AlignBottom);
    // mode2Layout->addWidget(cputemp2, 0, Qt::AlignBottom);
    // mode2Layout->addWidget(topBar2, 0, Qt::AlignBottom);
    // mode2Page->setLayout(mode2Layout);

    arrowSymbol->setGeometry(450, 170, 320, 360); // x, y, width, height
    speedometer->setGeometry(90, 160, 380, 380);
    battery->setGeometry(700, 160, 380, 380);
    leftB->setGeometry(0, 300, 100, 100);
    rightB->setGeometry(1070, 300, 100, 100);
    fanspeed->setGeometry(50, 800, 200, 50);
    cputemp->setGeometry(50, 900, 200, 50);
    topBar->setGeometry(350, 700, 250, 50);

    stats->setGeometry(1200, 200, 400, 400); 
    topBar2->setGeometry(800, 50, 400, 50);
    rightB2->setGeometry(1650, 300, 100, 100);
    leftB2->setGeometry(50, 300, 100, 100);
    bas->setGeometry(700, 200, 400, 400);
    fanspeed2->setGeometry(800, 50, 400, 50);
    cputemp2->setGeometry(800, 90, 400, 50); 
    // Toolbar for switching modes
    QToolBar* toolBar = new QToolBar;
    QAction* mode1Action = toolBar->addAction("Mode 1");
    QAction* mode2Action = toolBar->addAction("Mode 2");

    QObject::connect(mode1Action, &QAction::triggered,
                     [&]()
                     {
                         stackedWidget->setCurrentIndex(0); // Switch to Mode 1
                     });
    QObject::connect(mode2Action, &QAction::triggered,
                     [&]()
                     {
                         stackedWidget->setCurrentIndex(1); // Switch to Mode 2
                     });

    // Main Layout
    Color color = Color();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(toolBar);
    mainLayout->addWidget(stackedWidget);

    mainWindow->setLayout(mainLayout);
    mainWindow->resize(1200, 800);
    mainWindow->setStyleSheet(QString("%1; margin: 0px; padding: 0px;").arg(color.background));
    mainWindow->show();

    /*
    QTimer::singleShot(2000, [&]() { topBar->setImageState(0, true); });
    QTimer::singleShot(3000, [&]() { topBar->setImageState(1, true); });
    QTimer::singleShot(4000, [&]() { topBar->setImageState(2, true); });
    QTimer::singleShot(6000, [&]() { topBar->setImageState(4, true); });
    QTimer::singleShot(7000, [&]() { topBar->setImageState(3, true); });
    QTimer::singleShot(8000, [&]() { topBar->setImageState(5, true); });
    */
    int ret = app.exec();
    //rclcpp::shutdown();

    return ret;
}
