#include <QFile>
#include <QGroupBox>
#include <QToolButton>
#include <QGridLayout>
#include <QLabel>

#include "toolspanel.h"

namespace TMC {

ToolsPanel::ToolsPanel(QWidget *parent) {
    setFeatures(QDockWidget::NoDockWidgetFeatures);
    setTitleBarWidget(new QWidget()); // empty bar

    QFile stylesFile(":/styles/tools_panel.css");
    stylesFile.open(QFile::ReadOnly);
    QString toolsPanelStyles = QLatin1String(stylesFile.readAll());

    setStyleSheet(toolsPanelStyles);

    auto button1 = new QToolButton();
    button1->setIcon(QIcon(":/icons/new_file_ic.png"));

    auto button2 = new QToolButton();
    button2->setIcon(QIcon(":/icons/new_file_ic.png"));

    auto button3 = new QToolButton();
    button3->setIcon(QIcon(":/icons/new_file_ic.png"));

    auto button4 = new QToolButton();
    button4->setIcon(QIcon(":/icons/new_file_ic.png"));

    auto button5 = new QToolButton();
    button5->setIcon(QIcon(":/icons/new_file_ic.png"));

    auto button6 = new QToolButton();
    button6->setIcon(QIcon(":/icons/new_file_ic.png"));

    auto button7 = new QToolButton();
    button7->setIcon(QIcon(":/icons/new_file_ic.png"));

    auto button8 = new QToolButton();
    button8->setIcon(QIcon(":/icons/new_file_ic.png"));

    auto button9 = new QToolButton();
    button9->setIcon(QIcon(":/icons/new_file_ic.png"));

    auto gridLayout = new QGridLayout();

    gridLayout->setSpacing(2);
    gridLayout->setMargin(10);
    gridLayout->setSizeConstraint(QGridLayout::SetFixedSize);

    gridLayout->addWidget(button1, 0, 0, Qt::AlignCenter);
    gridLayout->addWidget(button2, 0, 1, Qt::AlignCenter);
    gridLayout->addWidget(button3, 0, 2, Qt::AlignCenter);
    gridLayout->addWidget(button4, 1, 0, Qt::AlignCenter);
    gridLayout->addWidget(button5, 1, 1, Qt::AlignCenter);
    gridLayout->addWidget(button6, 1, 2, Qt::AlignCenter);
    gridLayout->addWidget(button7, 2, 0, Qt::AlignCenter);
    gridLayout->addWidget(button8, 2, 1, Qt::AlignCenter);
    gridLayout->addWidget(button9, 2, 2, Qt::AlignCenter);

    auto groupBox = new QGroupBox(tr("Tools"));
    groupBox->setLayout(gridLayout);

    setWidget(groupBox);
}

} // namespace TMC
