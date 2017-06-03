#include "regimenoption.h"
#include "ui_regimenoption.h"
#include "infusion.h"
#include "patientgui.h"
#include "Common.h"

#include <iostream>
PatientGui*regimenBack=0;
Infusion*regimeninfusion=0;
int first_Regimen_Option=0;
double current_Infusion=0.00;

extern "C++"
{
#include "DB_Api.h"
}

RegimenOption::RegimenOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegimenOption)
{

    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    this->setStyleSheet("background-color:WHITE;");

    //KEEP UPDATING FUNCTIONS
    QTimer *Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this, SLOT(UpdateDefaults()));//CONNECT FUNCTIONS TO TIMEOUT,
    Timer->start(50);//UPDATES THE TIME ON THE SCREEN EVERY 50MS
    ui->Regimen3->setEnabled(false);
    ui->BedNo->hide();
    ui->PatientIdentifier->hide();

}

RegimenOption::~RegimenOption()
{
    delete ui;
}

void RegimenOption::on_Back_clicked()
{


    QString PatientUnregistered="Patient ID  "+ui->PatientIdentifier->text()+" Is Unregistered From Bed Number" +ui->BedNo->text();
    QByteArray UnregisteredPatient=PatientUnregistered.toUtf8();
    EventLog_OnTriggered(UnregisteredPatient.constData());
    regimenGuiBack();
}

//GO BACK TO PATIENTGUI PAGE
void RegimenOption::regimenGuiBack()
{
    regimenBack=new PatientGui();
    regimenBack->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->hide();
}

//GO TO INFUSION PAGE
void RegimenOption::regimenInfusionGui()
{
    regimeninfusion=new Infusion();
    regimeninfusion->show();
    #ifdef USE_LINUX
      sleep(1);
    #else
       Sleep(20);
    #endif
    this->close();
}

void RegimenOption::on_Regimen1_clicked()
{
first_Regimen_Option=1;
current_Infusion=5.00;
//SAVE FIRST REGIMEN TO PATIENTSESSIONSUMMARY TABLE
    QString Regimen1="Regimen 1 Selected At "+ui->Time->text();
    QByteArray SelectToRegimen1 =Regimen1.toUtf8();
    EventLog_OnTriggered(SelectToRegimen1.constData());
    regimenInfusionGui();

}

void RegimenOption::on_Regimen2_clicked()
{
 first_Regimen_Option=2;
 current_Infusion=10.00;
//SAVE FIRST REGIMEN TO PATIENTSESSIONSUMMARY TABLE
    QString Regimen2="Regimen 2 Selected At "+ui->Time->text();
    QByteArray SelectToRegimen2 =Regimen2.toUtf8();
    EventLog_OnTriggered(SelectToRegimen2.constData());
    regimenInfusionGui();
}

void RegimenOption::on_Regimen3_clicked()
{
  first_Regimen_Option=3;
  current_Infusion=ui->doubleSpinBox->text().toDouble();
//SAVE FIRST REGIMEN TO PATIENTSESSIONSUMMARY TABLE
    QString Regimen3="Regimen 3 With Infusion Value of "+ui->doubleSpinBox->text()+" Selected At "+ui->Time->text();
    QByteArray SelectToRegimen3 =Regimen3.toUtf8();
    EventLog_OnTriggered(SelectToRegimen3.constData());
    regimenInfusionGui();
}


void RegimenOption::on_doubleSpinBox_valueChanged(const QString &arg1)
{
    ui->Regimen3->setEnabled(true);
    if(arg1.toDouble()==100.00)
    {
         ui->SpinBoxError->setText("<font color=Red><b>(Maximum Infusion Rate !)</b></font>");
    }
    if(arg1.toDouble()==0.00)
    {
        ui->SpinBoxError->setText("<font color=Red><b>Please Input A Value More Than 0.00</b></font>");
    }
        else
            {
            ui->Regimen3->show();
            ui->Regimen3->setText("3)  PCEA With User-Defined Basal Infusion of "+arg1+" ml/hr");
            }
  }


void RegimenOption::UpdateDefaults()
{

    ui->Time->setText(GuiTime.currentTime().toString ("HH:mm:ss"));
    ui->Date->setText(GuiDate.currentDate().toString ());

}
