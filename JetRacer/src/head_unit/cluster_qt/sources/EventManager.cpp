#include "../includes/EventManager.h"
#include <iostream>
EventManager::EventManager(ArrowSymbolWidget* arrow, SpeedometerWidget* py_speed,
                     BatteryWidget* py_battery, BatteryAndSpeedWidget* py_batspeed,
                     Blinkers* left_blinker, Blinkers* right_blinker,
                     Blinkers* left_blinker2, Blinkers* right_blinker2,
                     StatsWidget* stats, TopBar* top, TopBar* top2,
                     QStackedWidget* stackedWidget, QWidget* mainWindow)
    : arrows(arrow), py_speed(py_speed), py_battery(py_battery), py_batspeed(py_batspeed),
      left_blinker(left_blinker), right_blinker(right_blinker), left_blinker2(left_blinker2), 
      right_blinker2(right_blinker2), stats(stats), top(top), top2(top2),
      stackedWidget(stackedWidget), mainWindow(mainWindow)
{
    color1 = Color();
    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this,
            &EventManager::processKeyStates);
    //executor.add_node(node);
    updateTimer->start(80); // Every 80ms
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

void EventManager::processKeyStates()
{
    
    //executor.spin_some(std::chrono::milliseconds(10)); // after this line, values are updated.

    py_speed->setCurrentSpeed(37);
    py_batspeed->setCurrentSpeed(37);
    py_battery->setCurrentLevel(42);
    py_batspeed->setCurrentLevel(42);
    stats->setDistance(4533);
    stats->setAverage(56);
    stats->setConsumed(78);
    stats->setObstacles(2);

    stats->update();
    py_speed->update();
    py_battery->update();
    py_batspeed->update();
    

    for (int key : pressedKeys)
    {
        switch (key)
        {
        case Qt::Key_Left:
        case Qt::Key_Right:
        case Qt::Key_Up:
            if (arrows)
                arrows->changeDirection(key);
            break;
        case Qt::Key_Space:
        case Qt::Key_Down:
            if (py_speed)
                py_speed->accelerate(key);
            break;
        case Qt::Key_L:
            turnLeftB();
            break;
        case Qt::Key_R:
            turnRightB();
            break;
        case Qt::Key_B:
            turnBothB();
            break;
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

void EventManager::turnLeftB()
{
    if (left_blinker && right_blinker)
    {
        if (!left_blinker->get_blinking())
            left_blinker->turnOnBlinkers(true);
        else if (!right_blinker->get_blinking())
            left_blinker->turnOnBlinkers(false);
        right_blinker->turnOnBlinkers(false);
    }
    if (left_blinker2 && right_blinker2)
    {
        if (!left_blinker2->get_blinking())
            left_blinker2->turnOnBlinkers(true);
        else if (!right_blinker2->get_blinking())
            left_blinker2->turnOnBlinkers(false);
        right_blinker2->turnOnBlinkers(false);
    }
}

void EventManager::turnRightB()
{
    if (left_blinker && right_blinker)
    {
        if (!right_blinker->get_blinking())
            right_blinker->turnOnBlinkers(true);
        else if (!left_blinker->get_blinking())
            right_blinker->turnOnBlinkers(false);
        left_blinker->turnOnBlinkers(false);
    }
    if (left_blinker2 && right_blinker2)
    {
        if (!right_blinker2->get_blinking())
            right_blinker2->turnOnBlinkers(true);
        else if (!left_blinker2->get_blinking())
            right_blinker2->turnOnBlinkers(false);
        left_blinker2->turnOnBlinkers(false);
    }
}

void EventManager::turnBothB()
{
    if (right_blinker && left_blinker)
    {
        if (right_blinker->get_blinking() &&
            left_blinker->get_blinking())
        {
            left_blinker->turnOnBlinkers(false);
            right_blinker->turnOnBlinkers(false);
        }
        else
        {
            left_blinker->turnOnBlinkers(false);
            right_blinker->turnOnBlinkers(false);
            left_blinker->turnOnBlinkers(true);
            right_blinker->turnOnBlinkers(true);
        }
    }
    if (right_blinker2 && left_blinker2)
    {
        if (right_blinker2->get_blinking() &&
            left_blinker2->get_blinking())
        {
            left_blinker2->turnOnBlinkers(false);
            right_blinker2->turnOnBlinkers(false);
        }
        else
        {
            left_blinker2->turnOnBlinkers(false);
            right_blinker2->turnOnBlinkers(false);
            left_blinker2->turnOnBlinkers(true);
            right_blinker2->turnOnBlinkers(true);
        }
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
    mainWindow->setStyleSheet(color1.background_array[color1.counter]);
}

void EventManager::changeUnits()
{
    py_speed->changeUnits();
    py_batspeed->changeUnits();
    stats->changeUnits();
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

EventManager::~EventManager() {}
