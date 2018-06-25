/********************************************************************************
** Form generated from reading UI file 'npointsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NPOINTSDIALOG_H
#define UI_NPOINTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_NpointsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *NpointsDialog)
    {
        if (NpointsDialog->objectName().isEmpty())
            NpointsDialog->setObjectName(QStringLiteral("NpointsDialog"));
        NpointsDialog->resize(320, 240);
        NpointsDialog->setStyleSheet(QLatin1String("background-color: rgb(206, 227, 246);\n"
"font: 75 italic bold 14pt \"Liberation Serif\";\n"
"color:rgb(26, 14, 165)"));
        buttonBox = new QDialogButtonBox(NpointsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(NpointsDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 121, 31));
        lineEdit = new QLineEdit(NpointsDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 80, 113, 33));
        lineEdit->setAutoFillBackground(true);

        retranslateUi(NpointsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NpointsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NpointsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NpointsDialog);
    } // setupUi

    void retranslateUi(QDialog *NpointsDialog)
    {
        NpointsDialog->setWindowTitle(QApplication::translate("NpointsDialog", "Dialog", 0));
        label->setText(QApplication::translate("NpointsDialog", "Set plot points", 0));
    } // retranslateUi

};

namespace Ui {
    class NpointsDialog: public Ui_NpointsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NPOINTSDIALOG_H
