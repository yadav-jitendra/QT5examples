//
// Created by jitendra on 10.07.21.
//


#include "SpinSlider.h"

SpinSlider::SpinSlider(int const min, int const max, QWidget *parent)
: QWidget(parent){
    slider = new QSlider(Qt::Orientation::Horizontal, this);
    slider->setMinimum(min);
    slider->setMaximum(max);

    box = new QSpinBox( this);
    box->setMinimum(min);
    box->setMaximum(max);

    layout = new QHBoxLayout(this);
    layout->addWidget(slider);
    layout->addWidget(box);

    QObject::connect(slider, &QSlider::valueChanged, box, &QSpinBox::setValue );
    QObject::connect(box, qOverload<int>(&QSpinBox::valueChanged), slider, &QSlider::setValue );
    QObject::connect(slider, &QSlider::valueChanged, this, &SpinSlider::stateChanged );
}

void SpinSlider::stateChanged() {
    emit valueChanged(slider->value());
}

void SpinSlider::setValueTo50() {
    slider->setValue(50); /// or,  because both are connected
    //box->setValue(50);
}


