#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QWidget>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QtGui>
#include <QtCore>
#include <QCompleter>
#include "patientgui.h"


namespace Ui {
class LoginGui;
}

class LoginGui : public QWidget
{
    Q_OBJECT
    
public:
    explicit LoginGui(QWidget *parent = 0);
    ~LoginGui();

public slots :
    void loginClinicianGui();
    void loginAdminGui();

private slots:

    void UpdateDefaults();


    void LoginCheckKeypadPressed();




    void on_administratorRB_clicked();

    void on_clinicianRB_clicked();

    void on_loginButton_clicked();

    void on_loginid_textChanged(const QString &arg1);

    void on_loginid_selectionChanged();

    void on_ClearID_clicked();

    void on_ClearPassword_clicked();


    //FUNCTIONN FOR POPUP KEYBOARD
    void typeQid();
    void typeWid();
    void typeEid();
    void typeRid();
    void typeTid();
    void typeYid();
    void typeUid();
    void typeIid();
    void typeOid();
    void typePid();
    void typeAid();
    void typeSid();
    void typeDid();
    void typeFid();
    void typeGid();
    void typeHid();
    void typeJid();
    void typeKid();
    void typeLid();
    void typeZid();
    void typeXid();
    void typeCid();
    void typeVid();
    void typeBid();
    void typeNid();
    void typeMid();
    void typeCapsQid();
    void typeCapsWid();
    void typeCapsEid();
    void typeCapsRid();
    void typeCapsTid();
    void typeCapsYid();
    void typeCapsUid();
    void typeCapsIid();
    void typeCapsOid();
    void typeCapsPid();
    void typeCapsAid();
    void typeCapsSid();
    void typeCapsDid();
    void typeCapsFid();
    void typeCapsGid();
    void typeCapsHid();
    void typeCapsJid();
    void typeCapsKid();
    void typeCapsLid();
    void typeCapsZid();
    void typeCapsXid();
    void typeCapsCid();
    void typeCapsVid();
    void typeCapsBid();
    void typeCapsNid();
    void typeCapsMid();
    void backspaceid();
    void Num1id();
    void Num2id();
    void Num3id();
    void Num4id();
    void Num5id();
    void Num6id();
    void Num7id();
    void Num8id();
    void Num9id();
    void Num0id();
    void popupKeyboardID();
    void popupKeyboardIDCaps();
    void ResetLineditLoginGui();
    void Reenableloginpass();
private:
    Ui::LoginGui *ui;
    QCompleter *IDCompleter;
    QCompleter *passCompleter;
    QTime GuiTime;
    QDate GuiDate;


};

#endif // LOGINGUI_H
