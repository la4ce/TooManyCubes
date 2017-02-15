#ifndef MISSINGBLOCKEXCEPTION_H
#define MISSINGBLOCKEXCEPTION_H

#include "sceneexception.h"
#include "vec3i.h"

namespace TMC {

class MissingBlockException : public SceneException {
public:
    MissingBlockException(Vec3i pos);
    ~MissingBlockException() = default;

    const char *what() const noexcept override;

};

}

#endif // MISSINGBLOCKEXCEPTION_H
