/********************************************************************************
** Form generated from reading UI file 'changeipadd.ui'
**
** Created: Fri Aug 23 05:17:57 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEIPADD_H
#define UI_CHANGEIPADD_H

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

class Ui_ChangeIpadd
{
public:
    QFrame *line;
    QLabel *Date;
    QProgressBar *progressBar;
    QLabel *Time;
    QLabel *label;
    QLineEdit *newIPaddress;
    QLabel *Format;
    QPushButton *Set;
    QPushButton *back;
    QPushButton *IPClear;
    QLabel *errormsg;

    void setupUi(QWidget *ChangeIpadd)
    {
        if (ChangeIpadd->objectName().isEmpty())
            ChangeIpadd->setObjectName(QString::fromUtf8("ChangeIpadd"));
        ChangeIpadd->resize(808, 486);
        line = new QFrame(ChangeIpadd);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 811, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        line->setFont(font);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        Date = new QLabel(ChangeIpadd);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setGeometry(QRect(30, 10, 191, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        Date->setPalette(palette);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        Date->setFont(font1);
        progressBar = new QProgressBar(ChangeIpadd);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(650, 10, 118, 23));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush3(QColor(0, 255, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush4(QColor(51, 153, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        progressBar->setPalette(palette1);
        progressBar->setValue(24);
        Time = new QLabel(ChangeIpadd);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(340, 10, 181, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        Time->setPalette(palette2);
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        Time->setFont(font2);
        label = new QLabel(ChangeIpadd);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 140, 461, 51));
        QFont font3;
        font3.setPointSize(28);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        newIPaddress = new QLineEdit(ChangeIpadd);
        newIPaddress->setObjectName(QString::fromUtf8("newIPaddress"));
        newIPaddress->setGeometry(QRect(500, 150, 181, 31));
        QFont font4;
        font4.setPointSize(14);
        newIPaddress->setFont(font4);
        Format = new QLabel(ChangeIpadd);
        Format->setObjectName(QString::fromUtf8("Format"));
        Format->setGeometry(QRect(420, 190, 191, 21));
        QPalette palette3;
        QBrush brush5(QColor(255, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        Format->setPalette(palette3);
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        Format->setFont(font5);
        Set = new QPushButton(ChangeIpadd);
        Set->setObjectName(QString::fromUtf8("Set"));
        Set->setGeometry(QRect(280, 290, 141, 31));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        Set->setFont(font6);
        Set->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        back = new QPushButton(ChangeIpadd);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(430, 290, 141, 31));
        back->setFont(font6);
        back->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        IPClear = new QPushButton(ChangeIpadd);
        IPClear->setObjectName(QString::fromUtf8("IPClear"));
        IPClear->setGeometry(QRect(690, 150, 111, 31));
        IPClear->setFont(font6);
        IPClear->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        errormsg = new QLabel(ChangeIpadd);
        errormsg->setObjectName(QString::fromUtf8("errormsg"));
        errormsg->setGeometry(QRect(330, 100, 261, 20));
        QWidget::setTabOrder(newIPaddress, IPClear);
        QWidget::setTabOrder(IPClear, Set);
        QWidget::setTabOrder(Set, back);

        retranslateUi(ChangeIpadd);

        QMetaObject::connectSlotsByName(ChangeIpadd);
    } // setupUi

    void retranslateUi(QWidget *ChangeIpadd)
    {
        ChangeIpadd->setWindowTitle(QApplication::translate("ChangeIpadd", "Form", 0, QApplication::UnicodeUTF8));
        Date->setText(QString());
        Time->setText(QString());
        label->setText(QApplication::translate("ChangeIpadd", "Change IP Address         :", 0, QApplication::UnicodeUTF8));
        newIPaddress->setText(QString());
        Format->setText(QApplication::translate("ChangeIpadd", "Eg: 172.016.254.001", 0, QApplication::UnicodeUTF8));
        Set->setText(QApplication::translate("ChangeIpadd", "Set", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("ChangeIpadd", "Back", 0, QApplication::UnicodeUTF8));
        IPClear->setText(QApplication::translate("ChangeIpadd", "Clear", 0, QApplication::UnicodeUTF8));
        errormsg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChangeIpadd: public Ui_ChangeIpadd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEIPADD_H
