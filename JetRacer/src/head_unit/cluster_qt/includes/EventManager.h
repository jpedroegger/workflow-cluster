#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "ArrowSymbolWidget.h"
#include "BatteryAndSpeedWidget.h"
#include "BatteryWidget.h"
#include "Blinkers.h"
#include "CPUTempWidget.h"
#include "Colors.h"
#include "FanSpeedWidget.h"
#include "RosNode.hpp"
#include "SpeedometerWidget.h"
#include "StatsWidget.h"
#include "ListeningWidget.h"
#include "TopBar.h"

#include <QObject>
#include <QSet>
#include <QStackedWidget>
#include <QSwipeGesture>
#include <QTimer>
#include <QWidget>
#include <rclcpp/rclcpp.hpp>

#define REFRESH_RATE_MS 50

class EventManager : public QWidget
{
        Q_OBJECT;

    private:
        ArrowSymbolWidget*                        arrows;
        SpeedometerWidget*                        py_speed;
        BatteryWidget*                            py_battery;
        BatteryAndSpeedWidget*                    py_batspeed;
        Blinkers*                                 left_blinker;
        Blinkers*                                 right_blinker;
        Blinkers*                                 left_blinker2;
        Blinkers*                                 right_blinker2;
        StatsWidget*                              stats;
        FanSpeedWidget*                           fan;
        FanSpeedWidget*                           fan2;
        CPUTempWidget*                            cpu;
        CPUTempWidget*                            cpu2;
        TopBar*                                   top;
        TopBar*                                   top2;
        ListeningWidget*                          listening;
        QSet<int>                                 pressed_keys;
        QTimer*                                   update_timer;
        QStackedWidget*                           stacked_widget;
        QWidget*                                  main_window;
        std::shared_ptr<RosNode>                  node;
        rclcpp::executors::SingleThreadedExecutor executor;

    public:
        EventManager(ArrowSymbolWidget* arrow, SpeedometerWidget* py_speed,
                     BatteryWidget* py_battery,
                     BatteryAndSpeedWidget* py_batspeed, Blinkers* left_blinker,
                     Blinkers* right_blinker, Blinkers* left_blinker2,
                     Blinkers* right_blinker2, StatsWidget* stats,
                     FanSpeedWidget* fan, FanSpeedWidget* fan2,
                     CPUTempWidget* cpu, CPUTempWidget* cpu2, TopBar* top,
                     TopBar* top2, QStackedWidget* stacked_widget,
                     QWidget* main_window, ListeningWidget* listening,
                     std::shared_ptr<RosNode> ros_node);

        virtual         ~EventManager();
        QStackedWidget* getStackedWidget();
        Color           color1;
        void            changeUnits();
        void            changeColors();

    protected:
        bool            eventFilter(QObject* obj, QEvent* event) override;

    private slots:
        void            handleGestureEvent(QGestureEvent* gesture_event);
        void            updateScreen();
        void            updateBlinkers();
};

#endif
