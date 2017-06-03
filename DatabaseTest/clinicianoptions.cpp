#include "clinicianoptions.h"
#include "ui_clinicianoptions.h"
#include "logingui.h"
#include "patientgui.h"
#include "Common.h"
extern QString ClinicianID;
LoginGui *ClinicianOptionsBack=0;
PatientGui *ClinicianOptionsPatientGui=0;
ClinicianOptions::ClinicianOptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClinicianOptions)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    this->setStyleSheet("background-color:WHITE;");
    ui->label_2->setText("<font color=Green><b>Please Select An Option :</b></font>");
    ui->listWidget->setStyleSheet("color: black; background-color: Yellow");
    QTimer *Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this, SLOT(UpdateDefaults()));//CONNECT FUNCTIONS TO TIMEOUT,

    Timer->start(50);//UPDATES THE TIME ON THE SCREEN EVERY 50MS
     ui->ClinicianID->setText(ClinicianID);

}

ClinicianOptions::~ClinicianOptions()
{
    delete ui;
}
void ClinicianOptions::UpdateDefaults()
{

    ui->Time->setText(GuiTime.currentTime().toString ("HH:mm:ss"));
    ui->Date->setText(GuiDate.currentDate().toString ());

}

void ClinicianOptions::on_Select_clicked()
{
    if( ui->listWidget->currentItem()->text()=="Register Patient")

   {

        ClinicianOptionRegisterPatient();
   }
    if( ui->listWidget->currentItem()->text()=="Check History")

    {
        ClinicianCheckHistory();
    }

}

void ClinicianOptions::on_Back_clicked()
{
    ClinicianBack();
}

void ClinicianOptions::ClinicianBack()
{

  ClinicianOptionsBack  =new LoginGui();
    ClinicianOptionsBack->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->close();

}
void ClinicianOptions::ClinicianOptionRegisterPatient()
{

    ClinicianOptionsPatientGui  =new PatientGui();
    ClinicianOptionsPatientGui->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->close();

}
void ClinicianOptions::ClinicianCheckHistory()
{



}

