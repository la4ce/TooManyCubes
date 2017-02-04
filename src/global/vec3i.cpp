#include <iostream>
#include <Qt3DCore>

#include "vec3i.h"

namespace TMC {

int Vec3i::x() const {
    return xp;
}

int Vec3i::y() const {
    return yp;
}

int Vec3i::z() const {
    return zp;
}

void Vec3i::setX(int x) {
    xp= x;
}

void Vec3i::setY(int y) {
    yp = y;
}

void Vec3i::setZ(int z) {
    zp = z;
}

const Vec3i& Vec3i::operator+() {
    return *this;
}

const Vec3i& Vec3i::operator-() {
    xp = -xp;
    yp = -yp;
    zp = -zp;

    return *this;
}

const Vec3i& Vec3i::operator+=(const Vec3i& vec) {
    xp += vec.xp;
    yp += vec.yp;
    zp += vec.zp;

    return *this;
}

const Vec3i& Vec3i::operator-=(const Vec3i& vec) {
    xp -= vec.xp;
    yp -= vec.yp;
    zp -= vec.zp;

    return *this;
}

int Vec3i::operator[](std::size_t id) {
    switch (id) {
        case 0:
            return this->xp;
        case 1:
            return this->yp;
        case 2:
            return this->zp;
        default:
            qDebug() << "Trying to access out of Vec3i bounds: " << (int)id << endl;
            return 0;
    }
}

bool operator==(const Vec3i& left, const Vec3i& right) {
    return left.xp == right.xp && left.yp == right.yp && left.zp == right.zp;
}

bool operator!=(const Vec3i &left, const Vec3i &right) {
    return left.xp != right.xp || left.yp != right.yp || left.zp != right.zp;
}

const Vec3i operator+(const Vec3i& left, const Vec3i& right) {
    return Vec3i(left.xp + right.xp, left.yp + right.yp, left.zp + right.zp);
}

const Vec3i operator-(const Vec3i& left, const Vec3i& right) {
    return Vec3i(left.xp - right.xp, left.yp - right.yp, left.zp - right.zp);
}

std::ostream& operator<<(std::ostream& os, const Vec3i& obj) {
    return os << "x: " << obj.xp << " y: " << obj.yp << " z: " << obj.zp << "\n";
}

QDebug operator<<(QDebug dbg, const Vec3i &vector)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "Vec3i("
        << vector.xp << ", " << vector.yp << ", " << vector.zp << ')';
    return dbg;
}

}
