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

void Scene::initScene() {
    addBlock(0.0, 0.0, 0.0);
    addBlock(1.0, 0.0, 0.0);
    addBlock(2.0, 0.0, 0.0);
    addBlock(1.0, 0.0, 1.0);
    addBlock(1.0, 0.0, -1.0);
    addBlock(1.0, 1.0, 0.0);

    moveBlock(Vec3i(1.0, 1.0, 0.0), Vec3i(2.0, 2.0, 0.0));

    //removeBlock(Vec3i(1.0, 1.0, 0.0));
}

bool Scene::hasBlock(Vec3i pos) {
    return !(m_blocksContainer.find(pos) == m_blocksContainer.end());
}

void Scene::addBlock(int x, int y, int z, BlockType type) {
    this->addBlock(Vec3i(x, y, z), type);
}

void Scene::addBlock(Vec3i pos, BlockType type) {
    // Inserts new block only if no block in pos
    m_blocksContainer.emplace(pos, std::unique_ptr<Block>(new Block(pos, m_rootEntity, type)));
}

void Scene::removeBlock(int x, int y, int z) {
    this->removeBlock(Vec3i(x, y, z));
}

void Scene::removeBlock(Vec3i pos) {
    m_blocksContainer.erase(pos);
}

void Scene::moveBlock(Vec3i blockPos, Vec3i newBlockPos) {
    if (!this->hasBlock(blockPos)) {
        qDebug() << "Trying to move a nonexistent block: " << blockPos.x() << " " << blockPos.y() << " " << blockPos.z() << endl; // TODO: overload qDebug() << operator and use it
        return;
    }

    if (this->hasBlock(newBlockPos)) {
        qDebug() << "Trying to move a block to an occupied position: " << newBlockPos.x() << " " << newBlockPos.y() << " " << newBlockPos.z() << endl; // TODO: overload qDebug() << operator and use it
        return;
    }

    std::unique_ptr<Block> tempPtr = std::move(m_blocksContainer[blockPos]);
    tempPtr->setDiscretePos(newBlockPos);
    m_blocksContainer.erase(blockPos);
    m_blocksContainer.emplace(newBlockPos, std::move(tempPtr));
}

void Scene::animatedMove(Vec3i blockPos, Vec3i shift) {
    if (!this->hasBlock(blockPos)) {
        qDebug() << "Trying to animate movement of a nonexistent block: " << blockPos.x() << " " << blockPos.y() << " " << blockPos.z() << endl; // TODO: overload qDebug() << operator and use it
        return;
    }

    if (abs(shift.x() / shift.x()) + abs(shift.y() / shift.y()) + abs(shift.z() / shift.z())) {
        qDebug() << "Trying to move block on more than one axis: " << blockPos.x() << " " << blockPos.y() << " " << blockPos.z() << endl; // TODO: overload qDebug() << operator and use it
        return;
    }
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
