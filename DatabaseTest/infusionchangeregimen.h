#ifndef INFUSIONCHANGEREGIMEN_H
#define INFUSIONCHANGEREGIMEN_H

#include <QWidget>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QtGui>
#include <QtCore>
#include <QCompleter>


namespace Ui {
class infusionChangeRegimen;
}

class infusionChangeRegimen : public QWidget
{
    Q_OBJECT
    
public:
    explicit infusionChangeRegimen(QWidget *parent = 0);
    ~infusionChangeRegimen();
    
private slots:
    void on_Regimen1_clicked();

    void on_Regimen2_clicked();

    void on_Regimen3_clicked();

    void on_Back_clicked();

    void UpdateDefaults();

     void on_doubleSpinBox_valueChanged(const QString &arg1);

private:
    Ui::infusionChangeRegimen *ui;
    QTime GuiTime;
    QDate GuiDate;
};

#endif // INFUSIONCHANGEREGIMEN_H
