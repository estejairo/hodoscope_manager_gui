#include "npointsdialog.h"
#include "ui_npointsdialog.h"

NpointsDialog::NpointsDialog(QWidget *parent = 0,int npoints=10) :
    QDialog(parent),
    ui(new Ui::NpointsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Plot points");
    ui->lineEdit->setText(QString("%1").arg(npoints));
    ui->lineEdit->setFocus();
}

NpointsDialog::~NpointsDialog()
{
    delete ui;
}

void NpointsDialog::on_buttonBox_accepted()
{
     emit npoints_changed(ui->lineEdit->text().toInt());
}
