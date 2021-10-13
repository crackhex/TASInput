#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#ifdef Q_OS_WIN
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

