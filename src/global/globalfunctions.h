#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

namespace TMC {

class GlobalFunctions {
public:
    GlobalFunctions() = delete;

    static int sgn(int a) {
        return (a > 0) - (a < 0);
    }
};

}

#endif // GLOBALFUNCTIONS_H
