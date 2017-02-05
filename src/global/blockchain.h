#ifndef TMC_BLOCKCHAIN_H
#define TMC_BLOCKCHAIN_H

#include <QMatrix4x4>

#include "vec3i.h"
#include "axisvec3i.h"

namespace TMC {

class BlockchainAxisShiftController;
class Scene;

/* Blockchain represents coordinates and dimenstions of a 1x1xN
 * row of blocks by any axis, conveniently packed. Contains at least one block position.*/
class Blockchain {
public:
    Blockchain(Scene *scene, Vec3i basePos, AxisVec3i range);

    Vec3i getBasePos();
    void setBasePos(Vec3i newBasePos);

    AxisVec3i getRange();
    void setRange(AxisVec3i newRange);

    Scene *getScene() const;

private:
    Scene *const m_scene;
    Vec3i m_basePos; // Blockchain has a base block and it occupies some area by one axis specified in m_range
    AxisVec3i m_range;
};

}

#endif // TMC_BLOCKCHAIN_H
