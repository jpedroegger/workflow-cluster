#include "../includes/mainwindow.h"
#include "./ui_mainwindow.h"

/**
 * @brief Constructs a MainWindow with the specified parent.
 *
 * @param parent The parent widget.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * @brief Destroys the MainWindow.
 *
 * This destructor cleans up the user interface components.
 */
MainWindow::~MainWindow()
{
    delete ui;
}
