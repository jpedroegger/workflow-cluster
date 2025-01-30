#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QStyle>
#include "../includes/EventManager.h"

class SettingsWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit       SettingsWidget(QWidget *parent, EventManager &event,
                                      int x = 0, int y = 0, int width = 0, int height = 0);

    protected:
        void           mousePressEvent(QMouseEvent *event) override;

    private slots:
        void           toggleExpand();

    private:
        bool           expanded;

        QStackedWidget *stacked_widget;
        QWidget        *collapsed_widget;
        QWidget        *expanded_widget;

        QPushButton    *main_icon;
        QPushButton    *close_icon;
        QPushButton    *themes_icon;
        QPushButton    *change_unit_icon;
        EventManager   &event;

        bool           setButtonIcon(QPushButton *button, const QString &imagePath);
        void           setExpanded(bool expand);
        bool           isClickOutside(const QPoint &pos) const;
};

#endif
