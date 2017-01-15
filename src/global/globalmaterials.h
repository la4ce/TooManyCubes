#ifndef TMC_MATERIALS_H
#define TMC_MATERIALS_H

#include <Qt3DExtras>
#include "customalphaphong.h"

namespace TooManyCubes {

class GlobalMaterials {
public:
    GlobalMaterials() = delete;

    // TODO: figure out how to prevent changing without const qualifier
    static Qt3DExtras::QPhongMaterial DEFAULT_MATERIAL;
    static CustomAlphaPhong DEFAULT_TRANSP_MATERIAL;
};

Qt3DExtras::QPhongMaterial GlobalMaterials::DEFAULT_MATERIAL;
CustomAlphaPhong GlobalMaterials::DEFAULT_TRANSP_MATERIAL;

}


#endif // TMC_MATERIALS_H
