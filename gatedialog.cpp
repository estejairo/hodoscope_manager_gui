#include "gatedialog.h"
#include "ui_gatedialog.h"

GateDialog::GateDialog(QWidget *parent=0, double stored_gate=5) :
    QDialog(parent),
    ui(new Ui::GateDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Gate Selection");
    ui->lineEdit->setText(QString("%1").arg(stored_gate));
    ui->lineEdit->setFocus();
}

GateDialog::~GateDialog()
{
    delete ui;
}

void GateDialog::on_buttonBox_accepted()
{
   emit gate_changed(ui->lineEdit->text().toDouble());
}
