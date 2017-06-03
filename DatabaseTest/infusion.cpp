#include "infusion.h"
#include "ui_infusion.h"
#include "logingui.h"
#include "infusionchangeregimen.h"
#include "patientgui.h"
#include "regimenoption.h"
#include "Common.h"
#include<stdio.h>
#include <QTime>
#include <QTableWidget>

infusionChangeRegimen*changeregimen=0;
LoginGui*infusionLogingui=0;
PatientGui*InfusionPatient=0;
int ChangeRegimenCount=0;

QTimer *StartInfuseData = new QTimer();
QTimer *PauseInfuseData = new QTimer();

extern int first_Regimen_Option;
extern int second_Regimen_Option;
extern int third_Regimen_Option;
extern double current_Infusion;
extern QString ClinicianID;
extern QString PatientNric;
extern QString BedNumber;
extern QString DrugName;
extern QString DrugConcentration;
extern QString DrugUnit;
extern "C++"
{
#include "DB_Api.h"
 #ifdef USE_LINUX
#include "Algo.h"
#endif

}

int GraphVol;
int GraphAB;
int GraphPB;
int GraphTotalPB;
Infusion::Infusion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Infusion)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    this->setStyleSheet("background-color:white");



    //KEEP UPDATING FUNCTIONS
    QTimer *Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this,SLOT(UpdateDefaults()));
    Timer->start(1);//UPDATES THE TIME ON THE SCREEN EVERY 1MS


    //SET DEFAULTS
    startTimer(0);//START TIMER
    mTotalTime=0;//SET TIMER TO 0
    ui->timeframe->setStyleSheet("background:Lime");                  //frame color
    ui->patientInfoFrame->setStyleSheet("background:orange");        //frame color
    ui->BolusFrame->setStyleSheet("background:yellow");              //frame color
    ui->TotalInfusionVolume->setText("0.00");
    ui->TotalPatientDemand->setText("0");
    ui->TotalMachineBolus->setText("0");
    ui->SuccessfulPatientDemand->setText("0");
    ui->Duration->setText("00:00.00");
    ui->StartTime->setText("-");
    ui->LockoutTime->setText("0.00.00");
    ui->PauseInfusion->hide();
    ui->StopInfuison->hide();

    ui->BedNo->setText(BedNumber);
    ui->Patientidentifier->setText(PatientNric);
    ui->ClinicianID->setText(ClinicianID);

    ui->DrugName->setText(DrugName);
    ui->DrugConcentrationUnit->setText(DrugUnit);
    ui->Concentration->setText(DrugConcentration);
//CHANGE REGIMEN FUNCTION NOT NEEDED
 ui->ChangeRegimen->hide();
 ui->label_2->hide();
 ui->RegimenNo->hide();
}
Infusion::~Infusion()
{
    delete ui;
}

//PAUSE EVERYTHING
void Infusion::on_PauseInfusion_clicked()
{
     disconnect (StartInfuseData,SIGNAL(timeout()),this,SLOT(UpdateInfusingDataFreq()));
     connect (PauseInfuseData,SIGNAL(timeout()),this,SLOT(UpdatePauseDataFreq()));
     disconnect (StartInfuseData,SIGNAL(timeout()),this,SLOT(UpdateInfusingDataTCP()));
     connect (PauseInfuseData,SIGNAL(timeout()),this,SLOT(UpdatePauseDataTCP()));
     PauseInfuseData->start(10000);
     pause();
//    ui->ChangeRegimen->show();
    ui->Status->setText("<font color=red><b>Pause</b></font>");
    ui->StartInfusion->show();
    ui->StartInfusion->setText("Resume");
    ui->PauseInfusion->hide();

    //SAVE DATA TO PATIENTSESSIONDETAILEDLOG WHERE STATE PAUSED//
    QString InfusionPaused="Infusion Paused at "+ui->Time->text();
    QByteArray pauseInfusion =InfusionPaused.toUtf8();
    EventLog_OnTriggered(pauseInfusion.constData());

}




//STOP INFUSION
void Infusion::on_StopInfuison_clicked()         //Save to database and go back to PatientGui for new operation
{

      disconnect (StartInfuseData,SIGNAL(timeout()),this,SLOT(UpdateInfusingDataFreq()));
      disconnect (PauseInfuseData,SIGNAL(timeout()),this,SLOT(UpdatePauseDataFreq()));
      disconnect (StartInfuseData,SIGNAL(timeout()),this,SLOT(UpdateInfusingDataTCP()));
      disconnect (PauseInfuseData,SIGNAL(timeout()),this,SLOT(UpdatePauseDataTCP()));
      UpdateStopDataFreq();
      UpdateStopDataTCP();

    //SAVE DATA TO PATIENTDETAILEDLOG WHERE STATE IS STOPPED//
      QString InfusionStops="Infusion For"+ui->Patientidentifier->text()+" Has Stopped";
      QByteArray StopsInfusion =InfusionStops.toUtf8();
      EventLog_OnTriggered(StopsInfusion.constData());

      QString PatientUnregistered= "Patient ID "+ui->Patientidentifier->text()+ " Unregistered From Bed Number "+ui->BedNo->text();
      QByteArray UnregisteredPatient =PatientUnregistered.toUtf8();
      EventLog_OnTriggered(UnregisteredPatient.constData());

      QString ClinicianLoggedOut="Clinician ID "+ui->ClinicianID->text()+  " Logged Out";
      QByteArray LoggedOutClinician =ClinicianLoggedOut.toUtf8();
      EventLog_OnTriggered(LoggedOutClinician.constData());
      StopInfusion();

#ifdef USE_LINUX
    btnStop(); //Infusion Syringe Start
#endif
}

//START INFUSION
void Infusion::on_StartInfusion_clicked()        //Start Infusion or resume infusion
{



    connect (StartInfuseData,SIGNAL(timeout()),this,SLOT(UpdateInfusingDataFreq()));
    connect (StartInfuseData,SIGNAL(timeout()),this,SLOT(UpdateInfusingDataTCP()));
    disconnect (PauseInfuseData,SIGNAL(timeout()),this,SLOT(UpdatePauseDataFreq()));
    disconnect (PauseInfuseData,SIGNAL(timeout()),this,SLOT(UpdatePauseDataTCP()));
    StartInfuseData->start(5000);
    //DATABSE ADD TIME

    //DATABASE ADD EVENT TYPE Infusion Starts
    QString InfusionStarts="Infusion For "+ui->Patientidentifier->text()+" Has Started/Resumed At " +ui->Time->text();
    QByteArray StartInfusion =InfusionStarts.toUtf8();
    EventLog_OnTriggered(StartInfusion.constData());

    ui->Status->setText("<font color=green><b>Running</b></font>");
    ui->StartInfusion->hide();
    ui->ChangeRegimen->hide();
    ui->PauseInfusion->show();
    ui->StopInfuison->show();

    //SET START TIME STAMP AND SAVE TO DATABASE
    QTime CurrentTime =QTime::currentTime();
    QString timeString=CurrentTime.toString();
    ui->StartTime->setText("" +timeString);


 #ifdef USE_LINUX
     btnStart(); //Infusion Syringe Start
#endif
    //START THE STOP WATCH WHEN STARTINFUSION BUTTON IS PRESSED
      start();



}




//START STOPWATCH
void Infusion::start()
{
    mStartTime = QDateTime::currentDateTime();
    mRunning = true;
}
//STOP STOPWATCH
void Infusion::stop()
{

    mRunning = false;
}

void Infusion::pause()
{
    timerEvent(new QTimerEvent(0));
    mTotalTime += mSessionTime;
    mRunning = false;
}


void Infusion::UpdateInfusingDataFreq()
{

    QByteArray patientIdentifier=ui->Patientidentifier->text().toUtf8();
    int TotalMachineBolus=ui->TotalMachineBolus->text().toInt();
    int TotalPatientDemand=ui->TotalPatientDemand->text().toInt();
    int TotalSuccessfulDemand=ui->SuccessfulPatientDemand->text().toInt();
    QByteArray CurrentInfusionRate=ui->CurrentInfusionRate->text().toUtf8();
    QByteArray TotalVolInfused=ui->TotalInfusionVolume->text().toUtf8();
    QString State="Infusing";
    QByteArray StateByte=State.toUtf8();
    int BedNumber=ui->BedNo->text().toInt();
    QByteArray ClinicianID=ui->ClinicianID->text().toUtf8();


    EventLog_OnPeriod(patientIdentifier.constData(),TotalMachineBolus,TotalPatientDemand,TotalSuccessfulDemand,CurrentInfusionRate.constData(),TotalVolInfused.constData(),StateByte.constData(),BedNumber,ClinicianID.constData());
}

void Infusion::UpdatePauseDataFreq()
{
    QByteArray patientIdentifier=ui->Patientidentifier->text().toUtf8();
    int TotalMachineBolus=ui->TotalMachineBolus->text().toInt();
    int TotalPatientDemand=ui->TotalPatientDemand->text().toInt();
    int TotalSuccessfulDemand=ui->SuccessfulPatientDemand->text().toInt();
    QByteArray CurrentInfusionRate=ui->CurrentInfusionRate->text().toUtf8();
    QByteArray TotalVolInfused=ui->TotalInfusionVolume->text().toUtf8();
    QString State="Pause Infusion";
    QByteArray StateByte=State.toUtf8();
    int BedNumber=ui->BedNo->text().toInt();
    QByteArray ClinicianID=ui->ClinicianID->text().toUtf8();


    EventLog_OnPeriod(patientIdentifier.constData(),TotalMachineBolus,TotalPatientDemand,TotalSuccessfulDemand,CurrentInfusionRate.constData(),TotalVolInfused.constData(),StateByte.constData(),BedNumber,ClinicianID.constData());
}

//UPDATE PATIENTSESSIONDETAILEDLOG DATABASE INFUSION STOP
void Infusion::UpdateStopDataFreq()
{
    QByteArray patientIdentifier=ui->Patientidentifier->text().toUtf8();
    int TotalMachineBolus=ui->TotalMachineBolus->text().toInt();
    int TotalPatientDemand=ui->TotalPatientDemand->text().toInt();
    int TotalSuccessfulDemand=ui->SuccessfulPatientDemand->text().toInt();
    QByteArray CurrentInfusionRate=ui->CurrentInfusionRate->text().toUtf8();
    QByteArray TotalVolInfused=ui->TotalInfusionVolume->text().toUtf8();
    QString State="Stop Infusion";
    QByteArray StateByte=State.toUtf8();
    int BedNumber=ui->BedNo->text().toInt();
    QByteArray ClinicianID=ui->ClinicianID->text().toUtf8();


    EventLog_OnPeriod(patientIdentifier.constData(),TotalMachineBolus,TotalPatientDemand,TotalSuccessfulDemand,CurrentInfusionRate.constData(),TotalVolInfused.constData(),StateByte.constData(),BedNumber,ClinicianID.constData());
}

//UPDATE TCPDATA DATABASE INFUSION START
void Infusion::UpdateInfusingDataTCP()
{

    QByteArray patientIdentifier=ui->Patientidentifier->text().toUtf8();
    int TotalMachineBolus=ui->TotalMachineBolus->text().toInt();
    int TotalPatientDemand=ui->TotalPatientDemand->text().toInt();
    int TotalSuccessfulDemand=ui->SuccessfulPatientDemand->text().toInt();
    QByteArray CurrentInfusionRate=ui->CurrentInfusionRate->text().toUtf8();
    QByteArray TotalVolInfused=ui->TotalInfusionVolume->text().toUtf8();
    QString State="Infusing";
    QByteArray StateByte=State.toUtf8();
    int BedNumber=ui->BedNo->text().toInt();
    QByteArray ClinicianID=ui->ClinicianID->text().toUtf8();
    EventLog_UpdateTCP(patientIdentifier.constData(),TotalMachineBolus,TotalPatientDemand,TotalSuccessfulDemand,CurrentInfusionRate.constData(),TotalVolInfused.constData(),StateByte.constData(),BedNumber,ClinicianID.constData());
}

//UPDATE TCPDATA DATABASE INFUSION PAUSE
void Infusion::UpdatePauseDataTCP()
{
    QByteArray patientIdentifier=ui->Patientidentifier->text().toUtf8();
    int TotalMachineBolus=ui->TotalMachineBolus->text().toInt();
    int TotalPatientDemand=ui->TotalPatientDemand->text().toInt();
    int TotalSuccessfulDemand=ui->SuccessfulPatientDemand->text().toInt();
    QByteArray CurrentInfusionRate=ui->CurrentInfusionRate->text().toUtf8();
    QByteArray TotalVolInfused=ui->TotalInfusionVolume->text().toUtf8();
    QString State="Pause Infusion";
    QByteArray StateByte=State.toUtf8();
    int BedNumber=ui->BedNo->text().toInt();
    QByteArray ClinicianID=ui->ClinicianID->text().toUtf8();
    EventLog_UpdateTCP(patientIdentifier.constData(),TotalMachineBolus,TotalPatientDemand,TotalSuccessfulDemand,CurrentInfusionRate.constData(),TotalVolInfused.constData(),StateByte.constData(),BedNumber,ClinicianID.constData());
}

//UPDATE TCPDATA DATABASE INFUSION STOP
void Infusion::UpdateStopDataTCP()
{
    QByteArray patientIdentifier=ui->Patientidentifier->text().toUtf8();
    int TotalMachineBolus=ui->TotalMachineBolus->text().toInt();
    int TotalPatientDemand=ui->TotalPatientDemand->text().toInt();
    int TotalSuccessfulDemand=ui->SuccessfulPatientDemand->text().toInt();
    QByteArray CurrentInfusionRate=ui->CurrentInfusionRate->text().toUtf8();
    QByteArray TotalVolInfused=ui->TotalInfusionVolume->text().toUtf8();
    QString State="Stop Infusion";
    QByteArray StateByte=State.toUtf8();
    int BedNumber=ui->BedNo->text().toInt();
    QByteArray ClinicianID=ui->ClinicianID->text().toUtf8();


    EventLog_UpdateTCP(patientIdentifier.constData(),TotalMachineBolus,TotalPatientDemand,TotalSuccessfulDemand,CurrentInfusionRate.constData(),TotalVolInfused.constData(),StateByte.constData(),BedNumber,ClinicianID.constData());
}


void Infusion::StopInfusion()
{
    infusionLogingui=new LoginGui();
    infusionLogingui->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->close();
}


void Infusion::UpdateDefaults()
{
#ifdef USE_LINUX
    QString  InfusedVol=QString::number(infusedVolumeReturn(),'f',2);
          QString AB=QString::number(ABReturn());
          QString PB=QString::number(PBReturn());
          QString TotalPB=QString::number(PBTotalReturn());

          ui->TotalInfusionVolume->setText(InfusedVol);
          ui->TotalMachineBolus->setText(AB);
          ui->SuccessfulPatientDemand->setText(PB);
          ui->TotalPatientDemand->setText(TotalPB);
#endif

                  ui->Time->setText(GuiTime.currentTime().toString ("HH:mm:ss"));
          ui->Date->setText(GuiDate.currentDate().toString ());
    QString InfusionRate=QString::number(current_Infusion);
    ui->CurrentInfusionRate->setText(InfusionRate);
    if (ChangeRegimenCount==0)
    {
       //SET 1st REGIMEN NUMBER.
       if (first_Regimen_Option==1)
       {
           ui->RegimenNo->setText("1");

       }
       if (first_Regimen_Option==2)
       {
           ui->RegimenNo->setText("2");
       }
       if (first_Regimen_Option==3)
        {
           ui->RegimenNo->setText("3");
        }
    }
   if (ChangeRegimenCount==1)
    {
       //SET 2nd REGIMEN NUMBER.
           if (second_Regimen_Option==1)
           {
               ui->RegimenNo->setText("1");

           }
           if (second_Regimen_Option==2)
           {
               ui->RegimenNo->setText("2");
           }
           if (second_Regimen_Option==3)
           {
               ui->RegimenNo->setText("3");
           }
   }
   if (ChangeRegimenCount==2)
       {
           //SET 1st REGIMEN NUMBER.
           if (third_Regimen_Option==1)
           {
               ui->RegimenNo->setText("1");

           }
           if (third_Regimen_Option==2)
           {
               ui->RegimenNo->setText("2");
           }
           if (third_Regimen_Option==3)
           {
               ui->RegimenNo->setText("3");
           }
       }
   if(ui->tabWidget->currentIndex()==0)
   {

   ui->label_15->setText("Infusion Text");
}
        if(ui->tabWidget->currentIndex()==1)
   {

       ui->label_15->setText("Graphs");
   }
}

//CHANGE NEW REGIMEN
void Infusion::on_ChangeRegimen_clicked()
{
    ChangeRegimenCount++;

    if (ChangeRegimenCount==1)
    {
     ui->label_2->setText("2nd Regimen No: ");
     changeregimen=new infusionChangeRegimen();
     changeregimen->show();

    }
    if (ChangeRegimenCount==2)
    {
        ui->label_2->setText("3nd Regimen No: ");
        ui->MaxRegimenCount->setText("<font color=red><b>Maximum Change Of Regimen</font></b>");
        ui->ChangeRegimen->setEnabled(false);


    changeregimen=new infusionChangeRegimen();
    changeregimen->show();
    }
}

//STOPWATCH CODES
void Infusion::timerEvent(QTimerEvent *)
{

    if(mRunning)
    {
        mSessionTime = mStartTime.secsTo(QDateTime::currentDateTime());
        qint64 time = mTotalTime + mSessionTime;
        time*111;
        unsigned int h = time / 60 / 60;           //IF GOT MS /1000
        unsigned int m = (time / 60) - (h * 60);  //IF GOT MS /1000
        unsigned int s = (time) - ((m +(h* 60))*60);       //IF GOT MS /1000

        const QString diff = QString("%1:%2:%3")
                                .arg(h,  2, 10, QChar('0'))
                                .arg(m,  2, 10, QChar('0'))
                                .arg(s,  2, 10, QChar('0'));


        ui->Duration->setText(diff);

    }
}


