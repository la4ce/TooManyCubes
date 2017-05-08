#include <QTabWidget>

#include "quickactionspanel.h"
#include "basequickactiontab.h"
#include "filetab.h"

namespace TMC {

QuickActionsPanel::QuickActionsPanel(QWidget *parent) {
    setFeatures(QDockWidget::NoDockWidgetFeatures);

    // Populating
    auto tabWidget = new QTabWidget();

    auto firstTab = new FileTab();

    tabWidget->addTab(firstTab, firstTab->getTabName());

    setWidget(tabWidget);
}

} // namespace TMC
