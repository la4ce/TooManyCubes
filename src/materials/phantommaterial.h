#ifndef TMC_PHANTOMMATERIAL_H
#define TMC_PHANTOMMATERIAL_H

#include <Qt3DExtras>

namespace TMC {

class PhantomMaterial : public Qt3DExtras::QPhongAlphaMaterial {
public:
    PhantomMaterial();
};

}

#endif // TMC_PHANTOMMATERIAL_H
