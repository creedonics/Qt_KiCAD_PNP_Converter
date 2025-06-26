#include "caddata.h"

CadData::CadData(QObject *parent)
    : QObject{parent}
{}

void CadData::getCadConfigData(QString _ConfigData)
{
    this->ConfigData << _ConfigData;
    //qInfo() << "CAD : " << ConfigData;
}

void CadData::getKiCADData(QString _KiCADData)
{
    this->KiCADData << _KiCADData;
}
