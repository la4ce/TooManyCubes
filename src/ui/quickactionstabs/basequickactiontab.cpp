#include <QHBoxLayout>

#include "basequickactiontab.h"

namespace TMC {

BaseQuickActionTab::BaseQuickActionTab(QWidget *parent, const QString &tabName)
    : QWidget(parent)
    , m_layout(new QHBoxLayout())
    , m_tabName(tabName) {

    setLayout(m_layout);

    auto widget = new QWidget();
   //widget->resize();
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::blue);
    widget->setAutoFillBackground(true);
    widget->setPalette(Pal);
    widget->show();

    auto widget2 = new QWidget();
    widget2->setAutoFillBackground(true);
    widget2->setPalette(Pal);
    widget2->setMinimumHeight(50);
    widget2->show();

    m_layout->addWidget(widget);
    m_layout->addWidget(widget2);
}

const QString BaseQuickActionTab::getTabName() {
    return m_tabName;
}

} // nemespace TMC
