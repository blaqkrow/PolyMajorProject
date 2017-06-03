#include "patientgui.h"
#include "ui_patientgui.h"
#include "regimenoption.h"
#include "infusion.h"
#include "drugoption.h"
#include "Common.h"
#include "qobject.h"
#include "clinicianoptions.h"
#include <iostream>
#include <stdio.h>
#include <QIntValidator>

DrugOption*PatientDrugOption =0;
RegimenOption*patientRegimenOptions=0;
ClinicianOptions*ClinicianOptionslogin=0;
QString PatientNric=0;
QString BedNumber=0;
extern QString ClinicianID;


extern "C++"
{
#include "DB_Api.h"

}



PatientGui::PatientGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientGui)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    this->setStyleSheet("background-color:WHITE;");


    //KEEP UPDATING FUNCTIONS
    QTimer *Timer = new QTimer(this);
    QTimer *Timer1 = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this, SLOT(UpdateDefaults()));//CONNECT FUNCTIONS TO TIMEOUT,
    connect(Timer, SIGNAL(timeout()),this, SLOT(PatientCheckKeypadPressed()));//Check For Keypad Pressed
    Timer->start(50);//UPDATES THE TIME ON THE SCREEN EVERY 50MS
    Timer1->start(500);//UPDATES THE TIME ON THE SCREEN EVERY 50MS
    ui->ClinicianName->setText(ClinicianID);




}




PatientGui::~PatientGui()
{
    delete ui;
}



void PatientGui::on_Back_clicked()
{
    //STORED IN DATABASE EVENT TYPE(CLINICIAN LOGGED OUT)
    QString ClinicianLoggedOut="Clinician "+ui->ClinicianName->text()+" Is Logged Out";
    QByteArray LoggedOutClinician=ClinicianLoggedOut.toUtf8();
    EventLog_OnTriggered(LoggedOutClinician.constData());
    patientguiback();
}


void PatientGui::on_Register_clicked()
{
    //CHECK PATIENT  RECORD FOR LOGIN
   if(ui->bednumber->text()!=""&&ui->nric->text()!="" )
{

       PatientNric=ui->nric->text();
       BedNumber=ui->bednumber->text();
    //ADD EVENT TYPE PATIENTIS REGISTERED TO DATABASE
    QString PatientLoggedIn="Patient ID  "+ui->nric->text()+" Is Registered To Bed Number" +ui->bednumber->text();
    QByteArray LoggedInPatient=PatientLoggedIn.toUtf8();
    EventLog_OnTriggered(LoggedInPatient.constData());


    patientSelectDrugOptions();
}
 else
    {
     // Failed login
     ui->errorMsg->setText("<font color=red><b>*Wrong Login ID & Password.</b></font>");
    }


if(ui->bednumber->text()=="")//BED NUMBER LEFT BLANK , ERROR MESSAGE
    {
    ui->errorMsg->setText("<font color=red><b>*Please Input The Bed Number</b></font>");
    }

if(ui->nric->text()=="")//NRIC LEFT BLANK, ERROR MESSAGE
   {
    ui->errorMsg->setText("<font color=red><b>*Please Input The NRIC</b></font>");
   }
if (ui->nric->text()==""&&ui->bednumber->text()=="")
   {
     ui->errorMsg->setText("<font color=red><b>*Please Input The NRIC & Bed Number</b></font>");
   }

}



void PatientGui::UpdateDefaults()
{

    ui->Time->setText(GuiTime.currentTime().toString ("HH:mm:ss"));
    ui->Date->setText(GuiDate.currentDate().toString ());

}

//BACK TO LOGIN PAGE
void PatientGui::patientguiback()
{
  ClinicianOptionslogin=new ClinicianOptions();
  ClinicianOptionslogin->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->hide();
}

//TO INFUSION PAGE
void PatientGui::patientSelectDrugOptions()
{
 PatientDrugOption=new DrugOption();
 PatientDrugOption->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->hide();
}

//BARCODE SCANNER
void PatientGui::on_nric_textChanged(const QString &arg1)
{
    ui->nric->setText(""+arg1);
}



void PatientGui::ResetLineditNricBedno()
{
    ui->nric->setStyleSheet("QLineEdit{background: white;}");
    ui->bednumber->setStyleSheet("QLineEdit{background: white;}");
}

void PatientGui::ReenableNricBedno()
{
    ui->nric->setEnabled(1);
    ui->bednumber->setEnabled(1);
}

void PatientGui::on_nric_selectionChanged()
{
    ui->nric->setStyleSheet("QLineEdit{background: grey;}");
    ui->bednumber->setStyleSheet("QLineEdit{background: white;}");
    popupKeyboardNRIC();
    ui->bednumber->setEnabled(false);
    ui->nric->setEnabled(0);

}

void PatientGui::popupKeyboardNRIC()
{

    QFont font("Arial ", 10);
    QFont Backfont("Arial ", 8 );

    QFrame * popupKeyboardNRIC = new QFrame(this, Qt::Tool | Qt::Window | Qt::FramelessWindowHint);
    popupKeyboardNRIC->resize(720,450);
    popupKeyboardNRIC->setAttribute( Qt::WA_TranslucentBackground );


    QPushButton *Num1nric= new QPushButton(  popupKeyboardNRIC );
    Num1nric->setText("1");
    Num1nric->setFont(font);
    Num1nric->setGeometry(120,290, 60, 40);
    Num1nric->setFocus();
    connect(Num1nric, SIGNAL(clicked()), this, SLOT(Num1Nric()));

    QPushButton *Num2nric= new QPushButton(  popupKeyboardNRIC );
    Num2nric->setText("2");
    Num2nric->setFont(font);
    Num2nric->setGeometry(180,290, 60, 40);
    Num2nric->setFocus();
    connect(Num2nric, SIGNAL(clicked()), this, SLOT(Num2Nric()));

    QPushButton *Num3nric= new QPushButton(  popupKeyboardNRIC );
    Num3nric->setText("3");
    Num3nric->setFont(font);
    Num3nric->setGeometry(240,290, 60, 40);
    Num3nric->setFocus();
    connect(Num3nric, SIGNAL(clicked()), this, SLOT(Num3Nric()));

    QPushButton *Num4nric= new QPushButton(  popupKeyboardNRIC );
    Num4nric->setText("4");
    Num4nric->setGeometry(300,290, 60, 40);
    Num4nric->setFocus();
    Num4nric->setFont(font);
    connect(Num4nric, SIGNAL(clicked()), this, SLOT(Num4Nric()));

    QPushButton *Num5nric= new QPushButton(  popupKeyboardNRIC );
    Num5nric->setText("5");
    Num5nric->setGeometry(360,290, 60, 40);
    Num5nric->setFocus();
    Num5nric->setFont(font);
    connect(Num5nric, SIGNAL(clicked()), this, SLOT(Num5Nric()));

    QPushButton *Num6nric= new QPushButton(  popupKeyboardNRIC );
    Num6nric->setText("6");
    Num6nric->setGeometry(420,290, 60, 40);
    Num6nric->setFocus();
    Num6nric->setFont(font);
    connect(Num6nric, SIGNAL(clicked()), this, SLOT(Num6Nric()));

    QPushButton *Num7nric= new QPushButton(  popupKeyboardNRIC );
    Num7nric->setText("7");
    Num7nric->setGeometry(480,290, 60, 40);
    Num7nric->setFocus();
    Num7nric->setFont(font);
    connect(Num7nric, SIGNAL(clicked()), this, SLOT(Num7Nric()));

    QPushButton *Num8nric= new QPushButton( popupKeyboardNRIC );
    Num8nric->setText("8");
    Num8nric->setGeometry(540,290, 60, 40);
    Num8nric->setFocus();
    Num8nric->setFont(font);
    connect(Num8nric, SIGNAL(clicked()), this, SLOT(Num8Nric()));

    QPushButton *Num9nric= new QPushButton( popupKeyboardNRIC );
    Num9nric->setText("9");
    Num9nric->setGeometry(600,290, 60, 40);
    Num9nric->setFocus();
    Num9nric->setFont(font);
    connect(Num9nric, SIGNAL(clicked()), this, SLOT(Num9Nric()));
    QPushButton *Num0id= new QPushButton( popupKeyboardNRIC );
    Num0id->setText("0");
    Num0id->setGeometry(660,290, 60, 40);
    Num0id->setFont(font);
    Num0id->setFocus();
    connect(Num0id, SIGNAL(clicked()), this, SLOT(Num0Nric()));

    QPushButton *qnric= new QPushButton( popupKeyboardNRIC );
    qnric->setText("q");
    qnric->setGeometry(120,330, 60, 40);
    qnric->setFocus();
    qnric->setFont(font);
    connect(qnric, SIGNAL(clicked()), this, SLOT(typeQnric()));

    QPushButton *wnric= new QPushButton( popupKeyboardNRIC );
    wnric->setText("w");
    wnric->setGeometry(180,330, 60, 40);
    wnric->setFocus();
    wnric->setFont(font);
    connect(wnric, SIGNAL(clicked()), this, SLOT(typeWnric()));

    QPushButton *enric= new QPushButton( popupKeyboardNRIC );
    enric->setText("e");
    enric->setGeometry(240,330, 60, 40);
    enric->setFocus();
    enric->setFont(font);
    connect(enric, SIGNAL(clicked()), this, SLOT(typeEnric()));

    QPushButton *rnric= new QPushButton( popupKeyboardNRIC );
    rnric->setText("r");
    rnric->setGeometry(300,330, 60, 40);
    rnric->setFocus();
    rnric->setFont(font);
    connect(rnric, SIGNAL(clicked()), this, SLOT(typeRnric()));

    QPushButton *tnric= new QPushButton( popupKeyboardNRIC );
    tnric->setText("t");
    tnric->setGeometry(360,330, 60, 40);
    tnric->setFocus();
    tnric->setFont(font);
    connect(tnric, SIGNAL(clicked()), this, SLOT(typeTnric()));

    QPushButton *ynric= new QPushButton( popupKeyboardNRIC );
    ynric->setText("y");
    ynric->setGeometry(420,330, 60, 40);
    ynric->setFocus();
    ynric->setFont(font);
    connect(ynric, SIGNAL(clicked()), this, SLOT(typeYnric()));

    QPushButton *unric= new QPushButton( popupKeyboardNRIC );
    unric->setText("u");
    unric->setGeometry(480,330, 60, 40);
    unric->setFocus();
    unric->setFont(font);
    connect(unric, SIGNAL(clicked()), this, SLOT(typeUnric()));

    QPushButton *inric= new QPushButton( popupKeyboardNRIC );
    inric->setText("i");
    inric->setGeometry(540,330, 60, 40);
    inric->setFocus();
    inric->setFont(font);
    connect(inric, SIGNAL(clicked()), this, SLOT(typeInric()));

    QPushButton *onric= new QPushButton( popupKeyboardNRIC );
    onric->setText("o");
    onric->setGeometry(600,330, 60, 40);
    onric->setFocus();
    onric->setFont(font);
    connect(onric, SIGNAL(clicked()), this, SLOT(typeOnric()));

    QPushButton *pnric= new QPushButton( popupKeyboardNRIC );
    pnric->setText("p");
    pnric->setGeometry(660,330, 60, 40);
    pnric->setFocus();
    pnric->setFont(font);
    connect(pnric, SIGNAL(clicked()), this, SLOT(typePnric()));

    QPushButton *anric= new QPushButton( popupKeyboardNRIC );
    anric->setText("a");
    anric->setGeometry(120,370, 60, 40);
    anric->setFocus();
    anric->setFont(font);
    connect(anric, SIGNAL(clicked()), this, SLOT(typeAnric()));

    QPushButton *snric= new QPushButton( popupKeyboardNRIC );
    snric->setText("s");
    snric->setGeometry(180,370, 60, 40);
    snric->setFocus();
    snric->setFont(font);
    connect(snric, SIGNAL(clicked()), this, SLOT(typeSnric()));

    QPushButton *dnric= new QPushButton( popupKeyboardNRIC );
    dnric->setText("d");
    dnric->setGeometry(240,370, 60, 40);
    dnric->setFocus();
    dnric->setFont(font);
    connect(dnric, SIGNAL(clicked()), this, SLOT(typeDnric()));

    QPushButton *fnric= new QPushButton( popupKeyboardNRIC );
    fnric->setText("f");
    fnric->setGeometry(300,370, 60, 40);
    fnric->setFocus();
    fnric->setFont(font);
    connect(fnric, SIGNAL(clicked()), this, SLOT(typeFnric()));

    QPushButton *gnric= new QPushButton( popupKeyboardNRIC );
    gnric->setText("g");
    gnric->setFont(font);
    gnric->setGeometry(360,370, 60, 40);
    gnric->setFocus();
    connect(gnric, SIGNAL(clicked()), this, SLOT(typeGnric()));

    QPushButton *hnric= new QPushButton( popupKeyboardNRIC );
    hnric->setText("h");
    hnric->setFont(font);
    hnric->setGeometry(420,370, 60, 40);
    hnric->setFocus();
    connect(hnric, SIGNAL(clicked()), this, SLOT(typeHnric()));

    QPushButton *jnric= new QPushButton( popupKeyboardNRIC );
    jnric->setText("j");
    jnric->setFont(font);
    jnric->setGeometry(480,370, 60, 40);
    jnric->setFocus();
    connect(jnric, SIGNAL(clicked()), this, SLOT(typeJnric()));

    QPushButton *knric= new QPushButton( popupKeyboardNRIC );
    knric->setText("k");
    knric->setFont(font);
    knric->setGeometry(540,370, 60, 40);
    knric->setFocus();
    connect(knric, SIGNAL(clicked()), this, SLOT(typeKnric()));

    QPushButton *lnric= new QPushButton( popupKeyboardNRIC );
    lnric->setText("l");
    lnric->setFont(font);
    lnric->setGeometry(600,370, 60, 40);
    lnric->setFocus();
    connect(lnric, SIGNAL(clicked()), this, SLOT(typeLnric()));

    QPushButton *backspacenric= new QPushButton( popupKeyboardNRIC );
    backspacenric->setText("Backspace");
    backspacenric->setGeometry(660,370, 60, 40);
    backspacenric->setFocus();
    backspacenric->setFont(Backfont);
    connect(backspacenric, SIGNAL(clicked()), this, SLOT(backspacenric()));

    QPushButton *znric= new QPushButton( popupKeyboardNRIC );
    znric->setText("z");
    znric->setFont(font);
    znric->setGeometry(120,410, 60, 40);
    znric->setFocus();
    connect(znric, SIGNAL(clicked()), this, SLOT(typeZnric()));

    QPushButton *xnric= new QPushButton( popupKeyboardNRIC );
    xnric->setText("x");
    xnric->setFont(font);
    xnric->setGeometry(180,410, 60, 40);
    xnric->setFocus();
    connect(xnric, SIGNAL(clicked()), this, SLOT(typeXnric()));

    QPushButton *cnric= new QPushButton( popupKeyboardNRIC );
    cnric->setText("c");
    cnric->setFont(font);
    cnric->setGeometry(240,410, 60, 40);
    cnric->setFocus();
    connect(cnric, SIGNAL(clicked()), this, SLOT(typeCnric()));

    QPushButton *vnric= new QPushButton( popupKeyboardNRIC );
    vnric->setText("v");
    vnric->setFont(font);
    vnric->setGeometry(300,410, 60, 40);
    vnric->setFocus();
    connect(vnric, SIGNAL(clicked()), this, SLOT(typeVnric()));

    QPushButton *bnric= new QPushButton( popupKeyboardNRIC );
    bnric->setText("b");
    bnric->setFont(font);
    bnric->setGeometry(360,410, 60, 40);
    bnric->setFocus();
    connect(bnric, SIGNAL(clicked()), this, SLOT(typeBnric()));

    QPushButton *nnric= new QPushButton( popupKeyboardNRIC );
    nnric->setText("n");
    nnric->setFont(font);
    nnric->setGeometry(420,410, 60, 40);
    nnric->setFocus();
    connect(nnric, SIGNAL(clicked()), this, SLOT(typeNnric()));

    QPushButton *mnric= new QPushButton( popupKeyboardNRIC );
    mnric->setText("m");
    mnric->setFont(font);
    mnric->setGeometry(480,410, 60, 40);
    mnric->setFocus();
    connect(mnric, SIGNAL(clicked()), this, SLOT(typeMnric()));


    QPushButton *Caps= new QPushButton( popupKeyboardNRIC );
    Caps->setText("Caps");
    Caps->setFont(font);
    Caps->setGeometry(540,410, 90, 40);
    Caps->setFocus();
    connect(Caps, SIGNAL(clicked()), this, SLOT(popupKeyboardCapsNRIC()));
    connect( Caps, SIGNAL( clicked() ), popupKeyboardNRIC, SLOT( hide()  ));



    QPushButton *enternric= new QPushButton( popupKeyboardNRIC );
    enternric->setText("Enter");
    enternric->setFont(font);
    enternric->setGeometry(630,410, 90, 40);
    enternric->setFocus();
    connect( enternric, SIGNAL( clicked() ), popupKeyboardNRIC, SLOT( hide()  ));
    connect( enternric, SIGNAL( clicked() ), this, SLOT( ResetLineditNricBedno()) );
    connect( enternric, SIGNAL( clicked() ), this, SLOT( ReenableNricBedno()) ) ;
    popupKeyboardNRIC->show();

}

void PatientGui::popupKeyboardCapsNRIC()
{
    QFont font("Arial ", 10);
    QFont Backfont("Arial ", 8 );

    QFrame * popupKeyboardCapsNRIC = new QFrame(this, Qt::Tool | Qt::Window | Qt::FramelessWindowHint);
    popupKeyboardCapsNRIC->resize(720,450);
    popupKeyboardCapsNRIC->setAttribute( Qt::WA_TranslucentBackground );


    QPushButton *Num1CapsNric= new QPushButton(  popupKeyboardCapsNRIC );
    Num1CapsNric->setText("1");
    Num1CapsNric->setFont(font);
    Num1CapsNric->setGeometry(120,290, 60, 40);
    Num1CapsNric->setFocus();
    connect(Num1CapsNric, SIGNAL(clicked()), this, SLOT(Num1CapsNric()));

    QPushButton *Num2CapsNric= new QPushButton( popupKeyboardCapsNRIC );
    Num2CapsNric->setText("2");
    Num2CapsNric->setFont(font);
    Num2CapsNric->setGeometry(180,290, 60, 40);
    Num2CapsNric->setFocus();
    connect(Num2CapsNric, SIGNAL(clicked()), this, SLOT(Num2CapsNric()));

    QPushButton *Num3CapsNric= new QPushButton(  popupKeyboardCapsNRIC );
    Num3CapsNric->setText("3");
    Num3CapsNric->setFont(font);
    Num3CapsNric->setGeometry(240,290, 60, 40);
    Num3CapsNric->setFocus();
    connect(Num3CapsNric, SIGNAL(clicked()), this, SLOT(Num3CapsNric()));

    QPushButton *Num4CapsNric= new QPushButton(  popupKeyboardCapsNRIC );
    Num4CapsNric->setText("4");
    Num4CapsNric->setGeometry(300,290, 60, 40);
    Num4CapsNric->setFocus();
    Num4CapsNric->setFont(font);
    connect(Num4CapsNric, SIGNAL(clicked()), this, SLOT(Num4CapsNric()));

    QPushButton *Num5CapsNric= new QPushButton(  popupKeyboardCapsNRIC );
    Num5CapsNric->setText("5");
    Num5CapsNric->setGeometry(360,290, 60, 40);
    Num5CapsNric->setFocus();
    Num5CapsNric->setFont(font);
    connect(Num5CapsNric, SIGNAL(clicked()), this, SLOT(Num5CapsNric()));

    QPushButton *Num6CapsNric= new QPushButton(  popupKeyboardCapsNRIC );
    Num6CapsNric->setText("6");
    Num6CapsNric->setGeometry(420,290, 60, 40);
    Num6CapsNric->setFocus();
    Num6CapsNric->setFont(font);
    connect(Num6CapsNric, SIGNAL(clicked()), this, SLOT(Num6CapsNric()));

    QPushButton *Num7CapsNric= new QPushButton(  popupKeyboardCapsNRIC );
    Num7CapsNric->setText("7");
    Num7CapsNric->setGeometry(480,290, 60, 40);
    Num7CapsNric->setFocus();
    Num7CapsNric->setFont(font);
    connect(Num7CapsNric, SIGNAL(clicked()), this, SLOT(Num7CapsNric()));

    QPushButton *Num8CapsNric= new QPushButton( popupKeyboardCapsNRIC );
    Num8CapsNric->setText("8");
    Num8CapsNric->setGeometry(540,290, 60, 40);
    Num8CapsNric->setFocus();
    Num8CapsNric->setFont(font);
    connect(Num8CapsNric, SIGNAL(clicked()), this, SLOT(Num8CapsNric()));

    QPushButton *Num9CapsNric= new QPushButton( popupKeyboardCapsNRIC );
    Num9CapsNric->setText("9");
    Num9CapsNric->setGeometry(600,290, 60, 40);
    Num9CapsNric->setFocus();
    Num9CapsNric->setFont(font);
    connect(Num9CapsNric, SIGNAL(clicked()), this, SLOT(Num9CapsNric()));
    QPushButton *Num0CapsNric= new QPushButton( popupKeyboardCapsNRIC );
    Num0CapsNric->setText("0");
    Num0CapsNric->setGeometry(660,290, 60, 40);
    Num0CapsNric->setFont(font);
    Num0CapsNric->setFocus();
    connect(Num0CapsNric, SIGNAL(clicked()), this, SLOT(Num0CapsNric()));

    QPushButton *qCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    qCapsNric->setText("Q");
    qCapsNric->setGeometry(120,330, 60, 40);
    qCapsNric->setFocus();
    qCapsNric->setFont(font);
    connect(qCapsNric, SIGNAL(clicked()), this, SLOT(typeQCapsNric()));

    QPushButton *wCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    wCapsNric->setText("W");
    wCapsNric->setGeometry(180,330, 60, 40);
    wCapsNric->setFocus();
    wCapsNric->setFont(font);
    connect(wCapsNric, SIGNAL(clicked()), this, SLOT(typeWCapsNric()));

    QPushButton *eCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    eCapsNric->setText("E");
    eCapsNric->setGeometry(240,330, 60, 40);
    eCapsNric->setFocus();
    eCapsNric->setFont(font);
    connect(eCapsNric, SIGNAL(clicked()), this, SLOT(typeECapsNric()));

    QPushButton *rCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    rCapsNric->setText("R");
    rCapsNric->setGeometry(300,330, 60, 40);
    rCapsNric->setFocus();
    rCapsNric->setFont(font);
    connect(rCapsNric, SIGNAL(clicked()), this, SLOT(typeRCapsNric()));

    QPushButton *tCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    tCapsNric->setText("T");
    tCapsNric->setGeometry(360,330, 60, 40);
    tCapsNric->setFocus();
    tCapsNric->setFont(font);
    connect(tCapsNric, SIGNAL(clicked()), this, SLOT(typeTCapsNric()));

    QPushButton *yCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    yCapsNric->setText("Y");
    yCapsNric->setGeometry(420,330, 60, 40);
    yCapsNric->setFocus();
    yCapsNric->setFont(font);
    connect(yCapsNric, SIGNAL(clicked()), this, SLOT(typeYCapsNric()));

    QPushButton *uCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    uCapsNric->setText("U");
    uCapsNric->setGeometry(480,330, 60, 40);
    uCapsNric->setFocus();
    uCapsNric->setFont(font);
    connect(uCapsNric, SIGNAL(clicked()), this, SLOT(typeUCapsNric()));

    QPushButton *iCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    iCapsNric->setText("I");
    iCapsNric->setGeometry(540,330, 60, 40);
    iCapsNric->setFocus();
    iCapsNric->setFont(font);
    connect(iCapsNric, SIGNAL(clicked()), this, SLOT(typeICapsNric()));

    QPushButton *oCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    oCapsNric->setText("O");
    oCapsNric->setGeometry(600,330, 60, 40);
    oCapsNric->setFocus();
    oCapsNric->setFont(font);
    connect(oCapsNric, SIGNAL(clicked()), this, SLOT(typeOCapsNric()));

    QPushButton *pCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    pCapsNric->setText("P");
    pCapsNric->setGeometry(660,330, 60, 40);
    pCapsNric->setFocus();
    pCapsNric->setFont(font);
    connect(pCapsNric, SIGNAL(clicked()), this, SLOT(typePCapsNric()));

    QPushButton *aCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    aCapsNric->setText("A");
    aCapsNric->setGeometry(120,370, 60, 40);
    aCapsNric->setFocus();
    aCapsNric->setFont(font);
    connect(aCapsNric, SIGNAL(clicked()), this, SLOT(typeACapsNric()));

    QPushButton *sCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    sCapsNric->setText("S");
    sCapsNric->setGeometry(180,370, 60, 40);
    sCapsNric->setFocus();
    sCapsNric->setFont(font);
    connect(sCapsNric, SIGNAL(clicked()), this, SLOT(typeSCapsNric()));

    QPushButton *dCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    dCapsNric->setText("D");
    dCapsNric->setGeometry(240,370, 60, 40);
    dCapsNric->setFocus();
    dCapsNric->setFont(font);
    connect(dCapsNric, SIGNAL(clicked()), this, SLOT(typeDCapsNric()));

    QPushButton *fCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    fCapsNric->setText("F");
    fCapsNric->setGeometry(300,370, 60, 40);
    fCapsNric->setFocus();
    fCapsNric->setFont(font);
    connect(fCapsNric, SIGNAL(clicked()), this, SLOT(typeFCapsNric()));

    QPushButton *gCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    gCapsNric->setText("G");
    gCapsNric->setFont(font);
    gCapsNric->setGeometry(360,370, 60, 40);
    gCapsNric->setFocus();
    connect(gCapsNric, SIGNAL(clicked()), this, SLOT(typeGCapsNric()));

    QPushButton *hCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    hCapsNric->setText("H");
    hCapsNric->setFont(font);
    hCapsNric->setGeometry(420,370, 60, 40);
    hCapsNric->setFocus();
    connect(hCapsNric, SIGNAL(clicked()), this, SLOT(typeHCapsNric()));

    QPushButton *jCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    jCapsNric->setText("J");
    jCapsNric->setFont(font);
    jCapsNric->setGeometry(480,370, 60, 40);
    jCapsNric->setFocus();
    connect(jCapsNric, SIGNAL(clicked()), this, SLOT(typeJCapsNric()));

    QPushButton *kCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    kCapsNric->setText("K");
    kCapsNric->setFont(font);
    kCapsNric->setGeometry(540,370, 60, 40);
    kCapsNric->setFocus();
    connect(kCapsNric, SIGNAL(clicked()), this, SLOT(typeKCapsNric()));

    QPushButton *lCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    lCapsNric->setText("L");
    lCapsNric->setFont(font);
    lCapsNric->setGeometry(600,370, 60, 40);
    lCapsNric->setFocus();
    connect(lCapsNric, SIGNAL(clicked()), this, SLOT(typeLCapsNric()));

    QPushButton *backspaceCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    backspaceCapsNric->setText("Backspace");
    backspaceCapsNric->setGeometry(660,370, 60, 40);
    backspaceCapsNric->setFocus();
    backspaceCapsNric->setFont(Backfont);
    connect(backspaceCapsNric, SIGNAL(clicked()), this, SLOT(backspaceCapsNric()));

    QPushButton *zCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    zCapsNric->setText("Z");
    zCapsNric->setFont(font);
    zCapsNric->setGeometry(120,410, 60, 40);
    zCapsNric->setFocus();
    connect(zCapsNric, SIGNAL(clicked()), this, SLOT(typeZCapsNric()));

    QPushButton *xCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    xCapsNric->setText("X");
    xCapsNric->setFont(font);
    xCapsNric->setGeometry(180,410, 60, 40);
    xCapsNric->setFocus();
    connect(xCapsNric, SIGNAL(clicked()), this, SLOT(typeXCapsNric()));

    QPushButton *cCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    cCapsNric->setText("C");
    cCapsNric->setFont(font);
    cCapsNric->setGeometry(240,410, 60, 40);
    cCapsNric->setFocus();
    connect(cCapsNric, SIGNAL(clicked()), this, SLOT(typeCCapsNric()));

    QPushButton *vCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    vCapsNric->setText("V");
    vCapsNric->setFont(font);
    vCapsNric->setGeometry(300,410, 60, 40);
    vCapsNric->setFocus();
    connect(vCapsNric, SIGNAL(clicked()), this, SLOT(typeVCapsNric()));

    QPushButton *bCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    bCapsNric->setText("B");
    bCapsNric->setFont(font);
    bCapsNric->setGeometry(360,410, 60, 40);
    bCapsNric->setFocus();
    connect(bCapsNric, SIGNAL(clicked()), this, SLOT(typeBCapsNric()));

    QPushButton *nCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    nCapsNric->setText("N");
    nCapsNric->setFont(font);
    nCapsNric->setGeometry(420,410, 60, 40);
    nCapsNric->setFocus();
    connect(nCapsNric, SIGNAL(clicked()), this, SLOT(typeNCapsNric()));

    QPushButton *mCapsNric= new QPushButton( popupKeyboardCapsNRIC );
    mCapsNric->setText("M");
    mCapsNric->setFont(font);
    mCapsNric->setGeometry(480,410, 60, 40);
    mCapsNric->setFocus();
    connect(mCapsNric, SIGNAL(clicked()), this, SLOT(typeMCapsNric()));


    QPushButton *Caps= new QPushButton( popupKeyboardCapsNRIC );
    Caps->setText("Caps");
    Caps->setStyleSheet("* { background-color: rgb(125,225,100) }");
    Caps->setFont(font);
    Caps->setGeometry(540,410, 90, 40);
    Caps->setFocus();
    connect(Caps, SIGNAL(clicked()), this, SLOT(popupKeyboardNRIC()));
    connect( Caps, SIGNAL( clicked() ), popupKeyboardCapsNRIC, SLOT( hide()  ));


    QPushButton *enterCapsnric= new QPushButton( popupKeyboardCapsNRIC );
    enterCapsnric->setText("Enter");
    enterCapsnric->setFont(font);
    enterCapsnric->setGeometry(630,410, 90, 40);
    enterCapsnric->setFocus();
    connect( enterCapsnric, SIGNAL( clicked() ), popupKeyboardCapsNRIC, SLOT( hide()  ));
    connect( enterCapsnric, SIGNAL( clicked() ), this, SLOT( ResetLineditNricBedno() ) );
    connect( enterCapsnric, SIGNAL( clicked() ), this, SLOT( ReenableNricBedno()) ) ;

    popupKeyboardCapsNRIC->show();
}

void PatientGui::typeQnric()         //LETTER Q
{
    ui->nric->setText(ui->nric->text()+"q");

}
void PatientGui::typeWnric()         //LETTER W
{
    ui->nric->setText(ui->nric->text()+"w");
}
void PatientGui::typeEnric()         //LETTER E
{
    ui->nric->setText(ui->nric->text()+"e");
}
void PatientGui::typeRnric()         //LETTER R
{
    ui->nric->setText(ui->nric->text()+"r");
}
void PatientGui::typeTnric()         //LETTER T
{
    ui->nric->setText(ui->nric->text()+"t");
}
void PatientGui::typeYnric()         //LETTER Y
{
    ui->nric->setText(ui->nric->text()+"y");
}
void PatientGui::typeUnric()         //LETTER U
{
    ui->nric->setText(ui->nric->text()+"u");
}
void PatientGui::typeInric()         //LETTER I
{
    ui->nric->setText(ui->nric->text()+"i");
}
void PatientGui::typeOnric()         //LETTER O
{
    ui->nric->setText(ui->nric->text()+"o");
}
void PatientGui::typePnric()         //LETTER P
{
    ui->nric->setText(ui->nric->text()+"p");
}
void PatientGui::typeAnric()         //LETTER A
{
    ui->nric->setText(ui->nric->text()+"a");
}
void PatientGui::typeSnric()         //LETTER S
{
    ui->nric->setText(ui->nric->text()+"s");
}
void PatientGui::typeDnric()         //LETTER D
{
    ui->nric->setText(ui->nric->text()+"d");
}
void PatientGui::typeFnric()         //LETTER F
{
    ui->nric->setText(ui->nric->text()+"f");
}
void PatientGui::typeGnric()         //LETTER G
{
    ui->nric->setText(ui->nric->text()+"g");
}
void PatientGui::typeHnric()         //LETTER H
{
    ui->nric->setText(ui->nric->text()+"h");
}
void PatientGui::typeJnric()         //LETTER J
{
    ui->nric->setText(ui->nric->text()+"j");
}
void PatientGui::typeKnric()         //LETTER K
{
    ui->nric->setText(ui->nric->text()+"k");
}
void PatientGui::typeLnric()         //LETTER L
{
    ui->nric->setText(ui->nric->text()+"l");
}
void PatientGui::typeZnric()         //LETTER Z
{
    ui->nric->setText(ui->nric->text()+"z");
}
void PatientGui::typeXnric()         //LETTER X
{
    ui->nric->setText(ui->nric->text()+"x");
}
void PatientGui::typeCnric()         //LETTER C
{
    ui->nric->setText(ui->nric->text()+"c");
}
void PatientGui::typeVnric()         //LETTER V
{
    ui->nric->setText(ui->nric->text()+"v");
}
void PatientGui::typeBnric()         //LETTER B
{
    ui->nric->setText(ui->nric->text()+"b");
}
void PatientGui::typeNnric()         //LETTER N
{
    ui->nric->setText(ui->nric->text()+"n");
}
void PatientGui::typeMnric()         //LETTER M
{
    ui->nric->setText(ui->nric->text()+"m");
}
void PatientGui::backspacenric()
{
    ui->nric->backspace();
}
void PatientGui::Num1Nric()
{
    ui->nric->setText(  ui->nric->text()+"1");
}
void PatientGui::Num2Nric()
{
    ui->nric->setText(  ui->nric->text()+"2");
}
void PatientGui::Num3Nric()
{
    ui->nric->setText(ui->nric->text()+"3");
}
void PatientGui::Num4Nric()
{
    ui->nric->setText(ui->nric->text()+"4");
}
void PatientGui::Num5Nric()
{
    ui->nric->setText(ui->nric->text()+"5");
}
void PatientGui::Num6Nric()
{
    ui->nric->setText(ui->nric->text()+"6");
}
void PatientGui::Num7Nric()
{
    ui->nric->setText(ui->nric->text()+"7");
}
void PatientGui::Num8Nric()
{
    ui->nric->setText(ui->nric->text()+"8");
}
void PatientGui::Num9Nric()
{
    ui->nric->setText(ui->nric->text()+"9");
}
void PatientGui::Num0Nric()
{
    ui->nric->setText(ui->nric->text()+"0");
}
void PatientGui::typeQCapsNric()         //LETTER Q
{
    ui->nric->setText(ui->nric->text()+"Q");

}
void PatientGui::typeWCapsNric()         //LETTER W
{
    ui->nric->setText(ui->nric->text()+"");
}
void PatientGui::typeECapsNric()         //LETTER E
{
    ui->nric->setText(ui->nric->text()+"E");
}
void PatientGui::typeRCapsNric()         //LETTER R
{
    ui->nric->setText(ui->nric->text()+"R");
}
void PatientGui::typeTCapsNric()         //LETTER T
{
    ui->nric->setText(ui->nric->text()+"T");
}
void PatientGui::typeYCapsNric()         //LETTER Y
{
    ui->nric->setText(ui->nric->text()+"Y");
}
void PatientGui::typeUCapsNric()         //LETTER U
{
    ui->nric->setText(ui->nric->text()+"U");
}
void PatientGui::typeICapsNric()         //LETTER I
{
    ui->nric->setText(ui->nric->text()+"I");
}
void PatientGui::typeOCapsNric()         //LETTER O
{
    ui->nric->setText(ui->nric->text()+"O");
}
void PatientGui::typePCapsNric()         //LETTER P
{
    ui->nric->setText(ui->nric->text()+"P");
}
void PatientGui::typeACapsNric()         //LETTER A
{
    ui->nric->setText(ui->nric->text()+"A");
}
void PatientGui::typeSCapsNric()         //LETTER S
{
    ui->nric->setText(ui->nric->text()+"S");
}
void PatientGui::typeDCapsNric()         //LETTER D
{
    ui->nric->setText(ui->nric->text()+"D");
}
void PatientGui::typeFCapsNric()         //LETTER F
{
    ui->nric->setText(ui->nric->text()+"F");
}
void PatientGui::typeGCapsNric()         //LETTER G
{
    ui->nric->setText(ui->nric->text()+"G");
}
void PatientGui::typeHCapsNric()         //LETTER H
{
    ui->nric->setText(ui->nric->text()+"H");
}
void PatientGui::typeJCapsNric()         //LETTER J
{
    ui->nric->setText(ui->nric->text()+"J");
}
void PatientGui::typeKCapsNric()         //LETTER K
{
    ui->nric->setText(ui->nric->text()+"K");
}
void PatientGui::typeLCapsNric()         //LETTER L
{
    ui->nric->setText(ui->nric->text()+"L");
}
void PatientGui::typeZCapsNric()         //LETTER Z
{
    ui->nric->setText(ui->nric->text()+"Z");
}
void PatientGui::typeXCapsNric()         //LETTER X
{
    ui->nric->setText(ui->nric->text()+"X");
}
void PatientGui::typeCCapsNric()         //LETTER C
{
    ui->nric->setText(ui->nric->text()+"C");
}
void PatientGui::typeVCapsNric()         //LETTER V
{
    ui->nric->setText(ui->nric->text()+"V");
}
void PatientGui::typeBCapsNric()         //LETTER B
{
    ui->nric->setText(ui->nric->text()+"B");
}
void PatientGui::typeNCapsNric()         //LETTER N
{
    ui->nric->setText(ui->nric->text()+"N");
}
void PatientGui::typeMCapsNric()         //LETTER M
{
    ui->nric->setText(ui->nric->text()+"M");
}
void PatientGui::backspaceCapsNric()
{
    ui->nric->backspace();
}
void PatientGui::Num1CapsNric()
{
    ui->nric->setText(  ui->nric->text()+"1");
}
void PatientGui::Num2CapsNric()
{
    ui->nric->setText(  ui->nric->text()+"2");
}
void PatientGui::Num3CapsNric()
{
    ui->nric->setText(ui->nric->text()+"3");
}
void PatientGui::Num4CapsNric()
{
    ui->nric->setText(ui->nric->text()+"4");
}
void PatientGui::Num5CapsNric()
{
    ui->nric->setText(ui->nric->text()+"5");
}
void PatientGui::Num6CapsNric()
{
    ui->nric->setText(ui->nric->text()+"6");
}
void PatientGui::Num7CapsNric()
{
    ui->nric->setText(ui->nric->text()+"7");
}
void PatientGui::Num8CapsNric()
{
    ui->nric->setText(ui->nric->text()+"8");
}
void PatientGui::Num9CapsNric()
{
    ui->nric->setText(ui->nric->text()+"9");
}
void PatientGui::Num0CapsNric()
{
    ui->nric->setText(ui->nric->text()+"0");
}

void PatientGui::on_ClearNric_clicked()
{
    ui->nric->setText("");
}
void PatientGui::on_ClearBedNumber_clicked()
{
    ui->bednumber->setText("");
}





