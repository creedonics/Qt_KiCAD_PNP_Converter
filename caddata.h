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
    QList<QStringList> KiCADData;
    int KiCADNumberOfLines;
    int KiCADIterator = 0;

    void FindFiducials(QList<QStringList> _KiCADData);
    QList<int> FID1, FID2;

signals:

public slots:
    void getCadConfigData(QString _ConfigData);
    void getKiCADData(QStringList _KiCADData);
    void getKiCADNumberOfLines(int _KiCADNumberOfLines);
};

#endif // CADDATA_H
