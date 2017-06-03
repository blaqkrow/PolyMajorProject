/********************************************************************************
** Form generated from reading UI file 'regimenoption.ui'
**
** Created: Wed Aug 14 22:31:24 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIMENOPTION_H
#define UI_REGIMENOPTION_H

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

class Ui_RegimenOption
{
public:
    QLabel *label;
    QPushButton *Regimen3;
    QPushButton *Regimen1;
    QPushButton *Regimen2;
    QPushButton *Back;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_3;
    QLabel *PatientIdentifier;
    QLabel *BedNo;
    QLabel *SpinBoxError;
    QLabel *Date;
    QProgressBar *progressBar;
    QLabel *Time;
    QFrame *line;

    void setupUi(QWidget *RegimenOption)
    {
        if (RegimenOption->objectName().isEmpty())
            RegimenOption->setObjectName(QString::fromUtf8("RegimenOption"));
        RegimenOption->resize(808, 486);
        label = new QLabel(RegimenOption);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 321, 21));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label->setPalette(palette);
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        Regimen3 = new QPushButton(RegimenOption);
        Regimen3->setObjectName(QString::fromUtf8("Regimen3"));
        Regimen3->setEnabled(true);
        Regimen3->setGeometry(QRect(30, 330, 729, 50));
        Regimen3->setFont(font);
        Regimen3->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        Regimen1 = new QPushButton(RegimenOption);
        Regimen1->setObjectName(QString::fromUtf8("Regimen1"));
        Regimen1->setGeometry(QRect(30, 100, 729, 50));
        Regimen1->setFont(font);
        Regimen1->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        Regimen2 = new QPushButton(RegimenOption);
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
        Back = new QPushButton(RegimenOption);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(340, 400, 131, 31));
        QFont font1;
        font1.setPointSize(18);
        Back->setFont(font1);
        Back->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        label_2 = new QLabel(RegimenOption);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 280, 411, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush2(QColor(255, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 63, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        label_2->setPalette(palette1);
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        doubleSpinBox = new QDoubleSpinBox(RegimenOption);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(430, 280, 91, 31));
        doubleSpinBox->setDecimals(2);
        doubleSpinBox->setMaximum(100);
        doubleSpinBox->setSingleStep(0.01);
        label_3 = new QLabel(RegimenOption);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 290, 161, 16));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_3->setFont(font3);
        PatientIdentifier = new QLabel(RegimenOption);
        PatientIdentifier->setObjectName(QString::fromUtf8("PatientIdentifier"));
        PatientIdentifier->setGeometry(QRect(40, 440, 271, 16));
        BedNo = new QLabel(RegimenOption);
        BedNo->setObjectName(QString::fromUtf8("BedNo"));
        BedNo->setGeometry(QRect(40, 460, 271, 16));
        SpinBoxError = new QLabel(RegimenOption);
        SpinBoxError->setObjectName(QString::fromUtf8("SpinBoxError"));
        SpinBoxError->setGeometry(QRect(590, 290, 201, 20));
        Date = new QLabel(RegimenOption);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setGeometry(QRect(30, 10, 191, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Active, QPalette::LinkVisited, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        Date->setPalette(palette2);
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        Date->setFont(font4);
        progressBar = new QProgressBar(RegimenOption);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(660, 10, 118, 23));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush7);
        QBrush brush9(QColor(0, 255, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush9);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        QBrush brush10(QColor(51, 153, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        progressBar->setPalette(palette3);
        progressBar->setValue(24);
        Time = new QLabel(RegimenOption);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(350, 10, 181, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        Time->setPalette(palette4);
        Time->setFont(font4);
        line = new QFrame(RegimenOption);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 811, 20));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        line->setFont(font5);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label->raise();
        Regimen3->raise();
        Regimen1->raise();
        Regimen2->raise();
        Back->raise();
        label_2->raise();
        doubleSpinBox->raise();
        label_3->raise();
        PatientIdentifier->raise();
        BedNo->raise();
        SpinBoxError->raise();
        line->raise();
        Date->raise();
        progressBar->raise();
        Time->raise();
        line->raise();

        retranslateUi(RegimenOption);

        QMetaObject::connectSlotsByName(RegimenOption);
    } // setupUi

    void retranslateUi(QWidget *RegimenOption)
    {
        RegimenOption->setWindowTitle(QApplication::translate("RegimenOption", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RegimenOption", "Please Select Regimen :", 0, QApplication::UnicodeUTF8));
        Regimen3->setText(QApplication::translate("RegimenOption", "3)  PCEA With User-Defined Basal Infusion", 0, QApplication::UnicodeUTF8));
        Regimen1->setText(QApplication::translate("RegimenOption", "1)CIPEA With Basal Infusion 5 ml/hr", 0, QApplication::UnicodeUTF8));
        Regimen2->setText(QApplication::translate("RegimenOption", "2) CIPEA With Basal Infusion 10 ml/hr", 0, QApplication::UnicodeUTF8));
        Back->setText(QApplication::translate("RegimenOption", "Back", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RegimenOption", "Please Select Basal Infusion Rate :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RegimenOption", "ml/hr", 0, QApplication::UnicodeUTF8));
        PatientIdentifier->setText(QString());
        BedNo->setText(QString());
        SpinBoxError->setText(QString());
        Date->setText(QString());
        Time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegimenOption: public Ui_RegimenOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIMENOPTION_H
