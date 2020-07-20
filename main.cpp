#include <QApplication>
#include <QQmlApplicationEngine>

#include "dockmenu.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // Use QApplication instead of QGuiApplication since the latter is needed
    // for widgets like the QMenu to work
    QApplication app(argc, argv);

    // Dock menu probably should be a singleton type
    QScopedPointer<DockMenu> macDockMenu(new DockMenu);
    qmlRegisterSingletonInstance("com.github.siexp", 1, 0, "DockMenu", macDockMenu.get());
    macDockMenu->setAsDockMenu();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection
    );
    engine.load(url);

    return app.exec();
}
