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
};

} // namespace TMC

#endif // ACTIVECOLORSWITCHER_H
