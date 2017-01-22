#include "phantomblock.h"

namespace TMC {

void PhantomBlock::setPos(Vec3i newDiscretePos) {
    if (m_discretePos == newDiscretePos) return;

    m_discretePos = newDiscretePos;
    m_blockTransform->setTranslation(QVector3D(newDiscretePos.x(), newDiscretePos.y(), newDiscretePos.z()));
}

}
