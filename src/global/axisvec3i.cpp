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
        qDebug() << "Trying to create AxisVec3i from Vec3i with more than one non zero component." << vec;
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

int AxisVec3i::getValue() const {
    return m_vec.xp + m_vec.yp + m_vec.zp;
}

void AxisVec3i::setValue(int newValue) {
    if (m_vec.xp) {
        m_vec.xp = newValue;
        return;
    }

    if (m_vec.yp) {
        m_vec.yp = newValue;
        return;
    }

    if (m_vec.zp) {
        m_vec.zp = newValue;
        return;
    }
}

AxisVec3i AxisVec3i::getNormal() {
    return AxisVec3i(this->getAxis(), 1);
}

AxisIndex AxisVec3i::getAxis() const {
    if (m_vec.xp) return XAXIS;

    if (m_vec.yp) return YAXIS;

    if (m_vec.zp) return ZAXIS;

    return DEFAULT_AXIS;
}

Vec3i AxisVec3i::getVec3i() const {
    return m_vec;
}

const AxisVec3i AxisVec3i::operator*=(const int scalar) {
    return AxisVec3i(this->getAxis(), this->getValue() * scalar);
}

const AxisVec3i AxisVec3i::operator/=(const int scalar) {
    return AxisVec3i(this->getAxis(), this->getValue() / scalar);
}

const Vec3i operator+(const Vec3i &vec, const AxisVec3i &axisVec) {
    return vec + axisVec.m_vec;
}

const Vec3i operator+(const AxisVec3i &axisVec, const Vec3i &vec) {
    return vec + axisVec.m_vec;
}

const AxisVec3i operator*(const AxisVec3i &axisVec, const int scalar) {
    return AxisVec3i(axisVec.getAxis(), axisVec.getValue() * scalar);
}

const AxisVec3i operator/(const AxisVec3i &axisVec, const int scalar) {
    return AxisVec3i(axisVec.getAxis(), axisVec.getValue() / scalar);
}

std::ostream& operator<<(std::ostream &os, const AxisVec3i &vec) {
    return os << vec.m_vec;
}

QDebug operator<<(QDebug dbg, const AxisVec3i &axisVec) {
    QDebugStateSaver saver(dbg);
       dbg.nospace() << "AxisVec3i("
           << axisVec.m_vec.x() << ", " << axisVec.m_vec.y() << ", " << axisVec.m_vec.z() << ')';
       return dbg;
}

}
