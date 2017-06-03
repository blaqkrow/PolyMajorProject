#include "infusionchangeregimen.h"
#include "ui_infusionchangeregimen.h"
#include <QTimer>
#include "Common.h"
#include "regimenoption.h"
extern "C++"
{
#include "DB_Api.h"
}
extern int first_Regimen_Option;
extern int ChangeRegimenCount;
int second_Regimen_Option=0;
int third_Regimen_Option=0;
extern double current_Infusion;

infusionChangeRegimen::infusionChangeRegimen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infusionChangeRegimen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    this->setStyleSheet("background-color:white");
    ui->SpinBoxError->setEnabled(false);

    //KEEP UPDATING FUNCTIONS
    QTimer *Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this, SLOT(UpdateDefaults()));//CONNECT FUNCTIONS TO TIMEOUT,

    Timer->start(50);//UPDATES THE TIME ON THE SCREEN EVERY 50MS

if (ChangeRegimenCount==1)
{
    ui->label->setText("Please Select 2nd Regimen : ");
    if (first_Regimen_Option ==1)
    {
       ui->Regimen1->setEnabled(false);
       ui->Regimen1Selected->setText("<font color=red><b>*(Current Infusion)</b></font>");


    }
    if (first_Regimen_Option==2)
    {
        ui->Regimen2->setEnabled(false);
       ui->Regimen2Selected->setText("<font color=red><b>*(Current Infusion)</b></font>");
    }


}
if (ChangeRegimenCount==2)
{

    ui->label->setText("Please Select 3rd Regimen : ");
        if (second_Regimen_Option==1)
        {
             ui->Regimen1->setEnabled(false);
              ui->Regimen1Selected->setText("<font color=red><b>*(Current Infusion)</b></font>");
        }
        if (second_Regimen_Option==2)
        {
              ui->Regimen2->setEnabled(false);
              ui->Regimen2Selected->setText("<font color=red><b>*(Current Infusion)</b></font>");
        }

    }

}

infusionChangeRegimen::~infusionChangeRegimen()
{
    delete ui;
}

void infusionChangeRegimen::on_Regimen1_clicked()//change regimen(add 2nd and 3rd selection to database)
{
    if (ChangeRegimenCount==1)
    {
        current_Infusion=5;
        second_Regimen_Option=1;
    }
    if (ChangeRegimenCount==2)
    {
        current_Infusion=5;
        third_Regimen_Option=1;
    }
    QString Regimen1="Change Regeimen To Regimen 1 At "+ui->Time->text();
    QByteArray ChangeToRegimen1 =Regimen1.toUtf8();
    EventLog_OnTriggered(ChangeToRegimen1.constData());
this->close();
}

void infusionChangeRegimen::on_Regimen2_clicked()//change regimen(add 2nd and 3rd selection to database)
{
    if (ChangeRegimenCount==1)
    {
        current_Infusion=10;
        second_Regimen_Option=2;
    }
    if (ChangeRegimenCount==2)
    {
        current_Infusion=10;
        third_Regimen_Option=2;
    }
    QString Regimen2="Change Regeimen To Regimen 2 At "+ui->Time->text();
    QByteArray ChangeToRegimen2 =Regimen2.toUtf8();
    EventLog_OnTriggered(ChangeToRegimen2.constData());
this->close();

}

void infusionChangeRegimen::on_Regimen3_clicked()//change regimen(add 2nd and 3rd selection to database)
{
      if (ChangeRegimenCount==1)
      {
          current_Infusion=ui->doubleSpinBox->text().toDouble();
          second_Regimen_Option=3;
      }
      if (ChangeRegimenCount==2)
      {
          current_Infusion=ui->doubleSpinBox->text().toDouble();
          third_Regimen_Option=3;
      }
QString Regimen3="Change Regeimen To Regimen 3 At "+ui->Time->text();
QByteArray ChangeToRegimen3 =Regimen3.toUtf8();
EventLog_OnTriggered(ChangeToRegimen3.constData());
this->close();
}

void infusionChangeRegimen::on_Back_clicked()
{
    this->close();
}

void infusionChangeRegimen::UpdateDefaults()
{

    ui->Time->setText(GuiTime.currentTime().toString ("HH:mm:ss"));
    ui->Date->setText(GuiDate.currentDate().toString ());

}
void infusionChangeRegimen::on_doubleSpinBox_valueChanged(const QString &arg1)
{
    if(arg1.toDouble()==100.00)
    {
        ui->SpinBoxError->show();
         ui->Regimen3->setEnabled(false);
         ui->SpinBoxError->setText("<font color=Red><b>(Maximum Infusion Rate !)</b></font>");
    }
    if(arg1.toDouble()==0.00)
    {
        ui->Regimen3->setEnabled(false);
        ui->SpinBoxError->show();
        ui->SpinBoxError->setText("<font color=Red><b>Please Input A Value More Than 0.00</b></font>");
    }
 if(arg1.toDouble()<100.00)
 {
 ui->SpinBoxError->hide();
 }
        else
            {

            ui->Regimen3->setText("3)  PCEA With User-Defined Basal Infusion of "+arg1+" ml/hr");
            current_Infusion=arg1.toDouble();
               }
}
