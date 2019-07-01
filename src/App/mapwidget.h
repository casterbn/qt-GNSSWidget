#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QStackedLayout>

#include <mapcontrol.h>
#include <osmmapadapter.h>
#include <maplayer.h>
#include <imagepoint.h>
#include <circlepoint.h>
#include <linestring.h>

using namespace qmapcontrol;

class MapWidget : public QWidget
{
    Q_OBJECT

    MapControl* mMc;
    MapAdapter* mMapadapter;
    Layer* mMainlayer;

    QList<Point*> points;

public:

    explicit MapWidget(QWidget *parent = nullptr);
    ~MapWidget();

signals:

public slots:

    void updatePosition(QPointF coordinate);
    void setZoom(int zoom);
    void zoomIn();
    void zoomOut();
//    void keyPressEvent(QKeyEvent* evnt);

    void testSlot();

protected:

    virtual void resizeEvent ( QResizeEvent * event );
};

#endif // MAPWIDGET_H
