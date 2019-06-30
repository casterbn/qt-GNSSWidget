#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mapcontrol.h>
#include <osmmapadapter.h>
#include <maplayer.h>

using namespace qmapcontrol;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    MapControl* mc;
    MapAdapter* mapadapter;
    Layer* mainlayer;

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

public slots:

    void updatePosition(QPointF coordinate);
    void zoomIn();
    void zoomOut();

protected:

    virtual void resizeEvent ( QResizeEvent * event );
};

#endif // MAINWINDOW_H
