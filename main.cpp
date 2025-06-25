#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "writeconf.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    WriteConf conf;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("conf", &conf);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Test_QML", "Main");



    return app.exec();
}
