#ifndef DOCKMENU_H
#define DOCKMENU_H

#include <QMenu>

class DockMenu : public QMenu
{
    Q_OBJECT
public:
    explicit DockMenu(QWidget *parent = nullptr);

signals:
    void itemClicked(qint32 id);

public slots:
    Q_INVOKABLE void addItem(const QString &label, qint32 id);
    Q_INVOKABLE void removeItem(qint32 id);

private slots:
    void onTriggered(const QAction *action);
};

#endif // DOCKMENU_H
