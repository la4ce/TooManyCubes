#include "vec3i.h"

namespace TooManyCubes {

Vec3i::Vec3i() {
    this->xp = 0;
    this->yp = 0;
    this->zp = 0;
}

int Vec3i::x() const {
    return this->xp;
}

int Vec3i::y() const {
    return this->yp;
}

int Vec3i::z() const {
    return this->zp;
}

void Vec3i::setX(int x) {
    this->xp= x;
}

void Vec3i::setY(int y) {
    this->yp = y;
}

void Vec3i::setZ(int z) {
    this->zp = z;
}

bool operator==(const Vec3i& left, const Vec3i& right) {
    return left.xp == right.xp && left.yp == right.yp && left.zp == right.zp;
}

}
