#include "azimuthdialog.h"
#include "ui_azimuthdialog.h"

AzimuthDialog::AzimuthDialog(QWidget *parent=0,double stored_azimuth=0) :
    QDialog(parent),
    ui(new Ui::AzimuthDialog)
{
    ui->setupUi(this);
    setWindowTitle("Azimuth angle Selection");
    ui->lineEdit->setText(QString("%1").arg(stored_azimuth));
    ui->lineEdit->setFocus();
}

AzimuthDialog::~AzimuthDialog()
{
    delete ui;
}

void AzimuthDialog::on_buttonBox_accepted()
{
    emit azimuth_changed(ui->lineEdit->text().toDouble());
}
