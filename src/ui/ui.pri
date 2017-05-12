QT += core gui

INCLUDEPATH += $$PWD

include(quickactionstabs/quickactionstabs.pri)

SOURCES += \
    $$PWD/mainwindow.cpp \
    $$PWD/quickactionspanel.cpp \
    $$PWD/toolspanel.cpp

HEADERS += \
    $$PWD/mainwindow.h \
    $$PWD/quickactionspanel.h \
    $$PWD/toolspanel.h

