#include <Qt3DCore/QEntity>

#include "placeholderblock.h"

namespace TMC {

PlaceholderBlock::PlaceholderBlock(Qt3DCore::QEntity *parent)
    : Block(Vec3i(0, 0, 0), parent, PLACEHOLDER_BLOCK, BLOCK_HIDED) {

}

}
