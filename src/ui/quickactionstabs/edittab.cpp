#include <QHBoxLayout>
#include <QToolButton>

#include "edittab.h"

namespace TMC {

EditTab::EditTab(QWidget *parent)
    : BaseQuickActionTab(parent, "Edit") {

    auto undoButton = new QToolButton();
    undoButton->setIcon(QIcon(":/icons/undo_ic.png"));

    auto redoButton = new QToolButton();
    redoButton->setIcon(QIcon(":/icons/redo_ic.png"));

    auto cutButton = new QToolButton();
    cutButton->setIcon(QIcon(":/icons/cut_ic.png"));

    m_layout->addWidget(undoButton);
    m_layout->addWidget(redoButton);
    m_layout->addWidget(cutButton);

}

} // namespace TMC
