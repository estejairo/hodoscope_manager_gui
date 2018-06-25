#include "wifimanager.h"
#include <iostream>

WifiManager::WifiManager(QObject *parent) :
    QObject(parent)
{

    offlineTimeout = 70;
    db = QSqlDatabase::addDatabase("QMYSQL");
    //db.setHostName("200.1.16.248");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("telescopes");
    db.setUserName("orsosa");
    db.setPort(10000);
    //db.setPassword("");
    if (!db.open()){
        qDebug()<<db.lastError();
        emit onlineFlag(false);
    }
    else{
        emit onlineFlag(true);
        queryData  = new QSqlQuery(db);
    }
}

WifiManager::~WifiManager(){
    delete queryData;
}

int WifiManager::getParameters(int npoints){
    double freq,azimuth,polar,distance,date,position;
    //uint date;
    queryData->finish();
    if(!queryData->exec(QString("SELECT freq, reg_date,position, azimuth_angle, polar_angle,distance\
                            FROM usm_telescope_data WHERE\
                            reg_date >= DATE_SUB(CURRENT_DATE, INTERVAL 6 MONTH)\
                           and freq < 5 ORDER BY reg_date DESC LIMIT %1").arg(npoints)))
    {
        qDebug()<<db.lastError();
        return 0;
    }
    queryData->next();
    freq       = queryData->value(0).toDouble();
    date       = (double)queryData->value(1).toDateTime().toTime_t();
    position   = queryData->value(2).toDouble();
    azimuth    = queryData->value(3).toDouble();
    polar      = queryData->value(4).toDouble();
    distance   = queryData->value(5).toDouble();

     while(queryData->next()){
        emit sendParameters(freq,date,position,azimuth,polar,distance);
        freq       = queryData->value(0).toDouble();
        date       = (double)queryData->value(1).toDateTime().toTime_t();
        position   = queryData->value(2).toDouble();
        azimuth    = queryData->value(3).toDouble();
        polar      = queryData->value(4).toDouble();
        distance   = queryData->value(5).toDouble();
     }
      emit sendParameters(freq,date,position,azimuth,polar,distance);
       queryData->clear();
  return 0;
}

void WifiManager::setParameters(double gate, double azimuth,double polar, double distance){
    queryData->first();

    if(!queryData->exec(QString("INSERT  INTO usm_telescope_parameters (gate,azimuth_angle,polar_angle,distance)  VALUES (%1,%2,%3,%4)").arg(gate).arg(azimuth).arg(polar).arg(distance)))
    {
         qDebug()<<db.lastError();
    }
}
