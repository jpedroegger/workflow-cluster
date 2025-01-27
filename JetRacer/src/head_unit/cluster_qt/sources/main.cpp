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
    TopBar*                 topBar = new TopBar(mode1Page, 340, 700, 250, 50);
    Blinkers*               leftB = new Blinkers(mode1Page, "left", "off", -5, 300, 100, 100);
    Blinkers*               rightB = new Blinkers(mode1Page, "right", "off", 1080, 300, 100, 100);
    SpeedometerWidget*      speedometer = new SpeedometerWidget(mode1Page, 90, 170, 365, 365);
    BatteryWidget*          battery = new BatteryWidget(mode1Page, 720, 170, 365, 365);
    FanSpeedWidget*         fanspeed = new FanSpeedWidget(mode1Page, 0, 630, 150, 140);
    CPUTempWidget*          cputemp = new CPUTempWidget(mode1Page, 100, 630, 150, 140);
    ArrowSymbolWidget*      arrowSymbol = new ArrowSymbolWidget(mode1Page, "zero", 454, 180, 270, 320);

    // Mode 2
    StatsWidget*            stats = new StatsWidget(mode2Page, 450, 200, 600, 400);
    TopBar*                 topBar2 = new TopBar(mode2Page, 340, 700, 250, 50);
    Blinkers*               leftB2 = new Blinkers(mode2Page, "left", "off", -5, 300, 100, 100);
    Blinkers*               rightB2 = new Blinkers(mode2Page, "right", "off", 1080, 300, 100, 100);
    BatteryAndSpeedWidget*  bas = new BatteryAndSpeedWidget(mode2Page, 130, 125, 200, 400);
    FanSpeedWidget*         fanspeed2 = new FanSpeedWidget(mode2Page, 0, 630, 150, 140);
    CPUTempWidget*          cputemp2 = new CPUTempWidget(mode2Page, 100, 630, 150, 140);
    //SettingsWidget*         settings2 = new SettingsWidget(mode2Page, stats);
    //SettingsWidget*         settings = new SettingsWidget(mode1Page, stats);


    // Ros node
    //auto node = std::make_shared<RosNode>();

    EventManager eventManager(arrowSymbol, speedometer, battery, bas, leftB, rightB,
                              leftB2, rightB2, stats, fanspeed, fanspeed2, cputemp,
                              cputemp2, topBar, topBar2, stackedWidget, mainWindow);
    app.installEventFilter(&eventManager);

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
