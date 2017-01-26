#ifndef TMC_SCENE_H
#define TMC_SCENE_H

#include <unordered_map>

#include "block.h"
#include "vec3i.h"

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

typedef std::unordered_map<Vec3i, std::unique_ptr<Block>> BlocksContainer;

/* Scene - holds and maintains blocks.
 * Nothing except for a block is expected to be an object. */
class Scene {
public:
    static constexpr float BLOCK_EDGE_LENGTH = 1.0f; // Scene global atomic length unit
    static Vec3i worldToDiscreteCoordinates(QVector3D worldCoordinates);
    static QVector3D discreteToWorldCoordinates(Vec3i discreteCoordinates);

public:
    Scene();
    ~Scene();

    void initScene();

    bool hasBlock(Vec3i pos);

    void addBlock(int x, int y, int z, BlockType type = DEFAULT_BLOCK);
    void addBlock(Vec3i pos, BlockType type = DEFAULT_BLOCK);

    void removeBlock(int x, int y, int z);
    void removeBlock(Vec3i pos);

    void moveBlock(Vec3i blockPos, Vec3i newBlockPos);

    void animatedMove(Vec3i blockPos, Vec3i shift);

    bool blockCouldBePlaced(Vec3i pos);
    bool blockCouldBeRemoved(Vec3i pos);

    Qt3DCore::QEntity* getRootEntity();

private:
    Scene(const Scene &s) = delete;
    const Scene& operator=(const Scene& s) = delete;

    Qt3DCore::QEntity* m_rootEntity;
    BlocksContainer m_blocksContainer;
};

} // namespace TooManyCubes

#endif // TMC_SCENE_H
