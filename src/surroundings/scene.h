#ifndef TMC_SCENE_H
#define TMC_SCENE_H

#include <unordered_map>

#include "block.h"

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

public:
    Scene();
    ~Scene();

    void initScene();

    bool hasBlock(Vec3i pos) const;
    bool isBlockLocked(Vec3i pos);

    void addBlock(Vec3i newBlockPos, std::shared_ptr<Block> existentBlock);

    void createBlock(int x, int y, int z, BlockType type = DEFAULT_BLOCK);
    void createBlock(Vec3i pos, BlockType type = DEFAULT_BLOCK);

    std::shared_ptr<Block> getBlock(int x, int y, int z);
    std::shared_ptr<Block> getBlock(Vec3i pos);

    void removeBlock(int x, int y, int z);
    void removeBlock(Vec3i pos);

    void moveBlock(Vec3i blockPos, Vec3i newBlockPos);

    bool blockCouldBePlacedManually(Vec3i pos);
    bool blockCouldBeRemovedManually(Vec3i pos);

    Qt3DCore::QEntity* getRootEntity();

private:
    Scene(const Scene &s) = delete;
    const Scene& operator=(const Scene& s) = delete;

    Qt3DCore::QEntity* m_rootEntity;
    BlocksContainer m_blocksContainer;

};

} // namespace TooManyCubes

#endif // TMC_SCENE_H
