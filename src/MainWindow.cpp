#include "MainWindow.h"

#include "chord.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    Ui_MainWindow ui;
    ui.setupUi(this);
}

MainWindow::~MainWindow()
{
}
