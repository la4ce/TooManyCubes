#include <QHBoxLayout>
#include <QToolButton>

#include "filetab.h"

namespace TMC {

FileTab::FileTab(QWidget *parent)
    : BaseQuickActionTab(parent, "File") {
    auto newButton = new QToolButton();
    newButton->setIcon(QIcon(":/icons/new_file_ic.png"));
    newButton->setToolTip("New File");

    auto openButton = new QToolButton();
    openButton->setIcon(QIcon(":/icons/open_file_ic.png"));
    openButton->setToolTip("Open File");

    auto saveButton = new QToolButton();
    saveButton->setIcon(QIcon(":/icons/save_ic.png"));
    saveButton->setToolTip("Save File");

    m_layout->addWidget(newButton);
    m_layout->addWidget(openButton);
    m_layout->addWidget(saveButton);
}

} // namespace TMC
