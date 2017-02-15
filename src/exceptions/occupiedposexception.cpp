#include <cstring>

#include "occupiedposexception.h"

namespace TMC {

OccupiedPosException::OccupiedPosException(Vec3i occupiedPos)
    : SceneException(occupiedPos) {
}

const char *OccupiedPosException::what() const noexcept {
    return ("Inserting block on occupied position: " + m_pos.toString() + ".").c_str();
}

}
