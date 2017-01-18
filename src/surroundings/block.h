#ifndef TMC_BLOCK_H
#define TMC_BLOCK_H

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>

#include "vec3i.h"

namespace TMC {

enum BlockType {
    DEFAULT_BLOCK = 1,
    DEFAULT_TRANSP_BLOCK
};

/* Block is an atomic unit of surrounding in the game. */
class Block {
public:
    Block(Vec3i discretePos, Qt3DCore::QEntity *parent, BlockType type);
    ~Block();

    BlockType getBlockType();
private:
    const BlockType m_type;
    const Vec3i m_discretePos;

    Qt3DExtras::QCuboidMesh *m_blockMesh;
    Qt3DCore::QEntity *m_blockEntity;
    Qt3DCore::QTransform *m_blockTransform;
    Qt3DRender::QMaterial *m_blockMaterial;
};

}

#endif // TMC_BLOCK_H
