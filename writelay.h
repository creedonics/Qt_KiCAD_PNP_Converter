#ifndef WRITELAY_H
#define WRITELAY_H

#include <QObject>
#include <QDebug>
#include <QtCore>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include "caddata.h"


class WriteLay : public QObject
{
    Q_OBJECT
public:
    explicit WriteLay(QObject *parent = nullptr);
    void WritingMyDataLayFile();
    int FID1_LAY_X, FID1_LAY_Y, FID2_LAY_X, FID2_LAY_Y;

signals:

public slots:
    void getLayData(int _FID1_LAY_X, int _FID1_LAY_Y, int _FID2_LAY_X, int _FID2_LAY_Y);
};

#endif // WRITELAY_H
