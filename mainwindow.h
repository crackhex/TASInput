#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include <qevent.h>
=======
#include <QMouseEvent>
#include <QPoint>
>>>>>>> c889c926649ede570ac315bb57a5c62ecef83df3

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    virtual void mousePressEvent(QMouseEvent* evt);
    virtual void mouseReleaseEvent(QMouseEvent* evt);
    virtual void mouseMoveEvent(QMouseEvent* evt);

private:
    Ui::MainWindow *ui;
    bool moving;
    QPoint oldPos;
};
#endif // MAINWINDOW_H
