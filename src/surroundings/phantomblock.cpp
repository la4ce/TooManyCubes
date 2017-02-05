#include "phantomblock.h"

namespace TMC {

PhantomBlock::PhantomBlock(Qt3DCore::QEntity *parent)
    : Block(Vec3i(0, 0, 0), parent, PHANTOM_BLOCK, BLOCK_HIDED) {
}

}
