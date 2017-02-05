#include <Qt3DExtras/QPhongMaterial>

#include <cmath>

#include "block.h"
#include "customalphaphong.h"
#include "phantommaterial.h"

namespace TMC {

Block::Block(Vec3i discretePos, Qt3DCore::QEntity *parent, BlockType type, bool isHided)
    : m_type(type)
    , m_discretePos(discretePos)
    , m_hided(isHided)
    , m_blockEntity(new Qt3DCore::QEntity())
    , m_blockTransform(nullptr)
    , m_blockMesh(nullptr)
    , m_blockMaterial(nullptr) {

    m_blockEntity->setParent(parent);

    if (type != PLACEHOLDER_BLOCK) {
        m_blockTransform = new Qt3DCore::QTransform();
        m_blockMesh = new Qt3DExtras::QCuboidMesh();

        this->updateScale();
        this->updateTranslation();

        m_blockTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0, 0, 0), 0.0f));

        switch (type) {
            case DEFAULT_BLOCK:
                m_blockMaterial = new Qt3DExtras::QPhongMaterial();
                break;
            case DEFAULT_TRANSP_BLOCK:
                m_blockMaterial = new CustomAlphaPhong();
                break;
            case PHANTOM_BLOCK:
                m_blockMaterial = new PhantomMaterial();
                break;
        }

        m_blockEntity->addComponent(m_blockTransform);
        m_blockEntity->addComponent(m_blockMesh);
        m_blockEntity->addComponent(m_blockMaterial);
    }

    qDebug() << "Block created:" << m_discretePos << "\tType:" << m_type;
}

Block::~Block() {
    if (m_blockEntity != nullptr) {
        // Deleting automatically notifies QEnity's parents and all connections
        // that it was deleted in QNode and QObject destructors
        delete m_blockEntity;
    }
    qDebug() << "Block destroyed:" << m_discretePos << "\tType:" << m_type;
}


Vec3i Block::worldToDiscreteCoordinates(QVector3D worldCoordinates) {
    return Vec3i(round(worldCoordinates.x() / BLOCK_LENGTH),
                 round(worldCoordinates.y() / BLOCK_LENGTH),
                 round(worldCoordinates.z() / BLOCK_LENGTH));
}

QVector3D Block::discreteToWorldCoordinates(Vec3i discreteCoordinates) {
    return QVector3D(discreteCoordinates.x() * BLOCK_LENGTH,
                     discreteCoordinates.y() * BLOCK_LENGTH,
                     discreteCoordinates.z() * BLOCK_LENGTH);
}


BlockType Block::getBlockType() const {
    return m_type;
}

bool Block::isHided() const {
    return m_hided;
}

void Block::setHided(bool hided) {
    if (m_hided == hided) return;

    m_hided = hided;

    // TODO: make this a method that is notified when m_hided changes
    updateScale();
}

Vec3i Block::getDiscretePos() const {
    return m_discretePos;
}

void Block::setDiscretePos(Vec3i newDiscretePos) {
    if (m_discretePos == newDiscretePos) return;

    m_discretePos = newDiscretePos;
    updateTranslation();
}

void Block::translateFromPos(QMatrix4x4 translMatr) {
    if (m_blockTransform == nullptr) return;

    updateTranslation();
    m_blockTransform->setMatrix(m_blockTransform->matrix() * translMatr);
}

void Block::updateScale() {
    if (m_blockTransform == nullptr) return;

    const float transfScale = m_hided ? 0.0f : 1.0f;
    m_blockTransform->setScale(transfScale);
}

// TODO: make this function notified when m_discretePos changed. Safer.
void Block::updateTranslation() {
    if (m_blockTransform == nullptr) return;

    QVector3D newTranslation = this->discreteToWorldCoordinates(m_discretePos);
    m_blockTransform->setTranslation(newTranslation);
}

}
