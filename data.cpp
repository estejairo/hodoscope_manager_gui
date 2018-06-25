#include "data.h"
/*
Data::Data(QObject *parent) : freq(0), azimuth(0),polar(0),distance(0),gate(0),date(0), npoints(0),
    QObject(parent)
{

}
*/
Data::Data(double f,double x, double a, double p, double d, double t) : freq(f),position(x), azimuth(a),polar(p),distance(d),date(t)
{

}
