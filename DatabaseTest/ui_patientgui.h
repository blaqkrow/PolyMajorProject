/********************************************************************************
** Form generated from reading UI file 'patientgui.ui'
**
** Created: Mon Aug 19 04:12:39 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTGUI_H
#define UI_PATIENTGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientGui
{
public:
    QLabel *errorMsg;
    QFrame *line;
    QLabel *ClinicianName;
    QLabel *label;
    QPushButton *ClearBedNumber;
    QLineEdit *bednumber;
    QLabel *bednumberlabel;
    QLineEdit *nric;
    QPushButton *ClearNric;
    QLabel *nriclabel;
    QPushButton *Register;
    QPushButton *Back;
    QProgressBar *progressBar;
    QLabel *Date;
    QLabel *Time;

    void setupUi(QWidget *PatientGui)
    {
        if (PatientGui->objectName().isEmpty())
            PatientGui->setObjectName(QString::fromUtf8("PatientGui"));
        PatientGui->resize(808, 486);
        PatientGui->setStyleSheet(QString::fromUtf8(""));
        errorMsg = new QLabel(PatientGui);
        errorMsg->setObjectName(QString::fromUtf8("errorMsg"));
        errorMsg->setGeometry(QRect(340, 150, 391, 21));
        QFont font;
        font.setPointSize(10);
        errorMsg->setFont(font);
        line = new QFrame(PatientGui);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 811, 20));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        line->setFont(font1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        ClinicianName = new QLabel(PatientGui);
        ClinicianName->setObjectName(QString::fromUtf8("ClinicianName"));
        ClinicianName->setGeometry(QRect(350, 60, 181, 31));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        ClinicianName->setFont(font2);
        label = new QLabel(PatientGui);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 321, 31));
        QPalette palette;
        QBrush brush(QColor(0, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        label->setPalette(palette);
        label->setFont(font2);
        ClearBedNumber = new QPushButton(PatientGui);
        ClearBedNumber->setObjectName(QString::fromUtf8("ClearBedNumber"));
        ClearBedNumber->setGeometry(QRect(550, 230, 141, 31));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        ClearBedNumber->setFont(font3);
        ClearBedNumber->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        bednumber = new QLineEdit(PatientGui);
        bednumber->setObjectName(QString::fromUtf8("bednumber"));
        bednumber->setGeometry(QRect(350, 240, 181, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        bednumber->setPalette(palette1);
        QFont font4;
        font4.setPointSize(14);
        bednumber->setFont(font4);
        bednumber->setInputMethodHints(Qt::ImhNone);
        bednumberlabel = new QLabel(PatientGui);
        bednumberlabel->setObjectName(QString::fromUtf8("bednumberlabel"));
        bednumberlabel->setGeometry(QRect(180, 220, 161, 55));
        QFont font5;
        font5.setPointSize(28);
        font5.setBold(true);
        font5.setWeight(75);
        bednumberlabel->setFont(font5);
        nric = new QLineEdit(PatientGui);
        nric->setObjectName(QString::fromUtf8("nric"));
        nric->setGeometry(QRect(350, 190, 181, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        QBrush brush5(QColor(127, 127, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush5);
        QBrush brush6(QColor(170, 170, 170, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        nric->setPalette(palette2);
        nric->setFont(font4);
        nric->setFocusPolicy(Qt::StrongFocus);
        nric->setStyleSheet(QString::fromUtf8(""));
        ClearNric = new QPushButton(PatientGui);
        ClearNric->setObjectName(QString::fromUtf8("ClearNric"));
        ClearNric->setGeometry(QRect(550, 196, 141, 31));
        ClearNric->setFont(font3);
        ClearNric->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        nriclabel = new QLabel(PatientGui);
        nriclabel->setObjectName(QString::fromUtf8("nriclabel"));
        nriclabel->setGeometry(QRect(180, 170, 171, 55));
        nriclabel->setFont(font5);
        Register = new QPushButton(PatientGui);
        Register->setObjectName(QString::fromUtf8("Register"));
        Register->setGeometry(QRect(260, 320, 141, 31));
        Register->setFont(font3);
        Register->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        Back = new QPushButton(PatientGui);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(410, 320, 141, 31));
        Back->setFont(font3);
        Back->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        progressBar = new QProgressBar(PatientGui);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(660, 10, 118, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush8(QColor(51, 153, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        progressBar->setPalette(palette3);
        progressBar->setValue(24);
        Date = new QLabel(PatientGui);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setGeometry(QRect(10, 10, 191, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Active, QPalette::LinkVisited, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        Date->setPalette(palette4);
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setWeight(75);
        Date->setFont(font6);
        Time = new QLabel(PatientGui);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(330, 10, 111, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        Time->setPalette(palette5);
        Time->setFont(font6);

        retranslateUi(PatientGui);

        QMetaObject::connectSlotsByName(PatientGui);
    } // setupUi

    void retranslateUi(QWidget *PatientGui)
    {
        PatientGui->setWindowTitle(QApplication::translate("PatientGui", "Form", 0, QApplication::UnicodeUTF8));
        errorMsg->setText(QString());
        ClinicianName->setText(QString());
        label->setText(QApplication::translate("PatientGui", "Logged In As Clinician :", 0, QApplication::UnicodeUTF8));
        ClearBedNumber->setText(QApplication::translate("PatientGui", "Clear Bed Number", 0, QApplication::UnicodeUTF8));
        bednumberlabel->setText(QApplication::translate("PatientGui", "Bed No :", 0, QApplication::UnicodeUTF8));
        ClearNric->setText(QApplication::translate("PatientGui", "Clear NRIC", 0, QApplication::UnicodeUTF8));
        nriclabel->setText(QApplication::translate("PatientGui", "NRIC    : ", 0, QApplication::UnicodeUTF8));
        Register->setText(QApplication::translate("PatientGui", "Register", 0, QApplication::UnicodeUTF8));
        Back->setText(QApplication::translate("PatientGui", "Back", 0, QApplication::UnicodeUTF8));
        Date->setText(QString());
        Time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PatientGui: public Ui_PatientGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTGUI_H
