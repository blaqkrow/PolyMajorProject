/********************************************************************************
** Form generated from reading UI file 'drugoption.ui'
**
** Created: Fri Aug 23 05:20:14 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRUGOPTION_H
#define UI_DRUGOPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrugOption
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *Time;
    QProgressBar *progressBar;
    QLabel *Date;
    QFrame *line;
    QComboBox *DrugCombo;
    QLabel *ConcentrationUnit;
    QPushButton *Ok;
    QPushButton *Back;
    QLineEdit *DrugConcentration;
    QLabel *DrugNameError;
    QLabel *DrugConcentrationError;

    void setupUi(QWidget *DrugOption)
    {
        if (DrugOption->objectName().isEmpty())
            DrugOption->setObjectName(QString::fromUtf8("DrugOption"));
        DrugOption->resize(808, 486);
        label = new QLabel(DrugOption);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 179, 241, 51));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(DrugOption);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 280, 391, 51));
        label_2->setFont(font);
        label_3 = new QLabel(DrugOption);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 851, 51));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        Time = new QLabel(DrugOption);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(330, 10, 181, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        Time->setPalette(palette);
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        Time->setFont(font2);
        progressBar = new QProgressBar(DrugOption);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(640, 10, 118, 23));
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
        Date = new QLabel(DrugOption);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setGeometry(QRect(10, 10, 191, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        Date->setPalette(palette2);
        Date->setFont(font2);
        line = new QFrame(DrugOption);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 811, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        DrugCombo = new QComboBox(DrugOption);
        DrugCombo->setObjectName(QString::fromUtf8("DrugCombo"));
        DrugCombo->setGeometry(QRect(440, 190, 271, 31));
        DrugCombo->setLayoutDirection(Qt::LeftToRight);
        DrugCombo->setAutoFillBackground(false);
        ConcentrationUnit = new QLabel(DrugOption);
        ConcentrationUnit->setObjectName(QString::fromUtf8("ConcentrationUnit"));
        ConcentrationUnit->setGeometry(QRect(520, 280, 51, 41));
        QFont font3;
        font3.setPointSize(22);
        ConcentrationUnit->setFont(font3);
        Ok = new QPushButton(DrugOption);
        Ok->setObjectName(QString::fromUtf8("Ok"));
        Ok->setGeometry(QRect(280, 390, 141, 31));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        Ok->setFont(font4);
        Ok->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        Back = new QPushButton(DrugOption);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(460, 390, 141, 31));
        Back->setFont(font4);
        Back->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        DrugConcentration = new QLineEdit(DrugOption);
        DrugConcentration->setObjectName(QString::fromUtf8("DrugConcentration"));
        DrugConcentration->setGeometry(QRect(430, 290, 71, 31));
        DrugNameError = new QLabel(DrugOption);
        DrugNameError->setObjectName(QString::fromUtf8("DrugNameError"));
        DrugNameError->setGeometry(QRect(310, 140, 381, 31));
        DrugNameError->setFont(font2);
        DrugConcentrationError = new QLabel(DrugOption);
        DrugConcentrationError->setObjectName(QString::fromUtf8("DrugConcentrationError"));
        DrugConcentrationError->setGeometry(QRect(320, 250, 381, 31));
        DrugConcentrationError->setFont(font2);
        QWidget::setTabOrder(Back, DrugConcentration);
        QWidget::setTabOrder(DrugConcentration, Ok);
        QWidget::setTabOrder(Ok, DrugCombo);

        retranslateUi(DrugOption);

        QMetaObject::connectSlotsByName(DrugOption);
    } // setupUi

    void retranslateUi(QWidget *DrugOption)
    {
        DrugOption->setWindowTitle(QApplication::translate("DrugOption", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DrugOption", "Drug Name :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DrugOption", "Drug Concentration :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DrugOption", "Please Select Drug And Drug Concentration", 0, QApplication::UnicodeUTF8));
        Time->setText(QString());
        Date->setText(QString());
        DrugCombo->clear();
        DrugCombo->insertItems(0, QStringList()
         << QApplication::translate("DrugOption", "-", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DrugOption", "Ropivacaine", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DrugOption", "Fentanyl", 0, QApplication::UnicodeUTF8)
        );
        ConcentrationUnit->setText(QString());
        Ok->setText(QApplication::translate("DrugOption", "Ok", 0, QApplication::UnicodeUTF8));
        Back->setText(QApplication::translate("DrugOption", "Back", 0, QApplication::UnicodeUTF8));
        DrugNameError->setText(QString());
        DrugConcentrationError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DrugOption: public Ui_DrugOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRUGOPTION_H
