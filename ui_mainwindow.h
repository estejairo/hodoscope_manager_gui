/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *gFreqTime;
    QLabel *title;
    QFrame *wifi_frame;
    QFrame *frame;
    QPushButton *gateButton;
    QPushButton *npointsButton;
    QPushButton *azimuthButton;
    QPushButton *polarButton;
    QPushButton *distanceButton;
    QCheckBox *checkBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_avg;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_sd;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QToolButton *toolButton;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 700);
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(206, 227, 246);\n"
"font: 75 italic bold 11pt \"Liberation Serif\";\n"
"color:rgb(26, 14, 165)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gFreqTime = new QCustomPlot(centralWidget);
        gFreqTime->setObjectName(QStringLiteral("gFreqTime"));
        gFreqTime->setGeometry(QRect(170, 80, 540, 420));
        gFreqTime->setAutoFillBackground(false);
        title = new QLabel(centralWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(230, 10, 511, 51));
        title->setStyleSheet(QStringLiteral("font: 75 italic 30pt \"Liberation Serif\";"));
        wifi_frame = new QFrame(centralWidget);
        wifi_frame->setObjectName(QStringLiteral("wifi_frame"));
        wifi_frame->setGeometry(QRect(150, 20, 51, 45));
        wifi_frame->setStyleSheet(QLatin1String("QFrame{ \n"
"       background-color: transparent;\n"
"         background-image: url(\"wifi_off.png\");\n"
"         background-repeat: none; border: none;\n"
"}"));
        wifi_frame->setFrameShape(QFrame::StyledPanel);
        wifi_frame->setFrameShadow(QFrame::Raised);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(760, 20, 94, 84));
        frame->setStyleSheet(QLatin1String("\n"
"QFrame\n"
"{\n"
"    background-color: transparent;\n"
"    background-image: url(\"utfsm_silab.png\");\n"
"    background-repeat: none;    \n"
"    border: none;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gateButton = new QPushButton(centralWidget);
        gateButton->setObjectName(QStringLiteral("gateButton"));
        gateButton->setGeometry(QRect(20, 120, 127, 127));
        gateButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    background-image: url(\"default_button.png\");\n"
"    background-repeat: none;    \n"
"    border: none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"   background-image: url(\"hover_button.png\");\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"   background-image: url(\"press_button.png\");\n"
"}\n"
"	border-color: rgba(255, 255, 255, 0);"));
        npointsButton = new QPushButton(centralWidget);
        npointsButton->setObjectName(QStringLiteral("npointsButton"));
        npointsButton->setGeometry(QRect(20, 300, 127, 127));
        npointsButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    background-image: url(\"default_button.png\");\n"
"    background-repeat: none;    \n"
"    border: none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"   background-image: url(\"hover_button.png\");\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"   background-image: url(\"press_button.png\");\n"
"}\n"
"	border-color: rgba(255, 255, 255, 0);"));
        azimuthButton = new QPushButton(centralWidget);
        azimuthButton->setObjectName(QStringLiteral("azimuthButton"));
        azimuthButton->setGeometry(QRect(740, 120, 127, 127));
        azimuthButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    background-image: url(\"default_button.png\");\n"
"    background-repeat: none;    \n"
"    border: none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"   background-image: url(\"hover_button.png\");\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"   background-image: url(\"press_button.png\");\n"
"}\n"
"	border-color: rgba(255, 255, 255, 0);"));
        polarButton = new QPushButton(centralWidget);
        polarButton->setObjectName(QStringLiteral("polarButton"));
        polarButton->setGeometry(QRect(740, 260, 127, 127));
        polarButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    background-image: url(\"default_button.png\");\n"
"    background-repeat: none;    \n"
"    border: none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"   background-image: url(\"hover_button.png\");\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"   background-image: url(\"press_button.png\");\n"
"}\n"
"	border-color: rgba(255, 255, 255, 0);"));
        distanceButton = new QPushButton(centralWidget);
        distanceButton->setObjectName(QStringLiteral("distanceButton"));
        distanceButton->setGeometry(QRect(740, 400, 127, 127));
        distanceButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    background-image: url(\"default_button.png\");\n"
"    background-repeat: none;    \n"
"    border: none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"   background-image: url(\"hover_button.png\");\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"   background-image: url(\"press_button.png\");\n"
"}\n"
"	border-color: rgba(255, 255, 255, 0);"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(60, 530, 111, 26));
        checkBox->setCheckable(true);
        checkBox->setChecked(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 520, 391, 111));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter);

        label_avg = new QLabel(layoutWidget);
        label_avg->setObjectName(QStringLiteral("label_avg"));

        gridLayout->addWidget(label_avg, 0, 1, 1, 1, Qt::AlignHCenter);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1, Qt::AlignHCenter);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1, Qt::AlignHCenter);

        label_sd = new QLabel(layoutWidget);
        label_sd->setObjectName(QStringLiteral("label_sd"));

        gridLayout->addWidget(label_sd, 1, 1, 1, 1, Qt::AlignHCenter);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1, Qt::AlignHCenter);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(660, 600, 171, 31));
        lineEdit->setAutoFillBackground(true);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 560, 95, 31));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(730, 570, 26, 29));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(660, 580, 66, 21));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        title->setText(QApplication::translate("MainWindow", "Cosmic Ray Telescope Monitor", 0));
        gateButton->setText(QApplication::translate("MainWindow", "Set Gate", 0));
        npointsButton->setText(QApplication::translate("MainWindow", "Set Plots \n"
" Points", 0));
        azimuthButton->setText(QApplication::translate("MainWindow", "Set Azimuth \n"
" Angle", 0));
        polarButton->setText(QApplication::translate("MainWindow", "Set Polar \n"
" Angle", 0));
        distanceButton->setText(QApplication::translate("MainWindow", "Set \n"
" Dstance", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Serial enable", 0));
        label->setText(QApplication::translate("MainWindow", "Average", 0));
        label_avg->setText(QApplication::translate("MainWindow", "...", 0));
        label_5->setText(QApplication::translate("MainWindow", "[Hz]", 0));
        label_2->setText(QApplication::translate("MainWindow", "Stantard deviation", 0));
        label_sd->setText(QApplication::translate("MainWindow", "...", 0));
        label_6->setText(QApplication::translate("MainWindow", "[Hz]", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Start", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        label_3->setText(QApplication::translate("MainWindow", "Save as...", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
