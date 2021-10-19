#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <cstdlib>
#include <qnamespace.h>

using std::cout;
using std::getenv;

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Qt::WindowFlags wt = Qt::Window;
    #ifdef Q_OS_LINUX
    // wayland is wack, we HAVE to have the title bar, else we can't move it
    if (!getenv("WAYLAND_DISPLAY")) {
        wt |= Qt::FramelessWindowHint;
    }
    #else
    wt |= Qt::FramelessWindowHint;
    #endif
    setWindowFlags(wt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::mousePressEvent(QMouseEvent* evt)
{
    moving = true;
    oldPos = evt->globalPos();
}

void
MainWindow::mouseMoveEvent(QMouseEvent* evt)
{
    if (moving) {
        const QPoint delta = evt->globalPos() - oldPos;
        cout << "Moving: (" << delta.x() << ", " << delta.y() << ")\n";
        move(x() + delta.x(), y() + delta.y());
        oldPos = evt->globalPos();
    }
}

void
MainWindow::mouseReleaseEvent(QMouseEvent* evt)
{
    oldPos = evt->globalPos();
    moving = false;
}