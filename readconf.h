#ifndef READCONF_H
#define READCONF_H

#include <QObject>
#include <QDebug>
#include <QtCore>
#include <QStringList>
#include <QTextStream>
#include <QFile>

class ReadConf : public QObject
{
    Q_OBJECT
public:
    explicit ReadConf(QObject *parent = nullptr);

public slots :
    void readingMydataConfigFile(QUrl testing);
};

#endif // READCONF_H
