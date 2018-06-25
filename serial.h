#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>

class serial : public QSerialPort
{
    Q_OBJECT
public:
    explicit serial(QObject *parent = 0);

signals:
    void serial_openError(bool);
public slots:

};

#endif // SERIAL_H
