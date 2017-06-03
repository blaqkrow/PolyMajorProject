#include "changeipadd.h"
#include "ui_changeipadd.h"
#include "administratorgui.h"
#include "Common.h"
administratorGui *IPaddressAdmin=0;
extern "C++"
{
#include "DB_Api.h"

 #ifdef USE_LINUX
#include "Algo.h"
#endif

}
#include <QMessageBox>


ChangeIpadd::ChangeIpadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeIpadd)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    this->setStyleSheet("background-color:WHITE;");
    QTimer *Timer = new QTimer(this);

    connect(Timer, SIGNAL(timeout()),this, SLOT(UpdateDefaults()));//CONNECT FUNCTIONS TO TIMEOUT
    Timer->start(50);//UPDATES THE TIME ON THE SCREEN EVERY 50MS
    ui->newIPaddress->setInputMask("000.000.000.000;");
}

ChangeIpadd::~ChangeIpadd()
{
    delete ui;
}
void ChangeIpadd::UpdateDefaults()
{

    ui->Time->setText(GuiTime.currentTime().toString ("HH:mm:ss"));
    ui->Date->setText(GuiDate.currentDate().toString ());

}

void ChangeIpadd::on_back_clicked()
{
    IPaddressAdmin=new administratorGui();
    IPaddressAdmin->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->close();
}

void ChangeIpadd::on_Clear_clicked()
{
  ui->newIPaddress->setText("");
}


void ChangeIpadd::on_Set_clicked()
{
  QByteArray IPaddressNew=  ui->newIPaddress->text().toUtf8();

 #ifdef USE_LINUX
  setIP(IPaddressNew.constData());
#endif
  QMessageBox::information(this,"Successfully Changed IP Address ",
           "<font color=Green><b>Successfully Changed IP Address to "+ui->newIPaddress->text()+".</b></font>");
}
