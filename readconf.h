#ifndef READCONF_H
#define READCONF_H

#include <QObject>
#include <QDebug>
#include <QtCore>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include "caddata.h"

class ReadConf : public QObject
{
    Q_OBJECT
public:
    explicit ReadConf(QObject *parent = nullptr);
    void ReadingMydataConfigFile(QString _FilePath);
    QString FilePath;

signals:
    void sendCadConfigData(QString _ConfigData);

public slots :
    void getFilePathUrl(QUrl _FilePathUrl);
};

#endif // READCONF_H
