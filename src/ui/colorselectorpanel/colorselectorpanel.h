#ifndef COLORSELECTORPANEL_H
#define COLORSELECTORPANEL_H

#include <QTabWidget>

#define CELL_GRID_W 2
#define CELL_GRID_H 6

namespace TMC {

class ColorSelectorPanel : public QTabWidget {
    Q_OBJECT
public:
    static const QSize CELLS_GRID_DIMENSIONS;
    static const QColor CELLS_INITIAL_C0LORS[CELL_GRID_W][CELL_GRID_H];

public:
    ColorSelectorPanel();
};

} // namespace TMC

#endif // COLORSELECTORPANEL_H
