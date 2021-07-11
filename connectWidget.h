//
// Created by jitendra on 10.07.21.
//

#ifndef QT5EXAMPLES_CONNECTWIDGET_H
#define QT5EXAMPLES_CONNECTWIDGET_H

#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

void connectWidget(){
    QWidget window;

    int const min = 0;
    int const max = 100;

    QSlider slider;
    slider.setMinimum(min);
    slider.setMaximum(max);
    slider.show();

    QSpinBox box;
    box.setMinimum(min);
    box.setMaximum(max);
    box.show();

    QHBoxLayout layout(&window);
    layout.addWidget(&slider);
    layout.addWidget(&box);

    window.show();

    QObject::connect(&slider, &QSlider::valueChanged, &box, &QSpinBox::setValue );
    QObject::connect(&box, qOverload<int>(&QSpinBox::valueChanged), &slider, &QSlider::setValue );

    SpinSlider spinslider(0, 100);
    spinslider.show();
}
#endif //QT5EXAMPLES_CONNECTWIDGET_H
