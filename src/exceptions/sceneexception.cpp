#include "sceneexception.h"

namespace TMC {

const char *SceneException::what() const noexcept {
    return "Unknown problem in scene occured.";
}

}
