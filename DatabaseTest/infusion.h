#ifndef INFUSION_H
#define INFUSION_H

#include <QWidget>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QtGui>
#include <QtCore>
#include <QCompleter>
#include <iostream>
#include "patientgui.h"
#include "regimenoption.h"




namespace Ui {
class Infusion;


}

class Infusion : public QWidget
{
    Q_OBJECT
    
public:
    explicit Infusion(QWidget *parent = 0);
    ~Infusion();

private slots:
      void on_PauseInfusion_clicked();
      void on_ChangeRegimen_clicked();
     void on_StopInfuison_clicked();
     void on_StartInfusion_clicked();

     void UpdateDefaults();


private:
    Ui::Infusion *ui;
    bool mRunning;
    QDateTime mStartTime;
    qint64      mTotalTime;
    qint64      mSessionTime;
    QTime GuiTime;
    QDate GuiDate;
    QString nric;







public slots:
    void start(void);
    void stop(void);
    void pause(void);
     void UpdateInfusingDataFreq();
     void UpdatePauseDataFreq();
     void UpdateStopDataFreq();
     void UpdateInfusingDataTCP();
     void UpdatePauseDataTCP();
     void UpdateStopDataTCP();
     void StopInfusion();






protected:
      void timerEvent(QTimerEvent *);
};

#endif // INFUSION_H
