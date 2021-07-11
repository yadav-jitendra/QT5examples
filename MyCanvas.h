//
// Created by jitendra on 11.07.21.
//

#ifndef QT5EXAMPLES_MYCANVAS_H
#define QT5EXAMPLES_MYCANVAS_H

#include <QWidget>
#include <vector>

class MyCanvas : public QWidget{
    Q_OBJECT
signals:


public slots:


public:
    MyCanvas(QWidget* parent);

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void paintEvent(QPaintEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void drawTriangle(QPainter & painter);
    std::vector<QPoint> mouseClickedPos;
};


#endif //QT5EXAMPLES_MYCANVAS_H
