QT += core gui

INCLUDEPATH += $$PWD

include(quickactionspanel/quickactionspanel.pri)

SOURCES += \
    $$PWD/mainwindow.cpp \
    $$PWD/toolspanel.cpp

HEADERS += \
    $$PWD/mainwindow.h \
    $$PWD/toolspanel.h

