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

//class BlockAnimation;

/* Block is an atomic unit of surrounding in the game. */
class Block {

    //friend class BlockAnimation;
public:
    static constexpr float BLOCK_LENGTH = 1.0f; // Scene global atomic length unit

    static Vec3i worldToDiscreteCoordinates(QVector3D worldCoordinates);
    static QVector3D discreteToWorldCoordinates(Vec3i discreteCoordinates);

public:
    Block(Qt3DCore::QEntity *parent, BlockType type = DEFAULT_BLOCK); // Hided object constructor (no pos)
    Block(Vec3i discretePos, Qt3DCore::QEntity *parent, BlockType type = DEFAULT_BLOCK, bool isHided = BLOCK_VISIBLE);
    virtual ~Block();

    BlockType getBlockType() const;
    bool isHided() const;
    void setHided(bool hided);

    Vec3i getDiscretePos() const;
    void setDiscretePos(Vec3i newDiscretePos);

protected:
    const BlockType m_type;
    Vec3i m_discretePos;

    bool m_hided;

    Qt3DCore::QEntity *m_blockEntity;
    Qt3DCore::QTransform *m_blockTransform;

private:
    void updateTranslation();

    Qt3DExtras::QCuboidMesh *m_blockMesh;
    Qt3DRender::QMaterial *m_blockMaterial;
};

}

#endif // TMC_BLOCK_H
