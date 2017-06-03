/********************************************************************************
** Form generated from reading UI file 'logingui.ui'
**
** Created: Fri Aug 23 05:20:14 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINGUI_H
#define UI_LOGINGUI_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginGui
{
public:
    QPushButton *loginButton;
    QLabel *errormsg;
    QLabel *passwordlabel;
    QLabel *loginlabel;
    QRadioButton *clinicianRB;
    QRadioButton *administratorRB;
    QPushButton *ClearID;
    QLineEdit *loginid;
    QPushButton *ClearPassword;
    QLineEdit *password;
    QFrame *line;
    QLabel *Date;
    QProgressBar *progressBar;
    QLabel *Time;

    void setupUi(QWidget *LoginGui)
    {
        if (LoginGui->objectName().isEmpty())
            LoginGui->setObjectName(QString::fromUtf8("LoginGui"));
        LoginGui->resize(808, 486);
        loginButton = new QPushButton(LoginGui);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(350, 350, 141, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        loginButton->setFont(font);
        loginButton->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        errormsg = new QLabel(LoginGui);
        errormsg->setObjectName(QString::fromUtf8("errormsg"));
        errormsg->setGeometry(QRect(270, 170, 431, 21));
        errormsg->setFont(font);
        passwordlabel = new QLabel(LoginGui);
        passwordlabel->setObjectName(QString::fromUtf8("passwordlabel"));
        passwordlabel->setGeometry(QRect(180, 250, 211, 41));
        QFont font1;
        font1.setPointSize(28);
        font1.setBold(true);
        font1.setWeight(75);
        passwordlabel->setFont(font1);
        loginlabel = new QLabel(LoginGui);
        loginlabel->setObjectName(QString::fromUtf8("loginlabel"));
        loginlabel->setGeometry(QRect(177, 189, 211, 51));
        loginlabel->setFont(font1);
        clinicianRB = new QRadioButton(LoginGui);
        clinicianRB->setObjectName(QString::fromUtf8("clinicianRB"));
        clinicianRB->setGeometry(QRect(270, 71, 191, 41));
        clinicianRB->setFont(font1);
        administratorRB = new QRadioButton(LoginGui);
        administratorRB->setObjectName(QString::fromUtf8("administratorRB"));
        administratorRB->setGeometry(QRect(270, 110, 321, 51));
        administratorRB->setFont(font1);
        ClearID = new QPushButton(LoginGui);
        ClearID->setObjectName(QString::fromUtf8("ClearID"));
        ClearID->setGeometry(QRect(597, 199, 141, 31));
        ClearID->setFont(font);
        ClearID->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        loginid = new QLineEdit(LoginGui);
        loginid->setObjectName(QString::fromUtf8("loginid"));
        loginid->setGeometry(QRect(397, 199, 181, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        loginid->setPalette(palette);
        QFont font2;
        font2.setPointSize(14);
        loginid->setFont(font2);
        loginid->setFocusPolicy(Qt::StrongFocus);
        ClearPassword = new QPushButton(LoginGui);
        ClearPassword->setObjectName(QString::fromUtf8("ClearPassword"));
        ClearPassword->setGeometry(QRect(597, 259, 141, 31));
        ClearPassword->setFont(font);
        ClearPassword->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        password = new QLineEdit(LoginGui);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(397, 259, 181, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        password->setPalette(palette1);
        password->setFont(font2);
        password->setEchoMode(QLineEdit::Normal);
        line = new QFrame(LoginGui);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 811, 20));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        line->setFont(font3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        Date = new QLabel(LoginGui);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setGeometry(QRect(0, 10, 191, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        Date->setPalette(palette2);
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        Date->setFont(font4);
        progressBar = new QProgressBar(LoginGui);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(630, 10, 118, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush3(QColor(0, 255, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush4(QColor(51, 153, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        progressBar->setPalette(palette3);
        progressBar->setValue(24);
        Time = new QLabel(LoginGui);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(320, 10, 141, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        Time->setPalette(palette4);
        Time->setFont(font4);

        retranslateUi(LoginGui);

        QMetaObject::connectSlotsByName(LoginGui);
    } // setupUi

    void retranslateUi(QWidget *LoginGui)
    {
        LoginGui->setWindowTitle(QApplication::translate("LoginGui", "Form", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("LoginGui", "Login", 0, QApplication::UnicodeUTF8));
        errormsg->setText(QString());
        passwordlabel->setText(QApplication::translate("LoginGui", "Password :", 0, QApplication::UnicodeUTF8));
        loginlabel->setText(QApplication::translate("LoginGui", "Login ID   :", 0, QApplication::UnicodeUTF8));
        clinicianRB->setText(QApplication::translate("LoginGui", "Clinician", 0, QApplication::UnicodeUTF8));
        administratorRB->setText(QApplication::translate("LoginGui", "Administrator", 0, QApplication::UnicodeUTF8));
        ClearID->setText(QApplication::translate("LoginGui", "Clear Login ID", 0, QApplication::UnicodeUTF8));
        ClearPassword->setText(QApplication::translate("LoginGui", "Clear Password", 0, QApplication::UnicodeUTF8));
        Date->setText(QString());
        Time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginGui: public Ui_LoginGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINGUI_H
