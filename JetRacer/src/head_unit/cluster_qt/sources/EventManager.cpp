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
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* mousePos = static_cast<QMouseEvent*>(event);
        QPointF pressPosition = mousePos->position();

        mousePosition = pressPosition;
        return true;
    }
    else if (event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent* mousePos = static_cast<QMouseEvent*>(event);
        QPointF releasePosition = mousePos->position();
        if (swipe(releasePosition))
            return true;
    }
    else if (event->type() == QEvent::KeyRelease)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        
        if (!keyEvent->isAutoRepeat())
            activateButton(keyEvent->key());
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void    EventManager::activateButton(int key)
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

bool    EventManager::swipe(QPointF releasePosition)
{
    bool swipeRange = qFabs(mousePosition.rx() - releasePosition.rx()) > 100;
    bool verticalRange = qFabs(mousePosition.ry() - releasePosition.ry()) < 200;

    if (mousePosition.rx() < releasePosition.rx() && swipeRange && verticalRange ) {
        int prevIndex = std::max(0, stackedWidget->currentIndex() - 1);
        stackedWidget->setCurrentIndex(prevIndex);

        return true;
    }
    else if (mousePosition.rx() > releasePosition.rx() && swipeRange && verticalRange ) {
        int nextIndex = std::min(stackedWidget->count() - 1, stackedWidget->currentIndex() + 1);
        stackedWidget->setCurrentIndex(nextIndex);

        return true;
    }
    return false;
}


QStackedWidget* EventManager::getStackedWidget() { return stackedWidget; }

EventManager::~EventManager() {}
