#include "readkicadfile.h"

ReadKiCADFile::ReadKiCADFile(QObject *parent)
    : QObject{parent}
{}

void ReadKiCADFile::ReadingKicadFile(QString _FilePath)
{
    QFile file(_FilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        //QString testing;
        int i;
        if(line.indexOf("#") == -1) {
            //i = line.indexOf("=");
            qInfo() << line.split(' ');
            //emit sendCadConfigData(line.sliced(i + 2));
        }
    }
}

void ReadKiCADFile::getFilePathUrl(QUrl _FilePathUrl)
{
    QString FilePath = _FilePathUrl.toLocalFile();
    ReadingKicadFile(FilePath);
}
