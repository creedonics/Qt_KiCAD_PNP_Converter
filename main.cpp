#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "writeconf.h"

int main(int argc, char *argv[])
{
    WriteConf dosmtth;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Test_QML", "Main");



    return app.exec();
}
