#ifndef QUICKACTIONSPANEL_H
#define QUICKACTIONSPANEL_H

#include <QTabWidget>

namespace TMC {

class QuickActionsPanel : public QTabWidget {
public:
    explicit QuickActionsPanel(QWidget *parent = nullptr);
};

} // namespace TMC

#endif // QUICKACTIONSPANEL_H
