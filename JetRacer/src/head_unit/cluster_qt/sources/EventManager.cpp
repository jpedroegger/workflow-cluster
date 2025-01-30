#include "../includes/EventManager.h"
#include <rclcpp/rclcpp.hpp>

EventManager::EventManager(
    ArrowSymbolWidget* arrow, SpeedometerWidget* py_speed,
    BatteryWidget* py_battery, BatteryAndSpeedWidget* py_batspeed,
    Blinkers* left_blinker, Blinkers* right_blinker, Blinkers* left_blinker2,
    Blinkers* right_blinker2, StatsWidget* stats, FanSpeedWidget* fan,
    FanSpeedWidget* fan2, CPUTempWidget* cpu, CPUTempWidget* cpu2, TopBar* top,
    TopBar* top2, QStackedWidget* stackedWidget, QWidget* mainWindow,
    std::shared_ptr<RosNode> ros_node)
    : arrows(arrow), py_speed(py_speed), py_battery(py_battery),
      py_batspeed(py_batspeed), left_blinker(left_blinker),
      right_blinker(right_blinker), left_blinker2(left_blinker2),
      right_blinker2(right_blinker2), stats(stats), fan(fan), fan2(fan2),
      cpu(cpu), cpu2(cpu2), top(top), top2(top2), stackedWidget(stackedWidget),
      mainWindow(mainWindow), node(ros_node)
{
    color1 = Color();
    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &EventManager::updateScreen);
    executor.add_node(node);
    updateTimer->start(REFRESH_RATE_MS); // Every 50ms => 20FPS
}

bool EventManager::eventFilter(QObject* obj, QEvent* event)
{
    // Handle gesture events
    if (event->type() == QEvent::Gesture)
    {
        QGestureEvent* gestureEvent = static_cast<QGestureEvent*>(event);
        handleGestureEvent(gestureEvent);
        return true;
    }

    // Handle key events
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        pressedKeys.insert(keyEvent->key());
        return true;
    }
    else if (event->type() == QEvent::KeyRelease)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        pressedKeys.remove(keyEvent->key());
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void EventManager::updateScreen()
{
    executor.spin_some(
        std::chrono::milliseconds(10)); // after this line, values are updated.
    py_speed->setCurrentSpeed(node->getSpeed());
    py_battery->setCurrentLevel(node->getBattery());
    py_batspeed->setCurrentLevel(node->getBattery());
    py_batspeed->setCurrentSpeed(node->getSpeed());
    updateBlinkers();

    stats->setDistance(4533);
    stats->setAverage(56);
    stats->setConsumed(78);
    stats->setObstacles(2);
    stats->update();

    for (int key : pressedKeys)
    {
        switch (key)
        {
        case Qt::Key_C:
            changeColors();
            break;
        case Qt::Key_U:
            changeUnits();
            break;
        default:
            break;
        }
    }
}

void EventManager::updateBlinkers()
{
    switch (node->getBlinkerState())
    {
    case blinkerState::IDLE:
        left_blinker->turnOnBlinkers(false);
        right_blinker->turnOnBlinkers(false);
        left_blinker2->turnOnBlinkers(false);
        right_blinker2->turnOnBlinkers(false);
        break;
    case blinkerState::TURN_LEFT:
        left_blinker->turnOnBlinkers(true);
        right_blinker->turnOnBlinkers(false);
        left_blinker2->turnOnBlinkers(true);
        right_blinker2->turnOnBlinkers(false);
        break;
    case blinkerState::TURN_RIGHT:
        left_blinker->turnOnBlinkers(false);
        right_blinker->turnOnBlinkers(true);
        left_blinker2->turnOnBlinkers(false);
        right_blinker2->turnOnBlinkers(true);
        break;
    case blinkerState::WARNINGS:
        left_blinker->turnOnBlinkers(true);
        right_blinker->turnOnBlinkers(true);
        left_blinker2->turnOnBlinkers(true);
        right_blinker2->turnOnBlinkers(true);
        break;
    default:
        left_blinker->turnOnBlinkers(false);
        right_blinker->turnOnBlinkers(false);
        left_blinker2->turnOnBlinkers(false);
        right_blinker2->turnOnBlinkers(false);
    }
}

void EventManager::changeColors()
{
    color1.indent();
    arrows->changeColor(color1.counter);
    py_batspeed->changeColor(color1.counter);
    py_speed->changeColor(color1.counter);
    py_battery->changeColor(color1.counter);
    stats->changeColor(color1.counter);
    top->changeColor(color1.counter);
    left_blinker->changeColor(color1.counter);
    right_blinker->changeColor(color1.counter);
    top2->changeColor(color1.counter);
    left_blinker2->changeColor(color1.counter);
    right_blinker2->changeColor(color1.counter);
    fan->changeColor(color1.counter);
    fan2->changeColor(color1.counter);
    cpu->changeColor(color1.counter);
    cpu2->changeColor(color1.counter);
    mainWindow->setStyleSheet(color1.background_array[color1.counter]);
}

void EventManager::changeUnits()
{
    py_speed->changeUnits();
    py_batspeed->changeUnits();
    stats->changeUnits();
    cpu->changeUnits();
    cpu2->changeUnits();
}

void EventManager::handleGestureEvent(QGestureEvent* gestureEvent)
{
    if (QSwipeGesture* swipe = static_cast<QSwipeGesture*>(
            gestureEvent->gesture(Qt::SwipeGesture)))
    {
        if (swipe->horizontalDirection() == QSwipeGesture::Left)
        {
            // nextIndex is the last or page + 1
            int nextIndex = std::min(stackedWidget->count() - 1,
                                     stackedWidget->currentIndex() + 1);
            stackedWidget->setCurrentIndex(nextIndex);
        }
        else if (swipe->horizontalDirection() == QSwipeGesture::Right)
        {
            // prevIndex is the first or page - 1
            int prevIndex = std::max(0, stackedWidget->currentIndex() - 1);
            stackedWidget->setCurrentIndex(prevIndex);
        }
    }
}

QStackedWidget* EventManager::getStackedWidget() { return stackedWidget; }

EventManager::~EventManager() {}
