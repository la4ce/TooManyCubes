#ifndef PLACEHOLDERBLOCK_H
#define PLACEHOLDERBLOCK_H

#include "block.h"
#include "vec3i.h"

namespace Qt3DCore {
    class QEntity;
}

namespace TMC {

class PlaceholderBlock : public Block {
public:
    PlaceholderBlock(Vec3i pos, Qt3DCore::QEntity *parent);
};

}

#endif // PLACEHOLDERBLOCK_H
