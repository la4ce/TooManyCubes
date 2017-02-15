#include "lockedblockexception.h"

namespace TMC {

LockedBlockException::LockedBlockException(Vec3i lockedPos)
    : SceneException(lockedPos){
}

const char *LockedBlockException::what() const noexcept {
    return ("Trying to perform operation on locked block: " + m_pos.toString() + ".").c_str();
}

}
