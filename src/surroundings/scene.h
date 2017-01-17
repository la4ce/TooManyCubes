#ifndef TMC_SCENE_H
#define TMC_SCENE_H

#include <unordered_map>

#include "block.h"
#include "vec3i.h"

namespace std {
template <>
struct hash<TooManyCubes::Vec3i> {
    size_t operator()(const TooManyCubes::Vec3i& v) const {
        size_t h1 = std::hash<int>()(v.x());
        size_t h2 = std::hash<int>()(v.y());
        size_t h3 = std::hash<int>()(v.z());
        return (h1 ^ (h2 << 1)) ^ (h3 << 2);
    }
};
} // namespace std

namespace TooManyCubes {

typedef std::unordered_map<Vec3i, std::unique_ptr<Block>> BlocksContainer;

/* Scene - holds and maintains blocks.
 * Nothing except for a block is expected to be an object. */
class Scene {
public:
    static Scene& getInstance() {
        static Scene instance;
        return instance;
    }

    void addBlock(Vec3i pos, BlockType type = DEFAULT_BLOCK);
    void removeBlock(Vec3i pos);

    Qt3DCore::QEntity* getRootEntity();

private:
    Scene();
    ~Scene();

    Scene(const Scene &s) = delete;
    const Scene& operator=(const Scene& s) = delete;

    Qt3DCore::QEntity* m_rootEntity;
    BlocksContainer m_blocksContainer;
};

} // namespace TooManyCubes

#endif // TMC_SCENE_H
