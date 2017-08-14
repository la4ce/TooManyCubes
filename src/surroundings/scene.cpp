#include <cmath>
#include <list>

#include "scene.h"
#include "globalfunctions.h"
#include "sceneexception.h"
#include "missingblockexception.h"
#include "lockedblockexception.h"
#include "occupiedposexception.h"
#include "placeholderblock.h"

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

    qDebug() << "Scene destroyed.";
}

void Scene::initScene() {
    createBlock(0.0, 0.0, 0.0);
    createBlock(1.0, 0.0, 0.0);
    createBlock(2.0, 0.0, 0.0);

    createBlock(1.0, 0.0, 1.0);
    createBlock(1.0, 0.0, -1.0);

    createBlock(1.0, 1.0, 0.0);
    createBlock(1.0, 2.0, 0.0);

    //moveBlock(Vec3i(1.0, 0.0, 1.0), Vec3i(3.0, 0.0, 0.0));
    //removeBlock(Vec3i(1.0, 1.0, 0.0));
}

bool Scene::hasBlock(Vec3i pos) const {
    return !(m_blocksContainer.find(pos) == m_blocksContainer.end());
}

bool Scene::isBlockLocked(Vec3i pos) {
    if (!hasBlock(pos)) return false;

    return m_blocksContainer[pos]->isLocked();
}

void Scene::addBlock(Vec3i newBlockPos, std::shared_ptr<Block> existentBlock) {
    if (hasBlock(newBlockPos)) throw OccupiedPosException(newBlockPos);

    m_blocksContainer.emplace(newBlockPos, existentBlock);
    m_blocksContainer[newBlockPos]->setDiscretePos(newBlockPos);
}

void Scene::createBlock(int x, int y, int z, BlockType type) {
    createBlock(Vec3i(x, y, z), type);
}

void Scene::createBlock(Vec3i pos, BlockType type) {
    if (hasBlock(pos)) throw OccupiedPosException(pos);

    switch (type) {
        case PLACEHOLDER_BLOCK:
            m_blocksContainer.emplace(pos, std::shared_ptr<Block>(new PlaceholderBlock(pos, m_rootEntity)));
            break;
        default:
            m_blocksContainer.emplace(pos, std::shared_ptr<Block>(new Block(pos, m_rootEntity, type)));
            break;
    }
}

std::shared_ptr<Block> Scene::getBlock(int x, int y, int z) {
    return getBlock(Vec3i(x, y, z));
}

std::shared_ptr<Block> Scene::getBlock(Vec3i pos) {
    if (!hasBlock(pos)) throw MissingBlockException(pos);

    return m_blocksContainer[pos];
}

void Scene::removeBlock(int x, int y, int z) {
    removeBlock(Vec3i(x, y, z));
}

void Scene::removeBlock(Vec3i pos) {
    if (!hasBlock(pos)) throw MissingBlockException(pos);

    if (m_blocksContainer[pos]->isLocked()) throw LockedBlockException(pos);

    m_blocksContainer.erase(pos);
}

void Scene::moveBlock(Vec3i blockPos, Vec3i newBlockPos) {
    if (blockPos == newBlockPos) return;

    if (!hasBlock(blockPos)) throw MissingBlockException(blockPos);

    if (hasBlock(newBlockPos)) throw OccupiedPosException(newBlockPos);

    if (isBlockLocked(blockPos)) throw LockedBlockException(blockPos);

    addBlock(newBlockPos, m_blocksContainer[blockPos]);
    m_blocksContainer.erase(blockPos);
}

/* We are able to place a block only if there is no block at pos
 * and if there are face-adjacent blocks nearby. Manually - means via input controller. */
bool Scene::blockCouldBePlacedManually(Vec3i pos) {
    const int CHECK_NUM = 7;
    const Vec3i shifts[] = { Vec3i(-1, 0, 0), Vec3i(1, 0, 0), // x face-adjacent
                             Vec3i(0, -1, 0), Vec3i(0, 1, 0), // y face-adjacent
                             Vec3i(0, 0, -1), Vec3i(0, 0, 1)  // z face-adjacent
                           };

    if (hasBlock(pos)) return false;

    for (int i = 0; i < CHECK_NUM; i++) {
        if (hasBlock(pos + shifts[i]) &&
                m_blocksContainer[pos + shifts[i]]->getBlockType() != PLACEHOLDER_BLOCK) return true;
    }

    return false;
}

// Manually - means via input controller.
bool Scene::blockCouldBeRemovedManually(Vec3i pos) {
    return hasBlock(pos) && !m_blocksContainer[pos]->isLocked();
}

Qt3DCore::QEntity *Scene::getRootEntity() {
    return m_rootEntity;
}

} // namespace TooManyCubes
