#include "blockchain.h"
#include "blockanimationcontroller.h"
#include "scene.h"

namespace TMC {

Blockchain::Blockchain(Vec3i basePos, AxisVec3i range)
    : m_basePos(basePos)
    , m_range(range) {
}

Vec3i Blockchain::getBasePos() {
    return m_basePos;
}

void Blockchain::setBasePos(Vec3i newBasePos) {
    m_basePos = newBasePos;
}

AxisVec3i Blockchain::getRange() {
    return m_range;
}

void Blockchain::setRange(AxisVec3i newRange) {
    m_range = newRange;
}

Blockchain::const_iterator Blockchain::begin() const {
    return const_iterator(*this);
}

Blockchain::const_iterator Blockchain::end() const {
    return const_iterator(Blockchain(m_basePos + (m_range + 1), AxisVec3i::NO_SHIFT));
}

// ------- CONST ITERATOR -------
Blockchain::const_iterator::const_iterator(Blockchain chain)
    : m_curPos(chain.getBasePos())
    , m_forwardDir(chain.getRange().normalized()) {
    // Iterating wouldn't chaige m_curPos if blockchain specified with NO_SHIFT
}

Blockchain::const_iterator Blockchain::const_iterator::operator++() {
    const_iterator buf = *this;
    m_curPos += m_forwardDir;
    return buf;
}

Blockchain::const_iterator Blockchain::const_iterator::operator++(int) {
    m_curPos += m_forwardDir;
    return *this;
}

Blockchain::const_iterator Blockchain::const_iterator::operator--() {
    const_iterator buf = *this;
    m_curPos -= m_forwardDir;
    return buf;
}

Blockchain::const_iterator Blockchain::const_iterator::operator--(int) {
    m_curPos -= m_forwardDir;
    return *this;
}

Vec3i Blockchain::const_iterator::operator*() {
    return m_curPos;
}

bool Blockchain::const_iterator::operator==(const const_iterator &it) {
    return m_curPos == it.m_curPos;
}

bool Blockchain::const_iterator::operator!=(const const_iterator &it) {
    return m_curPos != it.m_curPos;
}

}
