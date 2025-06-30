#ifndef READLIBFILE_H
#define READLIBFILE_H

#include <QObject>
#include <QDebug>
#include <QtCore>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include "caddata.h"

#define typeboitierCAO 0
#define valeurCAO 1
#define nomMYDATA 2
#define prioritée 3
#define montage 4
#define colle 5
#define angle 6

class ReadLibFile : public QObject
{
    Q_OBJECT
public:
    explicit ReadLibFile(QObject *parent = nullptr);
    QString LibFilePath = "MydataLibFile.lib";

public slots:
    void readingMydataLibFile();
signals:
    void sendLibData(QList<QStringList> _LibData, int _LibFileNumberOfLines);
};

#endif // READLIBFILE_H
