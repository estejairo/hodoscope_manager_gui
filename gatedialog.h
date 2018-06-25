#ifndef GATEDIALOG_H
#define GATEDIALOG_H

#include <QDialog>

namespace Ui {
class GateDialog;
}

class GateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GateDialog(QWidget *parent, double stored_gate);
    ~GateDialog();

private slots:
    void on_buttonBox_accepted();
signals:
    void gate_changed(double arg);
private:
    Ui::GateDialog *ui;
};

#endif // GATEDIALOG_H
