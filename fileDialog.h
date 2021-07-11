//
// Created by jitendra on 11.07.21.
//

#ifndef QT5EXAMPLES_FILEDIALOG_H
#define QT5EXAMPLES_FILEDIALOG_H

#include <QFileDialog>

void openFile(){
    auto filename = QFileDialog::getOpenFileName(); /// open filedialog
    std::cout << filename.toStdString() << std::endl;
}
#endif //QT5EXAMPLES_FILEDIALOG_H
