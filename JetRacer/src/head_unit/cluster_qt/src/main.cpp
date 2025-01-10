#include "../include/Cluster.h"

/*int main(int argc, char* argv[])
{
    // Initialize ROS 2
    rclcpp::init(argc, argv);

    QApplication app(argc, argv);

    QWidget* mainWindow = new QWidget;
    QWidget* mainPage = new QWidget;
    QWidget* secondPage = new QWidget;

    QStackedWidget* stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(mainPage);
    stackedWidget->addWidget(secondPage);

    TopBar*                 topBar = new TopBar(mainPage);
    Blinkers*               leftB = new Blinkers(mainPage, "left", "off");
    Blinkers*               rightB = new Blinkers(mainPage, "right", "off");
    SpeedometerWidget*      speedometer1 = new SpeedometerWidget(mainPage);
    FanSpeedWidget*         fanspeed = new FanSpeedWidget(mainPage);
    CPUTempWidget*          cputemp = new CPUTempWidget(mainPage);
    BatteryWidget*          battery2 = new BatteryWidget(mainPage);
    ArrowSymbolWidget*      arrowSymbol = new ArrowSymbolWidget(mainPage, "zero");
    CameraWidget*           cameraWidget = new CameraWidget(secondPage);
    BatteryAndSpeedWidget*  bas = new BatteryAndSpeedWidget(mainPage);

    EventManager eventManager(arrowSymbol, speedometer1, leftB, rightB, stackedWidget);
    app.installEventFilter(&eventManager);

    QVBoxLayout* firstLayout = new QVBoxLayout();
    QVBoxLayout* secondLayout = new QVBoxLayout();
    QVBoxLayout* mainPageLayout = new QVBoxLayout();
    QHBoxLayout* mainContentLayout1 = new QHBoxLayout();
    QHBoxLayout* mainContentLayout2 = new QHBoxLayout();
    QHBoxLayout* smallerLayout = new QHBoxLayout();

    arrowSymbol->setFixedSize(400, 400);
    app.installEventFilter(&eventManager);

    speedometer1->resize(900, 900);
    speedometer1->setFixedSize(400, 400);
    battery2->resize(900, 900);
    battery2->setFixedSize(400, 400);
    cameraWidget->resize(1920, 1080);
    cameraWidget->setFixedSize(700, 500);

    bas->resize(900, 900);
    bas->setFixedSize(400, 400);

    mainPageLayout->addWidget(topBar, 0, Qt::AlignCenter);
    mainPageLayout->addWidget(fanspeed, 0);

    mainContentLayout1->addWidget(leftB, 1);
    mainContentLayout1->addWidget(speedometer1, 1);
    mainContentLayout1->addWidget(arrowSymbol, 1);
    mainContentLayout1->addWidget(battery2, 1);
    mainContentLayout1->addWidget(rightB, 1);
    mainPageLayout->addLayout(mainContentLayout1, 1);
    mainPage->setLayout(mainPageLayout);

    mainContentLayout2->addWidget(leftB, 1);
    mainContentLayout2->addWidget(bas, 1);
    mainContentLayout2->addWidget(cameraWidget, 1);
    mainContentLayout2->addWidget(rightB, 1);
    secondLayout->addLayout(mainContentLayout2, 1);
    secondPage->setLayout(secondLayout);

    QToolBar* toolBar = new QToolBar;
    QAction* page1Action = toolBar->addAction("Main");
    QAction* page2Action = toolBar->addAction("Second");

    QObject::connect(page1Action, &QAction::triggered, [&]() {
        stackedWidget->setCurrentIndex(0);
    });
    QObject::connect(page2Action, &QAction::triggered, [&]() {
        stackedWidget->setCurrentIndex(1);
    });

    firstLayout->addWidget(toolBar);
    firstLayout->addWidget(stackedWidget);
    firstLayout->addWidget(topBar, 0, Qt::AlignCenter);

    fanspeed->setFixedSize(150, 150);
    cputemp->setFixedSize(150, 150);

    smallerLayout->addWidget(fanspeed, 0);
    smallerLayout->addWidget(cputemp, 0);
    smallerLayout->setSpacing(0);
    firstLayout->addLayout(smallerLayout, 0);
    firstLayout->setAlignment(smallerLayout, Qt::AlignTop | Qt::AlignLeft);

    mainWindow->setLayout(firstLayout);
    mainWindow->resize(1200, 200);
    //mainWindow->resize(1468, 768);
    mainWindow->setStyleSheet("background-color: #0D2126");
    mainWindow->grabGesture(Qt::SwipeGesture);
    mainWindow->showFullScreen();

    int ret = app.exec();

    // Shutdown ROS 2
    rclcpp::shutdown();

    return ret;
}*/

#include "../include/Cluster.h"

int main(int argc, char* argv[])
{
    // Initialize ROS 2
    rclcpp::init(argc, argv);

    QApplication app(argc, argv);

    QWidget* mainWindow = new QWidget;
    QWidget* mode1Page = new QWidget;
    QWidget* mode2Page = new QWidget;

    QStackedWidget* stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(mode1Page); // Mode 1
    stackedWidget->addWidget(mode2Page); // Mode 2

    // Widgets used in both modes
    TopBar*                 topBar = new TopBar(mainWindow);
    Blinkers*               leftB = new Blinkers(mainWindow, "left", "off");
    Blinkers*               rightB = new Blinkers(mainWindow, "right", "off");
    SpeedometerWidget*      speedometer = new SpeedometerWidget(mainWindow);
    BatteryWidget*          battery = new BatteryWidget(mainWindow);
    FanSpeedWidget*         fanspeed = new FanSpeedWidget(mainWindow);
    CPUTempWidget*          cputemp = new CPUTempWidget(mainWindow);
    ArrowSymbolWidget*      arrowSymbol = new ArrowSymbolWidget(mainWindow, "zero");
    BatteryAndSpeedWidget*  bas = new BatteryAndSpeedWidget(mainWindow);

    // Layout for Mode 1
    QVBoxLayout* mode1Layout = new QVBoxLayout();
    QHBoxLayout* mode1ContentLayout = new QHBoxLayout();

    EventManager eventManager(arrowSymbol, speedometer, leftB, rightB, stackedWidget);
    app.installEventFilter(&eventManager);

    mode1ContentLayout->addWidget(leftB, 1);
    mode1ContentLayout->addWidget(speedometer, 1);
    mode1ContentLayout->addWidget(arrowSymbol, 1);
    mode1ContentLayout->addWidget(battery, 1);
    mode1ContentLayout->addWidget(rightB, 1);

    mode1Layout->addWidget(topBar, 0, Qt::AlignBottom);
    mode1Layout->addLayout(mode1ContentLayout, 1);
    mode1Page->setLayout(mode1Layout);

    // Layout for Mode 2
    QVBoxLayout* mode2Layout = new QVBoxLayout();
    QHBoxLayout* mode2ContentLayout = new QHBoxLayout();

    mode2ContentLayout->addWidget(leftB, 1);
    mode2ContentLayout->addWidget(bas, 2);
    mode2ContentLayout->addWidget(rightB, 1);

    mode2Layout->addWidget(topBar, 0, Qt::AlignBottom);
    mode2Layout->addLayout(mode2ContentLayout, 1);
    mode2Page->setLayout(mode2Layout);

    // Toolbar for switching modes
    QToolBar* toolBar = new QToolBar;
    QAction* mode1Action = toolBar->addAction("Mode 1");
    QAction* mode2Action = toolBar->addAction("Mode 2");

    QObject::connect(mode1Action, &QAction::triggered, [&]() {
        stackedWidget->setCurrentIndex(0); // Switch to Mode 1
    });
    QObject::connect(mode2Action, &QAction::triggered, [&]() {
        stackedWidget->setCurrentIndex(1); // Switch to Mode 2
    });

    // Main Layout
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(toolBar);
    mainLayout->addWidget(stackedWidget);

    mainWindow->setLayout(mainLayout);
    mainWindow->resize(1200, 800);
    mainWindow->setStyleSheet("background-color: #0D2126");
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

    // Shutdown ROS 2
    rclcpp::shutdown();

    return ret;
}
