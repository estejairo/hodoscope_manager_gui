#ifndef NPOINTSDIALOG_H
#define NPOINTSDIALOG_H

#include <QDialog>

namespace Ui {
class NpointsDialog;
}

class NpointsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NpointsDialog(QWidget *parent,int npoints);
    ~NpointsDialog();

private slots:
    void on_buttonBox_accepted();

signals:
    void npoints_changed(int);

private:
    Ui::NpointsDialog *ui;
};

#endif // NPOINTSDIALOG_H
