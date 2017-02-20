#ifndef TMC_BLOCK_H
#define TMC_BLOCK_H

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QMesh>
#include <Qt3DRender/QMaterial>
#include <Qt3DExtras/QCuboidMesh>

#include "vec3i.h"

namespace TMC {

enum BlockType {
    DEFAULT_BLOCK = 1,
    DEFAULT_TRANSP_BLOCK,
    PHANTOM_BLOCK,
    PLACEHOLDER_BLOCK
};

enum HidedState {
    BLOCK_VISIBLE = false,
    BLOCK_HIDED = true
};

enum LockedState {
    BLOCK_UNLOCKED = false,
    BLOCK_LOCKED = true
};

class BlockAnimationController;

/* Block is an atomic unit of surrounding in the game. */
class Block : public QObject {
    Q_OBJECT

    Q_PROPERTY(bool hided READ isHided WRITE setHided NOTIFY hidedChanged)
    Q_PROPERTY(bool locked READ isLocked WRITE setLocked NOTIFY lockedChanged)

    friend class BlockAnimationController;

public:
    static constexpr float BLOCK_LENGTH = 1.0f; // Scene global atomic length unit

    static Vec3i worldToDiscreteCoordinates(QVector3D worldCoordinates);
    static QVector3D discreteToWorldCoordinates(Vec3i discreteCoordinates);

public:
    Block(Vec3i discretePos, Qt3DCore::QEntity *parent, BlockType type = DEFAULT_BLOCK, HidedState isHided = BLOCK_VISIBLE, LockedState isLocked = BLOCK_UNLOCKED);
    virtual ~Block();

    BlockType getBlockType() const;
    bool isHided() const;
    void setHided(bool hided);

    bool isLocked() const;
    void setLocked(bool isLocked);

    Vec3i getDiscretePos() const;
    void setDiscretePos(Vec3i newDiscretePos);

protected:
    const BlockType m_type;
    Vec3i m_discretePos;

    bool m_hided;
    bool m_locked;

    Qt3DCore::QEntity *m_blockEntity;
    Qt3DCore::QTransform *m_blockTransform;

private:

    void translateFromBasePos(QMatrix4x4 translMatr); // Only for animations, otherwise discretePos and transform's translation shouldn't diverge

    Qt3DExtras::QCuboidMesh *m_blockMesh;
    Qt3DRender::QMaterial *m_blockMaterial;

private slots:
    void updateScale();
    void updateBaseTranslation();

signals:
    void hidedChanged();
    void lockedChanged();
};

}

#endif // TMC_BLOCK_H
