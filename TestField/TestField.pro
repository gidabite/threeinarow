#-------------------------------------------------
#
# Project created by QtCreator 2016-02-21T14:31:04
#
#-------------------------------------------------

QT       += core gui declarative

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestField
TEMPLATE = app


SOURCES += main.cpp\
        mainwindowtest.cpp \
    field.cpp \
    cell.cpp \
    levelcontroller.cpp \
    cellbutton.cpp \
    random.cpp \
    imagecontroller.cpp

HEADERS  += mainwindowtest.h \
    field.h \
    cell.h \
    levelcontroller.h \
    cellbutton.h \
    imagecontroller.h

FORMS    += mainwindowtest.ui


RESOURCES += \
    res.qrc

DISTFILES +=
