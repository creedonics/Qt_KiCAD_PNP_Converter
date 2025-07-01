#ifndef CADDATA_H
#define CADDATA_H

#include <QObject>
#include <QDebug>
#include <QtCore>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include <QListIterator>

// CAD File Data
#define Ref 0
#define Val 1
#define Package 2
#define PosX 3
#define PosY 4
#define Rot 5
#define Side 6

// Lib File Data
#define typeboitierCAO 0
#define valeurCAO 1
#define nomMYDATA 2
#define prioritée 3
#define montage 4
#define colle 5
#define angle 6

// Config File Data
#define Conf_OffsetX 0
#define Conf_OffsetY 1
#define Conf_Scale 2
#define Conf_Rot 3
#define Conf_Mirror 4

// CAD Buffer Data
#define PosX_buf 0
#define PosY_buf 1
#define Rot_buf 2

class CadData : public QObject
{
    Q_OBJECT
public:
    explicit CadData(QObject *parent = nullptr);
    QStringList ConfigData;
    QList<QStringList> LibData;
    QList<QStringList> UsedLibData;
    //QListIterator<QStringList> LibDataIterator(QList<QStringList>);
    QList<QStringList> KiCADData;
    int KiCADNumberOfLines;
    int KiCADNumberOfComponents;
    int LibFileNumberOfLines;
    int KiCADIterator = 0;
    void FindFiducials(QStringList _KiCADData);
    double FID1_X, FID1_Y, FID2_X, FID2_Y;
    double FID1_PCB_X, FID1_PCB_Y, FID2_PCB_X, FID2_PCB_Y;
    double FID1_LAY_X, FID1_LAY_Y, FID2_LAY_X, FID2_LAY_Y;
    void ApplyConfigurations();

signals:

public slots:
    void getCadConfigData(QString _ConfigData);
    void getLibData(QList<QStringList> _LibData, int _LibFileNumberOfLines);
    void getKiCADData(QList<QStringList> _KiCADData, int _KiCADNumberOfComponents);
    void getKiCADNumberOfLines(int _KiCADNumberOfLines);
};

#endif // CADDATA_H
