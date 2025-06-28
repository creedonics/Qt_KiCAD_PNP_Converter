#include "readkicadfile.h"

ReadKiCADFile::ReadKiCADFile(QObject *parent)
    : QObject{parent}
{}

void ReadKiCADFile::ReadingKicadFile(QString _FilePath, int _KiCADNumberOfLines)
{
    QFile file(_FilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        int i = 0;
        QStringList list[this->KiCADNumberOfLines];
        if(line.indexOf("#") == -1) {
            /*list[i] << line.simplified().split(' ');
            qInfo() << list[i];
            i++;*/
            emit sendKiCADData(line.simplified().split(' '));
            //emit sendCadConfigData(line.sliced(i + 2));
        }
    }
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
