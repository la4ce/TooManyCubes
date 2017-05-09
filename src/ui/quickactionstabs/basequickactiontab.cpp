#include <QHBoxLayout>

#include "basequickactiontab.h"

namespace TMC {

BaseQuickActionTab::BaseQuickActionTab(QWidget *parent, const QString &tabName)
    : QWidget(parent)
    , m_layout(new QHBoxLayout())
    , m_tabName(tabName) {

    setLayout(m_layout);
}

const QString BaseQuickActionTab::getTabName() {
    return m_tabName;
}

} // nemespace TMC
