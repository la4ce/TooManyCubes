#ifndef TOOLSPANEL_H
#define TOOLSPANEL_H

#include <QGroupBox>

namespace TMC {

class ToolsPanel : public QGroupBox {
    Q_OBJECT
public:
    explicit ToolsPanel(const QString &title, QWidget *parent = nullptr);
};

} // namespace TMC

#endif // TOOLSPANEL_H
