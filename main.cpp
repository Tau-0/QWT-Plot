#include "mainwindow.h"

#include <QApplication>

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.run_test();
    return a.exec();
}
