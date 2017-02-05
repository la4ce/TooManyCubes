#ifndef TMC_PHANTOMBLOCK_H
#define TMC_PHANTOMBLOCK_H

#include <Qt3DCore/QEntity>
#include "block.h"

namespace TMC {

class PhantomBlock : public Block {
public:
    PhantomBlock(Qt3DCore::QEntity *parent);

    // TODO: if no new custom behaviour relatively to TMC::Block expected - remove class
};

}

#endif // TMC_PHANTOMBLOCK_H
