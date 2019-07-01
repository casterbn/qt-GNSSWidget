#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent) : QWidget(parent)
{
    if (parent == nullptr)
        setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

    mMc = new MapControl(QSize(380, 540));
    mMapadapter = new OSMMapAdapter();
    mMainlayer = new MapLayer("OpenStreetMap-Layer", mMapadapter);

    mMc->addLayer(mMainlayer);
    mMc->enableMouseWheelEvents(false);
    mMc->setMouseMode(MapControl::None);
    mMc->showScale(true);
    mMc->setView(QPointF(30.281671, 59.894273));
    mMc->setZoom(17);

    QStackedLayout* layout = new QStackedLayout;
    layout->addWidget(mMc);
    setLayout(layout);
    points.append(new CirclePoint(30.281661, 59.893163, "Mainz, Bauhofstraße LRP", Point::Middle));
    points.append(new ImagePoint(30.281671, 59.894273, "helm3.png", "Mainz, Hauptbahnhof", Point::BottomMiddle));
//    points.append(new CirclePoint(30.282771, 59.894273, "Mainz, Landtag", Point::Middle));
//    points.append(new CirclePoint(30.283881, 59.895383, "Mainz, Brückenkopf", Point::Middle));
    QPen* linepen = new QPen(QColor(0, 0, 0, 0));
    linepen->setWidth(0);
    LineString* ls = new LineString(points, "Busline 54", linepen);
    mMainlayer->addGeometry(ls);
}

MapWidget::~MapWidget()
{
    delete mMc;
    delete mMapadapter;
    delete mMainlayer;
}

void MapWidget::resizeEvent (QResizeEvent* event)
{
    mMc->resize(event->size());
}

void MapWidget::updatePosition(QPointF coordinate)
{
    mMc->setView(coordinate);
}

void MapWidget::setZoom(int zoom)
{
    mMc->setZoom(zoom);
}

void MapWidget::zoomIn()
{
    if (mMc->currentZoom() < 17)
        mMc->zoomIn();
}
void MapWidget::zoomOut()
{
    if (mMc->currentZoom() > 2)
        mMc->zoomOut();
}

//void MapWidget::keyPressEvent(QKeyEvent* evnt)
//{
//    qDebug() << evnt->key() << endl;
//}

void MapWidget::testSlot()
{
    qDebug() << "cleared";
    points.clear();
}
