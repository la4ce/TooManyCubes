#ifndef BADANIMATIONPARAMS_H
#define BADANIMATIONPARAMS_H

#include <stdexcept>

namespace TMC {

class BadAnimationParams : public std::runtime_error {
public:
    BadAnimationParams();
    ~BadAnimationParams() = default;
};

}

#endif // BADANIMATIONPARAMS_H
