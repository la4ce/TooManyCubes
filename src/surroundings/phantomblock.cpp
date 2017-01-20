#include "phantomblock.h"

namespace TMC {

void PhantomBlock::setPos(Vec3i newPos) {
    if (m_discretePos == newPos) return;

    m_discretePos = newPos;
    // TODO: need to properly convert between standard and discrete spaces, not just 1:1
    m_blockTransform->setTranslation(QVector3D(newPos.x(), newPos.y(), newPos.z()));
}


}
