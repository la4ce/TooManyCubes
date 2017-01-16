#ifndef TMC_MATERIALS_H
#define TMC_MATERIALS_H

#include <Qt3DExtras>
#include "customalphaphong.h"

namespace TooManyCubes {

class GlobalMaterials {
public:
    GlobalMaterials() = delete;

    // TODO: figure out how to prevent changing without const qualifier
    static Qt3DExtras::QPhongMaterial* DEFAULT_MATERIAL;
    static CustomAlphaPhong* DEFAULT_TRANSP_MATERIAL;
};

Qt3DExtras::QPhongMaterial* GlobalMaterials::DEFAULT_MATERIAL = new Qt3DExtras::QPhongMaterial();
CustomAlphaPhong* GlobalMaterials::DEFAULT_TRANSP_MATERIAL = new CustomAlphaPhong();

}


#endif // TMC_MATERIALS_H
