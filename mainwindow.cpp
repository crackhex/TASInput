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
    /*static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };*/

    QRect rect(10, 10, 80, 80);

    QPainterPath path;

  /*  int startAngle = 20 * 16;
    int arcLength = 120 * 16; */
//! [8]

//! [9]
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);
//! [9]

//! [10]
    for (int x = 0; x < width(); x += 250) {
        for (int y = 0; y < height(); y += 250) {
            painter.save();
            painter.translate(x, y);
            painter.drawRect(rect);
//! [10] //! [11]

//! [11]

//! [12]
            switch (shape) {
            case Line:
                painter.drawLine(rect.bottomLeft(), rect.topRight());
                break;
            case Rect:
                painter.drawRect(rect);
                break;
            case RoundedRect:
                painter.drawRoundedRect(rect, 25, 25, Qt::RelativeSize);
                break;
            case Ellipse:
                painter.drawEllipse(rect);
                break;
          /*  case Arc:
                painter.drawArc(rect, startAngle, arcLength);
                break;
            case Chord:
                painter.drawChord(rect, startAngle, arcLength);
                break;
            case Pie:
                painter.drawPie(rect, startAngle, arcLength);
                break; */
            case Path:
                painter.drawPath(path);
                break;
            case Pixmap:
                painter.drawPixmap(10, 10, pixmap);
            }
//! [12] //! [13]
            painter.restore();
        }
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

MainWindow::~MainWindow()
{

}
