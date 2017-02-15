#ifndef OCCUPIEDPOSEXCEPTION_H
#define OCCUPIEDPOSEXCEPTION_H

#include "sceneexception.h"
#include "vec3i.h"

namespace TMC {

class OccupiedPosException : public SceneException {
public:
    OccupiedPosException(Vec3i occupiedPos);
    ~OccupiedPosException() = default;

    const char *what() const noexcept override;
};

}

#endif // OCCUPIEDPOSEXCEPTION_H
