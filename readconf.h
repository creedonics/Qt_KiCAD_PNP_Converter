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
    ReadConf();

public slots :
    void test(QUrl testing);
};

#endif // READCONF_H
