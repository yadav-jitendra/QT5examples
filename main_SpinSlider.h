//
// Created by jitendra on 11.07.21.
//

#ifndef QT5EXAMPLES_MAIN_SPINSLIDER_H
#define QT5EXAMPLES_MAIN_SPINSLIDER_H

#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>
#include <QFileDialog>


void main_Spinslider(){
    QWidget window;

    SpinSlider* spinSlider = new SpinSlider(0, 100, &window);      /// eigene Widget !!!
    spinSlider->show();

    QLabel* label = new QLabel("The value is : 0", &window );

    QPushButton* button = new QPushButton("Set to 50", &window);


    QHBoxLayout* layout = new QHBoxLayout(&window);
    layout->addWidget(spinSlider);
    layout->addWidget(label);
    layout->addWidget(button);

    QObject::connect(spinSlider, &SpinSlider::valueChanged, [&](int val){ label->setText(QString("The value is : ") + QString::number(val)); }); ///own signal :valueChanged
    QObject::connect(button, &QPushButton::clicked, spinSlider, &SpinSlider::setValueTo50);

    window.show();
}
#endif //QT5EXAMPLES_MAIN_SPINSLIDER_H
