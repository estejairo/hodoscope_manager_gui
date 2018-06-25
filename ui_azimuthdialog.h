/********************************************************************************
** Form generated from reading UI file 'azimuthdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AZIMUTHDIALOG_H
#define UI_AZIMUTHDIALOG_H

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

class Ui_AzimuthDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *AzimuthDialog)
    {
        if (AzimuthDialog->objectName().isEmpty())
            AzimuthDialog->setObjectName(QStringLiteral("AzimuthDialog"));
        AzimuthDialog->resize(320, 240);
        AzimuthDialog->setStyleSheet(QLatin1String("background-color: rgb(206, 227, 246);\n"
"font: 75 italic bold 14pt \"Liberation Serif\";\n"
"color:rgb(26, 14, 165)"));
        buttonBox = new QDialogButtonBox(AzimuthDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AzimuthDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 151, 31));
        lineEdit = new QLineEdit(AzimuthDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 80, 113, 33));
        lineEdit->setAutoFillBackground(true);

        retranslateUi(AzimuthDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AzimuthDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AzimuthDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AzimuthDialog);
    } // setupUi

    void retranslateUi(QDialog *AzimuthDialog)
    {
        AzimuthDialog->setWindowTitle(QApplication::translate("AzimuthDialog", "Dialog", 0));
        label->setText(QApplication::translate("AzimuthDialog", "Set azimuth angle", 0));
    } // retranslateUi

};

namespace Ui {
    class AzimuthDialog: public Ui_AzimuthDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AZIMUTHDIALOG_H
