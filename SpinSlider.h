//
// Created by jitendra on 10.07.21.
//

#ifndef QT5EXAMPLES_SPINSLIDER_H
#define QT5EXAMPLES_SPINSLIDER_H

#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

class SpinSlider  : public QWidget {
    Q_OBJECT
public:
    SpinSlider(int const min, int const max, QWidget *parent);

signals:
    int valueChanged(int val);  ///signal value changed will be send

public slots:
    void setValueTo50(); /// own slot

private:
    QSpinBox* box;      /// alle member sind als Zeiger deklariert
    QSlider* slider;
    QHBoxLayout* layout;

    void stateChanged();    /// signal will be send when state changes
};


#endif //QT5EXAMPLES_SPINSLIDER_H
