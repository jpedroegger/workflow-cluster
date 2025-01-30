#include "../../includes/Blinkers.h"
#include <QCoreApplication>
#include <QTimer>
#include <QtTest>

class MockBlinkers : public Blinkers
{
};

class BlinkerTest : public QObject
{
        Q_OBJECT

    public:
        BlinkerTest();
        ~BlinkerTest();

    private slots:
        void testTurnOnLeftBlinkerStartsBlinking();
        void testTurnOnRightBlinkerStartsBlinking();
        void testTurnOffLeftBlinkerStopsBlinking();
        void testTurnOffRightBlinkerStopsBlinking();
        void testTimerStartsWhenBlinkerIsTurnedOn();
        void testTimerStopsWhenBlinkerIsTurnedOff();
        // void testImageUpdatesWhenBlinkerIsTurnedOff();
};

BlinkerTest::BlinkerTest() {}

BlinkerTest::~BlinkerTest() {}

void BlinkerTest::testTurnOnLeftBlinkerStartsBlinking()
{
    auto left_blinker = new MockBlinkers();
    auto right_blinker = new MockBlinkers();

    left_blinker->turnOnBlinkers(true);

    QVERIFY(left_blinker->get_blinking());
}

void BlinkerTest::testTurnOnRightBlinkerStartsBlinking()
{
    auto left_blinker = new MockBlinkers();
    auto right_blinker = new MockBlinkers();

    right_blinker->turnOnBlinkers(true);

    QVERIFY(right_blinker->get_blinking());
}

void BlinkerTest::testTurnOffLeftBlinkerStopsBlinking()
{
    auto left_blinker = new MockBlinkers();
    auto right_blinker = new MockBlinkers();

    left_blinker->turnOnBlinkers(true);
    left_blinker->turnOnBlinkers(false);

    QVERIFY(!left_blinker->get_blinking());
}

void BlinkerTest::testTurnOffRightBlinkerStopsBlinking()
{
    auto left_blinker = new MockBlinkers();
    auto right_blinker = new MockBlinkers();

    right_blinker->turnOnBlinkers(true);
    right_blinker->turnOnBlinkers(false);

    QVERIFY(!right_blinker->get_blinking());
}

void BlinkerTest::testTimerStartsWhenBlinkerIsTurnedOn()
{
    Blinkers leftBlinker;

    leftBlinker.turnOnBlinkers(true);

    QVERIFY(leftBlinker.getToggleTimer() != nullptr);
    QVERIFY(leftBlinker.getToggleTimer()->isActive());
}

void BlinkerTest::testTimerStopsWhenBlinkerIsTurnedOff()
{
    Blinkers leftBlinker;

    leftBlinker.turnOnBlinkers(true);
    leftBlinker.turnOnBlinkers(false);

    QVERIFY(leftBlinker.getToggleTimer() != nullptr);
    QVERIFY(!leftBlinker.getToggleTimer()->isActive());
}

QTEST_MAIN(BlinkerTest)

#include "tst_blinkertest.moc"
