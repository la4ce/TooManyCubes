#ifndef TMC_PHANTOMBLOCK_H
#define TMC_PHANTOMBLOCK_H

#include "block.h"

namespace TMC {

class PhantomBlock : public Block {
public:
    PhantomBlock(Qt3DCore::QEntity *parent, BlockType type = PHANTOM_BLOCK) : Block(parent, type) {}

    void setPos(Vec3i newPos);
};

}

#endif // TMC_PHANTOMBLOCK_H
