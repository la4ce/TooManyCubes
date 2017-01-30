#ifndef TMC_SCENE_H
#define TMC_SCENE_H

#include <unordered_map>

#include "block.h"
#include "axisvec3i.h"

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

class Blockchain;

typedef std::unordered_map<Vec3i, std::unique_ptr<Block>> BlocksContainer;

/* Scene - holds and maintains blocks.
 * Nothing except for a block is expected to be an object. */
class Scene {
public:
    static constexpr float DEFAULT_BLOCK_MOVE_DUR = 0.5;
    static const AxisVec3i NO_SHIFT;

public:
    Scene();
    ~Scene();

    void initScene();

    bool hasBlock(Vec3i pos) const;

    void addBlock(int x, int y, int z, BlockType type = DEFAULT_BLOCK);
    void addBlock(Vec3i pos, BlockType type = DEFAULT_BLOCK);
    // TODO: void addBlockchain(Blockchain blocksToAdd, BlockType type = DEFAULT_BLOCK);

    void removeBlock(int x, int y, int z);
    void removeBlock(Vec3i pos);
    // TODO: void removeBlockchain(Blockchain blocksToRemove);

    void moveBlock(Vec3i blockPos, Vec3i newBlockPos);
    // TODO: void moveBlockchain(Blockchain blocksToMove, AxisVec3i shift);

    void animatedMove(Vec3i blockToMove, AxisVec3i animatedShift);
    void animatedMove(Blockchain blocksToMove, AxisVec3i animatedShift);

    bool blockCouldBePlaced(Vec3i pos) const;
    bool blockCouldBeRemoved(Vec3i pos) const;

    // TODO: void blockchainCouldBePlaced(Blockchain blocksToPlace);
    // TODO: void blockchainCouldBeRemoved(Blockchain blocksToRemove);
    // TODO: void blockchainCouldBeMoved(Blockchain blocksToMove, AxisVec3i shift);

    Qt3DCore::QEntity* getRootEntity();

private:
    Scene(const Scene &s) = delete;
    const Scene& operator=(const Scene& s) = delete;

    Qt3DCore::QEntity* m_rootEntity;
    BlocksContainer m_blocksContainer;
};

} // namespace TooManyCubes

#endif // TMC_SCENE_H
