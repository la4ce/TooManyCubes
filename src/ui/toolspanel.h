#ifndef TOOLSPANEL_H
#define TOOLSPANEL_H

#include <QGroupBox>

namespace TMC {

class ToolsPanel : public QGroupBox {
public:
    ToolsPanel(const QString &title, QWidget *parent = nullptr);
};

} // namespace TMC

#endif // TOOLSPANEL_H
