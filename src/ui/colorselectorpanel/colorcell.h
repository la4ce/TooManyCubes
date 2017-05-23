#ifndef COLORCELL_H
#define COLORCELL_H

#include <QFrame>

#include "activecolorswitcher.h"

namespace TMC {

class ColorCell : public QFrame {
    Q_OBJECT
public:
    explicit ColorCell(const QColor &initialColor, ActiveColorSwitcher *switcher, QWidget *parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *) override;

private:
    void setCellColor(const QColor &color);

    QColor m_selectedColor;
    ActiveColorSwitcher &m_switcher;
};

} // namespace TMC

#endif // COLORCELL_H
