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
    QString offsetX;
    QString offsetY;
    QString scale;
    int rot;
    bool mirror;
    void WritingMydataConfigFile();

signals:

public slots :
    void getConfigParameters(QString _offsetX, QString _offsetY, QString _scale, int _rot, bool _mirror);

};

#endif // WRITECONF_H
