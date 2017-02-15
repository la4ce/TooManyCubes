QT += 3dcore 3drender 3dinput 3dextras

include(src/surroundings/surroundings.pri)
include(src/surroundings/blocks/blocks.pri)
include(src/global/global.pri)
include(src/materials/materials.pri)
include(src/player/player.pri)
include(src/animation/animation.pri)
include(src/exceptions/exceptions.pri)

SOURCES += \
    src/main.cpp \

