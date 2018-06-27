#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QGraphicsDropShadowEffect>

#include "serialmanager.h"
#include "wifimanager.h"
#include "gatedialog.h"
#include "npointsdialog.h"
#include "azimuthdialog.h"
#include "polardialog.h"
#include "distancedialog.h"
#include "datamanager.h"

extern bool check;
extern bool last_check;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double stored_gate,stored_azimuth,stored_polar,stored_distance;
    int npoints;

signals:

    void parameterChanged(double,double,double,double,int);
    void newNpoints(int);
    void changeConnectionType();
    void fileName(QString);

private slots:
    void plotTelescopeData(double*, double*, double , double );
    void isOnline(bool);

    void npoints_valueChanged(int);
    void gate_valueChanged(double);
    void azimuth_valueChanged(double);
    void distance_valueChanged(double);
    void polar_valueChanged(double);

    void on_gateButton_released();
    void on_npointsButton_released();
    void on_azimuthButton_released();
    void on_polarButton_released();
    void on_distanceButton_released();

    void on_checkBox_toggled(bool checked);
    void on_toolButton_clicked();

    void on_pushButton_2_clicked();

    void setInitValues();

private:
    Ui::MainWindow *ui;

    QVector<double> *y_data;
    QVector<double> *x_data;
    DataManager *manager;
    uint t_min,t_max,t_min_r,t_max_r;
    double f_min,f_max,f_min_r,f_max_r;

    void initLimits();
    void setPlotStyle();
    void setLimits();
};

#endif // MAINWINDOW_H
