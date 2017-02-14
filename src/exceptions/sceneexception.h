#ifndef SCENEEXCEPTION_H
#define SCENEEXCEPTION_H

#include <exception>

namespace TMC {

class SceneException : public std::exception {
public:
    const char *what() const noexcept override;
};

}

#endif // SCENEEXCEPTION_H
