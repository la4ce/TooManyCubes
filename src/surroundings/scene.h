#ifndef TMC_SCENE_H
#define TMC_SCENE_H

#include <unordered_map>

#include "block.h"
#include "axisvec3i.h"
#include "blockchain.h"

namespace std {
template <>
struct hash<TMC::Vec3i> {
    size_t operator()(const TMC::Vec3i& v) const {
        size_t h1 = std::hash<int>()(v.x());
        size_t h2 = std::hash<int>()(v.y());
        size_t h3 = std::hash<int>()(v.z());
        return (h1 ^ (h2 << 1)) ^ (h3 << 2);
    }
};
} // namespace std

namespace TMC {

typedef std::unordered_map<Vec3i, std::shared_ptr<Block>> BlocksContainer;

/* Scene - holds and maintains blocks.
 * Nothing except for a block is expected to be an object. */
class Scene : public QObject {
    Q_OBJECT

public:
    static constexpr float DEFAULT_BLOCK_MOVE_DUR = 0.25f * 1000.0f; // in milliseconds
    static Blockchain getAnimationPath(Blockchain movedBlocks, AxisVec3i shift);

public:
    Scene();
    ~Scene();

    void initScene();

    bool hasBlock(Vec3i pos) const;

    void addBlock(int x, int y, int z, BlockType type = DEFAULT_BLOCK);
    void addBlock(Vec3i pos, BlockType type = DEFAULT_BLOCK);
    void addBlockchain(Blockchain blocksToAdd, BlockType type = DEFAULT_BLOCK);

    std::shared_ptr<Block> getBlock(int x, int y, int z);
    std::shared_ptr<Block> getBlock(Vec3i pos);

    void removeBlock(int x, int y, int z);
    void removeBlock(Vec3i pos);
    void removeBlockchain(Blockchain blocksToRemove);

    void moveBlock(Vec3i blockPos, Vec3i newBlockPos);
    void moveBlockchain(Blockchain blocksToMove, AxisVec3i shift);

    // TODO: void Scene::animatedMove(Vec3i blockToMovePos, Vec3i newPos);
    void animatedMove(Vec3i blockToMove, AxisVec3i animatedShift);
    void animatedMove(Blockchain blocksToMove, AxisVec3i animatedShift);

    bool blockCouldBePlaced(Vec3i pos) const;
    bool blockCouldBeRemoved(Vec3i pos);

    // TODO: void blockchainCouldBePlaced(Blockchain blocksToPlace);
    // TODO: void blockchainCouldBeRemoved(Blockchain blocksToRemove);

    Qt3DCore::QEntity* getRootEntity();

private:
    Scene(const Scene &s) = delete;
    const Scene& operator=(const Scene& s) = delete;

    Qt3DCore::QEntity* m_rootEntity;
    BlocksContainer m_blocksContainer;

private slots:
    void animationCleanup(Blockchain movedBlocks, AxisVec3i shift);
};

} // namespace TooManyCubes

#endif // TMC_SCENE_H
