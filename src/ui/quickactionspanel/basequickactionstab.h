#ifndef BASEQUICKACTIONSTAB_H
#define BASEQUICKACTIONSTAB_H

#include <QWidget>

class QHBoxLayout;

namespace TMC {

class BaseQuickActionsTab : public QWidget {
    Q_OBJECT

public:
    const QString getTabName();

protected:
    BaseQuickActionsTab(QWidget *parent, const QString &tabName);

    void paintEvent(QPaintEvent *) override;

    QHBoxLayout *m_layout;

private:
    const QString m_tabName;
};

} // namespace TMC

#endif // BASEQUICKACTIONSTAB_H
