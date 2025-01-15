#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QWidget>
#include "ArrowSymbolWidget.h"
#include "SpeedometerWidget.h"
#include "BatteryAndSpeedWidget.h"
#include "Blinkers.h"
#include <QSwipeGesture>
#include <QStackedWidget>
#include <QObject>
#include <QSet>
#include <QTimer>
#include "Colors.h"

class EventManager : public QWidget
{
    Q_OBJECT;

    private:
        ArrowSymbolWidget* arrows;
        SpeedometerWidget* py_speed;
        BatteryAndSpeedWidget* py_batspeed;
        Blinkers* left_blinker;
        Blinkers* right_blinker;
        QSet<int> pressedKeys;
        QTimer* updateTimer;   // Used to check if a key is still being called
        QStackedWidget* stackedWidget;

    public:
        EventManager(ArrowSymbolWidget* arrow,
                     SpeedometerWidget* py_speed,
                     BatteryAndSpeedWidget* py_batspeed,
                     Blinkers* left_blinker,
                     Blinkers* right_blinker,
                     QStackedWidget* stackedWidget);
        virtual ~EventManager();
        Color color1;

    protected:
        bool eventFilter(QObject* obj, QEvent* event) override;

    private slots:
        void handleGestureEvent(QGestureEvent* gestureEvent);
        void processKeyStates();
};

#endif // EVENTMANAGER_H
