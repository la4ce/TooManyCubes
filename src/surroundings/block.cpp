#include "block.h"
#include "customalphaphong.h"
#include "phantommaterial.h"

namespace TMC {

// Block created and attached to scene, but hided (no position specified)
Block::Block(Qt3DCore::QEntity* parent, BlockType type)
    :Block(Vec3i(0, 0, 0), parent, type, true) {
}

Block::Block(Vec3i discretePos, Qt3DCore::QEntity* parent, BlockType type, bool isHided)
    : m_type(type)
    , m_discretePos(discretePos)
    , m_hided(isHided)
    , m_blockMesh(new Qt3DExtras::QCuboidMesh())
    , m_blockEntity(new Qt3DCore::QEntity())
    , m_blockTransform(new Qt3DCore::QTransform())
    , m_blockMaterial(nullptr) {

    if (m_hided) {
        m_blockTransform->setScale(0.0);
    } else {
        m_blockTransform->setScale(1.0);
    }

    m_blockTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0, 0, 0), 0.0f));
    m_blockTransform->setTranslation(QVector3D(discretePos.x(), discretePos.y(), discretePos.z()));

    m_blockEntity->addComponent(m_blockTransform);
    m_blockEntity->addComponent(m_blockMesh);

    switch (type) {
        case DEFAULT_BLOCK:
            m_blockMaterial = new Qt3DExtras::QPhongMaterial();
            break;
        case DEFAULT_TRANSP_BLOCK:
            m_blockMaterial = new CustomAlphaPhong();
            break;
        case PHANTOM_BLOCK:
            m_blockMaterial = new PhantomMaterial();
        default:
            m_blockMaterial = new Qt3DExtras::QPhongMaterial();
    }

    m_blockEntity->addComponent(m_blockMaterial);


    m_blockEntity->setParent(parent);
}

Block::~Block() {
    if (m_blockEntity != nullptr) {
        // Deleting automatically notifies QEnity's parents and all connections
        // that it was deleted in QNode and QObject destructors
        delete m_blockEntity;
    }
}

BlockType Block::getBlockType() {
    return m_type;
}

void Block::setPos(Vec3i newPos) {
    m_discretePos = newPos;
}

bool Block::isHided() {
    return m_hided;
}


}
