#ifndef SCENEEXCEPTION_H
#define SCENEEXCEPTION_H

#include <exception>
#include "vec3i.h"

namespace TMC {

class SceneException : public std::exception {
public:
    SceneException(Vec3i problemPos);
    virtual ~SceneException() = default;

    virtual const char *what() const noexcept override;

protected:
    Vec3i m_pos;
};

}

#endif // SCENEEXCEPTION_H
