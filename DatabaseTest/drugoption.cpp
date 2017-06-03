#include "drugoption.h"
#include "ui_drugoption.h"
#include "patientgui.h"
#include "infusion.h"
#include "Common.h"
QString DrugName=0;
QString DrugConcentration=0;
QString DrugUnit=0;
Infusion *DrugOptionInfusion=0;
PatientGui *DrugOptionBack=0;
#include <QTime>


DrugOption::DrugOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrugOption)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    this->setStyleSheet("background-color:white");
    QTimer *Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this, SLOT(UpdateDefaults()));//CONNECT FUNCTIONS TO TIMEOUT,
    Timer->start(50);
}

DrugOption::~DrugOption()
{
    delete ui;
}
//CURRENT TIME RUNNING
void DrugOption::UpdateDefaults()
{

    ui->Time->setText(GuiTime.currentTime().toString ("HH:mm:ss"));
    ui->Date->setText(GuiDate.currentDate().toString ());
    if(ui->DrugCombo->currentText()=="Ropivacaine")
    {
        ui->ConcentrationUnit->setText("%");
        DrugUnit="%";
    }
        if(ui->DrugCombo->currentText()=="Fentanyl")

   {
             ui->ConcentrationUnit->setText("mcg");
              DrugUnit="mcg";
        }

}

void DrugOption::on_Back_clicked()
{

    DrugOptionBack=new PatientGui();
     DrugOptionBack->show();
 #ifdef USE_LINUX
     sleep(1);
 #else
     Sleep(20);
 #endif
     this->close();

}

void DrugOption::on_Ok_clicked()
{
    if(ui->DrugCombo->currentText()=="-")
    {
        ui->DrugNameError->setText("<font color=Red><b>Please Select A Drug</b></font>");
    }
    if(ui->DrugCombo->currentText()!="-")
    {
        ui->DrugNameError->setText("");
    }

    if(ui->DrugConcentration->text()=="")
    {
        ui->DrugConcentrationError->setText("<font color=Red><b>Please Key In Drug Concentration</b></font>");
    }
    if(ui->DrugConcentration->text()!="")
    {
        ui->DrugConcentrationError->setText("");
    }

    if(ui->DrugCombo->currentText()=="-"&& ui->DrugConcentration->text()=="")
    {
        ui->DrugNameError->setText("<font color=Red><b>Please Select A Drug</b></font>");
         ui->DrugConcentrationError->setText("<font color=Red><b>Please Key In Drug Concentration</b></font>");
    }
    if(ui->DrugConcentration->text()!=""&&(ui->DrugCombo->currentText()!="-"))
    {
    DrugName=ui->DrugCombo->currentText();
    DrugConcentration=ui->DrugConcentration->text();
    DrugOptionInfusion=new Infusion();
    DrugOptionInfusion->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->close();
    }
}

