#include "../include/SettingsWidget.h"

SettingsWidget::SettingsWidget(QWidget *parent)
    : QWidget(parent), expanded(false)
{
    // Initialize main icon with an image
    mainIcon = new QPushButton(this);
    mainIcon->setFixedSize(50, 50);
    mainIcon->setStyleSheet("border: none; background-image: url('assets/icons/settings.png'); background-repeat: no-repeat; background-position: center;");

    // Initialize additional icons with images
    icon1 = new QPushButton(this);
    icon1->setFixedSize(50, 50);
    icon1->setStyleSheet("border: none; background-image: url('assets/icons/brush.png'); background-repeat: no-repeat; background-position: center;");

    icon2 = new QPushButton(this);
    icon2->setFixedSize(50, 50);
    icon2->setStyleSheet("border: none; background-image: url('assets/icons/convert.png'); background-repeat: no-repeat; background-position: center;");

    collapsedWidget = new QWidget(this);
    QVBoxLayout *collapsedLayout = new QVBoxLayout(collapsedWidget);
    collapsedLayout->addWidget(mainIcon);
    collapsedLayout->setAlignment(Qt::AlignCenter);

    // Create expanded widget
    expandedWidget = new QWidget(this);
    QVBoxLayout *expandedLayout = new QVBoxLayout(expandedWidget);
    expandedLayout->addWidget(mainIcon);
    expandedLayout->addWidget(icon1);
    expandedLayout->addWidget(icon2);
    expandedLayout->setAlignment(Qt::AlignCenter);

    // Create stacked widget
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(collapsedWidget);
    stackedWidget->addWidget(expandedWidget);

    // Set initial state
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stackedWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(mainLayout);
    setFixedSize(70, 70); // Collapsed size

    // Connect button
    connect(mainIcon, &QPushButton::clicked, this, &SettingsWidget::toggleExpand);
}

void SettingsWidget::toggleExpand()
{
    setExpanded(!expanded);
}

void SettingsWidget::setExpanded(bool expand)
{
    expanded = expand;

    if (expanded) {
        stackedWidget->setCurrentWidget(expandedWidget);
        setFixedSize(100, 200); // Expanded size
    } else {
        stackedWidget->setCurrentWidget(collapsedWidget);
        setFixedSize(70, 70); // Collapsed size
    }
}

void SettingsWidget::mousePressEvent(QMouseEvent *event)
{
    if (expanded && isClickOutside(event->pos())) {
        setExpanded(false);
    }

    // Call the base class implementation to handle other events
    QWidget::mousePressEvent(event);
}

bool SettingsWidget::isClickOutside(const QPoint &pos) const
{
    // Check if the click position is outside the widget's rectangle
    return !rect().contains(pos);
}
