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

    switch (type) {
        case DEFAULT_BLOCK:
            this->blockEntity.addComponent(&(GlobalMaterials::DEFAULT_MATERIAL));
            break;
        case DEFAULT_TRANSP_BLOCK:
            this->blockEntity.addComponent(&(GlobalMaterials::DEFAULT_TRANSP_MATERIAL));
            break;
    }

    this->blockEntity.setParent(&parent);
}

}
