#include <Qt3DCore>

#include "axisvec3i.h"

namespace TMC {

AxisVec3i::AxisVec3i(AxisIndex axis, int value) : m_vec(0) {
    switch (axis) {
        case XAXIS: // DEFAULT_AXIS
            m_vec.setX(value);
            break;
        case YAXIS:
            m_vec.setY(value);
            break;
        case ZAXIS:
            m_vec.setZ(value);
            break;
    }
}

AxisVec3i::AxisVec3i(Vec3i vec) {
    int nonNulCount = 0;
    for (int i = 0; i < 3; i++)
        if (vec[i] != 0) nonNulCount++;

    if (nonNulCount > 1) {
        m_vec = Vec3i(0);
        qDebug() << "Trying to create AxisVec3i from Vec3i with more than one non zero component." << vec.x() << " " << vec.y() << " " << vec.z() << endl; // TODO: overload qDebug() << operator and use it
    } else {
        m_vec = vec;
    }
}

AxisVec3i::AxisVec3i(int x, int y, int z) : AxisVec3i(Vec3i(x, y, z)) {
}

int AxisVec3i::x() const {
    return m_vec.xp;
}

int AxisVec3i::y() const {
    return m_vec.yp;
}

int AxisVec3i::z() const {
    return m_vec.zp;
}

void AxisVec3i::changeValue(int newValue) {
    if (m_vec.xp != 0) {
        m_vec.xp = newValue;
        return;
    }

    if (m_vec.yp != 0) {
        m_vec.yp = newValue;
        return;
    }

    if (m_vec.zp != 0) {
        m_vec.zp = newValue;
        return;
    }
}

const Vec3i operator+(const Vec3i &vec, const AxisVec3i &axisVec) {
    return vec + axisVec.m_vec;
}

const Vec3i operator+(const AxisVec3i &axisVec, const Vec3i &vec) {
    return vec + axisVec.m_vec;
}

std::ostream& operator<<(std::ostream &os, const AxisVec3i &vec) {
    return os << vec.m_vec;
}

}
