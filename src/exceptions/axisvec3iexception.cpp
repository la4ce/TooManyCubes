#include "axisvec3iexception.h"

namespace TMC {

AxisVec3iException::AxisVec3iException()
    : std::runtime_error("Trying to create AxisVec3i from Vec3i with more than one non-zero component."){
}

}
