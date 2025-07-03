#ifndef WRITEPCB_H
#define WRITEPCB_H

#include <QObject>
#include <QDebug>
#include <QtCore>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include "caddata.h"

class WritePcb : public QObject
{
    Q_OBJECT
public:
    explicit WritePcb(QObject *parent = nullptr);
    void WritingMyDataPcbFile();
    int FID1_PCB_X, FID2_PCB_X;
    double ConfigData_Scale;
    QList<QStringList> KiCADData;
    QList<QStringList> UsedLibData;
signals:

public slots:
    void getPcbData(int _FID1_PCB_X, int _FID2_PCB_X, double _ConfigData_Scale, QList<QStringList> _KiCADData, QList<QStringList> _UsedLibData);
};

#endif // WRITEPCB_H
