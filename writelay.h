#ifndef WRITELAY_H
#define WRITELAY_H

#include <QObject>

class WriteLay : public QObject
{
    Q_OBJECT
public:
    explicit WriteLay(QObject *parent = nullptr);

signals:
};

#endif // WRITELAY_H
