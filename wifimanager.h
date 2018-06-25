#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QDebug>


class WifiManager : public QObject
{
    Q_OBJECT
public:
    explicit WifiManager(QObject *parent);
    ~WifiManager();
    uint offlineTimeout;

signals:
    void onlineFlag(bool);
    void sendParameters(double,double,double,double,double,double);
public slots:
    void setParameters(double,double,double,double);
    int getParameters(int);

private:
    QSqlDatabase db;
    QSqlQuery *queryData;
};

#endif // WIFIMANAGER_H
