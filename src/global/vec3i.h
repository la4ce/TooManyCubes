#ifndef TMC_VEC3I_H
#define TMC_VEC3I_H

#include <iostream>

namespace TMC {
class Vec3i {
public:
    Vec3i();
    Vec3i(int oneValue) : xp(oneValue), yp(oneValue), zp(oneValue) {}
    Vec3i(int x, int y, int z) : xp(x), yp(y), zp(z) {}

    int x() const;
    int y() const;
    int z() const;

    void setX(int x);
    void setY(int y);
    void setZ(int z);

    const Vec3i& operator+();
    const Vec3i operator-();
    const Vec3i& operator+=(const Vec3i& vec);
    const Vec3i& operator-=(const Vec3i& vec);

    friend bool operator==(const Vec3i& left, const Vec3i& right);
    friend bool operator!=(const Vec3i& left, const Vec3i& right);
    friend const Vec3i operator+(const Vec3i& left, const Vec3i& right);
    friend const Vec3i operator-(const Vec3i& left, const Vec3i& right);
    friend std::ostream& operator<<(std::ostream& os, const Vec3i& obj); // TODO: impement output for qDebug too

private:
    int xp;
    int yp;
    int zp;

};
} // namespace TooManyCubes

#endif // TMC_VEC3I_H
