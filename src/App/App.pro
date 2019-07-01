#include(../QMapControl/QMapControl.pri)

QT += \
    gui \
    network \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): cache()

TARGET = GNSSWidget
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

LIBS += -L../bin -lqmapcontrol

INCLUDEPATH += ../QMapControl

HEADERS += \
    mainwindow.h \

SOURCES += \
    main.cpp \
    mainwindow.cpp \

# Default rules for deployment.
target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
