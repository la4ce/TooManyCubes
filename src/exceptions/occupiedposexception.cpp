#include <cstring>

#include "occupiedposexception.h"

namespace TMC {

OccupiedPosException::OccupiedPosException(Vec3i occupiedPos)
    : m_occupiedPos(occupiedPos) {
}

const char *OccupiedPosException::what() const noexcept {
    return ("Occupied position: " + m_occupiedPos.toString() + ".").c_str();
}

}
