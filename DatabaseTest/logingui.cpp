#include "logingui.h"
#include "ui_logingui.h"
#include "administratorgui.h"
#include "clinicianoptions.h"
#include "Common.h"


PatientGui*loginPatient=0;

administratorGui *loginAdmin=0;
ClinicianOptions *ClinicianLogin=0;
QString ClinicianID=0;
extern "C++"
{
#include "DB_Api.h"
 #ifdef USE_LINUX
#include "forFatah.h"
#include "client.h"
#endif
}

LoginGui::LoginGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginGui)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    this->setStyleSheet("background-color:WHITE;");

    //KEEP UPDATING FUNCTIONS
    QTimer *Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this, SLOT(UpdateDefaults()));//CONNECT FUNCTIONS TO TIMEOUT,
    connect(Timer, SIGNAL(timeout()),this, SLOT(LoginCheckKeypadPressed()));//CHECK FOR KEYPAD PRESSED
    Timer->start(50);//UPDATES THE TIME ON THE SCREEN EVERY 50MS

    //Current Date

    ui->loginlabel->hide();
    ui->loginButton->hide();
    ui->loginid->hide();
    ui->passwordlabel->hide();
    ui->password->hide();
    ui->ClearID->hide();
    ui->ClearPassword->hide();

    //Completer for loginid
    QStringList CompleterID;
    CompleterID<< "hello"<<"John"<<"Bryan"<<"bsfkjbav";
    IDCompleter=new QCompleter(CompleterID,this);
    IDCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->loginid->setCompleter(IDCompleter);





}

//DATABASE SAVE INFO TO CLINICIANDATABASE//

LoginGui::~LoginGui()
{
    delete ui;
}



//TO PATIENTGUI PAGE
void LoginGui::loginClinicianGui()
{

    ClinicianLogin=new ClinicianOptions();
    ClinicianLogin->show();
#ifdef USE_LINUX
    sleep(1);
#else
    Sleep(20);
#endif
    this->close();

}

//TO ADMIN PAGE
void LoginGui::loginAdminGui()
{
    loginAdmin=new administratorGui();
    loginAdmin->show();
    this->close();
}

void LoginGui::on_administratorRB_clicked()
{
    ui->loginid->hide();
    ui->loginlabel->hide();
    ui->password->show();
    ui->loginid->setText("");
    ui->passwordlabel->show();
    ui->password->setText("");
    ui->errormsg->hide();
    ui->loginButton->show();
    ui->ClearPassword->show();
    ui->ClearID->hide();
}

void LoginGui::on_clinicianRB_clicked()
{
    ui->loginid->show();
    ui->loginlabel->show();
    ui->password->show();
    ui->passwordlabel->show();
    ui->loginButton->show();
    ui->ClearID->show();
    ui->ClearPassword->show();

}

void LoginGui::on_loginButton_clicked()
{
    if (ui->administratorRB->isChecked())       //administrator checked
    {
        if(ui->password->text()=="")
        {
            ui->errormsg->show();
            ui->errormsg->setText("<font color=red><b>*Please Input Password </b></font>");
        }
        if(ui->password->text()!="")
        {
            if(ui->password->text()=="password"||ui->password->text()=="123")                  //correct password
            {
                loginAdminGui();
            }
            else                                                     //wrong password
            {
                ui->errormsg->show();
                ui->errormsg->setText("<font color=red><b>*Wrong Password </b></font>");
            }
        }
    }
    if (ui->clinicianRB->isChecked())                 //Clinician checked
    {
        if (ui->loginid->text()=="")                             //login ID blank
        {
            ui->errormsg->setText("<font color=red><b>*Please Input Your Login ID </b></font>");
        }
        if (ui->password->text()=="")                            //password blank
        {
            ui->errormsg->setText("<font color=red><b>*Please Input Your Password </b></font>");
        }
        if (ui->loginid->text()==""&& ui->password->text()=="")  //login ID and password blank
        {
            ui->errormsg->setText("<font color=red><b>*Please Input Your Login ID & Password </b></font>");
        }

        //CHECK LOGIN ID AND PASSWORD & SAVE DATA TO EVENT TYPE
        if(ui->loginid->text()!=""&& ui->password->text()!="")        //login ID and password filled
        {
            int onLogin;


            QByteArray Login = ui->loginid->text().toUtf8();
            QByteArray Password = ui->password->text().toUtf8();
            //Store Clinician ID to temp data base file
            onLogin = EventLog_OnLogin(Login.constData(),Password.constData());
            if(onLogin == 0)
            {
                //STORE CLINICIAN LOGGED IN DATATYPE
                QString ClinicianLoggedIn="Clinician "+ui->loginid->text()+" Is Logged In";
                QByteArray LoggedInClinician=ClinicianLoggedIn.toUtf8();
                EventLog_OnTriggered(LoggedInClinician.constData());
                ClinicianID=ui->loginid->text();
                loginClinicianGui();// SUCCESSFUL LOGIN
            }
            else
            {
                // Failed login
                ui->errormsg->setText("<font color=red><b>*Wrong Login ID & Password.</b></font>");
            }
        }
    }
}

void LoginGui::on_loginid_textChanged(const QString &arg1)
{
    ui->loginid->setText(""+arg1);
}

void LoginGui::popupKeyboardID()
{
    QFont font("Arial ", 10);
    QFont Backfont("Arial ", 8 );

    QFrame * popupKeyboardID = new QFrame(this, Qt::Tool | Qt::Window | Qt::FramelessWindowHint);
    popupKeyboardID->resize(720,450);
    popupKeyboardID->setAttribute( Qt::WA_TranslucentBackground );


    QPushButton *Num1id= new QPushButton(  popupKeyboardID );
    Num1id->setText("1");
    Num1id->setFont(font);
    Num1id->setGeometry(120,290, 60, 40);
    Num1id->setFocus();
    connect(Num1id, SIGNAL(clicked()), this, SLOT(Num1id()));

    QPushButton *Num2id= new QPushButton(  popupKeyboardID );
    Num2id->setText("2");
    Num2id->setFont(font);
    Num2id->setGeometry(180,290, 60, 40);
    Num2id->setFocus();
    connect(Num2id, SIGNAL(clicked()), this, SLOT(Num2id()));

    QPushButton *Num3id= new QPushButton(  popupKeyboardID );
    Num3id->setText("3");
    Num3id->setFont(font);
    Num3id->setGeometry(240,290, 60, 40);
    Num3id->setFocus();
    connect(Num3id, SIGNAL(clicked()), this, SLOT(Num3id()));

    QPushButton *Num4id= new QPushButton(  popupKeyboardID );
    Num4id->setText("4");
    Num4id->setGeometry(300,290, 60, 40);
    Num4id->setFocus();
    Num4id->setFont(font);
    connect(Num4id, SIGNAL(clicked()), this, SLOT(Num4id()));

    QPushButton *Num5id= new QPushButton(  popupKeyboardID );
    Num5id->setText("5");
    Num5id->setGeometry(360,290, 60, 40);
    Num5id->setFocus();
    Num5id->setFont(font);
    connect(Num5id, SIGNAL(clicked()), this, SLOT(Num5id()));

    QPushButton *Num6id= new QPushButton(  popupKeyboardID );
    Num6id->setText("6");
    Num6id->setGeometry(420,290, 60, 40);
    Num6id->setFocus();
    Num6id->setFont(font);
    connect(Num6id, SIGNAL(clicked()), this, SLOT(Num6id()));

    QPushButton *Num7id= new QPushButton(  popupKeyboardID );
    Num7id->setText("7");
    Num7id->setGeometry(480,290, 60, 40);
    Num7id->setFocus();
    Num7id->setFont(font);
    connect(Num7id, SIGNAL(clicked()), this, SLOT(Num7id()));

    QPushButton *Num8id= new QPushButton( popupKeyboardID );
    Num8id->setText("8");
    Num8id->setGeometry(540,290, 60, 40);
    Num8id->setFocus();
    Num8id->setFont(font);
    connect(Num8id, SIGNAL(clicked()), this, SLOT(Num8id()));

    QPushButton *Num9id= new QPushButton( popupKeyboardID );
    Num9id->setText("9");
    Num9id->setGeometry(600,290, 60, 40);
    Num9id->setFocus();
    Num9id->setFont(font);
    connect(Num9id, SIGNAL(clicked()), this, SLOT(Num9id()));
    QPushButton *Num0id= new QPushButton( popupKeyboardID );
    Num0id->setText("0");
    Num0id->setGeometry(660,290, 60, 40);
    Num0id->setFont(font);
    Num0id->setFocus();
    connect(Num0id, SIGNAL(clicked()), this, SLOT(Num0id()));

    QPushButton *qid= new QPushButton( popupKeyboardID );
    qid->setText("q");
    qid->setGeometry(120,330, 60, 40);
    qid->setFocus();
    qid->setFont(font);
    connect(qid, SIGNAL(clicked()), this, SLOT(typeQid()));

    QPushButton *wid= new QPushButton( popupKeyboardID );
    wid->setText("w");
    wid->setGeometry(180,330, 60, 40);
    wid->setFocus();
    wid->setFont(font);
    connect(wid, SIGNAL(clicked()), this, SLOT(typeWid()));

    QPushButton *eid= new QPushButton( popupKeyboardID );
    eid->setText("e");
    eid->setGeometry(240,330, 60, 40);
    eid->setFocus();
    eid->setFont(font);
    connect(eid, SIGNAL(clicked()), this, SLOT(typeEid()));

    QPushButton *rid= new QPushButton( popupKeyboardID );
    rid->setText("r");
    rid->setGeometry(300,330, 60, 40);
    rid->setFocus();
    rid->setFont(font);
    connect(rid, SIGNAL(clicked()), this, SLOT(typeRid()));

    QPushButton *tid= new QPushButton( popupKeyboardID );
    tid->setText("t");
    tid->setGeometry(360,330, 60, 40);
    tid->setFocus();
    tid->setFont(font);
    connect(tid, SIGNAL(clicked()), this, SLOT(typeTid()));

    QPushButton *yid= new QPushButton( popupKeyboardID );
    yid->setText("y");
    yid->setGeometry(420,330, 60, 40);
    yid->setFocus();
    yid->setFont(font);
    connect(yid, SIGNAL(clicked()), this, SLOT(typeYid()));

    QPushButton *uid= new QPushButton( popupKeyboardID );
    uid->setText("u");
    uid->setGeometry(480,330, 60, 40);
    uid->setFocus();
    uid->setFont(font);
    connect(uid, SIGNAL(clicked()), this, SLOT(typeUid()));

    QPushButton *iid= new QPushButton( popupKeyboardID );
    iid->setText("i");
    iid->setGeometry(540,330, 60, 40);
    iid->setFocus();
    iid->setFont(font);
    connect(iid, SIGNAL(clicked()), this, SLOT(typeIid()));

    QPushButton *oid= new QPushButton( popupKeyboardID );
    oid->setText("o");
    oid->setGeometry(600,330, 60, 40);
    oid->setFocus();
    oid->setFont(font);
    connect(oid, SIGNAL(clicked()), this, SLOT(typeOid()));

    QPushButton *pid= new QPushButton( popupKeyboardID );
    pid->setText("p");
    pid->setGeometry(660,330, 60, 40);
    pid->setFocus();
    pid->setFont(font);
    connect(pid, SIGNAL(clicked()), this, SLOT(typePid()));

    QPushButton *aid= new QPushButton( popupKeyboardID );
    aid->setText("a");
    aid->setGeometry(120,370, 60, 40);
    aid->setFocus();
    aid->setFont(font);
    connect(aid, SIGNAL(clicked()), this, SLOT(typeAid()));

    QPushButton *sid= new QPushButton( popupKeyboardID );
    sid->setText("s");
    sid->setGeometry(180,370, 60, 40);
    sid->setFocus();
    sid->setFont(font);
    connect(sid, SIGNAL(clicked()), this, SLOT(typeSid()));

    QPushButton *did= new QPushButton( popupKeyboardID );
    did->setText("d");
    did->setGeometry(240,370, 60, 40);
    did->setFocus();
    did->setFont(font);
    connect(did, SIGNAL(clicked()), this, SLOT(typeDid()));

    QPushButton *fid= new QPushButton( popupKeyboardID );
    fid->setText("f");
    fid->setGeometry(300,370, 60, 40);
    fid->setFocus();
    fid->setFont(font);
    connect(fid, SIGNAL(clicked()), this, SLOT(typeFid()));

    QPushButton *gid= new QPushButton( popupKeyboardID );
    gid->setText("g");
    gid->setFont(font);
    gid->setGeometry(360,370, 60, 40);
    gid->setFocus();
    connect(gid, SIGNAL(clicked()), this, SLOT(typeGid()));

    QPushButton *hid= new QPushButton( popupKeyboardID );
    hid->setText("h");
    hid->setFont(font);
    hid->setGeometry(420,370, 60, 40);
    hid->setFocus();
    connect(hid, SIGNAL(clicked()), this, SLOT(typeHid()));

    QPushButton *jid= new QPushButton( popupKeyboardID );
    jid->setText("j");
    jid->setFont(font);
    jid->setGeometry(480,370, 60, 40);
    jid->setFocus();
    connect(jid, SIGNAL(clicked()), this, SLOT(typeJid()));

    QPushButton *kid= new QPushButton( popupKeyboardID );
    kid->setText("k");
    kid->setFont(font);
    kid->setGeometry(540,370, 60, 40);
    kid->setFocus();
    connect(kid, SIGNAL(clicked()), this, SLOT(typeKid()));

    QPushButton *lid= new QPushButton( popupKeyboardID );
    lid->setText("l");
    lid->setFont(font);
    lid->setGeometry(600,370, 60, 40);
    lid->setFocus();
    connect(lid, SIGNAL(clicked()), this, SLOT(typeLid()));

    QPushButton *backspaceid= new QPushButton( popupKeyboardID );
    backspaceid->setText("Backspace");
    backspaceid->setGeometry(660,370, 60, 40);
    backspaceid->setFocus();
    backspaceid->setFont(Backfont);
    connect(backspaceid, SIGNAL(clicked()), this, SLOT(backspaceid()));

    QPushButton *zid= new QPushButton( popupKeyboardID );
    zid->setText("z");
    zid->setFont(font);
    zid->setGeometry(120,410, 60, 40);
    zid->setFocus();
    connect(zid, SIGNAL(clicked()), this, SLOT(typeZid()));

    QPushButton *xid= new QPushButton( popupKeyboardID );
    xid->setText("x");
    xid->setFont(font);
    xid->setGeometry(180,410, 60, 40);
    xid->setFocus();
    connect(xid, SIGNAL(clicked()), this, SLOT(typeXid()));

    QPushButton *cid= new QPushButton( popupKeyboardID );
    cid->setText("c");
    cid->setFont(font);
    cid->setGeometry(240,410, 60, 40);
    cid->setFocus();
    connect(cid, SIGNAL(clicked()), this, SLOT(typeCid()));

    QPushButton *vid= new QPushButton( popupKeyboardID );
    vid->setText("v");
    vid->setFont(font);
    vid->setGeometry(300,410, 60, 40);
    vid->setFocus();
    connect(vid, SIGNAL(clicked()), this, SLOT(typeVid()));

    QPushButton *bid= new QPushButton( popupKeyboardID );
    bid->setText("b");
    bid->setFont(font);
    bid->setGeometry(360,410, 60, 40);
    bid->setFocus();
    connect(bid, SIGNAL(clicked()), this, SLOT(typeBid()));

    QPushButton *nid= new QPushButton( popupKeyboardID );
    nid->setText("n");
    nid->setFont(font);
    nid->setGeometry(420,410, 60, 40);
    nid->setFocus();
    connect(nid, SIGNAL(clicked()), this, SLOT(typeNid()));

    QPushButton *mid= new QPushButton( popupKeyboardID );
    mid->setText("m");
    mid->setFont(font);
    mid->setGeometry(480,410, 60, 40);
    mid->setFocus();
    connect(mid, SIGNAL(clicked()), this, SLOT(typeMid()));


    QPushButton *Caps= new QPushButton( popupKeyboardID );
    Caps->setText("Caps");
    Caps->setFont(font);
    Caps->setGeometry(540,410, 90, 40);
    Caps->setFocus();
    connect(Caps, SIGNAL(clicked()), this, SLOT(popupKeyboardIDCaps()));
    connect(Caps, SIGNAL( clicked() ), popupKeyboardID, SLOT( hide()));


    QPushButton *enterid= new QPushButton( popupKeyboardID );
    enterid->setText("Enter");
    enterid->setFont(font);
    enterid->setGeometry(630,410, 90, 40);
    enterid->setFocus();
    connect( enterid, SIGNAL( clicked() ), popupKeyboardID, SLOT( hide()  ));
    connect( enterid, SIGNAL( clicked() ), this, SLOT( ResetLineditLoginGui() ) );
    connect( enterid, SIGNAL( clicked() ), this, SLOT( Reenableloginpass() ) );

    popupKeyboardID->show();

}
void LoginGui::popupKeyboardIDCaps()
{

    QFont font("Arial ", 10);
    QFont Backfont("Arial ", 8 );

    QFrame * popupKeyboardIDCaps = new QFrame(this, Qt::Tool | Qt::Window | Qt::FramelessWindowHint);
    popupKeyboardIDCaps->resize(720,450);
    popupKeyboardIDCaps->setAttribute( Qt::WA_TranslucentBackground );


    QPushButton *Num1id= new QPushButton(  popupKeyboardIDCaps );
    Num1id->setText("1");
    Num1id->setFont(font);
    Num1id->setGeometry(120,290, 60, 40);
    Num1id->setFocus();
    connect(Num1id, SIGNAL(clicked()), this, SLOT(Num1id()));

    QPushButton *Num2id= new QPushButton(  popupKeyboardIDCaps );
    Num2id->setText("2");
    Num2id->setFont(font);
    Num2id->setGeometry(180,290, 60, 40);
    Num2id->setFocus();
    connect(Num2id, SIGNAL(clicked()), this, SLOT(Num2id()));

    QPushButton *Num3id= new QPushButton(  popupKeyboardIDCaps );
    Num3id->setText("3");
    Num3id->setFont(font);
    Num3id->setGeometry(240,290, 60, 40);
    Num3id->setFocus();
    connect(Num3id, SIGNAL(clicked()), this, SLOT(Num3id()));

    QPushButton *Num4id= new QPushButton(  popupKeyboardIDCaps );
    Num4id->setText("4");
    Num4id->setGeometry(300,290, 60, 40);
    Num4id->setFocus();
    Num4id->setFont(font);
    connect(Num4id, SIGNAL(clicked()), this, SLOT(Num4id()));

    QPushButton *Num5id= new QPushButton(  popupKeyboardIDCaps );
    Num5id->setText("5");
    Num5id->setGeometry(360,290, 60, 40);
    Num5id->setFocus();
    Num5id->setFont(font);
    connect(Num5id, SIGNAL(clicked()), this, SLOT(Num5id()));

    QPushButton *Num6id= new QPushButton(  popupKeyboardIDCaps );
    Num6id->setText("6");
    Num6id->setGeometry(420,290, 60, 40);
    Num6id->setFocus();
    Num6id->setFont(font);
    connect(Num6id, SIGNAL(clicked()), this, SLOT(Num6id()));

    QPushButton *Num7id= new QPushButton(  popupKeyboardIDCaps );
    Num7id->setText("7");
    Num7id->setGeometry(480,290, 60, 40);
    Num7id->setFocus();
    Num7id->setFont(font);
    connect(Num7id, SIGNAL(clicked()), this, SLOT(Num7id()));

    QPushButton *Num8id= new QPushButton( popupKeyboardIDCaps );
    Num8id->setText("8");
    Num8id->setGeometry(540,290, 60, 40);
    Num8id->setFocus();
    Num8id->setFont(font);
    connect(Num8id, SIGNAL(clicked()), this, SLOT(Num8id()));

    QPushButton *Num9id= new QPushButton( popupKeyboardIDCaps );
    Num9id->setText("9");
    Num9id->setGeometry(600,290, 60, 40);
    Num9id->setFocus();
    Num9id->setFont(font);
    connect(Num9id, SIGNAL(clicked()), this, SLOT(Num9id()));
    QPushButton *Num0id= new QPushButton( popupKeyboardIDCaps );
    Num0id->setText("0");
    Num0id->setGeometry(660,290, 60, 40);
    Num0id->setFont(font);
    Num0id->setFocus();
    connect(Num0id, SIGNAL(clicked()), this, SLOT(Num0id()));

    QPushButton *qid= new QPushButton( popupKeyboardIDCaps );
    qid->setText("Q");
    qid->setGeometry(120,330, 60, 40);
    qid->setFocus();
    qid->setFont(font);
    connect(qid, SIGNAL(clicked()), this, SLOT(typeCapsQid()));

    QPushButton *wid= new QPushButton( popupKeyboardIDCaps );
    wid->setText("W");
    wid->setGeometry(180,330, 60, 40);
    wid->setFocus();
    wid->setFont(font);
    connect(wid, SIGNAL(clicked()), this, SLOT(typeCapsWid()));

    QPushButton *eid= new QPushButton( popupKeyboardIDCaps );
    eid->setText("E");
    eid->setGeometry(240,330, 60, 40);
    eid->setFocus();
    eid->setFont(font);
    connect(eid, SIGNAL(clicked()), this, SLOT(typeCapsEid()));

    QPushButton *rid= new QPushButton( popupKeyboardIDCaps );
    rid->setText("R");
    rid->setGeometry(300,330, 60, 40);
    rid->setFocus();
    rid->setFont(font);
    connect(rid, SIGNAL(clicked()), this, SLOT(typeCapsRid()));

    QPushButton *tid= new QPushButton( popupKeyboardIDCaps );
    tid->setText("T");
    tid->setGeometry(360,330, 60, 40);
    tid->setFocus();
    tid->setFont(font);
    connect(tid, SIGNAL(clicked()), this, SLOT(typeCapsTid()));

    QPushButton *yid= new QPushButton( popupKeyboardIDCaps );
    yid->setText("Y");
    yid->setGeometry(420,330, 60, 40);
    yid->setFocus();
    yid->setFont(font);
    connect(yid, SIGNAL(clicked()), this, SLOT(typeCapsYid()));

    QPushButton *uid= new QPushButton( popupKeyboardIDCaps );
    uid->setText("U");
    uid->setGeometry(480,330, 60, 40);
    uid->setFocus();
    uid->setFont(font);
    connect(uid, SIGNAL(clicked()), this, SLOT(typeCapsUid()));

    QPushButton *iid= new QPushButton( popupKeyboardIDCaps );
    iid->setText("I");
    iid->setGeometry(540,330, 60, 40);
    iid->setFocus();
    iid->setFont(font);
    connect(iid, SIGNAL(clicked()), this, SLOT(typeCapsIid()));

    QPushButton *oid= new QPushButton( popupKeyboardIDCaps );
    oid->setText("O");
    oid->setGeometry(600,330, 60, 40);
    oid->setFocus();
    oid->setFont(font);
    connect(oid, SIGNAL(clicked()), this, SLOT(typeCapsOid()));

    QPushButton *pid= new QPushButton( popupKeyboardIDCaps );
    pid->setText("P");
    pid->setGeometry(660,330, 60, 40);
    pid->setFocus();
    pid->setFont(font);
    connect(pid, SIGNAL(clicked()), this, SLOT(typeCapsPid()));

    QPushButton *aid= new QPushButton( popupKeyboardIDCaps );
    aid->setText("A");
    aid->setGeometry(120,370, 60, 40);
    aid->setFocus();
    aid->setFont(font);
    connect(aid, SIGNAL(clicked()), this, SLOT(typeCapsAid()));

    QPushButton *sid= new QPushButton( popupKeyboardIDCaps );
    sid->setText("S");
    sid->setGeometry(180,370, 60, 40);
    sid->setFocus();
    sid->setFont(font);
    connect(sid, SIGNAL(clicked()), this, SLOT(typeCapsSid()));

    QPushButton *did= new QPushButton( popupKeyboardIDCaps );
    did->setText("D");
    did->setGeometry(240,370, 60, 40);
    did->setFocus();
    did->setFont(font);
    connect(did, SIGNAL(clicked()), this, SLOT(typeCapsDid()));

    QPushButton *fid= new QPushButton( popupKeyboardIDCaps );
    fid->setText("F");
    fid->setGeometry(300,370, 60, 40);
    fid->setFocus();
    fid->setFont(font);
    connect(fid, SIGNAL(clicked()), this, SLOT(typeCapsFid()));

    QPushButton *gid= new QPushButton( popupKeyboardIDCaps );
    gid->setText("G");
    gid->setFont(font);
    gid->setGeometry(360,370, 60, 40);
    gid->setFocus();
    connect(gid, SIGNAL(clicked()), this, SLOT(typeCapsGid()));

    QPushButton *hid= new QPushButton( popupKeyboardIDCaps );
    hid->setText("H");
    hid->setFont(font);
    hid->setGeometry(420,370, 60, 40);
    hid->setFocus();
    connect(hid, SIGNAL(clicked()), this, SLOT(typeCapsHid()));

    QPushButton *jid= new QPushButton( popupKeyboardIDCaps );
    jid->setText("J");
    jid->setFont(font);
    jid->setGeometry(480,370, 60, 40);
    jid->setFocus();
    connect(jid, SIGNAL(clicked()), this, SLOT(typeCapsJid()));

    QPushButton *kid= new QPushButton( popupKeyboardIDCaps );
    kid->setText("K");
    kid->setFont(font);
    kid->setGeometry(540,370, 60, 40);
    kid->setFocus();
    connect(kid, SIGNAL(clicked()), this, SLOT(typeCapsKid()));

    QPushButton *lid= new QPushButton( popupKeyboardIDCaps );
    lid->setText("L");
    lid->setFont(font);
    lid->setGeometry(600,370, 60, 40);
    lid->setFocus();
    connect(lid, SIGNAL(clicked()), this, SLOT(typeCapsLid()));

    QPushButton *backspaceid= new QPushButton( popupKeyboardIDCaps );
    backspaceid->setText("Backspace");
    backspaceid->setGeometry(660,370, 60, 40);
    backspaceid->setFocus();
    backspaceid->setFont(Backfont);
    connect(backspaceid, SIGNAL(clicked()), this, SLOT(backspaceid()));

    QPushButton *zid= new QPushButton( popupKeyboardIDCaps );
    zid->setText("Z");
    zid->setFont(font);
    zid->setGeometry(120,410, 60, 40);
    zid->setFocus();
    connect(zid, SIGNAL(clicked()), this, SLOT(typeCapsZid()));

    QPushButton *xid= new QPushButton( popupKeyboardIDCaps );
    xid->setText("X");
    xid->setFont(font);
    xid->setGeometry(180,410, 60, 40);
    xid->setFocus();
    connect(xid, SIGNAL(clicked()), this, SLOT(typeCapsXid()));

    QPushButton *cid= new QPushButton( popupKeyboardIDCaps );
    cid->setText("C");
    cid->setFont(font);
    cid->setGeometry(240,410, 60, 40);
    cid->setFocus();
    connect(cid, SIGNAL(clicked()), this, SLOT(typeCapsCid()));

    QPushButton *vid= new QPushButton( popupKeyboardIDCaps );
    vid->setText("V");
    vid->setFont(font);
    vid->setGeometry(300,410, 60, 40);
    vid->setFocus();
    connect(vid, SIGNAL(clicked()), this, SLOT(typeCapsVid()));

    QPushButton *bid= new QPushButton( popupKeyboardIDCaps );
    bid->setText("B");
    bid->setFont(font);
    bid->setGeometry(360,410, 60, 40);
    bid->setFocus();
    connect(bid, SIGNAL(clicked()), this, SLOT(typeCapsBid()));

    QPushButton *nid= new QPushButton( popupKeyboardIDCaps );
    nid->setText("N");
    nid->setFont(font);
    nid->setGeometry(420,410, 60, 40);
    nid->setFocus();
    connect(nid, SIGNAL(clicked()), this, SLOT(typeCapsNid()));

    QPushButton *mid= new QPushButton( popupKeyboardIDCaps );
    mid->setText("M");
    mid->setFont(font);
    mid->setGeometry(480,410, 60, 40);
    mid->setFocus();
    connect(mid, SIGNAL(clicked()), this, SLOT(typeCapsMid()));


    QPushButton *Caps= new QPushButton( popupKeyboardIDCaps );
    Caps->setText("Caps");
    Caps->setStyleSheet("* { background-color: rgb(125,225,100) }");
    Caps->setFont(font);
    Caps->setGeometry(540,410, 90, 40);
    Caps->setFocus();
    connect(Caps, SIGNAL(clicked()), this, SLOT(popupKeyboardID()));
    connect( Caps, SIGNAL( clicked() ), popupKeyboardIDCaps, SLOT( hide()  ));


    QPushButton *enterid= new QPushButton( popupKeyboardIDCaps );
    enterid->setText("Enter");
    enterid->setFont(font);
    enterid->setGeometry(630,410, 90, 40);
    enterid->setFocus();
    connect( enterid, SIGNAL( clicked() ), popupKeyboardIDCaps, SLOT( hide()  ));
    connect( enterid, SIGNAL( clicked() ), this, SLOT( ResetLineditLoginGui() ) );
    connect( enterid, SIGNAL( clicked() ), this, SLOT( Reenableloginpass() ) );

    popupKeyboardIDCaps->show();

}


void LoginGui::UpdateDefaults()
{

    ui->Time->setText(GuiTime.currentTime().toString ("HH:mm:ss"));
    ui->Date->setText(GuiDate.currentDate().toString ());

}


//SET FUNCTION OF THE BUTTONS LOGIN ID
void LoginGui::typeQid()         //LETTER Q
{
    ui->loginid->setText(ui->loginid->text()+"q");

}
void LoginGui::typeWid()         //LETTER W
{
    ui->loginid->setText(ui->loginid->text()+"w");
}
void LoginGui::typeEid()         //LETTER E
{
    ui->loginid->setText(ui->loginid->text()+"e");
}
void LoginGui::typeRid()         //LETTER R
{
    ui->loginid->setText(ui->loginid->text()+"r");
}
void LoginGui::typeTid()         //LETTER T
{
    ui->loginid->setText(ui->loginid->text()+"t");
}
void LoginGui::typeYid()         //LETTER Y
{
    ui->loginid->setText(ui->loginid->text()+"y");
}
void LoginGui::typeUid()         //LETTER U
{
    ui->loginid->setText(ui->loginid->text()+"u");
}
void LoginGui::typeIid()         //LETTER I
{
    ui->loginid->setText(ui->loginid->text()+"i");
}
void LoginGui::typeOid()         //LETTER O
{
    ui->loginid->setText(ui->loginid->text()+"o");
}
void LoginGui::typePid()         //LETTER P
{
    ui->loginid->setText(ui->loginid->text()+"p");
}
void LoginGui::typeAid()         //LETTER A
{
    ui->loginid->setText(ui->loginid->text()+"a");
}
void LoginGui::typeSid()         //LETTER S
{
    ui->loginid->setText(ui->loginid->text()+"s");
}
void LoginGui::typeDid()         //LETTER D
{
    ui->loginid->setText(ui->loginid->text()+"d");
}
void LoginGui::typeFid()         //LETTER F
{
    ui->loginid->setText(ui->loginid->text()+"f");
}
void LoginGui::typeGid()         //LETTER G
{
    ui->loginid->setText(ui->loginid->text()+"g");
}
void LoginGui::typeHid()         //LETTER H
{
    ui->loginid->setText(ui->loginid->text()+"h");
}
void LoginGui::typeJid()         //LETTER J
{
    ui->loginid->setText(ui->loginid->text()+"j");
}
void LoginGui::typeKid()         //LETTER K
{
    ui->loginid->setText(ui->loginid->text()+"k");
}
void LoginGui::typeLid()         //LETTER L
{
    ui->loginid->setText(ui->loginid->text()+"l");
}
void LoginGui::typeZid()         //LETTER Z
{
    ui->loginid->setText(ui->loginid->text()+"z");
}
void LoginGui::typeXid()         //LETTER X
{
    ui->loginid->setText(ui->loginid->text()+"x");
}
void LoginGui::typeCid()         //LETTER C
{
    ui->loginid->setText(ui->loginid->text()+"c");
}
void LoginGui::typeVid()         //LETTER V
{
    ui->loginid->setText(ui->loginid->text()+"v");
}
void LoginGui::typeBid()         //LETTER B
{
    ui->loginid->setText(ui->loginid->text()+"b");
}
void LoginGui::typeNid()         //LETTER N
{
    ui->loginid->setText(ui->loginid->text()+"n");
}
void LoginGui::typeMid()         //LETTER M
{
    ui->loginid->setText(ui->loginid->text()+"m");
}
void LoginGui::typeCapsQid()         //LETTER Q
{
    ui->loginid->setText(ui->loginid->text()+"Q");

}
void LoginGui::typeCapsWid()         //LETTER W
{
    ui->loginid->setText(ui->loginid->text()+"W");
}
void LoginGui::typeCapsEid()         //LETTER E
{
    ui->loginid->setText(ui->loginid->text()+"E");
}
void LoginGui::typeCapsRid()         //LETTER R
{
    ui->loginid->setText(ui->loginid->text()+"R");
}
void LoginGui::typeCapsTid()         //LETTER T
{
    ui->loginid->setText(ui->loginid->text()+"T");
}
void LoginGui::typeCapsYid()         //LETTER Y
{
    ui->loginid->setText(ui->loginid->text()+"Y");
}
void LoginGui::typeCapsUid()         //LETTER U
{
    ui->loginid->setText(ui->loginid->text()+"U");
}
void LoginGui::typeCapsIid()         //LETTER I
{
    ui->loginid->setText(ui->loginid->text()+"I");
}
void LoginGui::typeCapsOid()         //LETTER O
{
    ui->loginid->setText(ui->loginid->text()+"O");
}
void LoginGui::typeCapsPid()         //LETTER P
{
    ui->loginid->setText(ui->loginid->text()+"P");
}
void LoginGui::typeCapsAid()         //LETTER A
{
    ui->loginid->setText(ui->loginid->text()+"A");
}
void LoginGui::typeCapsSid()         //LETTER S
{
    ui->loginid->setText(ui->loginid->text()+"S");
}
void LoginGui::typeCapsDid()         //LETTER D
{
    ui->loginid->setText(ui->loginid->text()+"D");
}
void LoginGui::typeCapsFid()         //LETTER F
{
    ui->loginid->setText(ui->loginid->text()+"F");
}
void LoginGui::typeCapsGid()         //LETTER G
{
    ui->loginid->setText(ui->loginid->text()+"G");
}
void LoginGui::typeCapsHid()         //LETTER H
{
    ui->loginid->setText(ui->loginid->text()+"H");
}
void LoginGui::typeCapsJid()         //LETTER J
{
    ui->loginid->setText(ui->loginid->text()+"J");
}
void LoginGui::typeCapsKid()         //LETTER K
{
    ui->loginid->setText(ui->loginid->text()+"K");
}
void LoginGui::typeCapsLid()         //LETTER L
{
    ui->loginid->setText(ui->loginid->text()+"L");
}
void LoginGui::typeCapsZid()         //LETTER Z
{
    ui->loginid->setText(ui->loginid->text()+"Z");
}
void LoginGui::typeCapsXid()         //LETTER X
{
    ui->loginid->setText(ui->loginid->text()+"X");
}
void LoginGui::typeCapsCid()         //LETTER C
{
    ui->loginid->setText(ui->loginid->text()+"C");
}
void LoginGui::typeCapsVid()         //LETTER V
{
    ui->loginid->setText(ui->loginid->text()+"V");
}
void LoginGui::typeCapsBid()         //LETTER B
{
    ui->loginid->setText(ui->loginid->text()+"B");
}
void LoginGui::typeCapsNid()         //LETTER N
{
    ui->loginid->setText(ui->loginid->text()+"N");
}
void LoginGui::typeCapsMid()         //LETTER M
{
    ui->loginid->setText(ui->loginid->text()+"M");
}
void LoginGui::backspaceid()
{
    ui->loginid->backspace();
}
void LoginGui::Num1id()
{
    ui->loginid->setText(  ui->loginid->text()+"1");
}
void LoginGui::Num2id()
{
    ui->loginid->setText(  ui->loginid->text()+"2");
}
void LoginGui::Num3id()
{
    ui->loginid->setText(ui->loginid->text()+"3");
}
void LoginGui::Num4id()
{
    ui->loginid->setText(ui->loginid->text()+"4");
}
void LoginGui::Num5id()
{
    ui->loginid->setText(ui->loginid->text()+"5");
}
void LoginGui::Num6id()
{
    ui->loginid->setText(ui->loginid->text()+"6");
}
void LoginGui::Num7id()
{
    ui->loginid->setText(ui->loginid->text()+"7");
}
void LoginGui::Num8id()
{
    ui->loginid->setText(ui->loginid->text()+"8");
}
void LoginGui::Num9id()
{
    ui->loginid->setText(ui->loginid->text()+"9");
}
void LoginGui::Num0id()
{
    ui->loginid->setText(ui->loginid->text()+"0");
}


void LoginGui::ResetLineditLoginGui()
{
    ui->loginid->setStyleSheet("QLineEdit{background: white;}");
    ui->password->setStyleSheet("QLineEdit{background: white;}");
}

void LoginGui::Reenableloginpass()
{
    ui->loginid->setEnabled(1);
    ui->password->setEnabled(1);
}

void LoginGui::on_loginid_selectionChanged()
{
    ui->password->setStyleSheet("QLineEdit{background: white;}");
    ui->loginid->setStyleSheet("QLineEdit{background: grey;}");
    popupKeyboardID();
    ui->loginid->setEnabled(0);
    ui->password->setEnabled(0);
}


void LoginGui::on_ClearID_clicked()
{
    ui->loginid->setText("");
}

void LoginGui::on_ClearPassword_clicked()
{
  ui->password->setText("");
}


//KEYPAD CODES (USE THIS IN LINUX)!!!!!!!!!!!!!!!!!!!!!
void LoginGui::LoginCheckKeypadPressed()

{
 #ifdef USE_LINUX
QWidget *Focus = QApplication::focusWidget();
    if(Focus)
    {
    if(key_Available()==1)
        {
            int CheckNumber;
             CheckNumber=key_Get();
             if(CheckNumber==1)
             {
                 QKeyEvent press(QEvent::KeyPress, Qt::Key_1, Qt::NoModifier, "1");
                        QApplication::sendEvent(Focus, &press);
                        QKeyEvent release(QEvent::KeyRelease, Qt::Key_1, Qt::NoModifier, "1");
                        QApplication::sendEvent(Focus, &release);
             }
             if(CheckNumber==2)
             {
                 QKeyEvent press(QEvent::KeyPress, Qt::Key_2, Qt::NoModifier, "2");
                        QApplication::sendEvent(Focus, &press);
                        QKeyEvent release(QEvent::KeyRelease, Qt::Key_2, Qt::NoModifier, "2");
                        QApplication::sendEvent(Focus, &release);
             }
             if(CheckNumber==3)
             {
                 QKeyEvent press(QEvent::KeyPress, Qt::Key_3, Qt::NoModifier, "3");
                        QApplication::sendEvent(Focus, &press);
                        QKeyEvent release(QEvent::KeyRelease, Qt::Key_3, Qt::NoModifier, "3");
                        QApplication::sendEvent(Focus, &release);
             }
             if(CheckNumber==4)
             {
                 QKeyEvent press(QEvent::KeyPress, Qt::Key_4, Qt::NoModifier, "4");
                        QApplication::sendEvent(Focus, &press);
                        QKeyEvent release(QEvent::KeyRelease, Qt::Key_4, Qt::NoModifier, "4");
                        QApplication::sendEvent(Focus, &release);
             }
             if(CheckNumber==5)
             {
                 QKeyEvent press(QEvent::KeyPress, Qt::Key_5, Qt::NoModifier, "5");
                        QApplication::sendEvent(Focus, &press);
                        QKeyEvent release(QEvent::KeyRelease, Qt::Key_5, Qt::NoModifier, "5");
                        QApplication::sendEvent(Focus, &release);
             }
             if(CheckNumber==6)
             {
                 QKeyEvent press(QEvent::KeyPress, Qt::Key_6, Qt::NoModifier, "6");
                        QApplication::sendEvent(Focus, &press);
                        QKeyEvent release(QEvent::KeyRelease, Qt::Key_6, Qt::NoModifier, "6");
                        QApplication::sendEvent(Focus, &release);
             }
             if(CheckNumber==7)
             {
                 QKeyEvent press(QEvent::KeyPress, Qt::Key_7, Qt::NoModifier, "7");
                        QApplication::sendEvent(Focus, &press);
                        QKeyEvent release(QEvent::KeyRelease, Qt::Key_7, Qt::NoModifier, "7");
                        QApplication::sendEvent(Focus, &release);
             }
             if(CheckNumber==8)
             {
                 QKeyEvent press(QEvent::KeyPress, Qt::Key_8, Qt::NoModifier, "8");
                 QApplication::sendEvent(Focus, &press);
                 QKeyEvent release(QEvent::KeyRelease, Qt::Key_8, Qt::NoModifier, "8");
                 QApplication::sendEvent(Focus, &release);
             }
             if(CheckNumber==9)
             {
                 QKeyEvent press(QEvent::KeyPress, Qt::Key_9, Qt::NoModifier, "9");
                 QApplication::sendEvent(Focus, &press);
                 QKeyEvent release(QEvent::KeyRelease, Qt::Key_9, Qt::NoModifier, "9");
                 QApplication::sendEvent(Focus, &release);
             }
}
    }
     #endif
    }

//KEYPAD CODES (USE THIS IN LINUX)!!!!!!!!!!!!!!!!!!!!!

