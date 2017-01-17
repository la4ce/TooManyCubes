#include "block.h"
#include "customalphaphong.h"

namespace TooManyCubes {

Block::Block(Vec3i pos, Qt3DCore::QEntity *parent, BlockType type)
    : type(type)
    , blockMesh(new Qt3DExtras::QCuboidMesh())
    , blockEntity(new Qt3DCore::QEntity())
    , blockTransform(new Qt3DCore::QTransform())
    , blockMaterial(nullptr) {

    this->blockTransform->setScale(1.0);
    this->blockTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0, 0, 0), 0.0f));
    this->blockTransform->setTranslation(QVector3D(pos.x(), pos.y(), pos.z()));

    this->blockEntity->addComponent(this->blockTransform);
    this->blockEntity->addComponent(this->blockMesh);

    switch (type) {
        case DEFAULT_BLOCK:
            this->blockMaterial = new Qt3DExtras::QPhongMaterial();
            break;
        case DEFAULT_TRANSP_BLOCK:
            this->blockMaterial = new CustomAlphaPhong();
            break;
        default:
            this->blockMaterial = new Qt3DExtras::QPhongMaterial();
    }

    this->blockEntity->addComponent(this->blockMaterial);


    this->blockEntity->setParent(parent);
}

Block::~Block() {
    if (blockEntity != nullptr) {
        // Deleting automatically notifies QEnity's parents and all connections
        // that it was deleted in QNode and QObject destructors
        delete blockEntity;
    }
}

}
