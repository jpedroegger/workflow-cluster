#include "includes/EventManager.h"

EventManager::EventManager(ArrowSymbolWidget* arrow,
                           SpeedometerWidget* py_speed,
                           Blinkers* left_blinker,
                           Blinkers* right_blinker)
    : arrows(arrow), py_speed(py_speed), left_blinker(left_blinker), right_blinker(right_blinker)
{
    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &EventManager::processKeyStates);
    updateTimer->start(80); // Every 80ms
}

bool EventManager::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        pressedKeys.insert(keyEvent->key());
        return true;
    }
    else if (event->type() == QEvent::KeyRelease) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        pressedKeys.remove(keyEvent->key());
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void EventManager::processKeyStates()
{
    for (int key : pressedKeys) {
        switch (key) {
            case Qt::Key_Left:
            case Qt::Key_Right:
            case Qt::Key_Up:
                arrows->changeDirection(key);
                break;
            case Qt::Key_Space:
            case Qt::Key_Down:
                py_speed->accelerate(key);
                break;
            case Qt::Key_L:
                left_blinker->turnOnBlinkers(key);
                break;
            case Qt::Key_R:
                right_blinker->turnOnBlinkers(key);
                break;
            default:
                break;
        }
    }
}
