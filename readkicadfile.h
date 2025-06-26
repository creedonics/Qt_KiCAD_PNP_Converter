#ifndef READKICADFILE_H
#define READKICADFILE_H

#include <QObject>
#include <QDebug>
#include <QtCore>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include "caddata.h"

class ReadKiCADFile : public QObject
{
    Q_OBJECT
public:
    explicit ReadKiCADFile(QObject *parent = nullptr);
    void ReadingKicadFile(QString _FilePath);

signals:

public slots:
    void getFilePathUrl(QUrl _FilePathUrl);
};

#endif // READKICADFILE_H
