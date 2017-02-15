#ifndef AXISVEC3IEXCEPTION_H
#define AXISVEC3IEXCEPTION_H

#include <stdexcept>

namespace TMC {

class AxisVec3iException : public std::runtime_error {
public:
    AxisVec3iException();
    ~AxisVec3iException() = default;
};

}

#endif // AXISVEC3IEXCEPTION_H
