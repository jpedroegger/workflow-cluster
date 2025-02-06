#include "../includes/SettingsWidget.h"


/**
 * @brief Constructs a SettingsWidget with the specified parameters.
 *
 * @param parent The parent widget.
 * @param event Reference to the EventManager for handling user actions.
 * @param x The x-coordinate of the widget's position (default is 0).
 * @param y The y-coordinate of the widget's position (default is 0).
 * @param width The width of the widget (default is 0).
 * @param height The height of the widget (default is 0).
 */
SettingsWidget::SettingsWidget(QWidget *parent, EventManager &event, int x, int y, int width, int height)
    : QWidget(parent), expanded(false), event(event)
{
    setGeometry(x, y, width, height);
    // Initialize main icon with an image
    mainIcon = new QPushButton(this);
    mainIcon->setFixedSize(50, 50);
    mainIcon->setStyleSheet("border: none; "
                            "background-image: url('/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/settings.png'); "
                            "background-repeat: no-repeat; "
                            "background-position: center;"
                            );

    // Initialize close icon with an image
    closeIcon = new QPushButton(this);
    closeIcon->setFixedSize(50, 50);
    closeIcon->setStyleSheet("border: none; "
                             "background-image: url('/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/settings.png'); "
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
    themesIcon->setIcon(QIcon("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brush.png"));
    themesIcon->setIconSize(QSize(50, 50));
    themesIcon->setText("Change Themes");

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
    changeUnitIcon->setIcon(QIcon("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/convert.png"));
    changeUnitIcon->setIconSize(QSize(50, 50));
    changeUnitIcon->setText("Change Units");


    collapsedWidget = new QWidget(this);
    QVBoxLayout *collapsedLayout = new QVBoxLayout(collapsedWidget);
    collapsedLayout->addWidget(mainIcon);

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
    connect(changeUnitIcon, &QPushButton::clicked, stats, &event->changeUnits());
    connect(themesIcon, &QPushButton::clicked, stats, &event->changeColors());
}

/**
 * @brief Toggles the widget between collapsed and expanded states.
 *
 * This slot is triggered when the user clicks the main icon to expand or collapse the settings menu.
 */
void SettingsWidget::toggleExpand()
{
    setExpanded(!expanded);
}

/**
 * @brief Expands or collapses the settings menu.
 *
 * This method updates the widget's state and UI to reflect the expanded or collapsed state.
 *
 * @param expand If true, the widget is expanded; if false, it is collapsed.
 */
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

/**
 * @brief Handles mouse press events to detect clicks outside the widget.
 *
 * This method is overridden from QWidget to detect clicks outside the widget and collapse
 * the settings menu if it is expanded.
 *
 * @param event The mouse event.
 */
void SettingsWidget::mousePressEvent(QMouseEvent *event)
{
    if (expanded && isClickOutside(event->pos())) {
        setExpanded(false);
    }

    // Call the base class implementation to handle other events
    QWidget::mousePressEvent(event);
}

/**
 * @brief Checks if a click occurred outside the widget.
 *
 * This method determines whether a mouse click occurred outside the bounds of the widget.
 *
 * @param pos The position of the mouse click.
 * @return true if the click was outside the widget, false otherwise.
 */
bool SettingsWidget::isClickOutside(const QPoint &pos) const
{
    // Check if the click position is outside the widget's rectangle
    return !rect().contains(pos);
}
