#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent) : QWidget(parent)
{

    mc = new MapControl(QSize(380, 540));
    mapadapter = new OSMMapAdapter();
    mainlayer = new MapLayer("OpenStreetMap-Layer", mapadapter);

    mc->addLayer(mainlayer);
    mc->enableMouseWheelEvents(false);
    mc->setMouseMode(MapControl::None);
    mc->showScale(true);
    mc->setView(QPointF(30.281671, 59.894273));
    mc->setZoom(17);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(mc);
    setLayout(layout);
}

MapWidget::~MapWidget()
{

}

void MapWidget::resizeEvent ( QResizeEvent * event )
{
    mc->resize(event->size());
//    mc->resize(size());
}

void MapWidget::updatePosition(QPointF coordinate)
{
    mc->setView(coordinate);
}

void MapWidget::zoomIn()
{
    if (mc->currentZoom() < 17)
        mc->zoomIn();
}
void MapWidget::zoomOut()
{
    if (mc->currentZoom() > 2)
        mc->zoomOut();
}
