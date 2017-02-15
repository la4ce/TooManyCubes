#include "sceneexception.h"

namespace TMC {

SceneException::SceneException(Vec3i problemPos)
    : m_pos(problemPos){
}

const char *SceneException::what() const noexcept {
    return ("Unknown problem in scene occured on position " + m_pos.toString()).c_str();
}

}
