#include "vec3i.h"
#include <iostream>

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

const Vec3i& Vec3i::operator+() {
    return *this;
}

const Vec3i Vec3i::operator-() {
    return Vec3i(-this->xp, -this->yp, -this->zp);
}

const Vec3i& Vec3i::operator+=(const Vec3i& vec) {
    this->xp += vec.xp;
    this->yp += vec.yp;
    this->zp += vec.zp;

    return *this;
}

const Vec3i& Vec3i::operator-=(const Vec3i& vec) {
    this->xp -= vec.xp;
    this->yp -= vec.yp;
    this->zp -= vec.zp;

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
