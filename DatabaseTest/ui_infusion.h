/********************************************************************************
** Form generated from reading UI file 'infusion.ui'
**
** Created: Fri Aug 23 05:20:14 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFUSION_H
#define UI_INFUSION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Infusion
{
public:
    QFrame *timeframe;
    QLabel *Duration;
    QLabel *label_4;
    QLabel *StartTime;
    QLabel *label_5;
    QFrame *patientInfoFrame;
    QLabel *label;
    QLabel *Patientidentifier;
    QLabel *label_8;
    QLabel *ClinicianID;
    QLabel *MaxRegimenCount;
    QLabel *BedNo;
    QLabel *label_3;
    QFrame *line;
    QLabel *Date;
    QLabel *Time;
    QProgressBar *progressBar;
    QPushButton *ChangeRegimen;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *InfusionText;
    QFrame *BolusFrame;
    QLabel *label_6;
    QLabel *LockoutTime;
    QLabel *label_7;
    QLabel *TotalInfusionVolume;
    QLabel *label_12;
    QLabel *CurrentInfusionRate;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_24;
    QLabel *TotalPatientDemand;
    QLabel *label_16;
    QLabel *SuccessfulPatientDemand;
    QLabel *label_11;
    QLabel *TotalMachineBolus;
    QLabel *Status;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *DrugName;
    QLabel *Concentration;
    QLabel *label_18;
    QLabel *DrugConcentrationUnit;
    QLabel *RegimenNo;
    QWidget *graph;
    QLabel *label_15;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *StartInfusion;
    QPushButton *PauseInfusion;
    QPushButton *StopInfuison;
    QPushButton *DeliveryInProgress_2;
    QPushButton *SilenceAlarm;

    void setupUi(QWidget *Infusion)
    {
        if (Infusion->objectName().isEmpty())
            Infusion->setObjectName(QString::fromUtf8("Infusion"));
        Infusion->resize(808, 486);
        timeframe = new QFrame(Infusion);
        timeframe->setObjectName(QString::fromUtf8("timeframe"));
        timeframe->setGeometry(QRect(-10, 100, 921, 51));
        timeframe->setFrameShape(QFrame::StyledPanel);
        timeframe->setFrameShadow(QFrame::Raised);
        Duration = new QLabel(timeframe);
        Duration->setObjectName(QString::fromUtf8("Duration"));
        Duration->setGeometry(QRect(650, 10, 111, 29));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        Duration->setFont(font);
        label_4 = new QLabel(timeframe);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 10, 131, 29));
        label_4->setFont(font);
        StartTime = new QLabel(timeframe);
        StartTime->setObjectName(QString::fromUtf8("StartTime"));
        StartTime->setGeometry(QRect(240, 10, 121, 29));
        StartTime->setFont(font);
        label_5 = new QLabel(timeframe);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(390, 10, 251, 29));
        label_5->setFont(font);
        Duration->raise();
        label_4->raise();
        StartTime->raise();
        label_5->raise();
        patientInfoFrame = new QFrame(Infusion);
        patientInfoFrame->setObjectName(QString::fromUtf8("patientInfoFrame"));
        patientInfoFrame->setGeometry(QRect(0, 40, 811, 61));
        patientInfoFrame->setFrameShape(QFrame::StyledPanel);
        patientInfoFrame->setFrameShadow(QFrame::Raised);
        label = new QLabel(patientInfoFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 191, 19));
        label->setFont(font);
        Patientidentifier = new QLabel(patientInfoFrame);
        Patientidentifier->setObjectName(QString::fromUtf8("Patientidentifier"));
        Patientidentifier->setGeometry(QRect(210, 20, 91, 19));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        Patientidentifier->setPalette(palette);
        Patientidentifier->setFont(font);
        label_8 = new QLabel(patientInfoFrame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(310, 20, 141, 19));
        label_8->setFont(font);
        ClinicianID = new QLabel(patientInfoFrame);
        ClinicianID->setObjectName(QString::fromUtf8("ClinicianID"));
        ClinicianID->setGeometry(QRect(460, 20, 81, 19));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        ClinicianID->setPalette(palette1);
        ClinicianID->setFont(font);
        MaxRegimenCount = new QLabel(patientInfoFrame);
        MaxRegimenCount->setObjectName(QString::fromUtf8("MaxRegimenCount"));
        MaxRegimenCount->setGeometry(QRect(620, 40, 121, 16));
        BedNo = new QLabel(patientInfoFrame);
        BedNo->setObjectName(QString::fromUtf8("BedNo"));
        BedNo->setGeometry(QRect(680, 20, 71, 19));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        BedNo->setPalette(palette2);
        BedNo->setFont(font);
        label_3 = new QLabel(patientInfoFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(583, 20, 91, 20));
        label_3->setFont(font);
        line = new QFrame(Infusion);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 811, 9));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        line->setFont(font1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        Date = new QLabel(Infusion);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setGeometry(QRect(10, 10, 191, 21));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        Date->setPalette(palette3);
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        Date->setFont(font2);
        Time = new QLabel(Infusion);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(330, 10, 181, 21));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        Time->setPalette(palette4);
        Time->setFont(font2);
        progressBar = new QProgressBar(Infusion);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(677, 10, 81, 23));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush3(QColor(0, 255, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        QBrush brush4(QColor(51, 153, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        progressBar->setPalette(palette5);
        progressBar->setValue(24);
        ChangeRegimen = new QPushButton(Infusion);
        ChangeRegimen->setObjectName(QString::fromUtf8("ChangeRegimen"));
        ChangeRegimen->setGeometry(QRect(394, 529, 141, 31));
        ChangeRegimen->setMinimumSize(QSize(94, 0));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QRadialGradient gradient(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(255, 255, 255, 255));
        gradient.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush5(gradient);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QRadialGradient gradient1(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(255, 255, 255, 255));
        gradient1.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush6(gradient1);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush6);
        QRadialGradient gradient2(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(255, 255, 255, 255));
        gradient2.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush7(gradient2);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QRadialGradient gradient3(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(255, 255, 255, 255));
        gradient3.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush8(gradient3);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QRadialGradient gradient4(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(255, 255, 255, 255));
        gradient4.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush9(gradient4);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        QRadialGradient gradient5(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(255, 255, 255, 255));
        gradient5.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush10(gradient5);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QRadialGradient gradient6(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(255, 255, 255, 255));
        gradient6.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush11(gradient6);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QRadialGradient gradient7(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(255, 255, 255, 255));
        gradient7.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush12(gradient7);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        QRadialGradient gradient8(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(255, 255, 255, 255));
        gradient8.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush13(gradient8);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        ChangeRegimen->setPalette(palette6);
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        ChangeRegimen->setFont(font3);
        ChangeRegimen->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));
        label_2 = new QLabel(Infusion);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(574, 529, 140, 19));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label_2->setFont(font4);
        tabWidget = new QTabWidget(Infusion);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 150, 911, 281));
        tabWidget->setFont(font3);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        InfusionText = new QWidget();
        InfusionText->setObjectName(QString::fromUtf8("InfusionText"));
        BolusFrame = new QFrame(InfusionText);
        BolusFrame->setObjectName(QString::fromUtf8("BolusFrame"));
        BolusFrame->setGeometry(QRect(0, 0, 921, 261));
        BolusFrame->setMinimumSize(QSize(0, 0));
        QFont font5;
        font5.setPointSize(6);
        font5.setBold(false);
        font5.setWeight(50);
        font5.setKerning(false);
        BolusFrame->setFont(font5);
        BolusFrame->setFrameShape(QFrame::StyledPanel);
        BolusFrame->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(BolusFrame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 135, 271, 31));
        QFont font6;
        font6.setPointSize(20);
        font6.setBold(true);
        font6.setWeight(75);
        label_6->setFont(font6);
        LockoutTime = new QLabel(BolusFrame);
        LockoutTime->setObjectName(QString::fromUtf8("LockoutTime"));
        LockoutTime->setGeometry(QRect(280, 135, 101, 31));
        LockoutTime->setFont(font6);
        LockoutTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(BolusFrame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 50, 231, 31));
        label_7->setFont(font6);
        TotalInfusionVolume = new QLabel(BolusFrame);
        TotalInfusionVolume->setObjectName(QString::fromUtf8("TotalInfusionVolume"));
        TotalInfusionVolume->setGeometry(QRect(240, 50, 94, 31));
        TotalInfusionVolume->setFont(font6);
        TotalInfusionVolume->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_12 = new QLabel(BolusFrame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(720, 50, 94, 31));
        label_12->setFont(font6);
        CurrentInfusionRate = new QLabel(BolusFrame);
        CurrentInfusionRate->setObjectName(QString::fromUtf8("CurrentInfusionRate"));
        CurrentInfusionRate->setGeometry(QRect(650, 50, 70, 31));
        CurrentInfusionRate->setMinimumSize(QSize(0, 0));
        CurrentInfusionRate->setFont(font6);
        CurrentInfusionRate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_9 = new QLabel(BolusFrame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(320, 50, 94, 31));
        label_9->setFont(font6);
        label_10 = new QLabel(BolusFrame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(440, 50, 201, 31));
        label_10->setFont(font6);
        label_24 = new QLabel(BolusFrame);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 90, 311, 31));
        label_24->setFont(font6);
        TotalPatientDemand = new QLabel(BolusFrame);
        TotalPatientDemand->setObjectName(QString::fromUtf8("TotalPatientDemand"));
        TotalPatientDemand->setGeometry(QRect(670, 90, 94, 31));
        TotalPatientDemand->setFont(font6);
        TotalPatientDemand->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_16 = new QLabel(BolusFrame);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(440, 90, 211, 31));
        label_16->setFont(font6);
        SuccessfulPatientDemand = new QLabel(BolusFrame);
        SuccessfulPatientDemand->setObjectName(QString::fromUtf8("SuccessfulPatientDemand"));
        SuccessfulPatientDemand->setGeometry(QRect(320, 90, 94, 31));
        SuccessfulPatientDemand->setFont(font6);
        SuccessfulPatientDemand->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_11 = new QLabel(BolusFrame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(440, 135, 271, 31));
        label_11->setFont(font6);
        TotalMachineBolus = new QLabel(BolusFrame);
        TotalMachineBolus->setObjectName(QString::fromUtf8("TotalMachineBolus"));
        TotalMachineBolus->setGeometry(QRect(720, 135, 94, 31));
        TotalMachineBolus->setFont(font6);
        Status = new QLabel(BolusFrame);
        Status->setObjectName(QString::fromUtf8("Status"));
        Status->setGeometry(QRect(120, 220, 181, 35));
        Status->setFont(font6);
        label_13 = new QLabel(BolusFrame);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 220, 101, 35));
        label_13->setFont(font6);
        label_14 = new QLabel(BolusFrame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 5, 171, 31));
        label_14->setFont(font6);
        DrugName = new QLabel(BolusFrame);
        DrugName->setObjectName(QString::fromUtf8("DrugName"));
        DrugName->setGeometry(QRect(190, 5, 201, 31));
        DrugName->setFont(font6);
        Concentration = new QLabel(BolusFrame);
        Concentration->setObjectName(QString::fromUtf8("Concentration"));
        Concentration->setGeometry(QRect(650, 5, 94, 31));
        Concentration->setFont(font6);
        label_18 = new QLabel(BolusFrame);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(440, 5, 201, 31));
        label_18->setFont(font6);
        DrugConcentrationUnit = new QLabel(BolusFrame);
        DrugConcentrationUnit->setObjectName(QString::fromUtf8("DrugConcentrationUnit"));
        DrugConcentrationUnit->setGeometry(QRect(750, 5, 94, 31));
        DrugConcentrationUnit->setFont(font6);
        RegimenNo = new QLabel(BolusFrame);
        RegimenNo->setObjectName(QString::fromUtf8("RegimenNo"));
        RegimenNo->setGeometry(QRect(800, 70, 94, 20));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        RegimenNo->setPalette(palette7);
        RegimenNo->setFont(font2);
        tabWidget->addTab(InfusionText, QString());
        graph = new QWidget();
        graph->setObjectName(QString::fromUtf8("graph"));
        tabWidget->addTab(graph, QString());
        label_15 = new QLabel(Infusion);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(230, 10, 46, 13));
        widget = new QWidget(Infusion);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 440, 751, 35));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        StartInfusion = new QPushButton(widget);
        StartInfusion->setObjectName(QString::fromUtf8("StartInfusion"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QRadialGradient gradient9(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(255, 255, 255, 255));
        gradient9.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush14(gradient9);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush14);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QRadialGradient gradient10(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(255, 255, 255, 255));
        gradient10.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush15(gradient10);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush15);
        QRadialGradient gradient11(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(255, 255, 255, 255));
        gradient11.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush16(gradient11);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush16);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QRadialGradient gradient12(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(255, 255, 255, 255));
        gradient12.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush17(gradient12);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QRadialGradient gradient13(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(255, 255, 255, 255));
        gradient13.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush18(gradient13);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush18);
        QRadialGradient gradient14(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(255, 255, 255, 255));
        gradient14.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush19(gradient14);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush19);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QRadialGradient gradient15(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0, QColor(255, 255, 255, 255));
        gradient15.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush20(gradient15);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush20);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QRadialGradient gradient16(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0, QColor(255, 255, 255, 255));
        gradient16.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush21(gradient16);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush21);
        QRadialGradient gradient17(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0, QColor(255, 255, 255, 255));
        gradient17.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush22(gradient17);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush22);
        StartInfusion->setPalette(palette8);
        StartInfusion->setFont(font4);
        StartInfusion->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));

        horizontalLayout->addWidget(StartInfusion);

        PauseInfusion = new QPushButton(widget);
        PauseInfusion->setObjectName(QString::fromUtf8("PauseInfusion"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QRadialGradient gradient18(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient18.setSpread(QGradient::PadSpread);
        gradient18.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient18.setColorAt(0, QColor(255, 255, 255, 255));
        gradient18.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush23(gradient18);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush23);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QRadialGradient gradient19(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient19.setSpread(QGradient::PadSpread);
        gradient19.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient19.setColorAt(0, QColor(255, 255, 255, 255));
        gradient19.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush24(gradient19);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush24);
        QRadialGradient gradient20(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient20.setSpread(QGradient::PadSpread);
        gradient20.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient20.setColorAt(0, QColor(255, 255, 255, 255));
        gradient20.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush25(gradient20);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush25);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QRadialGradient gradient21(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient21.setSpread(QGradient::PadSpread);
        gradient21.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient21.setColorAt(0, QColor(255, 255, 255, 255));
        gradient21.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush26(gradient21);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush26);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QRadialGradient gradient22(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient22.setSpread(QGradient::PadSpread);
        gradient22.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient22.setColorAt(0, QColor(255, 255, 255, 255));
        gradient22.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush27(gradient22);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush27);
        QRadialGradient gradient23(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient23.setSpread(QGradient::PadSpread);
        gradient23.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient23.setColorAt(0, QColor(255, 255, 255, 255));
        gradient23.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush28(gradient23);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush28);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QRadialGradient gradient24(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient24.setSpread(QGradient::PadSpread);
        gradient24.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient24.setColorAt(0, QColor(255, 255, 255, 255));
        gradient24.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush29(gradient24);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush29);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QRadialGradient gradient25(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient25.setSpread(QGradient::PadSpread);
        gradient25.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient25.setColorAt(0, QColor(255, 255, 255, 255));
        gradient25.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush30(gradient25);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush30);
        QRadialGradient gradient26(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient26.setSpread(QGradient::PadSpread);
        gradient26.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient26.setColorAt(0, QColor(255, 255, 255, 255));
        gradient26.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush31(gradient26);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush31);
        PauseInfusion->setPalette(palette9);
        PauseInfusion->setFont(font4);
        PauseInfusion->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));

        horizontalLayout->addWidget(PauseInfusion);

        StopInfuison = new QPushButton(widget);
        StopInfuison->setObjectName(QString::fromUtf8("StopInfuison"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QRadialGradient gradient27(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient27.setSpread(QGradient::PadSpread);
        gradient27.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient27.setColorAt(0, QColor(255, 255, 255, 255));
        gradient27.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush32(gradient27);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush32);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QRadialGradient gradient28(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient28.setSpread(QGradient::PadSpread);
        gradient28.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient28.setColorAt(0, QColor(255, 255, 255, 255));
        gradient28.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush33(gradient28);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush33);
        QRadialGradient gradient29(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient29.setSpread(QGradient::PadSpread);
        gradient29.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient29.setColorAt(0, QColor(255, 255, 255, 255));
        gradient29.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush34(gradient29);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush34);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QRadialGradient gradient30(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient30.setSpread(QGradient::PadSpread);
        gradient30.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient30.setColorAt(0, QColor(255, 255, 255, 255));
        gradient30.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush35(gradient30);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush35);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QRadialGradient gradient31(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient31.setSpread(QGradient::PadSpread);
        gradient31.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient31.setColorAt(0, QColor(255, 255, 255, 255));
        gradient31.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush36(gradient31);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush36);
        QRadialGradient gradient32(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient32.setSpread(QGradient::PadSpread);
        gradient32.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient32.setColorAt(0, QColor(255, 255, 255, 255));
        gradient32.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush37(gradient32);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush37);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QRadialGradient gradient33(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient33.setSpread(QGradient::PadSpread);
        gradient33.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient33.setColorAt(0, QColor(255, 255, 255, 255));
        gradient33.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush38(gradient33);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush38);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QRadialGradient gradient34(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient34.setSpread(QGradient::PadSpread);
        gradient34.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient34.setColorAt(0, QColor(255, 255, 255, 255));
        gradient34.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush39(gradient34);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush39);
        QRadialGradient gradient35(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient35.setSpread(QGradient::PadSpread);
        gradient35.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient35.setColorAt(0, QColor(255, 255, 255, 255));
        gradient35.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush40(gradient35);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush40);
        StopInfuison->setPalette(palette10);
        StopInfuison->setFont(font4);
        StopInfuison->setContextMenuPolicy(Qt::PreventContextMenu);
        StopInfuison->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));

        horizontalLayout->addWidget(StopInfuison);

        DeliveryInProgress_2 = new QPushButton(widget);
        DeliveryInProgress_2->setObjectName(QString::fromUtf8("DeliveryInProgress_2"));
        DeliveryInProgress_2->setMinimumSize(QSize(94, 0));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QRadialGradient gradient36(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient36.setSpread(QGradient::PadSpread);
        gradient36.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient36.setColorAt(0, QColor(255, 255, 255, 255));
        gradient36.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush41(gradient36);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush41);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QRadialGradient gradient37(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient37.setSpread(QGradient::PadSpread);
        gradient37.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient37.setColorAt(0, QColor(255, 255, 255, 255));
        gradient37.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush42(gradient37);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush42);
        QRadialGradient gradient38(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient38.setSpread(QGradient::PadSpread);
        gradient38.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient38.setColorAt(0, QColor(255, 255, 255, 255));
        gradient38.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush43(gradient38);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush43);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QRadialGradient gradient39(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient39.setSpread(QGradient::PadSpread);
        gradient39.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient39.setColorAt(0, QColor(255, 255, 255, 255));
        gradient39.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush44(gradient39);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush44);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QRadialGradient gradient40(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient40.setSpread(QGradient::PadSpread);
        gradient40.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient40.setColorAt(0, QColor(255, 255, 255, 255));
        gradient40.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush45(gradient40);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush45);
        QRadialGradient gradient41(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient41.setSpread(QGradient::PadSpread);
        gradient41.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient41.setColorAt(0, QColor(255, 255, 255, 255));
        gradient41.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush46(gradient41);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush46);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QRadialGradient gradient42(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient42.setSpread(QGradient::PadSpread);
        gradient42.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient42.setColorAt(0, QColor(255, 255, 255, 255));
        gradient42.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush47(gradient42);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush47);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QRadialGradient gradient43(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient43.setSpread(QGradient::PadSpread);
        gradient43.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient43.setColorAt(0, QColor(255, 255, 255, 255));
        gradient43.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush48(gradient43);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush48);
        QRadialGradient gradient44(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient44.setSpread(QGradient::PadSpread);
        gradient44.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient44.setColorAt(0, QColor(255, 255, 255, 255));
        gradient44.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush49(gradient44);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush49);
        DeliveryInProgress_2->setPalette(palette11);
        DeliveryInProgress_2->setFont(font4);
        DeliveryInProgress_2->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));

        horizontalLayout->addWidget(DeliveryInProgress_2);

        SilenceAlarm = new QPushButton(widget);
        SilenceAlarm->setObjectName(QString::fromUtf8("SilenceAlarm"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QRadialGradient gradient45(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient45.setSpread(QGradient::PadSpread);
        gradient45.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient45.setColorAt(0, QColor(255, 255, 255, 255));
        gradient45.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush50(gradient45);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush50);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QRadialGradient gradient46(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient46.setSpread(QGradient::PadSpread);
        gradient46.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient46.setColorAt(0, QColor(255, 255, 255, 255));
        gradient46.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush51(gradient46);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush51);
        QRadialGradient gradient47(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient47.setSpread(QGradient::PadSpread);
        gradient47.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient47.setColorAt(0, QColor(255, 255, 255, 255));
        gradient47.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush52(gradient47);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush52);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QRadialGradient gradient48(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient48.setSpread(QGradient::PadSpread);
        gradient48.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient48.setColorAt(0, QColor(255, 255, 255, 255));
        gradient48.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush53(gradient48);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush53);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QRadialGradient gradient49(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient49.setSpread(QGradient::PadSpread);
        gradient49.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient49.setColorAt(0, QColor(255, 255, 255, 255));
        gradient49.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush54(gradient49);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush54);
        QRadialGradient gradient50(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient50.setSpread(QGradient::PadSpread);
        gradient50.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient50.setColorAt(0, QColor(255, 255, 255, 255));
        gradient50.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush55(gradient50);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush55);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QRadialGradient gradient51(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient51.setSpread(QGradient::PadSpread);
        gradient51.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient51.setColorAt(0, QColor(255, 255, 255, 255));
        gradient51.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush56(gradient51);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush56);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QRadialGradient gradient52(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient52.setSpread(QGradient::PadSpread);
        gradient52.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient52.setColorAt(0, QColor(255, 255, 255, 255));
        gradient52.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush57(gradient52);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush57);
        QRadialGradient gradient53(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient53.setSpread(QGradient::PadSpread);
        gradient53.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient53.setColorAt(0, QColor(255, 255, 255, 255));
        gradient53.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush58(gradient53);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush58);
        SilenceAlarm->setPalette(palette12);
        SilenceAlarm->setFont(font4);
        SilenceAlarm->setContextMenuPolicy(Qt::DefaultContextMenu);
        SilenceAlarm->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: 2px solid #000;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;"));

        horizontalLayout->addWidget(SilenceAlarm);

        timeframe->raise();
        patientInfoFrame->raise();
        line->raise();
        Date->raise();
        Time->raise();
        progressBar->raise();
        SilenceAlarm->raise();
        ChangeRegimen->raise();
        DeliveryInProgress_2->raise();
        StopInfuison->raise();
        StartInfusion->raise();
        label_2->raise();
        PauseInfusion->raise();
        SilenceAlarm->raise();
        tabWidget->raise();
        label_15->raise();
        CurrentInfusionRate->raise();
        BolusFrame->raise();

        retranslateUi(Infusion);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Infusion);
    } // setupUi

    void retranslateUi(QWidget *Infusion)
    {
        Infusion->setWindowTitle(QApplication::translate("Infusion", "Form", 0, QApplication::UnicodeUTF8));
        Duration->setText(QApplication::translate("Infusion", "Duration", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Infusion", "Start Time :", 0, QApplication::UnicodeUTF8));
        StartTime->setText(QApplication::translate("Infusion", "StartTime", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Infusion", "Duration(Since Start) :", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Infusion", "Patient Identifier :", 0, QApplication::UnicodeUTF8));
        Patientidentifier->setText(QString());
        label_8->setText(QApplication::translate("Infusion", "Clinician ID :", 0, QApplication::UnicodeUTF8));
        ClinicianID->setText(QString());
        MaxRegimenCount->setText(QString());
        BedNo->setText(QString());
        label_3->setText(QApplication::translate("Infusion", "Bed No :", 0, QApplication::UnicodeUTF8));
        Date->setText(QString());
        Time->setText(QString());
        ChangeRegimen->setText(QApplication::translate("Infusion", "Change Regimen", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Infusion", "1st Regimen No :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Infusion", "PCA Lockout Time :", 0, QApplication::UnicodeUTF8));
        LockoutTime->setText(QString());
        label_7->setText(QApplication::translate("Infusion", "Tot Vol Infused :", 0, QApplication::UnicodeUTF8));
        TotalInfusionVolume->setText(QApplication::translate("Infusion", "1000", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Infusion", "ml/hr", 0, QApplication::UnicodeUTF8));
        CurrentInfusionRate->setText(QString());
        label_9->setText(QApplication::translate("Infusion", "ml", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Infusion", "Infusion Rate :", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Infusion", "Successful PCA Bolus :", 0, QApplication::UnicodeUTF8));
        TotalPatientDemand->setText(QString());
        label_16->setText(QApplication::translate("Infusion", "Tot PCA Bolus :", 0, QApplication::UnicodeUTF8));
        SuccessfulPatientDemand->setText(QString());
        label_11->setText(QApplication::translate("Infusion", "Tot Machine Bolus :", 0, QApplication::UnicodeUTF8));
        TotalMachineBolus->setText(QString());
        Status->setText(QApplication::translate("Infusion", "Not Started", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Infusion", "Status :", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Infusion", "Drug Name :", 0, QApplication::UnicodeUTF8));
        DrugName->setText(QString());
        Concentration->setText(QString());
        label_18->setText(QApplication::translate("Infusion", "Concentration:", 0, QApplication::UnicodeUTF8));
        DrugConcentrationUnit->setText(QString());
        RegimenNo->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(InfusionText), QApplication::translate("Infusion", "Infusion Text", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(graph), QApplication::translate("Infusion", "Graphs", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Infusion", "TextLabel", 0, QApplication::UnicodeUTF8));
        StartInfusion->setText(QApplication::translate("Infusion", "Start", 0, QApplication::UnicodeUTF8));
        PauseInfusion->setText(QApplication::translate("Infusion", "Pause", 0, QApplication::UnicodeUTF8));
        StopInfuison->setText(QApplication::translate("Infusion", "Stop", 0, QApplication::UnicodeUTF8));
        DeliveryInProgress_2->setText(QApplication::translate("Infusion", "Delivery In Progress", 0, QApplication::UnicodeUTF8));
        SilenceAlarm->setText(QApplication::translate("Infusion", "Silence Alarm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Infusion: public Ui_Infusion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFUSION_H
