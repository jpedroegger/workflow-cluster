#include "../includes/EventManager.h"
#include <iostream>
EventManager::EventManager(ArrowSymbolWidget* arrow,
                           SpeedometerWidget* py_speed,
                           BatteryWidget* py_battery,
                           BatteryAndSpeedWidget* py_batspeed,
                           Blinkers* left_blinker, Blinkers* right_blinker,
                           StatsWidget* stats, TopBar* top,
                           QStackedWidget* stackedWidget, QWidget* mainWindow)
    : arrows(arrow), py_speed(py_speed), py_battery(py_battery), py_batspeed(py_batspeed),
      left_blinker(left_blinker), right_blinker(right_blinker), stats(stats), top(top),
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
    py_battery->setCurrentLevel(42);
    py_batspeed->setCurrentLevel(42);
    py_batspeed->setCurrentSpeed(37);
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
            if (left_blinker && right_blinker)
            {
                if (!left_blinker->get_blinking())
                    left_blinker->turnOnBlinkers(true);
                else
                    left_blinker->turnOnBlinkers(false);
                right_blinker->turnOnBlinkers(false);
            }
            break;
        case Qt::Key_R:
            if (left_blinker && right_blinker)
            {
                if (!right_blinker->get_blinking())
                    right_blinker->turnOnBlinkers(true);
                else
                    right_blinker->turnOnBlinkers(false);
                left_blinker->turnOnBlinkers(false);
            }
            break;
        case Qt::Key_B:
            if (right_blinker && left_blinker)
            {
                if (right_blinker->get_blinking() &&
                    left_blinker->get_blinking())
                {
                    left_blinker->turnOnBlinkers(false);
                    right_blinker->turnOnBlinkers(false);
                    break;
                }
                left_blinker->turnOnBlinkers(false);
                right_blinker->turnOnBlinkers(false);
                left_blinker->turnOnBlinkers(true);
                right_blinker->turnOnBlinkers(true);
            }
            break;
        case Qt::Key_C:
            color1.indent();
            arrows->changeColor(color1.counter);
            py_batspeed->changeColor(color1.counter);
            py_speed->changeColor(color1.counter);
            py_battery->changeColor(color1.counter);
            stats->changeColor(color1.counter);
            top->changeColor(color1.counter);
            left_blinker->changeColor(color1.counter);
            right_blinker->changeColor(color1.counter);
            mainWindow->setStyleSheet(color1.background_array[color1.counter]);
            break;
        default:
            break;
        }
    }
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
