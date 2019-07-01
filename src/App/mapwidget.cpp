#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent) : QWidget(parent)
{
    if (parent == nullptr)
        setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

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
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(mc);
    setLayout(layout);
}

MapWidget::~MapWidget()
{
    delete mc;
    delete mapadapter;
    delete mainlayer;
}

void MapWidget::resizeEvent ( QResizeEvent * event )
{
    mc->resize(event->size());
}

void MapWidget::updatePosition(QPointF coordinate)
{
    mc->setView(coordinate);
}

void MapWidget::setZoom(int zoom)
{
    mc->setZoom(zoom);
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
