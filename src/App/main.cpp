#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mw;
    mw.setWindowTitle("GNSS Widget");
    mw.resize(640, 480);
    mw.show();

    return a.exec();
}
