#ifndef PATIENTGUI_H
#define PATIENTGUI_H

#include <QWidget>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QtGui>
#include <QtCore>
#include <QCompleter>
#include "logingui.h"


namespace Ui {
class PatientGui;


}

class PatientGui : public QWidget
{
    Q_OBJECT
    
public:
    explicit PatientGui(QWidget *parent = 0);
    ~PatientGui();
    QString NRIC;


public slots:



private slots:
    void on_Back_clicked();

    void patientguiback();

    void patientSelectDrugOptions();

    void on_nric_textChanged(const QString &arg1);

    void on_Register_clicked();


    void UpdateDefaults();

     void popupKeyboardNRIC();
     void popupKeyboardCapsNRIC();
;


     void ResetLineditNricBedno();

     void ReenableNricBedno();

     void on_nric_selectionChanged();   

     void typeQnric();
     void typeWnric();
     void typeEnric();
     void typeRnric();
     void typeTnric();
     void typeYnric();
     void typeUnric();
     void typeInric();
     void typeOnric();
     void typePnric();
     void typeAnric();
     void typeSnric();
     void typeDnric();
     void typeFnric();
     void typeGnric();
     void typeHnric();
     void typeJnric();
     void typeKnric();
     void typeLnric();
     void typeZnric();
     void typeXnric();
     void typeCnric();
     void typeVnric();
     void typeBnric();
     void typeNnric();
     void typeMnric();
     void Num0Nric();
     void Num1Nric();
     void Num2Nric();
     void Num3Nric();
     void Num4Nric();
     void Num5Nric();
     void Num6Nric();
     void Num7Nric();
     void Num8Nric();
     void Num9Nric();
     void typeQCapsNric();
     void typeWCapsNric();
     void typeECapsNric();
     void typeRCapsNric();
     void typeTCapsNric();
     void typeYCapsNric();
     void typeUCapsNric();
     void typeICapsNric();
     void typeOCapsNric();
     void typePCapsNric();
     void typeACapsNric();
     void typeSCapsNric();
     void typeDCapsNric();
     void typeFCapsNric();
     void typeGCapsNric();
     void typeHCapsNric();
     void typeJCapsNric();
     void typeKCapsNric();
     void typeLCapsNric();
     void typeZCapsNric();
     void typeXCapsNric();
     void typeCCapsNric();
     void typeVCapsNric();
     void typeBCapsNric();
     void typeNCapsNric();
     void typeMCapsNric();
     void Num0CapsNric();
     void Num1CapsNric();
     void Num2CapsNric();
     void Num3CapsNric();
     void Num4CapsNric();
     void Num5CapsNric();
     void Num6CapsNric();
     void Num7CapsNric();
     void Num8CapsNric();
     void Num9CapsNric();
     void backspacenric();
     void backspaceCapsNric();

     void on_ClearNric_clicked();

     void on_ClearBedNumber_clicked();


private:
  Ui::PatientGui *ui;
    QTime GuiTime;
    QDate GuiDate;
signals:
        void Nric(const QString&NricText);



};

#endif // PATIENTGUI_H

