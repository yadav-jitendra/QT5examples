//
// Created by jitendra on 11.07.21.
//

#include "MyCanvas.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QPainter>
#include <QBrush>


MyCanvas::MyCanvas(QWidget *parent)
: QWidget(parent){
    this->setWindowTitle("My Canvas Program");
}

void MyCanvas::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Escape){
        if(QMessageBox::question(this,"Exit","Exit sure?") == QMessageBox::Yes){
            this->topLevelWidget()->close();
        }
    }
}

void MyCanvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.fillRect(this->rect(), QBrush(Qt::lightGray));   // fill whole canvas

    painter.setPen(Qt::black);

    painter.setBrush(QBrush(Qt::red, Qt::BrushStyle::CrossPattern));   // with color pattern
    painter.drawEllipse(250, 10, 100, 80);

    painter.setBrush(QBrush(Qt::darkMagenta));// change brush for all next coming shape
    painter.drawEllipse(400, 10, 100, 80);


    drawTriangle(painter);  /// eigene shape

    painter.save();
    for (int i = 0; i < 500; ++i) {
        painter.translate(1,1);  /// shifts painter
        painter.setPen(QColor(i*0.2, 0, 0));
        drawTriangle(painter);
    }
    painter.restore();


    for (auto pos: mouseClickedPos) {
        painter.setBrush(QColor(Qt::darkMagenta));
        painter.drawRect(QRect(pos - QPoint(5, 5), pos + QPoint(5,5)));
    }

    //painter.rotate(90);    // rotate by 90 degree

}

void MyCanvas::drawTriangle(QPainter & painter) {
    painter.drawLine(50, 0, 0 , 50);
    painter.drawLine(0,50, 100,50);
    painter.drawLine(100,50,50, 0);
}

void MyCanvas::mouseReleaseEvent(QMouseEvent *event) {
    mouseClickedPos.push_back(event->pos());
    update();
}
