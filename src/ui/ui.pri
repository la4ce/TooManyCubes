INCLUDEPATH += $$PWD

include(quickactionspanel/quickactionspanel.pri)
include(colorselectorpanel/colorselectorpanel.pri)

SOURCES += \
    $$PWD/mainwindow.cpp \
    $$PWD/toolspanel.cpp

HEADERS += \
    $$PWD/mainwindow.h \
    $$PWD/toolspanel.h

