#include <QTabWidget>
#include <QFile>

#include "quickactionspanel.h"
#include "basequickactiontab.h"
#include "filetab.h"
#include "edittab.h"

namespace TMC {

QuickActionsPanel::QuickActionsPanel(QWidget *parent) : QTabWidget(parent) {

    QFile stylesFile(":/styles/quick_actions_panel.css");
    stylesFile.open(QFile::ReadOnly);
    QString quickActionsPanelStyles = QLatin1String(stylesFile.readAll());

    setStyleSheet(quickActionsPanelStyles);

    // Populating panel
    auto fileTab = new FileTab();
    auto editTab = new EditTab();

    addTab(fileTab, fileTab->getTabName());
    addTab(editTab, editTab->getTabName());
}

} // namespace TMC
