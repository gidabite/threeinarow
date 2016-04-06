#include "mainwindowtest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowTest w;

    w.showFullScreen();

    return a.exec();
}
