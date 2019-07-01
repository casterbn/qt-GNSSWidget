#include <QApplication>
#include <QTimer>

#include "mapwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MapWidget mw;
    mw.setWindowTitle("GNSS widget environment");
    mw.resize(640,480);
    mw.show();

    QTimer::singleShot(1000, &mw, SLOT(testSlot()));

    return a.exec();
}
