#include <cmath>
#include "scene.h"
#include "blockanimation.h"
#include "globalfunctions.h"

namespace TMC {

Blockchain Scene::getAnimationPath(Blockchain movedBlocks, AxisVec3i shift) {
    if (movedBlocks.getRange().getValue() == 0) {
        // Single block, direction doesn't matter
        return Blockchain(movedBlocks.getBasePos() + AxisVec3i(shift.getAxis(), GlobalFunctions::sgn(shift.getValue())), shift - 1);
    } else {
        if (movedBlocks.getRange().getAxis() != shift.getAxis()) {
            // EXCEPTION REQUIRED
        }

        if (GlobalFunctions::sgn(movedBlocks.getRange().getValue()) == GlobalFunctions::sgn(shift.getValue())) {
            // Need to subtract blockchain range from animation shift to get path
            return Blockchain(movedBlocks.getBasePos() + (movedBlocks.getRange() + 1), shift - 1);
        } else {
            // Since basePos of blockchain is leading in direciton of animation, need to subtract only it to get path
            return Blockchain(movedBlocks.getBasePos() + AxisVec3i(shift.getAxis(), 1), shift - 1);
        }
    }
}

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
    addBlock(0.0, 0.0, 0.0);
    addBlock(1.0, 0.0, 0.0);
    addBlock(2.0, 0.0, 0.0);
    addBlock(1.0, 0.0, 1.0);
    addBlock(1.0, 0.0, -1.0);
    addBlock(1.0, 1.0, 0.0);

    moveBlock(Vec3i(1.0, 0.0, 1.0), Vec3i(3.0, 0.0, 0.0));

    animatedMove(Vec3i(2.0, 0.0, 0.0), AxisVec3i(YAXIS, 10));
    animatedMove(Vec3i(1.0, 1.0, 0.0), AxisVec3i(XAXIS, -10));

    //removeBlock(Vec3i(1.0, 1.0, 0.0));
}

bool Scene::hasBlock(Vec3i pos) const {
    return !(m_blocksContainer.find(pos) == m_blocksContainer.end());
}

void Scene::addBlock(int x, int y, int z, BlockType type) {
    this->addBlock(Vec3i(x, y, z), type);
}

void Scene::addBlock(Vec3i pos, BlockType type) {
    // Inserts new block only if no block in pos
    m_blocksContainer.emplace(pos, std::unique_ptr<Block>(new Block(pos, m_rootEntity, type))); // Redirect to addBlockchain
}

void Scene::addBlockchain(Blockchain blocksToAdd, BlockType type) {
    // EXCEPTION REQUIRED
    for (Blockchain::const_iterator it = blocksToAdd.begin(); it != blocksToAdd.end(); ++it) {
        this->addBlock(*it, type);
    }
}

std::shared_ptr<Block> Scene::getBlock(int x, int y, int z) {
    // EXCEPTION REQUIRED
    return this->getBlock(Vec3i(x, y, z));
}

std::shared_ptr<Block> Scene::getBlock(Vec3i pos) {
    // EXCEPTION REQUIRED
    return m_blocksContainer[pos];
}

void Scene::removeBlock(int x, int y, int z) {
    // EXCEPTION REQUIRED
    this->removeBlock(Vec3i(x, y, z));
}

void Scene::removeBlock(Vec3i pos) {
    // EXCEPTION REQUIRED
    m_blocksContainer.erase(pos);
}

void Scene::removeBlockchain(Blockchain blocksToRemove) {
    // EXCEPTION REQUIRED
    for (Blockchain::const_iterator it = blocksToRemove.begin(); it != blocksToRemove.end(); ++it) {
        this->removeBlock(*it);
    }
}

void Scene::moveBlock(Vec3i blockPos, Vec3i newBlockPos) {
    // EXCEPTION REQUIRED
    if (!this->hasBlock(blockPos)) {
        qDebug() << "Trying to move a nonexistent block: " << blockPos;
        return;
    }

    if (this->hasBlock(newBlockPos)) {
        qDebug() << "Trying to move a block to an occupied position: " << newBlockPos;
        return;
    }

    m_blocksContainer.emplace(newBlockPos, m_blocksContainer[blockPos]);
    m_blocksContainer[blockPos]->setDiscretePos(newBlockPos);
    m_blocksContainer.erase(blockPos);
}

void Scene::moveBlockchain(Blockchain blocksToMove, AxisVec3i shift) {
    // TODO: need a complex checker (as a part of TMC::Scene) of occupied blocks and destination for all blocks to move via blockchainCouldBeMoved
    // EXCEPTION REQUIRED: occupied blocks (OccupiedPositionException); no blocks to move(BlocksAbsenceException)
    this->moveBlock(blocksToMove.getBasePos(), shift + blocksToMove.getBasePos());
}

void Scene::animatedMove(Vec3i blockToMove, AxisVec3i animatedShift) {
    animatedMove(Blockchain(blockToMove, AxisVec3i::NO_SHIFT), animatedShift);
}

void Scene::animatedMove(Blockchain blocksToMove, AxisVec3i animatedShift) {
    // TODO: need a complex checker (as a part of TMC::Scene) of occupied blocks, path, and destination for all blocks to move
    // TODO: need to check that we are moving by axis of blockchain
    // EXCEPTION REQUIRED
    // self-destructed animation with cleanup signal
    BlockAnimation *animation = new BlockAnimation(this, blocksToMove, animatedShift, DEFAULT_BLOCK_MOVE_DUR);

    QObject::connect(animation, SIGNAL(cleanupTrigger(Blockchain, AxisVec3i)), SLOT(animationCleanup(Blockchain,AxisVec3i)));

    this->addBlockchain(getAnimationPath(blocksToMove, animatedShift), PLACEHOLDER_BLOCK);

    animation->animate();


    // TODO: freeze all blocks while animating and add placeholder blocks to animation end
}

/* We are able to place a block only if there is no block at pos
 * and if there are face-adjacent blocks nearby. */
bool Scene::blockCouldBePlaced(Vec3i pos) const {
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
    return hasBlock(pos) && !m_blocksContainer[pos]->isLocked();
}

Qt3DCore::QEntity* Scene::getRootEntity() {
    return m_rootEntity;
}

void Scene::animationCleanup(Blockchain movedBlocks, AxisVec3i shift) {
    qDebug() << "Cleaning up animation.";

    // Removing placeholders
    this->removeBlockchain(getAnimationPath(movedBlocks, shift));

    // Moving blocks positions in scene
    this->moveBlockchain(movedBlocks, shift);
}

} // namespace TooManyCubes
