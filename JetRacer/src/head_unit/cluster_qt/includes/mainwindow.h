#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


/**
 * @brief The MainWindow class represents the main window of the application.
 *
 * @details This class inherits from QMainWindow and serves as the primary interface for the application.
 * It manages the user interface components defined in the Ui::MainWindow namespace.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
    
    private:
        Ui::MainWindow *ui;
};
#endif
