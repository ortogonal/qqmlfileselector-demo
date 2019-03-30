#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlFileSelector>
#include <QFileSelector>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QStringList selectors;
    selectors << "desktop";

    // Our QQmlApplicationEngine will take owner-ship of fs.
    QQmlFileSelector *fs = new QQmlFileSelector(&engine);
    fs->setExtraSelectors(selectors);
    qDebug() << fs->selector()->allSelectors();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
