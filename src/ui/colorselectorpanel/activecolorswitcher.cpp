#include <QStyleOption>
#include <QPainter>

#include "activecolorswitcher.h"

namespace TMC {

ActiveColorSwitcher::ActiveColorSwitcher(QWidget *parent)
    : QFrame(parent) {
    setObjectName("ActiveColorSwitcher");

    setPrimaryColor(Qt::black);
    setSecondaryColor(Qt::white);
}

void ActiveColorSwitcher::setPrimaryColor(const QColor &color) {
    setStyleSheet("QFrame#ActiveColorSwitcher {\
                       background-color:" + color.name() + ";\
                   }");
    setToolTip(color.name());
}

void ActiveColorSwitcher::setSecondaryColor(const QColor &color) {
    setStyleSheet("QFrame#ActiveColorSwitcher {\
                       background-color:" + color.name() + ";\
                   }");
}

} // namespace TMC
