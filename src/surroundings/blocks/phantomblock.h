#ifndef TMC_PHANTOMBLOCK_H
#define TMC_PHANTOMBLOCK_H

#include <Qt3DCore/QEntity>
#include "block.h"

namespace TMC {

class PhantomBlock : public Block {
public:
    PhantomBlock(Qt3DCore::QEntity *parent);
};

}

#endif // TMC_PHANTOMBLOCK_H
