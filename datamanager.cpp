#include "datamanager.h"
#include "mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QTextStream>

DataManager::DataManager(QObject *parent) :
    QObject(parent)
{
    buffer = new Buffer(this);
    //filename = new QString();
    counter = 0;
    npoints = 10;
    connect(this,&DataManager::plot,this,&DataManager::sendPlot);
    std::cout<<__FILE__<<__LINE__<<" inicializando Plot"<<std::endl;
    class_serial = new SerialManager(this);
    connect(class_serial,&SerialManager::dataRead,this,&DataManager::processSerialData);
    connect(class_serial,&SerialManager::sendParams,this,&DataManager::getSignal);
    connect(this,&DataManager::sendtoSerial,this,&DataManager::sendSerialData);
    connect(this,&DataManager::sendData,class_serial,&SerialManager::sendData);
    std::cout<<__FILE__<<__LINE__<<std::endl;

}

void DataManager::connectionType(bool uart){       //tipo de conexion seria: uart=1
    uart_state = uart;
std::cout<<__FILE__<<__LINE__<<std::endl;
    if(uart_state){
        std::cout<<__FILE__<<__LINE__<<std::endl;
        class_serial = new SerialManager(this);
       class_wifi->disconnect();                   //si esta uart , desconecta WIFI
       delete class_wifi;
        connect(class_serial,&SerialManager::dataRead,this,&DataManager::processSerialData);
        connect(class_serial,&SerialManager::sendParams,this,&DataManager::getSignal);
        connect(this,&DataManager::sendtoSerial,this,&DataManager::sendSerialData);
        connect(this,&DataManager::sendData,class_serial,&SerialManager::sendData);
        std::cout<<__FILE__<<__LINE__<<std::endl;
    }
    else{
        class_serial->disconnect();             //si esta WIFI, desconecta serial
        delete class_serial;
        class_wifi = new WifiManager(this);

        QTimer *timer = new QTimer(this);
        connect(timer,&QTimer::timeout,this,&DataManager::getSql);
        timer->start(200);

        connect(this,&DataManager::newNpoints,class_wifi,&WifiManager::getParameters);
        connect(class_wifi,&WifiManager::sendParameters,this,&DataManager::processSqlData);
        connect(this,&DataManager::sendtoSql,class_wifi,&WifiManager::setParameters);
    }
}

void DataManager::recieveDataFromMain(double g, double a, double p, double d, int np){
    npoints = np;                          //datos enviados desde interfaz principal.
    gate = g;
    azimuth = a;
    polar = p;

    if(uart_state){
        emit sendtoSerial(g,a,p,d);
    }
    else{
        emit sendtoSql(g,a,p,d);
    }
}

void DataManager::getSql(){
    emit newNpoints(npoints);
}

void DataManager::processSerialData(QByteArray dataIn){

    QByteArray f("f:");
    QByteArray a("a:");
    QByteArray p("p:");
    QByteArray dx("d:");
    QByteArray x("x:");
    QByteArray temp;
    int fi,ai,pi,dxi,xx,i,size;
    QDateTime t;
    Data d;
    double freq,azimuth,polar,distance,position;
    qDebug()<<"DataIn: "<<dataIn;
    size = dataIn.size();

    if(dataIn[0]=='#' && dataIn[size-1]=='*')
        dataArray.insert(0,dataIn);
    if(dataIn[0]!='#' && dataIn[size-1]=='*')
        dataArray.append(dataIn);
    if(dataIn[0]=='#' && dataIn[size-1]!='*')
            dataArray.insert(0,dataIn);
  qDebug()<<"Array: "<<dataArray;
    if(dataArray[0]=='#' && dataArray[dataArray.size()-1]=='*'){
        fi  = dataArray.lastIndexOf(f);
        ai  = dataArray.lastIndexOf(a);
        pi  = dataArray.lastIndexOf(p);
        dxi = dataArray.lastIndexOf(dx);
        xx  = dataArray.lastIndexOf(x);

        for(i=fi+2;i<ai;i++)
            temp.append(dataArray[i]);

        freq = temp.toDouble();
        qDebug()<<"Freq: "<<temp;
        temp.clear();

        for(i=ai+2;i<pi;i++)
            temp.append(dataArray[i]);

        azimuth = temp.toDouble();
        qDebug()<<"Azimtuh: "<<temp;
        temp.clear();

        for(i=pi+2;i<dxi;i++)
            temp.append(dataArray[i]);

        polar = temp.toDouble();
        qDebug()<<"Polar: "<<temp;
        temp.clear();

        for(i=dxi+2;i<xx;i++)
            temp.append(dataArray[i]);
        distance = temp.toDouble();
        qDebug()<<"Distance: "<<temp;
        temp.clear();

        for(i=xx+2;i<dataArray.size()-2;i++)
            temp.append(dataArray[i]);
        position = temp.toDouble();
        qDebug()<<"Position: "<<temp;
        temp.clear();

        dataArray.clear();
        dataIn.clear();
        std::cout<<__FILE__<<__LINE__<<std::endl;
            d.freq      = freq;
            d.azimuth   = azimuth;
            d.polar     = polar;
            d.distance  = distance;
            d.position  = position;
            d.date      = t.currentDateTime().toTime_t();
        qDebug()<<"Time: "<<t.currentDateTime().toTime_t();
            buffer->push(d);
            counter++;

            if(counter == npoints){
                emit plot();
                counter = 0;
            }
    }
}

void DataManager::processSqlData(double f, double da, double x, double a,double p, double dx ){

    Data d(f,x,a,p,dx,da);

    buffer->push(d);
    counter++;
std::cout<<"Nplots sql: "<<npoints<<std::endl;
    if(counter == npoints){
    std::cout<<__FILE__<<__LINE__<<std::endl;
        emit plot();
        counter = 0;
    }
}

void DataManager::getSignal(){

    emit sendtoSerial(gate,azimuth,polar,distance);

}

void DataManager::sendSerialData(double g, double a, double p, double d){

    QString gate = QString::number(g);
    QString azimuth = QString::number(a);
    QString polar = QString::number(p);
    QString distance = QString::number(d);

    QString parameters;
    parameters.append("!#");
    parameters.append(" pa: ");
    parameters.append(polar);
    parameters.append(" aa: ");
    parameters.append(azimuth);
    parameters.append(" dx: ");
    parameters.append(distance);
    parameters.append(" gate: ");
    parameters.append(gate);
    parameters.append(" #!");
    qDebug()<<"DataSend: "<<parameters;
    emit sendData(parameters);
}
/*
void DataManager::createFile(QString name){

    filename = name;
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug()<<"Could not open file for write";
    }

    QTextStream out(&file);
    out << "Date    Freq    Azimuth     Polar   Distance    Position";
}

void DataManager::writeFile(){
    QFile file(filename);
    QTextStream out(&file);
    out << buffer->d->date<<"   "<< buffer->d->freq ;
}
*/

void DataManager::sendPlot(){
    double *x; double *y;
    double mean, rms;

    buffer->setMaxSize(npoints);
    std::cout<<"Nplots Buffer: "<<npoints<<std::endl;
    buffer->getNpointsFT(npoints,x,y,mean,rms);

    for(int i=0;i<npoints;i++){
        std::cout<<"Buffer i: "<<i<<" date: "<<x[i]<<" freq: "<<y[i]<<std::endl;
    }
    std::cout<<"DataManager mean: "<<mean<<" rms:"<<rms<<std::endl;
    emit plotPoints(x,y,mean,rms);
}
