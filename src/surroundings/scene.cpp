#include "scene.h"

namespace TooManyCubes {

Scene::Scene() {
}

void Scene::addBlock(Vec3i pos, BlockType type) {
   this->blocks.emplace(pos, ::std::unique_ptr<Block>(new Block(pos, this->rootEntity, type)));
}

void Scene::removeBlock(Vec3i pos) {
    this->blocks.erase(pos);
}

Qt3DCore::QEntity *Scene::getRootEntity() {
    return &(this->rootEntity);
}

} // namespace TooManyCubes
