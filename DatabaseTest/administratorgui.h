#ifndef ADMINISTRATORGUI_H
#define ADMINISTRATORGUI_H

#include <QWidget>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QtGui>
#include <QtCore>
#include <QCompleter>


namespace Ui {
class administratorGui;
}

class administratorGui : public QWidget
{
    Q_OBJECT
    
public:
    explicit administratorGui(QWidget *parent = 0);
    ~administratorGui();

private:
    Ui::administratorGui *ui;
    QTime GuiTime;
    QDate GuiDate;
private slots :
     void UpdateDefaults();

      void AdminRegisterClinician();
      void AdminChangeIPAddress();
     void on_pushButton_clicked();
     void on_pushButton_2_clicked();
};

#endif // ADMINISTRATORGUI_H
