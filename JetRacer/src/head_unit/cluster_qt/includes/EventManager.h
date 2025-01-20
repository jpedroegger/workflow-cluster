#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "ArrowSymbolWidget.h"
#include "BatteryAndSpeedWidget.h"
#include "Blinkers.h"
#include "Colors.h"
//#include "RosNode.hpp"
#include "SpeedometerWidget.h"
#include "StatsWidget.h"
#include "BatteryWidget.h"
#include <QObject>
#include <QSet>
#include <QStackedWidget>
#include <QSwipeGesture>
#include <QTimer>
#include <QWidget>

class EventManager : public QWidget
{
        Q_OBJECT;

    private:
        ArrowSymbolWidget* arrows;
        SpeedometerWidget* py_speed;
        BatteryWidget* py_battery;
        BatteryAndSpeedWidget* py_batspeed;
        Blinkers* left_blinker;
        Blinkers* right_blinker;
        StatsWidget* stats;
        QSet<int> pressedKeys;
        QTimer* updateTimer; // Used to check if a key is still being called
        QStackedWidget* stackedWidget;
        QWidget* mainWindow;
        //std::shared_ptr<RosNode> node;
        //rclcpp::executors::SingleThreadedExecutor executor;

    public:
        EventManager(ArrowSymbolWidget* arrow, SpeedometerWidget* py_speed,
                     BatteryWidget* py_battery,
                     BatteryAndSpeedWidget* py_batspeed, Blinkers* left_blinker,
                     Blinkers* right_blinker, StatsWidget* stats,
                     QStackedWidget* stackedWidget, QWidget* mainWindow);
        virtual ~EventManager();
        Color color1;

    protected:
        bool eventFilter(QObject* obj, QEvent* event) override;

    private slots:
        void handleGestureEvent(QGestureEvent* gestureEvent);
        void processKeyStates();
};

#endif // EVENTMANAGER_H
