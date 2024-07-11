#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include "ui_main.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

};

#endif