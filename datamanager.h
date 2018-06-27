#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <QString>
#include "buffer.h"
#include "serialmanager.h"
#include "wifimanager.h"

class DataManager : public QObject
{
    Q_OBJECT
public:
    explicit DataManager(QObject *parent = 0);


signals:
    void sendData(QString);
    void plotPoints(double*,double*,double,double);
    void sendtoSerial(double,double,double,double);
    void sendtoSql(double,double,double,double);
    void newNpoints(int);
    void plot();

public slots:
    void processSerialData(QByteArray);
    void processSqlData(double,double,double,double,double,double);
    void sendSerialData(double,double,double,double);
    void sendPlot();
    void recieveDataFromMain(double, double, double, double,int);
    void connectionType();
    void getSql();
    void getSignal();
  //  void createFile(QString);
private:
    SerialManager *class_serial;
    WifiManager *class_wifi;
    Buffer *buffer;
    QByteArray dataArray;
  //  QString *filename;
    bool uart_state;
    int npoints;
    double gate, azimuth, polar, distance;
    int counter;
};

#endif // DATAMANAGER_H
