#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>

#include "basequickactiontab.h"

namespace TMC {

BaseQuickActionTab::BaseQuickActionTab(QWidget *parent, const QString &tabName)
    : QWidget(parent)
    , m_layout(new QHBoxLayout())
    , m_tabName(tabName) {

    m_layout->setAlignment(Qt::AlignLeft);
    m_layout->setSizeConstraint(QHBoxLayout::SetMinimumSize);
    m_layout->setMargin(0);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(2);

    setLayout(m_layout);
}

void BaseQuickActionTab::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

const QString BaseQuickActionTab::getTabName() {
    return m_tabName;
}

} // nemespace TMC
