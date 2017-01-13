#ifndef TMC_BLOCK_H
#define TMC_BLOCK_H

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>

namespace TooManyCubes {

enum BlockType {
    DEFAULT_BLOCK = 1 // More types of blocks will be added with materials
};

/* Block is an atomic unit of surrounding in the game. */
class Block {
public:
    Block(QVector3D pos, Qt3DCore::QEntity &parent, BlockType type);

private:
    const BlockType type;
    const QVector3D pos;

    Qt3DCore::QEntity blockEntity;

    static Qt3DExtras::QCuboidMesh blockMesh;
    Qt3DCore::QTransform blockTransform;

    // Future experiments
    // bool isCollidable;
    // bool isGravityAffected;
    // bool isLiquid;
};

}

#endif // TMC_BLOCK_H
