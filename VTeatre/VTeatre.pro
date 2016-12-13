#-------------------------------------------------
#
# Project created by QtCreator 2016-10-21T16:31:56
#
#-------------------------------------------------

QT       += core gui sql
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = VTeatre
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp \
    windowbuyer.cpp \
    statistic.cpp \
    optionsforhall.cpp \
    addscene.cpp \
    qcustomplot.cpp \
    scene.cpp \
    finalywindow.cpp

HEADERS  += mainwindow.h \
    about.h \
    windowbuyer.h \
    statistic.h \
    optionsforhall.h \
    addscene.h \
    qcustomplot.h \
    scene.h \
    finalywindow.h

FORMS    += mainwindow.ui \
    about.ui \
    windowbuyer.ui \
    statistic.ui \
    optionsforhall.ui \
    addscene.ui \
    finalywindow.ui

RESOURCES += \
    Resurs1.qrc
