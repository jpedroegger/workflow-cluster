#include "../includes/SettingsWidget.h"
#include "../includes/StatsWidget.h"

SettingsWidget::SettingsWidget(QWidget *parent)
    : QWidget(parent), expanded(false)
{
    // Initialize main icon with an image
    mainIcon = new QPushButton(this);
    mainIcon->setFixedSize(50, 50);
    mainIcon->setStyleSheet("border: none; "
                            "background-image: url('assets/icons/settings.png'); "
                            "background-repeat: no-repeat; "
                            "background-position: center;"
                            );

    // Initialize close icon with an image
    closeIcon = new QPushButton(this);
    closeIcon->setFixedSize(50, 50);
    closeIcon->setStyleSheet("border: none; "
                             "background-image: url('assets/icons/settings.png'); "
                             "background-repeat: no-repeat; "
                             "background-position: center;");

    themesIcon = new QPushButton(this);
    themesIcon->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    themesIcon->setStyleSheet(
        "QPushButton {"
        "   border: none;"
        "   background: none;"
        "}"
        "QPushButton::icon {"
        "   margin-bottom: 50px;"
        "}"
        "QPushButton {"
        "   text-align: center;"
        "}"
        );
    themesIcon->setIcon(QIcon("assets/icons/brush.png"));
    themesIcon->setIconSize(QSize(50, 50));
    themesIcon->setText("Themes");

    changeUnitIcon = new QPushButton(this);
    changeUnitIcon->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    changeUnitIcon->setStyleSheet(
        "QPushButton {"
        "   border: none;"
        "   background: none;"
        "}"
        "QPushButton::icon {"
        "   margin-bottom: 50px;"
        "}"
        "QPushButton {"
        "   text-align: center;"
        "}"
        );
    changeUnitIcon->setIcon(QIcon("assets/icons/convert.png"));
    changeUnitIcon->setIconSize(QSize(50, 50));
    changeUnitIcon->setText("Change Units");

    StatsWidget *statsWidget = new StatsWidget(this);

    collapsedWidget = new QWidget(this);
    QVBoxLayout *collapsedLayout = new QVBoxLayout(collapsedWidget);
    collapsedLayout->addWidget(mainIcon);
    collapsedLayout->addWidget(statsWidget);

    collapsedLayout->setContentsMargins(0, 0, 0, 0);
    collapsedLayout->setSpacing(0);

    // Create expanded widget
    expandedWidget = new QWidget(this);
    QVBoxLayout *expandedLayout = new QVBoxLayout(expandedWidget);
    expandedLayout->addWidget(themesIcon);
    expandedLayout->addWidget(changeUnitIcon);
    expandedLayout->addWidget(closeIcon);

    expandedLayout->setContentsMargins(0, 0, 0, 0);
    expandedLayout->setSpacing(10);

    // Create stacked widget
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(collapsedWidget);
    stackedWidget->addWidget(expandedWidget);


    // Set initial state
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stackedWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);


    setLayout(mainLayout);
    setFixedSize(140, 120); // Collapsed size


    // Connect buttons
    connect(mainIcon, &QPushButton::clicked, this, &SettingsWidget::toggleExpand);
    connect(closeIcon, &QPushButton::clicked, this, &SettingsWidget::toggleExpand);
    // connect(themesIcon, &QPushButton::clicked, &statsWidget, &StatsWidget::changeUnits);
    connect(changeUnitIcon, &QPushButton::clicked, statsWidget, &StatsWidget::changeUnits);
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
        setMinimumSize(140, 200);
        setMaximumSize(140, 200);
    } else {
        stackedWidget->setCurrentWidget(collapsedWidget);
        setMinimumSize(140, 120);
        setMaximumSize(140, 120);
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
