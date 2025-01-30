#include "../includes/SettingsWidget.h"

SettingsWidget::SettingsWidget(QWidget *parent, EventManager &event, int x, int y, int width, int height)
    : QWidget(parent), expanded(false), event(event)
{
    setGeometry(x, y, width, height);
    main_icon = new QPushButton(this);
    main_icon->setFixedSize(50, 50);
    main_icon->setStyleSheet("border: none; "
                            "background-image: url('/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/settings.png'); "
                            "background-repeat: no-repeat; "
                            "background-position: center;"
                            );

    close_icon = new QPushButton(this);
    close_icon->setFixedSize(50, 50);
    close_icon->setStyleSheet("border: none; "
                             "background-image: url('/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/settings.png'); "
                             "background-repeat: no-repeat; "
                             "background-position: center;");

    themes_icon = new QPushButton(this);
    themes_icon->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    themes_icon->setStyleSheet(
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
    themes_icon->setIcon(QIcon("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/brush.png"));
    themes_icon->setIconSize(QSize(50, 50));
    themes_icon->setText("Change Themes");

    change_unit_icon = new QPushButton(this);
    change_unit_icon->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    change_unit_icon->setStyleSheet(
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
    change_unit_icon->setIcon(QIcon("/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/head_unit/cluster_qt/assets/icons/convert.png"));
    change_unit_icon->setIconSize(QSize(50, 50));
    change_unit_icon->setText("Change Units");


    collapsed_widget = new QWidget(this);
    QVBoxLayout *collapsedLayout = new QVBoxLayout(collapsed_widget);
    collapsedLayout->addWidget(main_icon);

    collapsedLayout->setContentsMargins(0, 0, 0, 0);
    collapsedLayout->setSpacing(0);

    expanded_widget = new QWidget(this);
    QVBoxLayout *expandedLayout = new QVBoxLayout(expanded_widget);
    expandedLayout->addWidget(themes_icon);
    expandedLayout->addWidget(change_unit_icon);
    expandedLayout->addWidget(close_icon);

    expandedLayout->setContentsMargins(0, 0, 0, 0);
    expandedLayout->setSpacing(10);

    stacked_widget = new QStackedWidget(this);
    stacked_widget->addWidget(collapsed_widget);
    stacked_widget->addWidget(expanded_widget);


    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stacked_widget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);


    setLayout(mainLayout);
    setFixedSize(140, 120); // Collapsed size


    connect(main_icon, &QPushButton::clicked, this, &SettingsWidget::toggleExpand);
    connect(close_icon, &QPushButton::clicked, this, &SettingsWidget::toggleExpand);
    connect(change_unit_icon, &QPushButton::clicked, stats, &event->changeUnits());
    connect(themes_icon, &QPushButton::clicked, stats, &event->changeColors());
}

void SettingsWidget::toggleExpand()
{
    setExpanded(!expanded);
}

void SettingsWidget::setExpanded(bool expand)
{
    expanded = expand;

    if (expanded) {
        stacked_widget->setCurrentWidget(expanded_widget);
        setMinimumSize(140, 200);
        setMaximumSize(140, 200);
    } else {
        stacked_widget->setCurrentWidget(collapsed_widget);
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
