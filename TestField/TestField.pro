#-------------------------------------------------
#
# Project created by QtCreator 2016-02-21T14:31:04
#
#-------------------------------------------------

QT       += core gui quick multimedia

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
    imagecontroller.cpp \
    hero/hero.cpp \
    hero/hunter.cpp \
    hero/mage.cpp \
    hero/warrior.cpp \
    herobutton.cpp

HEADERS  += mainwindowtest.h \
    field.h \
    cell.h \
    levelcontroller.h \
    cellbutton.h \
    imagecontroller.h \
    hero/hero.h \
    hero/hunter.h \
    hero/mage.h \
    hero/warrior.h \
    herobutton.h

FORMS    += mainwindowtest.ui


RESOURCES += \
    res.qrc \
    music.qrc \
    settings.qrc \
    ffff.qrc

DISTFILES += \
    ../Users/Павел/Desktop/TestField/Cell.qml \
    Field.qml \
    Cell.qml
