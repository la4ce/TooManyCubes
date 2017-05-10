#include <QTabWidget>

#include "quickactionspanel.h"
#include "basequickactiontab.h"
#include "filetab.h"
#include "edittab.h"

namespace TMC {

QuickActionsPanel::QuickActionsPanel(QWidget *parent) {
    setFeatures(QDockWidget::NoDockWidgetFeatures);
    setTitleBarWidget(new QWidget()); // empty bar

    // Populating panel
    auto tabWidget = new QTabWidget();

    auto fileTab = new FileTab();
    auto editTab = new EditTab();

    tabWidget->addTab(fileTab, fileTab->getTabName());
    tabWidget->addTab(editTab, editTab->getTabName());

    setWidget(tabWidget);
}

} // namespace TMC
