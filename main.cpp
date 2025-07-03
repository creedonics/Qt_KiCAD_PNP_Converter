#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "writeconf.h"
#include "readconf.h"
#include "caddata.h"
#include "readkicadfile.h"
#include "readlibfile.h"
#include "writelay.h"
#include "writepcb.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    WriteConf W_Conf;
    ReadConf R_Conf;
    CadData CadDataElem;
    ReadKiCADFile KiCADFile;
    ReadLibFile LibFile;
    WriteLay W_Lay;
    WritePcb W_Pcb;


    QObject::connect(&R_Conf, &ReadConf::sendCadConfigData, &CadDataElem, &CadData::getCadConfigData);
    QObject::connect(&KiCADFile, &ReadKiCADFile::sendKiCADNumberOfLines, &CadDataElem, &CadData::getKiCADNumberOfLines);
    QObject::connect(&KiCADFile, &ReadKiCADFile::sendKiCADData, &CadDataElem, &CadData::getKiCADData);
    QObject::connect(&LibFile, &ReadLibFile::sendLibData, &CadDataElem, &CadData::getLibData);
    QObject::connect(&CadDataElem, &CadData::sendLayData, &W_Lay, &WriteLay::getLayData);
    QObject::connect(&CadDataElem, &CadData::sendPcbData, &W_Pcb, &WritePcb::getPcbData);


    QQmlContext *KiCADFile_context = engine.rootContext();
    QQmlContext *W_Conf_context = engine.rootContext();
    QQmlContext *R_Conf_context = engine.rootContext();
    QQmlContext *LibFile_context = engine.rootContext();


    KiCADFile_context->setContextProperty("KiCADFile", &KiCADFile);
    W_Conf_context->setContextProperty("W_Conf", &W_Conf);
    R_Conf_context->setContextProperty("R_Conf", &R_Conf);
    LibFile_context->setContextProperty("LibFile", &LibFile);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Test_QML", "Main");



    return app.exec();
}
