/********************************************************************************
** Form generated from reading UI file 'gatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GATEDIALOG_H
#define UI_GATEDIALOG_H

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

class Ui_GateDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *GateDialog)
    {
        if (GateDialog->objectName().isEmpty())
            GateDialog->setObjectName(QStringLiteral("GateDialog"));
        GateDialog->resize(320, 240);
        GateDialog->setStyleSheet(QLatin1String("background-color: rgb(206, 227, 246);\n"
"font: 75 italic bold 14pt \"Liberation Serif\";\n"
"color:rgb(26, 14, 165)"));
        buttonBox = new QDialogButtonBox(GateDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(GateDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 70, 113, 33));
        lineEdit->setAutoFillBackground(false);
        label = new QLabel(GateDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 70, 81, 31));
        label->setStyleSheet(QStringLiteral("font: Italic Bold 14pt \"Cantarell\";"));

        retranslateUi(GateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GateDialog);
    } // setupUi

    void retranslateUi(QDialog *GateDialog)
    {
        GateDialog->setWindowTitle(QApplication::translate("GateDialog", "Dialog", 0));
        label->setText(QApplication::translate("GateDialog", "Set gate", 0));
    } // retranslateUi

};

namespace Ui {
    class GateDialog: public Ui_GateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GATEDIALOG_H
