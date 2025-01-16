#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "ArrowSymbolWidget.h"
#include "Blinkers.h"
#include "SpeedometerWidget.h"
#include <QObject>
#include <QSet>
#include <QStackedWidget>
#include <QSwipeGesture>
#include <QTimer>
#include <QWidget>
#include <RosNode.hpp>

class EventManager : public QWidget
{
        Q_OBJECT;

    private:
        ArrowSymbolWidget* arrows;
        SpeedometerWidget* py_speed;
        Blinkers* left_blinker;
        Blinkers* right_blinker;
        QSet<int> pressedKeys;
        QTimer* updateTimer; // Used to check if a key is still being called
        QStackedWidget* stackedWidget;
        QPointF mousePosition;

        // ROS related objects
        std::shared_ptr<RosNode> node;
        rclcpp::executors::SingleThreadedExecutor executor;

    public:
        EventManager(ArrowSymbolWidget* arrow, SpeedometerWidget* py_speed,
                     Blinkers* left_blinker, Blinkers* right_blinker,
                     QStackedWidget* stackedWidget,
                     std::shared_ptr<RosNode> ros_node);

        QStackedWidget* getStackedWidget(void) const;
        void processKeyStates();

    protected:
        bool eventFilter(QObject* obj, QEvent* event) override;
        bool swipe(QPointF releasePosition);

    private slots:
};

#endif // EVENTMANAGER_H
