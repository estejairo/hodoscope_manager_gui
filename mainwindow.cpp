#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->window()->setWindowTitle("HuLC");
//Setting ploting configuration
    setPlotStyle();
//Objects

    npoints = 10;
    stored_gate = 5;
    stored_azimuth = 0;
    stored_polar = 0;
    stored_distance = 30;
    manager = new DataManager(this);
    x_data = new QVector<double>(npoints);
    y_data = new QVector<double>(npoints);

    /////// getting histogram limits

    initLimits();
    setLimits();

    connect(ui->gFreqTime->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->gFreqTime->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->gFreqTime->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->gFreqTime->yAxis2, SLOT(setRange(QCPRange)));

    ui->gFreqTime->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(5);
    ui->gFreqTime->setGraphicsEffect(effect);

    connect(this,&MainWindow::parameterChanged,manager,&DataManager::recieveDataFromMain);
    connect(this,&MainWindow::changeConnectionType,manager,&DataManager::connectionType);
    connect(manager,&DataManager::plotPoints,this,&MainWindow::plotTelescopeData);

    setInitValues();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initLimits()
{
    f_max = -1e6;
    f_min = 1e6;
    t_max = -UINT_MAX;
    t_min = UINT_MAX;
}

void MainWindow::setLimits()
{
    if (t_min_r>t_min ||
        t_max_r<t_max ||
        f_min_r>f_min ||
        f_max_r>f_max)
    {
      t_min_r = t_min-0.1*(t_max-t_min);
      t_max_r = t_max+0.1*(t_max-t_min);
      f_min_r = f_min-0.1*(f_max-f_min);
      f_max_r = f_max+0.1*(f_max-f_min);
      ui->gFreqTime->xAxis->setRange(t_min_r,t_max_r);
      ui->gFreqTime->yAxis->setRange(f_min_r,f_max_r);
    }
}

void MainWindow::plotTelescopeData(double *x, double *y, double f_avg, double f_sd){

     for(int i =0; i<npoints;i++){
        x_data->insert(i,1,x[i]);
        y_data->insert(i,1,y[i]);
     }

     f_max = -1e6;
     t_max = -UINT_MAX;
     t_min = UINT_MAX;

    double date;
    double freq;
    double f_min_a=1e6;

    for(int i = 0;i<npoints;i++){
        date = x_data->value(i);
        freq = y_data->value(i);
        if(t_max<date)  t_max=date;
        if(t_min>date)  t_min=date;
        if (freq>f_max) f_max=freq;
        if (freq<f_min_a) f_min_a=freq;
     std::cout<<"Plot i: "<<i<<" date: "<<date<<" freq: "<<freq<<std::endl;
    }

    if (date<t_min || date<t_min_r) t_min=date;
    if (f_min_a>f_min ||f_min_a<f_min_r) f_min=f_min_a;

    setLimits();

    ui->label_avg->setNum(f_avg);
    ui->label_sd->setNum(f_sd);

        ui->gFreqTime->graph(0)->setData((*x_data),(*y_data));
        ui->gFreqTime->replot();
}

void MainWindow::setPlotStyle()
{
    ui->gFreqTime->addGraph();
    ui->gFreqTime->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    ui->gFreqTime->graph()->setPen(QPen(QColor(120, 120, 120), 2, Qt::DashLine));

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->gFreqTime->setBackground(plotGradient);
    ui->gFreqTime->xAxis->setTickLabelColor(Qt::white);
    ui->gFreqTime->yAxis->setTickLabelColor(Qt::white);
    ui->gFreqTime->xAxis->setLabelColor(Qt::white);
    ui->gFreqTime->yAxis->setLabelColor(Qt::white);

    ui->gFreqTime->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->gFreqTime->xAxis->setDateTimeFormat("mm-ss");
    ui->gFreqTime->xAxis->setLabel("Time (mm-ss)");
    ui->gFreqTime->yAxis->setLabel("Frequency (Hz)");
}

void MainWindow::isOnline(bool onlineFlag){
    if (onlineFlag)
       ui->wifi_frame->setStyleSheet("background-image: url(\"wifi_on.png\");");
    else
       ui->wifi_frame->setStyleSheet("background-image: url(\"wifi_off.png\");");
}

void MainWindow::on_gateButton_released(){
    GateDialog *diag = new GateDialog(this,stored_gate);
    connect(diag,&GateDialog::gate_changed,this,&MainWindow::gate_valueChanged);
    diag->show();
}

void MainWindow::on_npointsButton_released()
{
    NpointsDialog *diag = new NpointsDialog(this,npoints);
    connect(diag,&NpointsDialog::npoints_changed,this,&MainWindow::npoints_valueChanged);
    diag->show();
}

void MainWindow::on_azimuthButton_released()
{
    AzimuthDialog *diag = new AzimuthDialog(this,stored_azimuth);
    connect(diag,&AzimuthDialog::azimuth_changed,this,&MainWindow::azimuth_valueChanged);
    diag->show();
}

void MainWindow::on_polarButton_released()
{
    PolarDialog *diag = new PolarDialog(this,stored_polar);
    connect(diag,&PolarDialog::polar_changed,this,&MainWindow::polar_valueChanged);
    diag->show();
}

void MainWindow::on_distanceButton_released()
{
    DistanceDialog *diag = new DistanceDialog(this,stored_distance);
    connect(diag,&DistanceDialog::distance_changed,this,&MainWindow::distance_valueChanged);
    diag->show();
}

void MainWindow::gate_valueChanged(double arg){
    stored_gate = arg;
    emit parameterChanged(stored_gate,stored_azimuth,stored_polar,stored_distance,npoints);
}

void MainWindow::npoints_valueChanged(int arg){
    if (arg<=npoints){initLimits();}
    if (arg>50) ui->gFreqTime->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 5));
    if (arg<20) ui->gFreqTime->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    npoints=arg;
    delete x_data;
    delete y_data;
    x_data = new QVector<double>(npoints);
    y_data = new QVector<double>(npoints);
    emit parameterChanged(stored_gate,stored_azimuth,stored_polar,stored_distance,npoints);
}
void MainWindow::azimuth_valueChanged(double arg){
    stored_azimuth = arg;
    emit parameterChanged(stored_gate,stored_azimuth,stored_polar,stored_distance,npoints);
}

void MainWindow::polar_valueChanged(double arg){
    stored_polar = arg;
    emit parameterChanged(stored_gate,stored_azimuth,stored_polar,stored_distance,npoints);
}

void MainWindow::distance_valueChanged(double arg){
    stored_distance = arg;
    emit parameterChanged(stored_gate,stored_azimuth,stored_polar,stored_distance,npoints);
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    emit changeConnectionType(checked);
}

void MainWindow::on_toolButton_clicked()
{
    QString name = QFileDialog::getSaveFileName(this, "Save file");
    ui->lineEdit->setText(name);
    emit fileName(name);
}

void MainWindow::on_pushButton_2_clicked()
{
    std::cout<<__FILE__<<__LINE__<<std::endl;
    bool checked = true;
    emit changeConnectionType(checked);
}

void MainWindow::setInitValues(){
    emit parameterChanged(stored_gate,stored_azimuth,stored_polar,stored_distance,npoints);
}
