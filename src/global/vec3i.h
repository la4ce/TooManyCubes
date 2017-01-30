#ifndef TMC_VEC3I_H
#define TMC_VEC3I_H

#include <iostream>
#include <QVector3D>

namespace TMC {

class AxisVec3i;

class Vec3i {
    friend AxisVec3i;

public:
    Vec3i() : xp(0), yp(0), zp(0) {}
    Vec3i(int oneValue) : xp(oneValue), yp(oneValue), zp(oneValue) {}
    Vec3i(int x, int y, int z) : xp(x), yp(y), zp(z) {}
    Vec3i(QVector3D vec) : xp((int)vec.x()), yp((int)vec.y()), zp((int)vec.z()) {}

    int x() const;
    int y() const;
    int z() const;

    void setX(int x);
    void setY(int y);
    void setZ(int z);

    const Vec3i& operator+();
    const Vec3i& operator-();

    const Vec3i& operator+=(const Vec3i& vec);
    const Vec3i& operator-=(const Vec3i& vec);

    int operator[](std::size_t id);

    friend bool operator==(const Vec3i& left, const Vec3i& right);
    friend bool operator!=(const Vec3i& left, const Vec3i& right);

    friend const Vec3i operator+(const Vec3i& left, const Vec3i& right);
    friend const Vec3i operator-(const Vec3i& left, const Vec3i& right);

    friend std::ostream& operator<<(std::ostream& os, const Vec3i& obj);
    // TODO: impement output for qDebug too

private:
    int xp;
    int yp;
    int zp;

};
} // namespace TooManyCubes

#endif // TMC_VEC3I_H
