/********************************************************************************
** Form generated from reading UI file 'infusionchangeregimen.ui'
**
** Created: Wed Aug 14 22:31:24 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFUSIONCHANGEREGIMEN_H
#define UI_INFUSIONCHANGEREGIMEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_infusionChangeRegimen
{
public:
    QPushButton *Regimen3;
    QLabel *PatientIdentifier;
    QLabel *SpinBoxError;
    QPushButton *Regimen2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *Regimen1;
    QPushButton *Back;
    QLabel *label;
    QLabel *BedNo;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *Regimen1Selected;
    QLabel *label_5;
    QLabel *Regimen2Selected;
    QFrame *line;
    QLabel *Date;
    QProgressBar *progressBar;
    QLabel *Time;

    void setupUi(QWidget *infusionChangeRegimen)
    {
        if (infusionChangeRegimen->objectName().isEmpty())
            infusionChangeRegimen->setObjectName(QString::fromUtf8("infusionChangeRegimen"));
        infusionChangeRegimen->resize(808, 486);
        Regimen3 = new QPushButton(infusionChangeRegimen);
        Regimen3->setObjectName(QString::fromUtf8("Regimen3"));
        Regimen3->setEnabled(true);
        Regimen3->setGeometry(QRect(30, 330, 729, 50));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        Regimen3->setFont(font);
        Regimen3->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        PatientIdentifier = new QLabel(infusionChangeRegimen);
        PatientIdentifier->setObjectName(QString::fromUtf8("PatientIdentifier"));
        PatientIdentifier->setGeometry(QRect(40, 440, 271, 16));
        SpinBoxError = new QLabel(infusionChangeRegimen);
        SpinBoxError->setObjectName(QString::fromUtf8("SpinBoxError"));
        SpinBoxError->setGeometry(QRect(610, 290, 181, 16));
        Regimen2 = new QPushButton(infusionChangeRegimen);
        Regimen2->setObjectName(QString::fromUtf8("Regimen2"));
        Regimen2->setGeometry(QRect(30, 200, 729, 50));
        Regimen2->setFont(font);
        Regimen2->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        label_2 = new QLabel(infusionChangeRegimen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 280, 411, 31));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 127, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(255, 63, 63, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        label_2->setPalette(palette);
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(infusionChangeRegimen);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 290, 51, 16));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        Regimen1 = new QPushButton(infusionChangeRegimen);
        Regimen1->setObjectName(QString::fromUtf8("Regimen1"));
        Regimen1->setGeometry(QRect(30, 120, 729, 50));
        Regimen1->setFont(font);
        Regimen1->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        Back = new QPushButton(infusionChangeRegimen);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(340, 400, 131, 41));
        QFont font3;
        font3.setPointSize(18);
        Back->setFont(font3);
        Back->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        label = new QLabel(infusionChangeRegimen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 321, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush8(QColor(120, 120, 120, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        label->setPalette(palette1);
        label->setFont(font);
        BedNo = new QLabel(infusionChangeRegimen);
        BedNo->setObjectName(QString::fromUtf8("BedNo"));
        BedNo->setGeometry(QRect(40, 460, 271, 16));
        doubleSpinBox = new QDoubleSpinBox(infusionChangeRegimen);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(430, 280, 91, 31));
        doubleSpinBox->setDecimals(2);
        doubleSpinBox->setMaximum(100);
        doubleSpinBox->setSingleStep(0.01);
        Regimen1Selected = new QLabel(infusionChangeRegimen);
        Regimen1Selected->setObjectName(QString::fromUtf8("Regimen1Selected"));
        Regimen1Selected->setGeometry(QRect(630, 70, 151, 20));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        Regimen1Selected->setFont(font4);
        label_5 = new QLabel(infusionChangeRegimen);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(660, 180, 151, 20));
        Regimen2Selected = new QLabel(infusionChangeRegimen);
        Regimen2Selected->setObjectName(QString::fromUtf8("Regimen2Selected"));
        Regimen2Selected->setGeometry(QRect(630, 170, 151, 20));
        Regimen2Selected->setFont(font4);
        line = new QFrame(infusionChangeRegimen);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 811, 20));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        line->setFont(font5);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        Date = new QLabel(infusionChangeRegimen);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setGeometry(QRect(40, 10, 191, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Active, QPalette::LinkVisited, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush5);
        Date->setPalette(palette2);
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setWeight(75);
        Date->setFont(font6);
        progressBar = new QProgressBar(infusionChangeRegimen);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(670, 10, 118, 23));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush6);
        QBrush brush9(QColor(0, 255, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush9);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        QBrush brush10(QColor(51, 153, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush5);
        progressBar->setPalette(palette3);
        progressBar->setValue(24);
        Time = new QLabel(infusionChangeRegimen);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(360, 10, 181, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush5);
        Time->setPalette(palette4);
        Time->setFont(font6);
        Regimen3->raise();
        PatientIdentifier->raise();
        SpinBoxError->raise();
        Regimen2->raise();
        label_2->raise();
        label_3->raise();
        Regimen1->raise();
        Back->raise();
        label->raise();
        BedNo->raise();
        doubleSpinBox->raise();
        Regimen1Selected->raise();
        label_5->raise();
        Regimen2Selected->raise();
        line->raise();
        line->raise();
        Date->raise();
        progressBar->raise();
        Time->raise();

        retranslateUi(infusionChangeRegimen);

        QMetaObject::connectSlotsByName(infusionChangeRegimen);
    } // setupUi

    void retranslateUi(QWidget *infusionChangeRegimen)
    {
        infusionChangeRegimen->setWindowTitle(QApplication::translate("infusionChangeRegimen", "Form", 0, QApplication::UnicodeUTF8));
        Regimen3->setText(QApplication::translate("infusionChangeRegimen", "3)  PCEA With User-Defined Basal Infusion", 0, QApplication::UnicodeUTF8));
        PatientIdentifier->setText(QString());
        SpinBoxError->setText(QString());
        Regimen2->setText(QApplication::translate("infusionChangeRegimen", "2) CIPEA With Basal Infusion 10 ml/hr", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("infusionChangeRegimen", "Please Select Basal Infusion Rate :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("infusionChangeRegimen", "ml/hr", 0, QApplication::UnicodeUTF8));
        Regimen1->setText(QApplication::translate("infusionChangeRegimen", "1)CIPEA With Basal Infusion 5 ml/hr", 0, QApplication::UnicodeUTF8));
        Back->setText(QApplication::translate("infusionChangeRegimen", "Back", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("infusionChangeRegimen", "Please Select Regimen :", 0, QApplication::UnicodeUTF8));
        BedNo->setText(QString());
        Regimen1Selected->setText(QString());
        label_5->setText(QString());
        Regimen2Selected->setText(QString());
        Date->setText(QString());
        Time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class infusionChangeRegimen: public Ui_infusionChangeRegimen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFUSIONCHANGEREGIMEN_H
