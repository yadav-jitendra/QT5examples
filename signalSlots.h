//
// Created by jitendra on 10.07.21.
//

#ifndef QT5EXAMPLES_SIGNALSLOTS_H
#define QT5EXAMPLES_SIGNALSLOTS_H

#include <QApplication>
#include <QPushButton>
#include <iostream>

#include "signalSlots.h"


void output(){
    std::cout << "Function"<< std::endl;
}

class NonQTClass{
public:
    void memberOutput() const{
        std::cout << "Member"<< std::endl;

    }
};

void setupConnection(QPushButton const & button, NonQTClass const & nonqt){
    QObject::connect(&button, &QPushButton::clicked, &output);

    QObject::connect(&button, &QPushButton::clicked, [](){ std::cout << "Lambda"<< std::endl; });

    QObject::connect(&button, &QPushButton::clicked, [&](){ nonqt.memberOutput(); });

}

void main_signalslots(){

    QPushButton button("Hello world QT5!", nullptr);
    button.resize(200, 100);
    button.show();

    NonQTClass nonQt;
    setupConnection(button, nonQt);

}


#endif //QT5EXAMPLES_SIGNALSLOTS_H
