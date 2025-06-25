#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "writeconf.h"
#include "readconf.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    WriteConf W_Conf;
    ReadConf R_Conf;
    QQmlContext *W_Conf_context = engine.rootContext();
    QQmlContext *R_Conf_context = engine.rootContext();
    W_Conf_context->setContextProperty("W_Conf", &W_Conf);
    R_Conf_context->setContextProperty("R_Conf", &R_Conf);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Test_QML", "Main");



    return app.exec();
}
