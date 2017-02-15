#include "badanimationparams.h"

namespace TMC {

BadAnimationParams::BadAnimationParams()
    : std::runtime_error("Animating blockchain on wrong axis.") {
}

}
