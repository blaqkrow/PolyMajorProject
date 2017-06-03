#include "administratorgui.h"
#include "ui_administratorgui.h"
#include "Common.h"
#include "registercliniciangui.h"
#include "changeipadd.h"
#include "logingui.h"
#include <QListWidget>

RegisterClinicianGui *RegisterClinician=0;
ChangeIpadd *ChangeIPAddress=0;
LoginGui *AdminLoginGui=0;
administratorGui::administratorGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administratorGui)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    this->setStyleSheet("background-color:WHITE;");
    ui->label_2->setText("<font color=Green><b>Please Select An Option :</b></font>");
    ui->listWidget->setStyleSheet("color: black; background-color: Yellow");

     //KEEP UPDATING FUNCTIONS
    QTimer *Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this, SLOT(UpdateDefaults()));//CONNECT FUNCTIONS TO TIMEOUT,

    Timer->start(50);//UPDATES THE TIME ON THE SCREEN EVERY 50MS

}

administratorGui::~administratorGui()
{
    delete ui;
}

void administratorGui::UpdateDefaults()
{

    ui->Time->setText(GuiTime.currentTime().toString ("HH:mm:ss"));
    ui->Date->setText(GuiDate.currentDate().toString ());

}


//TO PATIENTGUI PAGE
void administratorGui::AdminRegisterClinician()
{

    RegisterClinician=new RegisterClinicianGui();
    RegisterClinician->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->close();

}
void administratorGui::AdminChangeIPAddress()
{

    ChangeIPAddress=new ChangeIpadd();
    ChangeIPAddress->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->close();

}



void administratorGui::on_pushButton_clicked()
{
    AdminLoginGui=new LoginGui();
    AdminLoginGui->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->close();
}

void administratorGui::on_pushButton_2_clicked()
{

    if( ui->listWidget->currentItem()->text()=="Register A New Clinician")

   {
       AdminRegisterClinician();
   }
    if( ui->listWidget->currentItem()->text()=="Change IP Address")

    {
        AdminChangeIPAddress();
    }


}
