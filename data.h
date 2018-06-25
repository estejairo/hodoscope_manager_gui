#ifndef DATA_H
#define DATA_H

//#include <QObject>

class Data
{
  //  Q_OBJECT
public:
   // explicit Data(QObject *parent = 0);
    explicit Data(double f=0,double x =0, double a=0, double p=0, double d=0, double t=0);
    double freq,position, azimuth,polar,distance,date ;

};

#endif // DATA_H
