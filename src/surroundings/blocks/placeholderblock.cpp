#include <Qt3DCore/QEntity>

#include "placeholderblock.h"

namespace TMC {

PlaceholderBlock::PlaceholderBlock(Vec3i pos, Qt3DCore::QEntity *parent)
    : Block(pos, parent, PLACEHOLDER_BLOCK, BLOCK_HIDED, BLOCK_LOCKED) {

}

}
