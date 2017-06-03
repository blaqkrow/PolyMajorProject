#ifndef CLINICIANOPTIONS_H
#define CLINICIANOPTIONS_H

#include <QWidget>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QtGui>
#include <QtCore>
namespace Ui {
class ClinicianOptions;
}

class ClinicianOptions : public QWidget
{
    Q_OBJECT
    
public:
    explicit ClinicianOptions(QWidget *parent = 0);
    ~ClinicianOptions();
    
private:
    Ui::ClinicianOptions *ui;
    QTime GuiTime;
    QDate GuiDate;

private slots:
    void UpdateDefaults();
    void on_Select_clicked();
    void on_Back_clicked();
    void ClinicianBack();
    void ClinicianOptionRegisterPatient();
    void ClinicianCheckHistory();

};

#endif // CLINICIANOPTIONS_H
