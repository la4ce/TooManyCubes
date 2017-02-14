#ifndef OCCUPIEDPOSEXCEPTION_H
#define OCCUPIEDPOSEXCEPTION_H

#include "sceneexception.h"
#include "vec3i.h"

namespace TMC {

class OccupiedPosException : public SceneException{
public:
    OccupiedPosException(Vec3i occupiedPos);
    ~OccupiedPosException() = default;

    const char *what() const noexcept override;

private:
    Vec3i m_occupiedPos;
};

}

#endif // OCCUPIEDPOSEXCEPTION_H
