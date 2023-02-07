#include "mainwindow.h"

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFixedSize(325, 183);
    w.setWindowTitle("Audio Player");
    return a.exec();

}
