/********************************************************************************
** Form generated from reading UI file 'registercliniciangui.ui'
**
** Created: Wed Aug 14 22:31:24 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERCLINICIANGUI_H
#define UI_REGISTERCLINICIANGUI_H

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

class Ui_RegisterClinicianGui
{
public:
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *Date;
    QFrame *line;
    QLabel *Time;
    QPushButton *ClearPassword;
    QLineEdit *Password;
    QLabel *PasswordLabel;
    QLabel *loginlabel;
    QPushButton *ClearID;
    QLineEdit *loginid;
    QPushButton *Back;
    QPushButton *Register;

    void setupUi(QWidget *RegisterClinicianGui)
    {
        if (RegisterClinicianGui->objectName().isEmpty())
            RegisterClinicianGui->setObjectName(QString::fromUtf8("RegisterClinicianGui"));
        RegisterClinicianGui->resize(808, 486);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Active, QPalette::Link, brush);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        QBrush brush1(QColor(51, 153, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        RegisterClinicianGui->setPalette(palette);
        label = new QLabel(RegisterClinicianGui);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 270, 191, 16));
        progressBar = new QProgressBar(RegisterClinicianGui);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(650, 10, 118, 23));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush2(QColor(0, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        progressBar->setPalette(palette1);
        progressBar->setValue(24);
        Date = new QLabel(RegisterClinicianGui);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setGeometry(QRect(20, 10, 191, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        Date->setPalette(palette2);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        Date->setFont(font);
        line = new QFrame(RegisterClinicianGui);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 811, 20));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        line->setFont(font1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        Time = new QLabel(RegisterClinicianGui);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(340, 10, 181, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        Time->setPalette(palette3);
        Time->setFont(font);
        ClearPassword = new QPushButton(RegisterClinicianGui);
        ClearPassword->setObjectName(QString::fromUtf8("ClearPassword"));
        ClearPassword->setGeometry(QRect(560, 220, 141, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        ClearPassword->setFont(font2);
        ClearPassword->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        Password = new QLineEdit(RegisterClinicianGui);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(360, 220, 181, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        Password->setPalette(palette4);
        QFont font3;
        font3.setPointSize(14);
        Password->setFont(font3);
        Password->setFocusPolicy(Qt::StrongFocus);
        PasswordLabel = new QLabel(RegisterClinicianGui);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setGeometry(QRect(140, 220, 211, 29));
        QFont font4;
        font4.setPointSize(28);
        font4.setBold(true);
        font4.setWeight(75);
        PasswordLabel->setFont(font4);
        loginlabel = new QLabel(RegisterClinicianGui);
        loginlabel->setObjectName(QString::fromUtf8("loginlabel"));
        loginlabel->setGeometry(QRect(140, 150, 211, 41));
        loginlabel->setFont(font4);
        ClearID = new QPushButton(RegisterClinicianGui);
        ClearID->setObjectName(QString::fromUtf8("ClearID"));
        ClearID->setGeometry(QRect(560, 160, 141, 31));
        ClearID->setFont(font2);
        ClearID->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        loginid = new QLineEdit(RegisterClinicianGui);
        loginid->setObjectName(QString::fromUtf8("loginid"));
        loginid->setGeometry(QRect(360, 160, 181, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        loginid->setPalette(palette5);
        loginid->setFont(font3);
        loginid->setFocusPolicy(Qt::StrongFocus);
        Back = new QPushButton(RegisterClinicianGui);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(450, 300, 141, 31));
        Back->setFont(font2);
        Back->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        Register = new QPushButton(RegisterClinicianGui);
        Register->setObjectName(QString::fromUtf8("Register"));
        Register->setGeometry(QRect(300, 300, 141, 31));
        Register->setFont(font2);
        Register->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));

        retranslateUi(RegisterClinicianGui);

        QMetaObject::connectSlotsByName(RegisterClinicianGui);
    } // setupUi

    void retranslateUi(QWidget *RegisterClinicianGui)
    {
        RegisterClinicianGui->setWindowTitle(QApplication::translate("RegisterClinicianGui", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        Date->setText(QString());
        Time->setText(QString());
        ClearPassword->setText(QApplication::translate("RegisterClinicianGui", "Clear Password", 0, QApplication::UnicodeUTF8));
        Password->setText(QString());
        PasswordLabel->setText(QApplication::translate("RegisterClinicianGui", "Password :", 0, QApplication::UnicodeUTF8));
        loginlabel->setText(QApplication::translate("RegisterClinicianGui", "Login ID   :", 0, QApplication::UnicodeUTF8));
        ClearID->setText(QApplication::translate("RegisterClinicianGui", "Clear Login ID", 0, QApplication::UnicodeUTF8));
        loginid->setText(QString());
        Back->setText(QApplication::translate("RegisterClinicianGui", "Back", 0, QApplication::UnicodeUTF8));
        Register->setText(QApplication::translate("RegisterClinicianGui", "Register", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegisterClinicianGui: public Ui_RegisterClinicianGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERCLINICIANGUI_H
