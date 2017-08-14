QT += core gui 3dcore 3drender 3dinput 3dextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(src/surroundings/surroundings.pri)
include(src/global/global.pri)
include(src/materials/materials.pri)
include(src/player/player.pri)
include(src/exceptions/exceptions.pri)
include(src/ui/ui.pri)

SOURCES += \
    src/main.cpp \

RESOURCES += \
    resources/res.qrc

DISTFILES +=

