#ifndef LOCKEDBLOCKEXCEPTION_H
#define LOCKEDBLOCKEXCEPTION_H

#include "sceneexception.h"

namespace TMC {

class LockedBlockException : public SceneException {
public:
    LockedBlockException(Vec3i lockedPos);
    ~LockedBlockException() = default;

    const char *what() const noexcept override;
};

}

#endif // LOCKEDBLOCKEXCEPTION_H
