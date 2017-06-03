/********************************************************************************
** Form generated from reading UI file 'clinicianoptions.ui'
**
** Created: Fri Aug 23 05:20:14 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLINICIANOPTIONS_H
#define UI_CLINICIANOPTIONS_H

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

class Ui_ClinicianOptions
{
public:
    QLabel *Date;
    QFrame *line;
    QLabel *Time;
    QProgressBar *progressBar;
    QListWidget *listWidget;
    QLabel *label_2;
    QPushButton *Select;
    QPushButton *Back;
    QLabel *label;
    QLabel *ClinicianID;

    void setupUi(QWidget *ClinicianOptions)
    {
        if (ClinicianOptions->objectName().isEmpty())
            ClinicianOptions->setObjectName(QString::fromUtf8("ClinicianOptions"));
        ClinicianOptions->resize(808, 486);
        Date = new QLabel(ClinicianOptions);
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
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        Date->setFont(font);
        line = new QFrame(ClinicianOptions);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 811, 20));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        line->setFont(font1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        Time = new QLabel(ClinicianOptions);
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
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        Time->setFont(font2);
        progressBar = new QProgressBar(ClinicianOptions);
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
        listWidget = new QListWidget(ClinicianOptions);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(220, 260, 441, 91));
        QFont font3;
        font3.setPointSize(22);
        font3.setBold(true);
        font3.setWeight(75);
        listWidget->setFont(font3);
        label_2 = new QLabel(ClinicianOptions);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 140, 551, 51));
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
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        label_2->setFont(font4);
        Select = new QPushButton(ClinicianOptions);
        Select->setObjectName(QString::fromUtf8("Select"));
        Select->setGeometry(QRect(160, 390, 251, 31));
        QFont font5;
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setWeight(75);
        Select->setFont(font5);
        Select->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        Back = new QPushButton(ClinicianOptions);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(420, 390, 251, 31));
        Back->setFont(font5);
        Back->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        label = new QLabel(ClinicianOptions);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 351, 51));
        QPalette palette4;
        QBrush brush12(QColor(0, 170, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush3);
        QBrush brush13(QColor(0, 212, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        QBrush brush14(QColor(0, 85, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush14);
        QBrush brush15(QColor(0, 113, 0, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush16(QColor(127, 212, 127, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush16);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush12);
        label->setPalette(palette4);
        label->setFont(font3);
        ClinicianID = new QLabel(ClinicianOptions);
        ClinicianID->setObjectName(QString::fromUtf8("ClinicianID"));
        ClinicianID->setGeometry(QRect(380, 60, 111, 51));
        ClinicianID->setFont(font3);

        retranslateUi(ClinicianOptions);

        QMetaObject::connectSlotsByName(ClinicianOptions);
    } // setupUi

    void retranslateUi(QWidget *ClinicianOptions)
    {
        ClinicianOptions->setWindowTitle(QApplication::translate("ClinicianOptions", "Form", 0, QApplication::UnicodeUTF8));
        Date->setText(QString());
        Time->setText(QString());

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("ClinicianOptions", "Register Patient", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("ClinicianOptions", "Check History", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_2->setText(QString());
        Select->setText(QApplication::translate("ClinicianOptions", "Select", 0, QApplication::UnicodeUTF8));
        Back->setText(QApplication::translate("ClinicianOptions", "Back", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ClinicianOptions", "Logged In As Clinician :", 0, QApplication::UnicodeUTF8));
        ClinicianID->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ClinicianOptions: public Ui_ClinicianOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLINICIANOPTIONS_H
