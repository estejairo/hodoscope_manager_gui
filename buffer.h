#ifndef BUFFER_H
#define BUFFER_H

#include <QObject>
#include <QVector>
#include "data.h"
#include <math.h>

class Buffer : public QObject
{
    Q_OBJECT
public:
    explicit Buffer(QObject *parent = 0);
    Data *d;
    QVector <Data> data;
    int maxSize;
    int push(Data d);
    int getNpointsFT(int n, double *&x, double *&y, double &mean, double &rms);
    void setMaxSize(int m){(m>maxSize)?(maxSize = m):(maxSize = maxSize);}
    int getMaxSize(){return maxSize;}
signals:

public slots:

private:

};

#endif // BUFFER_H
