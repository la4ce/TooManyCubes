#include <cmath>
#include "scene.h"

namespace TMC {

Scene::Scene() {
    m_rootEntity = new Qt3DCore::QEntity();
    initScene();
}

Scene::~Scene() {
    // Parent QEntity, should be destroyed
    if (m_rootEntity != nullptr && m_rootEntity->parent() == nullptr) {
        delete m_rootEntity;
    }
}

Vec3i Scene::worldToDiscreteCoordinates(QVector3D worldCoordinates) {
    return Vec3i(round(worldCoordinates.x() / BLOCK_EDGE_LENGTH),
                 round(worldCoordinates.y() / BLOCK_EDGE_LENGTH),
                 round(worldCoordinates.z() / BLOCK_EDGE_LENGTH));
}

QVector3D Scene::discreteToWorldCoordinates(Vec3i discreteCoordinates) {
    return QVector3D(discreteCoordinates.x() * BLOCK_EDGE_LENGTH,
                     discreteCoordinates.y() * BLOCK_EDGE_LENGTH,
                     discreteCoordinates.z() * BLOCK_EDGE_LENGTH);
}

void Scene::initScene() {
    addBlock(Vec3i(0.0, 0.0, 0.0));
    addBlock(Vec3i(1.0, 0.0, 0.0));
    addBlock(Vec3i(2.0, 0.0, 0.0));
    addBlock(Vec3i(1.0, 0.0, 1.0));
    addBlock(Vec3i(1.0, 0.0, -1.0));
    addBlock(Vec3i(1.0, 1.0, 0.0));

    //removeBlock(Vec3i(0.0, 0.0, 0.0));
}

void Scene::addBlock(Vec3i pos, BlockType type) {
    // Inserts new block only if no block in pos
   m_blocksContainer.emplace(pos, ::std::unique_ptr<Block>(new Block(pos, m_rootEntity, type)));
}

void Scene::removeBlock(Vec3i pos) {
    m_blocksContainer.erase(pos);
}

Qt3DCore::QEntity* Scene::getRootEntity() {
    return m_rootEntity;
}

} // namespace TooManyCubes
