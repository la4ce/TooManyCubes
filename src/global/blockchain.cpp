#include "blockchain.h"
#include "blockchainanimationcontroller.h"
#include "scene.h"

namespace TMC {

Blockchain::Blockchain(Scene *scene, Vec3i basePos, AxisVec3i range)
    : m_scene(scene)
    , m_basePos(basePos)
    , m_range(range) {
}

Vec3i Blockchain::getBasePos() {
    return m_basePos;
}

void Blockchain::setBasePos(Vec3i newBasePos) {
    m_basePos = newBasePos;
}

AxisVec3i Blockchain::getRange() {
    return m_range;
}

void Blockchain::setRange(AxisVec3i newRange) {
    m_range = newRange;
}

Scene *Blockchain::getScene() const {
    return m_scene;
}

}
