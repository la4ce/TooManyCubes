#include "block.h"
#include "customalphaphong.h"

namespace TooManyCubes {

Block::Block(Vec3i discretePos, Qt3DCore::QEntity *parent, BlockType type)
    : m_type(type)
    , m_discretePos(discretePos)
    , m_blockMesh(new Qt3DExtras::QCuboidMesh())
    , m_blockEntity(new Qt3DCore::QEntity())
    , m_blockTransform(new Qt3DCore::QTransform())
    , m_blockMaterial(nullptr) {

    this->m_blockTransform->setScale(1.0);
    this->m_blockTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0, 0, 0), 0.0f));
    this->m_blockTransform->setTranslation(QVector3D(discretePos.x(), discretePos.y(), discretePos.z()));

    this->m_blockEntity->addComponent(this->m_blockTransform);
    this->m_blockEntity->addComponent(this->m_blockMesh);

    switch (type) {
        case DEFAULT_BLOCK:
            this->m_blockMaterial = new Qt3DExtras::QPhongMaterial();
            break;
        case DEFAULT_TRANSP_BLOCK:
            this->m_blockMaterial = new CustomAlphaPhong();
            break;
        default:
            this->m_blockMaterial = new Qt3DExtras::QPhongMaterial();
    }

    this->m_blockEntity->addComponent(this->m_blockMaterial);


    this->m_blockEntity->setParent(parent);
}

Block::~Block() {
    if (m_blockEntity != nullptr) {
        // Deleting automatically notifies QEnity's parents and all connections
        // that it was deleted in QNode and QObject destructors
        delete m_blockEntity;
    }
}

}
