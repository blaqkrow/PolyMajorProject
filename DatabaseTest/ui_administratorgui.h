/********************************************************************************
** Form generated from reading UI file 'administratorgui.ui'
**
** Created: Fri Aug 23 05:20:14 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATORGUI_H
#define UI_ADMINISTRATORGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_administratorGui
{
public:
    QFrame *line;
    QLabel *label;
    QLabel *Date;
    QLabel *Time;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *Error;

    void setupUi(QWidget *administratorGui)
    {
        if (administratorGui->objectName().isEmpty())
            administratorGui->setObjectName(QString::fromUtf8("administratorGui"));
        administratorGui->resize(808, 486);
        QFont font;
        font.setPointSize(10);
        administratorGui->setFont(font);
        administratorGui->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(administratorGui);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 811, 20));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        line->setFont(font1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(administratorGui);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 471, 51));
        QFont font2;
        font2.setPointSize(28);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        Date = new QLabel(administratorGui);
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
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        Date->setFont(font3);
        Time = new QLabel(administratorGui);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(340, 10, 181, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        Time->setPalette(palette1);
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        Time->setFont(font4);
        progressBar = new QProgressBar(administratorGui);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(650, 10, 118, 23));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush3(QColor(0, 255, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush4(QColor(51, 153, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        progressBar->setPalette(palette2);
        progressBar->setValue(24);
        pushButton = new QPushButton(administratorGui);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 380, 251, 31));
        QFont font5;
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setWeight(75);
        pushButton->setFont(font5);
        pushButton->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        listWidget = new QListWidget(administratorGui);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(220, 200, 401, 121));
        QFont font6;
        font6.setPointSize(22);
        font6.setBold(true);
        font6.setWeight(75);
        listWidget->setFont(font6);
        pushButton_2 = new QPushButton(administratorGui);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 380, 251, 31));
        pushButton_2->setFont(font5);
        pushButton_2->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        label_2 = new QLabel(administratorGui);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 130, 551, 51));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush5);
        QBrush brush6(QColor(255, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush7(QColor(212, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush7);
        QBrush brush8(QColor(85, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush8);
        QBrush brush9(QColor(113, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush10(QColor(212, 127, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        QBrush brush11(QColor(255, 255, 220, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_2->setPalette(palette3);
        QFont font7;
        font7.setPointSize(20);
        font7.setBold(true);
        font7.setWeight(75);
        label_2->setFont(font7);
        Error = new QLabel(administratorGui);
        Error->setObjectName(QString::fromUtf8("Error"));
        Error->setGeometry(QRect(230, 330, 231, 31));
        QFont font8;
        font8.setPointSize(15);
        font8.setBold(true);
        font8.setWeight(75);
        Error->setFont(font8);

        retranslateUi(administratorGui);

        QMetaObject::connectSlotsByName(administratorGui);
    } // setupUi

    void retranslateUi(QWidget *administratorGui)
    {
        administratorGui->setWindowTitle(QApplication::translate("administratorGui", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("administratorGui", "Welcome Administrator ", 0, QApplication::UnicodeUTF8));
        Date->setText(QString());
        Time->setText(QString());
        pushButton->setText(QApplication::translate("administratorGui", "Main Menu", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("administratorGui", "Register A New Clinician", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("administratorGui", "Change IP Address", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton_2->setText(QApplication::translate("administratorGui", "Select", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        Error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class administratorGui: public Ui_administratorGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORGUI_H
