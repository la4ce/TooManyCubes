#include "scene.h"

namespace TMC {

Scene::Scene() {
    this->m_rootEntity = new Qt3DCore::QEntity();
}

Scene::~Scene() {
    // Parent QEntity, should be destroyed
    if (this->m_rootEntity != nullptr && this->m_rootEntity->parent() == nullptr) {
        delete m_rootEntity;
    }
}

void Scene::addBlock(Vec3i pos, BlockType type) {
   this->m_blocksContainer.emplace(pos, ::std::unique_ptr<Block>(new Block(pos, this->m_rootEntity, type)));
}

void Scene::removeBlock(Vec3i pos) {
    this->m_blocksContainer.erase(pos);
}

Qt3DCore::QEntity* Scene::getRootEntity() {
    return this->m_rootEntity;
}

} // namespace TooManyCubes
