#include <cmath>
#include <list>

#include "scene.h"
#include "blockanimation.h"
#include "globalfunctions.h"
#include "sceneexception.h"
#include "missingblockexception.h"
#include "lockedblockexception.h"
#include "occupiedposexception.h"
#include "badanimationparams.h"
#include "placeholderblock.h"

namespace TMC {

/* Returns the animation path of a shifted blockchain, excluding starting
 * positions and including end positions (basically where placeholders should be placed). */
Blockchain Scene::getAnimationPath(Blockchain movedBlocks, AxisVec3i shift) {
    // Checking if single-block blockchain, direction wouldn't matter then
    if (movedBlocks.getRange().getValue() == 0) {
        return Blockchain(movedBlocks.getBasePos() + AxisVec3i(shift.getAxis(), GlobalFunctions::sgn(shift.getValue())), shift - 1);
    }

    // Animation could be performed only by axis of blockchain (if it is not a single-block blockchain)
    if (movedBlocks.getRange().getAxis() != shift.getAxis()) {
        throw BadAnimationParams();
    }

    if (GlobalFunctions::sgn(movedBlocks.getRange().getValue()) == GlobalFunctions::sgn(shift.getValue())) {
        // Need to subtract blockchain range from animation shift to get path
        return Blockchain(movedBlocks.getBasePos() + (movedBlocks.getRange() + 1), shift - 1);
    } else {
        // Since basePos of blockchain is leading in direciton of animation, need to subtract only it to get path
        return Blockchain(movedBlocks.getBasePos() + AxisVec3i(shift.getAxis(), 1), shift - 1);
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
    createBlock(0.0, 0.0, 0.0);
    createBlock(1.0, 0.0, 0.0);
    createBlock(2.0, 0.0, 0.0);

    createBlock(1.0, 0.0, 1.0);
    createBlock(1.0, 0.0, -1.0);

    createBlock(1.0, 1.0, 0.0);
    createBlock(1.0, 2.0, 0.0);

    //moveBlock(Vec3i(1.0, 0.0, 1.0), Vec3i(3.0, 0.0, 0.0));

    //animatedMove(Vec3i(2.0, 0.0, 0.0), AxisVec3i(YAXIS, 10));
    animatedMove(Blockchain(Vec3i(1.0, 1.0, 0.0), AxisVec3i(YAXIS, 1)), AxisVec3i(YAXIS, 10));
    animatedMove(Blockchain(Vec3i(0.0, 0.0, 0.0), AxisVec3i(XAXIS, 2)), AxisVec3i(XAXIS, 20));

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

void Scene::createBlockchain(Blockchain blocksToAdd, BlockType type) {
    for (Blockchain::const_iterator it = blocksToAdd.begin(); it != blocksToAdd.end(); ++it) {
        createBlock(*it, type);
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

void Scene::removeBlockchain(Blockchain blocksToRemove) {
    for (Blockchain::const_iterator it = blocksToRemove.begin(); it != blocksToRemove.end(); ++it) {
        removeBlock(*it);
    }
}

void Scene::moveBlock(Vec3i blockPos, Vec3i newBlockPos) {
    if (blockPos == newBlockPos) return;

    if (!hasBlock(blockPos)) throw MissingBlockException(blockPos);

    if (hasBlock(newBlockPos)) throw OccupiedPosException(newBlockPos);

    if (isBlockLocked(blockPos)) throw LockedBlockException(blockPos);

    addBlock(newBlockPos, m_blocksContainer[blockPos]);
    m_blocksContainer.erase(blockPos);
}

void Scene::moveBlockchain(Blockchain blocksToMove, AxisVec3i shift) {
    // Checker
    for (Blockchain::const_iterator it = blocksToMove.begin(); it != blocksToMove.end(); ++it) {
        if (!hasBlock(*it)) throw MissingBlockException(*it);

        if (hasBlock(*it + shift)) throw OccupiedPosException(*it);

        if (isBlockLocked(*it + shift)) throw LockedBlockException(*it);
    }

    std::list<std::shared_ptr<Block>> tempContainer;

    // Removing blocks from scene (but their objects are not deleted)
    for (Blockchain::const_iterator it = blocksToMove.begin(); it != blocksToMove.end(); ++it) {
        tempContainer.push_back(m_blocksContainer[*it]);
        removeBlock(*it);
    }

    // Adding blocks back to scene on new pos
    for (Blockchain::const_iterator it = blocksToMove.begin(); it != blocksToMove.end(); ++it) {
        addBlock(*it + shift, tempContainer.front());
        tempContainer.pop_front();
    }
}

void Scene::animatedMove(Vec3i blockToMove, AxisVec3i animatedShift) {
    animatedMove(Blockchain(blockToMove, AxisVec3i::NO_SHIFT), animatedShift);
}

void Scene::animatedMove(Blockchain blocksToMove, AxisVec3i animatedShift) {            
    if (animatedShift == AxisVec3i::NO_SHIFT) return;

    // Validating animation
    Blockchain animationPath = getAnimationPath(blocksToMove, animatedShift); // Could throw BadAnimationParams

    for (Blockchain::const_iterator it = blocksToMove.begin(); it != blocksToMove.end(); ++it) {
        if (!hasBlock(*it)) throw MissingBlockException(*it);

        if (isBlockLocked(*it)) throw LockedBlockException(*it);
    }

    for (Blockchain::const_iterator it = animationPath.begin(); it != animationPath.end(); ++it) {
        if (hasBlock(*it)) throw OccupiedPosException(*it);
    }


    // Self-destructed animation with cleanup signal
    BlockAnimation *animation = new BlockAnimation(this, blocksToMove, animatedShift, DEFAULT_BLOCK_MOVE_DUR);

    QObject::connect(animation, SIGNAL(cleanupTrigger(Blockchain, AxisVec3i)), SLOT(animationCleanup(Blockchain, AxisVec3i)));

    // Locking blocks
    for (Blockchain::const_iterator it = blocksToMove.begin(); it != blocksToMove.end(); ++it) {
        m_blocksContainer[*it]->setLocked(true);
    }

    // Creating placeholders on animation path to prevent block intersections
    createBlockchain(animationPath, PLACEHOLDER_BLOCK);

    animation->animate();
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

void Scene::animationCleanup(Blockchain movedBlocks, AxisVec3i shift) {
    qDebug() << "Cleaning up animation.";

    Blockchain animationPath = getAnimationPath(movedBlocks, shift);

    // Unlocking placeholders
    for (Blockchain::const_iterator it = animationPath.begin(); it != animationPath.end(); ++it) {
        m_blocksContainer[*it]->setLocked(false);
    }

    // Removing placeholders
    removeBlockchain(getAnimationPath(movedBlocks, shift));

    // Unlocking blocks
    for (Blockchain::const_iterator it = movedBlocks.begin(); it != movedBlocks.end(); ++it) {
        m_blocksContainer[*it]->setLocked(false);
    }

    // Moving blocks positions in scene
    moveBlockchain(movedBlocks, shift);
}

} // namespace TooManyCubes
