#include "vec3i.h"
#include <iostream>

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

const Vec3i Vec3i::operator-() {
    return Vec3i(-xp, -yp, -zp);
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
    std::cout << "x: " << obj.xp << " y: " << obj.yp << " z: " << obj.zp;
    return os;
}


}
