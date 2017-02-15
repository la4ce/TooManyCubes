#ifndef PLACEHOLDERBLOCK_H
#define PLACEHOLDERBLOCK_H

#include "block.h"

namespace Qt3DCore {
    class QEntity;
}

namespace TMC {

class PlaceholderBlock : public Block {
public:
    PlaceholderBlock(Qt3DCore::QEntity *parent);
};

}

#endif // PLACEHOLDERBLOCK_H
