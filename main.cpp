#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>
#include <QFileDialog>

#include "signalSlots.h"
#include "SpinSlider.h"
#include "fileDialog.h"
#include "MyCanvas.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MyCanvas* canvas = new MyCanvas(nullptr);
    canvas->show();
    //canvas->showFullScreen();

    return QApplication::exec();
}
