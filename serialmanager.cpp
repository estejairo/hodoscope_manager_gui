#include "serialmanager.h"
#include <QDebug>
#include <iostream>

SerialManager::SerialManager(QObject *parent) :
    QSerialPort(parent)
{
    serial = new QSerialPort;
std::cout<<__FILE__<<__LINE__<<" Construyendo SerialManager"<<std::endl;
    serial->setPortName("/dev/ttyUSB0");
    if (serial->open(QIODevice::ReadWrite)){
        std::cout<<__FILE__<<__LINE__<<" leyendo ttyUSB0"<<std::endl;
        serial->setBaudRate(QSerialPort::Baud57600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        std::cout<<__FILE__<<__LINE__<<" Conectado a ttyUSB0"<<std::endl;
    }
    else
        qDebug() <<"Error de conexion serial: ¿Tiene conectade el dispositive?";
std::cout<<__FILE__<<__LINE__<<" Conexión Completa"<<std::endl;
 connect(serial,&QSerialPort::readyRead,this,&SerialManager::readData);
 std::cout<<__FILE__<<__LINE__<<std::endl;
}

SerialManager::~SerialManager(){
    delete serial;
}

void SerialManager::readData(){
std::cout<<__FILE__<<__LINE__<<" Serial::readData()Abriendo"<<std::endl;
    QByteArray data = serial ->readAll();
    qDebug() << "data read: "<<data;
    if(data.contains("#g*")) emit sendParams();
    else emit dataRead(data);
    std::cout<<__FILE__<<__LINE__<<" Serial::readData Hecho."<<std::endl;
}
void SerialManager::sendData(QString data){
        std::cout<<__FILE__<<__LINE__<<" Serial::sendData()Abriendo"<<std::endl;
   serial->write(data.toStdString().c_str());
       std::cout<<__FILE__<<__LINE__<<" Serial::sendData()Hecho"<<std::endl;
}


