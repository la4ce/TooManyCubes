#ifndef TMC_BLOCK_H
#define TMC_BLOCK_H

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>

#include "vec3i.h"

namespace TooManyCubes {

enum BlockType {
    DEFAULT_BLOCK = 1,
    DEFAULT_TRANSP_BLOCK
};

/* Block is an atomic unit of surrounding in the game. */
class Block {
public:
    Block(Vec3i pos, Qt3DCore::QEntity *parent, BlockType type);
    ~Block();

private:
    const BlockType type;
    const Vec3i pos;

    static Qt3DExtras::QCuboidMesh *blockMesh;

    Qt3DCore::QEntity *blockEntity;
    Qt3DCore::QTransform *blockTransform;
};

}

#endif // TMC_BLOCK_H
