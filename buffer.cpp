#include "buffer.h"
#include <iostream>


Buffer::Buffer(QObject *parent) : QObject(parent)
{
    maxSize=100;
    for(int i = 0; i<maxSize;i++){
        Data d;
        data.append(d);
    }
}

int Buffer::push(Data d){
    data.push_back(d);
    if(data.size()>maxSize){
        data.pop_front();
    }
    return 0;
}

int Buffer::getNpointsFT(int n, double *&x, double *&y, double &mean, double &rms){

    x = new double[n];
    y = new double[n];
    mean = 0; rms = 0;

    for(int i = data.size()-1;i>data.size()-n-1;i--){
        int ind = n-(data.size()-i);
        x[ind] = data[i].date;
        y[ind] = data[i].freq;

       mean += y[ind];
       rms  += y[ind]*y[ind];

    }

    mean = mean/n;
    rms = ( rms/(n-1) > n/(n-1)*pow(mean,2) )?( sqrt(rms/(n-1) - n/(n-1)*pow(mean,2)) ):-1.0;
    std::cout<<"Buffer mean: "<<mean<<" rms:"<<rms<<std::endl;
    return 0;
}
