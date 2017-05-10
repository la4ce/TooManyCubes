#ifndef BASEQUICKACTIONTAB_H
#define BASEQUICKACTIONTAB_H

#include <QWidget>

class QHBoxLayout;

namespace TMC {

class BaseQuickActionTab : public QWidget {
    Q_OBJECT

public:
    const QString getTabName();

protected:
    BaseQuickActionTab(QWidget *parent, const QString &tabName);

    void paintEvent(QPaintEvent *) override;

    QHBoxLayout *m_layout;

private:
    const QString m_tabName;
};

} // namespace TMC

#endif // BASEQUICKACTIONTAB_H
