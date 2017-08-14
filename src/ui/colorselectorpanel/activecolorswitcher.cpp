#include <QStyleOption>
#include <QPainter>
#include <QVBoxLayout>

#include "activecolorswitcher.h"

namespace TMC {

ActiveColorSwitcher::ActiveColorSwitcher(QWidget *parent)
    : QFrame(parent)
    , m_primaryFrame(new QFrame())
    , m_secondaryFrame(new QFrame()) {
    setObjectName("ActiveColorSwitcher");

    auto vLayout = new QVBoxLayout();

    m_primaryFrame->setObjectName("ActiveColorSwitcherPHalf");
    m_secondaryFrame->setObjectName("ActiveColorSwitcherSHalf");

    vLayout->addWidget(m_primaryFrame, 0);
    vLayout->addWidget(m_secondaryFrame, 1);

    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->setSpacing(2);
    vLayout->setSizeConstraint(QVBoxLayout::SetFixedSize);

    setLayout(vLayout);

    setPrimaryColor(Qt::black);
    setSecondaryColor(Qt::white);
}

void ActiveColorSwitcher::setPrimaryColor(const QColor &color) {
    m_primaryFrame->setStyleSheet("QFrame#ActiveColorSwitcherPHalf {\
                                        background-color:" + color.name() + ";\
                                   }");
    m_primaryFrame->setToolTip(color.name());

    primaryColor = color;
}

void ActiveColorSwitcher::setSecondaryColor(const QColor &color) {
    m_secondaryFrame->setStyleSheet("QFrame#ActiveColorSwitcherSHalf {\
                                         background-color:" + color.name() + ";\
                                     }");
    m_secondaryFrame->setToolTip(color.name());

    secondaryColor = color;
}

const QColor &ActiveColorSwitcher::getPrimaryColor() {
    return primaryColor;
}

const QColor &ActiveColorSwitcher::getSecondaryColor() {
    return secondaryColor;
}

} // namespace TMC
