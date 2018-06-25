/********************************************************************************
** Form generated from reading UI file 'polardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLARDIALOG_H
#define UI_POLARDIALOG_H

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

class Ui_PolarDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *PolarDialog)
    {
        if (PolarDialog->objectName().isEmpty())
            PolarDialog->setObjectName(QStringLiteral("PolarDialog"));
        PolarDialog->resize(320, 240);
        PolarDialog->setStyleSheet(QLatin1String("background-color: rgb(206, 227, 246);\n"
"font: 75 italic bold 14pt \"Liberation Serif\";\n"
"color:rgb(26, 14, 165)"));
        buttonBox = new QDialogButtonBox(PolarDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(PolarDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 121, 31));
        lineEdit = new QLineEdit(PolarDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 80, 113, 33));
        lineEdit->setAutoFillBackground(false);

        retranslateUi(PolarDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PolarDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PolarDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PolarDialog);
    } // setupUi

    void retranslateUi(QDialog *PolarDialog)
    {
        PolarDialog->setWindowTitle(QApplication::translate("PolarDialog", "Dialog", 0));
        label->setText(QApplication::translate("PolarDialog", "Set polar angle", 0));
    } // retranslateUi

};

namespace Ui {
    class PolarDialog: public Ui_PolarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLARDIALOG_H
