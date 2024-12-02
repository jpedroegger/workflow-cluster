#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QWidget>
#include "ArrowSymbolWidget.h"
#include "SpeedometerWidget.h"
#include "Blinkers.h"

class EventManager : public QWidget
{
    Q_OBJECT;

    public:
        ArrowSymbolWidget* arrows;
        SpeedometerWidget* py_speed;
        Blinkers* left_blinker;
        Blinkers* right_blinker;
        QSet<int> pressedKeys;
        QTimer* updateTimer;   // Used to check if a key is still being called

        EventManager(ArrowSymbolWidget* arrow,
                     SpeedometerWidget* py_speed,
                     Blinkers* left_blinker,
                     Blinkers* right_blinker);

    protected:
        bool eventFilter(QObject* obj, QEvent* event) override;

    private slots:
        void processKeyStates();
};

#endif // EVENTMANAGER_H
