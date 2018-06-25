#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDateTime>

class SerialManager : public QSerialPort
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parent);
    ~SerialManager();
signals:
    void dataRead(QByteArray);
    void sendParams();
public slots:
    void readData();
    void sendData(QString);
private:
    QSerialPort *serial;

};

#endif // SERIALMANAGER_H
