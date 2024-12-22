#include <QCoreApplication>
#include <QtTest>
#include "../cluster_qt/includes/EventManager.h"


class MockArrowSymbolWidget : public ArrowSymbolWidget {};
class MockSpeedometerWidget : public SpeedometerWidget {};
class MockBlinkers : public Blinkers {};
class MockStackedWidget : public QStackedWidget {};

class EventManagerTest : public QObject
{
    Q_OBJECT

public:
    EventManagerTest();
    ~EventManagerTest();

private:
    EventManager* createEventManager(int initialIndex = 0)
    {
        auto arrows = new MockArrowSymbolWidget();
        auto speedometer = new MockSpeedometerWidget();
        auto leftBlinker = new MockBlinkers();
        auto rightBlinker = new MockBlinkers();
        auto stackedWidget = new MockStackedWidget();

        // Setup the stacked widget
        stackedWidget->addWidget(new QWidget());
        stackedWidget->addWidget(new QWidget());
        stackedWidget->setCurrentIndex(initialIndex);

        auto eventManager = new EventManager(arrows, speedometer, leftBlinker, rightBlinker, stackedWidget);
        eventManager->installEventFilter(eventManager);
        eventManager->resize(900, 900);
        eventManager->show();

        return eventManager;
    }

private slots:
    void testSwipeRight();
    void testSwipeLeft();
    void testSwipeRightLastPage();
    void testSwipeLeftFirstPage();
    void testNoSwipeForShortDistance();
    void testNoSwipeForLongVerticalDistance();
};

EventManagerTest::EventManagerTest() {}

EventManagerTest::~EventManagerTest() {}

void EventManagerTest::testSwipeRight()
{
    auto eventManager = createEventManager(0);
    auto stackedWidget = eventManager->getStackedWidget();

    QPoint startPos(250, 150);
    QPoint endPos(50, 150);

    // This simulates the swipe to the right window
    QTest::mousePress(eventManager, Qt::LeftButton, Qt::NoModifier, startPos);
    QTest::mouseMove(eventManager, endPos);
    QTest::mouseRelease(eventManager, Qt::LeftButton, Qt::NoModifier, endPos);

    QCOMPARE(stackedWidget->currentIndex(), 1);

    delete eventManager;
}

void EventManagerTest::testSwipeLeft()
{
    auto eventManager = createEventManager(1);
    auto stackedWidget = eventManager->getStackedWidget();

    QPoint startPos(50, 150);
    QPoint endPos(250, 150);

    // This simulates the swipe to the left window
    QTest::mousePress(eventManager, Qt::LeftButton, Qt::NoModifier, startPos);
    QTest::mouseMove(eventManager, endPos);
    QTest::mouseRelease(eventManager, Qt::LeftButton, Qt::NoModifier, endPos);

    QCOMPARE(stackedWidget->currentIndex(), 0);

    delete eventManager;
}

void EventManagerTest::testSwipeRightLastPage()
{
    auto eventManager = createEventManager(1);
    auto stackedWidget = eventManager->getStackedWidget();

    QPoint startPos(250, 150);
    QPoint endPos(50, 150);

    QTest::mousePress(eventManager, Qt::LeftButton, Qt::NoModifier, startPos);
    QTest::mouseMove(eventManager, endPos);
    QTest::mouseRelease(eventManager, Qt::LeftButton, Qt::NoModifier, endPos);

    QCOMPARE(stackedWidget->currentIndex(), 1);

    delete eventManager;
}

void EventManagerTest::testSwipeLeftFirstPage()
{
    auto eventManager = createEventManager(0);
    auto stackedWidget = eventManager->getStackedWidget();

    QPoint startPos(50, 150);
    QPoint endPos(250, 150);

    QTest::mousePress(eventManager, Qt::LeftButton, Qt::NoModifier, startPos);
    QTest::mouseMove(eventManager, endPos);
    QTest::mouseRelease(eventManager, Qt::LeftButton, Qt::NoModifier, endPos);

    QCOMPARE(stackedWidget->currentIndex(), 0);

    delete eventManager;
}

void EventManagerTest::testNoSwipeForShortDistance()
{
    auto eventManager = createEventManager(0);
    auto stackedWidget = eventManager->getStackedWidget();

    QPoint startPos(50, 150);
    QPoint endPos(149, 150);

    QTest::mousePress(eventManager, Qt::LeftButton, Qt::NoModifier, startPos);
    QTest::mouseMove(eventManager, endPos);
    QTest::mouseRelease(eventManager, Qt::LeftButton, Qt::NoModifier, endPos);

    QCOMPARE(stackedWidget->currentIndex(), 0);

    delete eventManager;
}

void EventManagerTest::testNoSwipeForLongVerticalDistance()
{
    auto eventManager = createEventManager(0);
    auto stackedWidget = eventManager->getStackedWidget();

    QPoint startPos(250, 150);
    QPoint endPos(50, 450);

    QTest::mousePress(eventManager, Qt::LeftButton, Qt::NoModifier, startPos);
    QTest::mouseMove(eventManager, endPos);
    QTest::mouseRelease(eventManager, Qt::LeftButton, Qt::NoModifier, endPos);

    QCOMPARE(stackedWidget->currentIndex(), 0);

    delete eventManager;
}

QTEST_MAIN(EventManagerTest)

#include "tst_eventmanagertest.moc"

