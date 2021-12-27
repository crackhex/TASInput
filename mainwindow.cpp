#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)


{

    resize(250, 250);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

}
void MainWindow::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->position().x();
    m_nMouseClick_Y_Coordinate = event->position().y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalPosition().x()-m_nMouseClick_X_Coordinate,event->globalPosition().y()-m_nMouseClick_Y_Coordinate);
}

QSize MainWindow::minimumSizeHint() const
{
    return QSize(100, 100);
}
//! [1]

//! [2]
QSize MainWindow::sizeHint() const
{
    return QSize(400, 200);
}
//! [2]

//! [3]
void MainWindow::setShape(Shape shape)
{
    this->shape = shape;
    update();
}
//! [3]

//! [4]
void MainWindow::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}
//! [4]

//! [5]
void MainWindow::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}
//! [5]

//! [6]
void MainWindow::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}
//! [6]

//! [7]
void MainWindow::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}
//! [7]

//! [8]
void MainWindow::paintEvent(QPaintEvent * /* event */)
{

    QRect rect(10, 10, 80, 80);

    QPainterPath path;

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);


    painter.save();
    painter.drawRect(rect);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

MainWindow::~MainWindow()
{

}
