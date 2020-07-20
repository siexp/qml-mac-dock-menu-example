#include "dockmenu.h"

DockMenu::DockMenu(QWidget *parent) : QMenu("Dock Menu", parent)
{
    connect(this, &QMenu::triggered, this, &DockMenu::onTriggered);
}

void DockMenu::addItem(const QString &label, qint32 id)
{
    auto action = addAction(label);
    action->setData(id);
}

void DockMenu::removeItem(qint32 id)
{
    const auto it = std::find_if(
        actions().begin(), actions().end(),
        [&id](const QAction *action) { return action->data().toInt() == id; }
        );

    if (it != actions().end())
    {
        removeAction(*it);
    }
}

void DockMenu::onTriggered(const QAction *action)
{
    emit itemClicked(action->data().toInt());
}
