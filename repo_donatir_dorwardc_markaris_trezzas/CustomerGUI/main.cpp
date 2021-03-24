#include "mainwindow.h"
#include "beechimes.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();*/
    BeeChimes bc;
    bc.show();

    return a.exec();
}
