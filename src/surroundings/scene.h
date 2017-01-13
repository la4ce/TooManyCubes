#ifndef TMC_BLOCKS_SCENE_H
#define TMC_BLOCKS_SCENE_H

#include "block.h"
#include <unordered_map>
#include <vector>

namespace std {
template <>
struct hash<QVector3D> {
    size_t operator()(const QVector3D& v) const {
        size_t h1 = std::hash<float>()(v.x()); // Don't like hash from float and QVector3D usage because of that,
        size_t h2 = std::hash<float>()(v.y()); // will implement own int 3 vector soon.
        size_t h3 = std::hash<float>()(v.z());
        return (h1 ^ (h2 << 1)) ^ (h3 << 2); // Good enough, eh?
    }
};
} // namespace std

namespace TooManyCubes {

typedef std::unordered_map<QVector3D, std::unique_ptr<Block>> BlocksContainer;

/* BlocksScene - holds and maintains blocks.
 * Nothing except for a block is expected to be an object. */
class Scene {
public:
    Scene(); //TODO: singleton

    void addBlock(QVector3D pos, BlockType type = DEFAULT_BLOCK);
    void removeBlock(QVector3D pos);

    Qt3DCore::QEntity *getRootEntity();

private:
    Qt3DCore::QEntity rootEntity;
    BlocksContainer blocks;
};

} // namespace TooManyCubes

#endif // TMC_BLOCKS_SCENE_H
