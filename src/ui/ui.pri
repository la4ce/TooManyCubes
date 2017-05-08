QT += core gui

INCLUDEPATH += $$PWD

include(quickactionstabs/quickactionstabs.pri)

SOURCES += \
    $$PWD/mainwindow.cpp \
    $$PWD/quickactionspanel.cpp

HEADERS += \
    $$PWD/mainwindow.h \
    $$PWD/quickactionspanel.h

