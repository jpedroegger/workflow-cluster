#include "../includes/EventManager.h"
#include <rclcpp/rclcpp.hpp>

EventManager::EventManager(
    ArrowSymbolWidget* arrow, SpeedometerWidget* py_speed,
    BatteryWidget* py_battery, BatteryAndSpeedWidget* py_batspeed,
    Blinkers* left_blinker, Blinkers* right_blinker, Blinkers* left_blinker2,
    Blinkers* right_blinker2, StatsWidget* stats, FanSpeedWidget* fan,
    FanSpeedWidget* fan2, CPUTempWidget* cpu, CPUTempWidget* cpu2, TopBar* top,
    TopBar* top2, QStackedWidget* stacked_widget, QWidget* main_window,
    ListeningWidget* listening, std::shared_ptr<RosNode> ros_node)
    : arrows(arrow), py_speed(py_speed), py_battery(py_battery),
      py_batspeed(py_batspeed), left_blinker(left_blinker),
      right_blinker(right_blinker), left_blinker2(left_blinker2),
      right_blinker2(right_blinker2), stats(stats), fan(fan), fan2(fan2),
      cpu(cpu), cpu2(cpu2), top(top), top2(top2), stacked_widget(stacked_widget),
      main_window(main_window), listening(listening), node(ros_node)
{
    color1 = Color();
    update_timer = new QTimer(this);
    connect(update_timer, &QTimer::timeout, this, &EventManager::updateScreen);
    executor.add_node(node);
    update_timer->start(REFRESH_RATE_MS); // Every 50ms => 20FPS
}

bool EventManager::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::Gesture)
    {
        QGestureEvent* gesture_event = static_cast<QGestureEvent*>(event);
        handleGestureEvent(gesture_event);
        return true;
    }

    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        pressed_keys.insert(keyEvent->key());
        return true;
    }
    else if (event->type() == QEvent::KeyRelease)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        pressed_keys.remove(keyEvent->key());
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

    for (int key : pressed_keys)
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
    listening->changeColor(color1.counter);
    main_window->setStyleSheet(color1.background_array[color1.counter]);
}

void EventManager::changeUnits()
{
    py_speed->changeUnits();
    py_batspeed->changeUnits();
    stats->changeUnits();
    cpu->changeUnits();
    cpu2->changeUnits();
}

void EventManager::handleGestureEvent(QGestureEvent* gesture_event)
{
    if (QSwipeGesture* swipe = static_cast<QSwipeGesture*>(
            gesture_event->gesture(Qt::SwipeGesture)))
    {
        if (swipe->horizontalDirection() == QSwipeGesture::Left)
        {
            int nextIndex = std::min(stacked_widget->count() - 1,
                                     stacked_widget->currentIndex() + 1);
            stacked_widget->setCurrentIndex(nextIndex);
        }
        else if (swipe->horizontalDirection() == QSwipeGesture::Right)
        {
            int prevIndex = std::max(0, stacked_widget->currentIndex() - 1);
            stacked_widget->setCurrentIndex(prevIndex);
        }
    }
}

QStackedWidget* EventManager::getStackedWidget() { return stacked_widget; }

EventManager::~EventManager() {}
