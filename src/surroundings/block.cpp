#include "block.h"
#include "globalmaterials.h"

namespace TooManyCubes {

Qt3DExtras::QCuboidMesh Block::blockMesh;

Block::Block(Vec3i pos, Qt3DCore::QEntity &parent, BlockType type)
    : type(type) {

    this->blockTransform.setScale(1.0);
    this->blockTransform.setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0, 0, 0), 0.0f));
    this->blockTransform.setTranslation(QVector3D(pos.x(), pos.y(), pos.z()));

    this->blockEntity.addComponent(&(this->blockTransform));
    this->blockEntity.addComponent(&(this->blockMesh));
    this->blockEntity.addComponent(dynamic_cast<Qt3DCore::QComponent *>(&(GlobalMaterials::DEFAULT_MATERIAL)));

    this->blockEntity.setParent(&parent);
}

}
