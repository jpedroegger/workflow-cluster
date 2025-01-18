#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QStyle>


class SettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void toggleExpand();

private:
    bool expanded;

    QStackedWidget *stackedWidget;
    QWidget *collapsedWidget;
    QWidget *expandedWidget;

    QPushButton *mainIcon;
    QPushButton *icon1;
    QPushButton *icon2;


    void setExpanded(bool expand);
    bool isClickOutside(const QPoint &pos) const;
};
#endif
