#ifndef TMC_BLOCKCHAIN_H
#define TMC_BLOCKCHAIN_H

#include <QMatrix4x4>

#include "vec3i.h"
#include "axisvec3i.h"

namespace TMC {

class BlockAnimationController;
class Scene;

/* Blockchain represents coordinates and dimenstions of a 1x1xN
 * row of blocks by any axis, conveniently packed.
 * Blockchain is a Vec3i base position and AxisVec3i shift; NO_SHIFT
 * specifies that this blockchain occupies only block in base position. */
class Blockchain {
public:
    Blockchain(Vec3i basePos, AxisVec3i range);

    Vec3i getBasePos();
    void setBasePos(Vec3i newBasePos);

    AxisVec3i getRange();
    void setRange(AxisVec3i newRange);

    class const_iterator {
    public:
        typedef std::random_access_iterator_tag iterator_category;

        const_iterator(Blockchain chain);

        const_iterator operator++();
        const_iterator operator++(int);

        const_iterator operator--();
        const_iterator operator--(int);

        // TODO: add + and - operators

        Vec3i operator*();

        bool operator==(const const_iterator& it);
        bool operator!=(const const_iterator& it);

    private:
        Vec3i m_curPos;
        AxisVec3i m_forwardDir;
    };

    const_iterator begin() const;
    const_iterator end() const;

private:
    Vec3i m_basePos;
    AxisVec3i m_range;
};

}

#endif // TMC_BLOCKCHAIN_H
