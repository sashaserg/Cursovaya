#-------------------------------------------------
#
# Project created by QtCreator 2016-10-21T16:31:56
#
#-------------------------------------------------

QT       += core gui sql svg
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = VTeatre
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp \
    statistic.cpp \
    optionsforhall.cpp \
    addscene.cpp \
    qcustomplot.cpp \
    scene.cpp \
    finalywindow.cpp \
    dataforstatistic.cpp

HEADERS  += mainwindow.h \
    about.h \
    statistic.h \
    optionsforhall.h \
    addscene.h \
    qcustomplot.h \
    scene.h \
    finalywindow.h \
    dataforstatistic.h

FORMS    += mainwindow.ui \
    about.ui \
    statistic.ui \
    optionsforhall.ui \
    addscene.ui \
    finalywindow.ui

RESOURCES += \
    Resurs1.qrc
