#ifndef TMC_BLOCK_H
#define TMC_BLOCK_H

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>

#include "vec3i.h"

namespace TMC {

enum BlockType {
    DEFAULT_BLOCK = 1,
    DEFAULT_TRANSP_BLOCK,
    PHANTOM_BLOCK
};

enum HidedState {
    BLOCK_HIDED = true,
    BLOCK_VISIBLE = false
};

/* Block is an atomic unit of surrounding in the game. */
class Block {
public:
    Block(Qt3DCore::QEntity *parent, BlockType type = DEFAULT_BLOCK);
    Block(Vec3i discretePos, Qt3DCore::QEntity *parent, BlockType type = DEFAULT_BLOCK, bool isHided = BLOCK_VISIBLE);
    ~Block();

    BlockType getBlockType();
    void setPos(Vec3i newPos);
    bool isHided();
    void setHided(bool hided);

protected:
    const BlockType m_type;
    Vec3i m_discretePos;

    bool m_hided;

    Qt3DCore::QEntity *m_blockEntity;
    Qt3DCore::QTransform *m_blockTransform;

private:
    Qt3DExtras::QCuboidMesh *m_blockMesh;
    Qt3DRender::QMaterial *m_blockMaterial;
};

}

#endif // TMC_BLOCK_H
