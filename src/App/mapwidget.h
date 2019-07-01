#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <mapcontrol.h>
#include <osmmapadapter.h>
#include <maplayer.h>

using namespace qmapcontrol;

class MapWidget : public QWidget
{
    Q_OBJECT

    MapControl* mc;
    MapAdapter* mapadapter;
    Layer* mainlayer;

public:

    explicit MapWidget(QWidget *parent = nullptr);
    ~MapWidget();

signals:

public slots:

    void updatePosition(QPointF coordinate);
    void zoomIn();
    void zoomOut();

protected:

    virtual void resizeEvent ( QResizeEvent * event );
};

#endif // MAPWIDGET_H
