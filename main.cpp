#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "writeconf.h"
#include "readconf.h"
#include "caddata.h"
#include "readkicadfile.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    WriteConf W_Conf;
    ReadConf R_Conf;
    CadData CadDataConf;
    ReadKiCADFile KiCADFile;


    QObject::connect(&R_Conf, &ReadConf::sendCadConfigData, &CadDataConf, &CadData::getCadConfigData);
    QQmlContext *KiCADFile_context = engine.rootContext();
    QQmlContext *W_Conf_context = engine.rootContext();
    QQmlContext *R_Conf_context = engine.rootContext();
    KiCADFile_context->setContextProperty("KiCADFile", &KiCADFile);
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
