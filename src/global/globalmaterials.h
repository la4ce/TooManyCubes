#ifndef TMC_MATERIALS_H
#define TMC_MATERIALS_H

#include <Qt3DExtras>

namespace TooManyCubes {

class GlobalMaterials {
public:
    GlobalMaterials() = delete;
    static Qt3DExtras::QPhongMaterial DEFAULT_MATERIAL; // TODO: figure out how to prevent changing without const qualifier
};

Qt3DExtras::QPhongMaterial GlobalMaterials::DEFAULT_MATERIAL;

}


#endif // TMC_MATERIALS_H
