#include <QStyleOption>
#include <QPainter>
#include <QColorDialog>
#include <QMouseEvent>

#include "colorcell.h"

namespace TMC {

ColorCell::ColorCell(const QColor &initialColor, ActiveColorSwitcher *switcher, QWidget *parent)
    : QFrame(parent)
    , m_selectedColor(initialColor)
    , m_switcher(*switcher) {
    setObjectName("ColorCell");
    setCellColor(initialColor);
}

void ColorCell::mousePressEvent(QMouseEvent *event) {
    switch (event->buttons()) {
    case Qt::LeftButton:
        m_switcher.setPrimaryColor(m_selectedColor);
        break;
    case Qt::RightButton:
        m_switcher.setSecondaryColor(m_selectedColor);
        break;
    }
}

void ColorCell::mouseDoubleClickEvent(QMouseEvent *) {
    setCellColor(QColorDialog::getColor(Qt::green, nullptr, tr("Select Color")));
    m_switcher.setPrimaryColor(m_selectedColor);
}

void ColorCell::setCellColor(const QColor &color) {
    m_selectedColor = color;
    setStyleSheet("QFrame#ColorCell {\
                        background-color:" + m_selectedColor.name() +";\
                   }");
    setToolTip(m_selectedColor.name());
}

} // namespace TMC
