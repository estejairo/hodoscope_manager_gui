/********************************************************************************
** Form generated from reading UI file 'distancedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISTANCEDIALOG_H
#define UI_DISTANCEDIALOG_H

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

class Ui_DistanceDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *DistanceDialog)
    {
        if (DistanceDialog->objectName().isEmpty())
            DistanceDialog->setObjectName(QStringLiteral("DistanceDialog"));
        DistanceDialog->resize(320, 240);
        DistanceDialog->setStyleSheet(QLatin1String("background-color: rgb(206, 227, 246);\n"
"font: 75 italic bold 14pt \"Liberation Serif\";\n"
"color:rgb(26, 14, 165)"));
        buttonBox = new QDialogButtonBox(DistanceDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DistanceDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 101, 31));
        lineEdit = new QLineEdit(DistanceDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 80, 113, 33));
        lineEdit->setAutoFillBackground(false);

        retranslateUi(DistanceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DistanceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DistanceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DistanceDialog);
    } // setupUi

    void retranslateUi(QDialog *DistanceDialog)
    {
        DistanceDialog->setWindowTitle(QApplication::translate("DistanceDialog", "Dialog", 0));
        label->setText(QApplication::translate("DistanceDialog", "Set distance", 0));
    } // retranslateUi

};

namespace Ui {
    class DistanceDialog: public Ui_DistanceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISTANCEDIALOG_H
