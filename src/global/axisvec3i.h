#ifndef AXISVEC3I_H
#define AXISVEC3I_H

#include <iostream>
#include "vec3i.h"

namespace TMC {

enum AxisIndex {
    XAXIS,
    YAXIS,
    ZAXIS,
    DEFAULT_AXIS = 0
};

/* AxisVec3 is a Vec3 that works exclusively on one axis (maximum
 * one value of this vector is non-zero at given moment).
 * It allows to specify blocks movement shifts by any axis,
 * blockchains range (1x1xN regions of blocks) etc in a general safe way.*/
class AxisVec3i {
public:
    AxisVec3i(AxisIndex axis, int value);
    AxisVec3i(Vec3i vec);
    AxisVec3i(int x, int y, int z);

    int x() const;
    int y() const;
    int z() const;

    void changeValue(int newValue);

    friend const Vec3i operator+(const Vec3i &vec, const AxisVec3i &axisVec);
    friend const Vec3i operator+(const AxisVec3i &axisVec, const Vec3i &vec);

    friend std::ostream& operator<<(std::ostream &os, const AxisVec3i &axis);

private:
    Vec3i m_vec;
};

}

#endif // AXISVEC3I_H