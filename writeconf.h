#ifndef WRITECONF_H
#define WRITECONF_H

#include <QObject>
#include <QDebug>
#include <QtCore>
#include <QStringList>
#include <QTextStream>
#include <QFile>

class WriteConf : public QObject
{
    Q_OBJECT
public:
    explicit WriteConf(QObject *parent = nullptr);

signals:

public slots :
    void getThemStrings(QString &str);
};

#endif // WRITECONF_H
