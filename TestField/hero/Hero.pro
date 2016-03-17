QT += core
QT -= gui

CONFIG += c++11

TARGET = Hero
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    hero.cpp \
    mage.cpp \
    warrior.cpp \
    hunter.cpp

HEADERS += \
    hero.h \
    mage.h \
    warrior.h \
    hunter.h
