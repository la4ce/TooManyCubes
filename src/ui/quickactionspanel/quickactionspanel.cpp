#include <QTabWidget>
#include <QFile>

#include "quickactionspanel.h"
#include "basequickactionstab.h"
#include "filetab.h"
#include "edittab.h"

namespace TMC {

QuickActionsPanel::QuickActionsPanel(QWidget *parent) : QTabWidget(parent) {

    // Populating panel
    auto fileTab = new FileTab();
    auto editTab = new EditTab();

    addTab(fileTab, fileTab->getTabName());
    addTab(editTab, editTab->getTabName());
}

} // namespace TMC
