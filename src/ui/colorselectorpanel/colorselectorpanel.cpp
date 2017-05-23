#include <QTabWidget>
#include <QHBoxLayout>
#include <QGridLayout>

#include "colorselectorpanel.h"
#include "colorcell.h"

namespace TMC {

ColorSelectorPanel::ColorSelectorPanel() {
    auto activeColorSwitcher = new ActiveColorSwitcher();

    auto colorCells = new QWidget();
    QPalette cellsPalette(palette());
    cellsPalette.setColor(QPalette::Background, Qt::black);
    colorCells->setAutoFillBackground(true);
    colorCells->setPalette(cellsPalette);

    auto gLayout = new QGridLayout();
    gLayout->setSpacing(1);
    gLayout->setContentsMargins(1, 1, 1, 1);
    gLayout->setSizeConstraint(QLayout::SetMinimumSize);

    for (int i = 0; i < CELLS_GRID_DIMENSIONS.width(); ++i) {
        gLayout->setColumnStretch(i, 0);
        gLayout->setRowStretch(i, 0);

        for (int j = 0; j < CELLS_GRID_DIMENSIONS.height(); ++j) {
            auto cell = new ColorCell(CELLS_INITIAL_C0LORS[i][j], activeColorSwitcher);
            gLayout->addWidget(cell, i, j);
        }
    }
    colorCells->setLayout(gLayout);

    auto hLayout = new QHBoxLayout();
    hLayout->setAlignment(Qt::AlignLeft);
    hLayout->setSizeConstraint(QLayout::SetMinimumSize);

    hLayout->addWidget(activeColorSwitcher);
    hLayout->addWidget(colorCells, 0, Qt::AlignCenter);

    setLayout(hLayout);
}

const QSize ColorSelectorPanel::CELLS_GRID_DIMENSIONS = QSize(CELL_GRID_W, CELL_GRID_H); // columns/rows

const QColor ColorSelectorPanel::CELLS_INITIAL_C0LORS[CELL_GRID_W][CELL_GRID_H] = {
    // First row
    { QColor::fromRgb(0, 0, 0),       QColor::fromRgb(85, 85, 85),    QColor::fromRgb(39, 0, 141),
      QColor::fromRgb(145, 0, 0),     QColor::fromRgb(39, 71, 3),     QColor::fromRgb(227, 189, 50), },
    // Second row
    { QColor::fromRgb(255, 255, 255), QColor::fromRgb(170, 170, 170), QColor::fromRgb(62, 103, 238),
      QColor::fromRgb(197, 0, 85),    QColor::fromRgb(94, 170, 23),   QColor::fromRgb(245, 229, 155) },
};

} // namespace TMC
