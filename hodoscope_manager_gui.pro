#-------------------------------------------------
#
# Project created by QtCreator 2018-02-07T12:40:03
#
#-------------------------------------------------

QT       += core gui sql widgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = hodoscope_manager_gui
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
        mainwindow.cpp\
        qcustomplot.cpp \
    serialmanager.cpp \
    wifimanager.cpp \
    gatedialog.cpp \
    npointsdialog.cpp \
    azimuthdialog.cpp \
    polardialog.cpp \
    distancedialog.cpp \
    data.cpp \
    buffer.cpp \
    datamanager.cpp

HEADERS  += mainwindow.h\
            qcustomplot.h \
    serialmanager.h \
    wifimanager.h \
    gatedialog.h \
    npointsdialog.h \
    azimuthdialog.h \
    polardialog.h \
    distancedialog.h \
    data.h \
    buffer.h \
    datamanager.h

FORMS    += mainwindow.ui \
    gatedialog.ui \
    npointsdialog.ui \
    azimuthdialog.ui \
    polardialog.ui \
    distancedialog.ui
