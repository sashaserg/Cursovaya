#-------------------------------------------------
#
# Project created by QtCreator 2016-10-21T16:31:56
#
#-------------------------------------------------

QT       += core gui sql

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
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    about.h \
    windowbuyer.h \
    statistic.h \
    optionsforhall.h \
    addscene.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    about.ui \
    windowbuyer.ui \
    statistic.ui \
    optionsforhall.ui \
    addscene.ui

RESOURCES += \
    Resurs1.qrc
