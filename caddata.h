#ifndef CADDATA_H
#define CADDATA_H

#include <QObject>
#include <QDebug>
#include <QtCore>
#include <QStringList>
#include <QTextStream>
#include <QFile>

class CadData : public QObject
{
    Q_OBJECT
public:
    explicit CadData(QObject *parent = nullptr);
    QStringList ConfigData;
    QStringList KiCADData;

signals:

public slots:
    void getCadConfigData(QString _ConfigData);
    void getKiCADData(QString _KiCADData);
};

#endif // CADDATA_H
