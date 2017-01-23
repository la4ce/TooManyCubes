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

bool Scene::hasBlock(Vec3i pos) {
    return !(m_blocksContainer.find(pos) == m_blocksContainer.end());
}

void Scene::addBlock(Vec3i pos, BlockType type) {
    // Inserts new block only if no block in pos
   m_blocksContainer.emplace(pos, ::std::unique_ptr<Block>(new Block(pos, m_rootEntity, type)));
}

void Scene::removeBlock(Vec3i pos) {
    m_blocksContainer.erase(pos);
}

/* We can place block only if there is no block at pos
 * and if there are face-adjacent blocks nearby. */
bool Scene::blockCouldBePlaced(Vec3i pos) {
    const int CHECK_NUM = 7;
    const Vec3i shifts[] = { Vec3i(-1, 0, 0), Vec3i(1, 0, 0), // x face-adjacent
                             Vec3i(0, -1, 0), Vec3i(0, 1, 0), // y face-adjacent
                             Vec3i(0, 0, -1), Vec3i(0, 0, 1)  // z face-adjacent
                           };

    if (this->hasBlock(pos)) return false;

    for (int i = 0; i < CHECK_NUM; i++) {
        if (this->hasBlock(pos + shifts[i])) return true;
    }

    return false;
}

bool Scene::blockCouldBeRemoved(Vec3i pos) {
    // May be additional restrictions in the future
    return hasBlock(pos);
}

Qt3DCore::QEntity* Scene::getRootEntity() {
    return m_rootEntity;
}

} // namespace TooManyCubes
