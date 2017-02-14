#include "missingblockexception.h"

namespace TMC {

MissingBlockException::MissingBlockException(Vec3i pos)
    : m_pos(pos) {
}

const char *MissingBlockException::what() const noexcept {
    return ("Missing block at position: " + m_pos.toString() + ".").c_str();
}

}
