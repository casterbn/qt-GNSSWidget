#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlag(Qt::FramelessWindowHint, true);

    mc = new MapControl(QSize(380, 540));
    mapadapter = new OSMMapAdapter();
    mainlayer = new MapLayer("OpenStreetMap-Layer", mapadapter);

    mc->addLayer(mainlayer);
    mc->enableMouseWheelEvents(false);
    mc->setMouseMode(MapControl::None);
    mc->showScale(true);
    mc->setView(QPointF(30.281671, 59.894273));
    mc->setZoom(17);

    setCentralWidget(mc);
}

MainWindow::~MainWindow()
{
//    delete mMapWidget;
}

void MainWindow::resizeEvent ( QResizeEvent * event )
{
    mc->resize(event->size());
}

void MainWindow::updatePosition(QPointF coordinate)
{
    mc->setView(coordinate);
}

void MainWindow::zoomIn()
{
    if (mc->currentZoom() < 17)
        mc->zoomIn();
}
void MainWindow::zoomOut()
{
    if (mc->currentZoom() > 2)
        mc->zoomOut();
}
