#include <QApplication>
#include "mapwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MapWidget mw;
    mw.setWindowTitle("GNSS widget environment");
    mw.resize(640,480);
    mw.show();

    return a.exec();
}
