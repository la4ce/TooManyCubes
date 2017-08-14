#ifndef ACTIVECOLORSWITCHER_H
#define ACTIVECOLORSWITCHER_H

#include <QFrame>

namespace TMC {

class ActiveColorSwitcher : public QFrame {
    Q_OBJECT
public:
    explicit ActiveColorSwitcher(QWidget *parent = nullptr);

    void setPrimaryColor(const QColor &color);
    void setSecondaryColor(const QColor &color);

    const QColor &getPrimaryColor();
    const QColor &getSecondaryColor();

private:
    QColor primaryColor;
    QColor secondaryColor;

    QFrame *m_primaryFrame;
    QFrame *m_secondaryFrame;
};

} // namespace TMC

#endif // ACTIVECOLORSWITCHER_H
