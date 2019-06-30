#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent) : QWidget(parent)
{

    mc = new MapControl(QSize(380, 540));
    mapadapter = new OSMMapAdapter();
    mainlayer = new MapLayer("OpenStreetMap-Layer", mapadapter);

    mc->showScale(true);
    mc->addLayer(mainlayer);
    mc->setView(QPointF(30.281671, 59.894273));
    mc->setZoom(17);

}

MapWidget::~MapWidget()
{

}

void MapWidget::resizeEvent ( QResizeEvent * event )
{
//    mc->resize(event->size());
    mc->resize(size());
}
