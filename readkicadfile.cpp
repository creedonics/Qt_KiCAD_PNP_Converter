#include "readkicadfile.h"

ReadKiCADFile::ReadKiCADFile(QObject *parent)
    : QObject{parent}
{}

void ReadKiCADFile::ReadingKicadFile(QString _FilePath, int _KiCADNumberOfLines)
{
    QFile file(_FilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    int KiCADNumberOfComponents = 0;
    QList<QStringList> KiCADData;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.indexOf("#") == -1) {
            KiCADData.append(line.simplified().split(' '));
            KiCADNumberOfComponents++;
        }
    }
    emit sendKiCADData(KiCADData, KiCADNumberOfComponents);
}

void ReadKiCADFile::GetKicadNumberOfLines(QString _FilePath, int _KiCADNumberOfLines)
{
    QFile file(_FilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    this->KiCADNumberOfLines = 0;
    while (!in.atEnd()) {
        in.readLine();
        this->KiCADNumberOfLines++;
    }
    emit sendKiCADNumberOfLines(KiCADNumberOfLines);
    //qInfo() << "readkicadfile.cpp : " << this->KiCADNumberOfLines;
}

void ReadKiCADFile::getFilePathUrl(QUrl _FilePathUrl)
{
    QString FilePath = _FilePathUrl.toLocalFile();
    GetKicadNumberOfLines(FilePath, this->KiCADNumberOfLines);
    ReadingKicadFile(FilePath, this->KiCADNumberOfLines);
}
