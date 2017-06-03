#include "registercliniciangui.h"
#include "ui_registercliniciangui.h"
#include "administratorgui.h"
#include "Common.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
extern "C++"
{
#include "DB_Api.h"
}

administratorGui * BackRegisterClinician=0;
RegisterClinicianGui::RegisterClinicianGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterClinicianGui)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    this->setStyleSheet("background-color:WHITE;");
    QTimer *Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this, SLOT(UpdateDefaults()));//CONNECT FUNCTIONS TO TIMEOUT,
    Timer->start(50);//UPDATES THE TIME ON THE SCREEN EVERY 50MS
}

RegisterClinicianGui::~RegisterClinicianGui()
{
    delete ui;
}

void RegisterClinicianGui::on_Back_clicked()
{
    RegisterClinicianBack();
}
void RegisterClinicianGui::RegisterClinicianBack()
{
    BackRegisterClinician=new administratorGui();
    BackRegisterClinician->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->close();
}

void RegisterClinicianGui::on_Register_clicked()
{

int onRegister;
    QByteArray RegisterLoginId=ui->loginid->text().toUtf8();
QByteArray RegisterPassword=ui->Password->text().toUtf8();
onRegister=EventLog_RegisterClinician(RegisterLoginId.constData(),RegisterPassword.constData());
if(onRegister==0)
{
    QMessageBox::information(this,"Successfully Registered",
             "<font color=Green><b>Successfully Registered.</b></font>");

}
}
void RegisterClinicianGui::UpdateDefaults()
{

    ui->Time->setText(GuiTime.currentTime().toString ("HH:mm:ss"));
    ui->Date->setText(GuiDate.currentDate().toString ());

}
