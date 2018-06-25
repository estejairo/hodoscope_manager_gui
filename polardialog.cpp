#include "polardialog.h"
#include "ui_polardialog.h"

PolarDialog::PolarDialog(QWidget *parent=0, double stored_polar = 0) :
    QDialog(parent),
    ui(new Ui::PolarDialog)
{
    ui->setupUi(this);
    setWindowTitle("Polar angle Selection");
    ui->lineEdit->setText(QString("%1").arg(stored_polar));
    ui->lineEdit->setFocus();
}

PolarDialog::~PolarDialog()
{
    delete ui;
}

void PolarDialog::on_buttonBox_accepted()
{
    emit polar_changed(ui->lineEdit->text().toDouble());
}
