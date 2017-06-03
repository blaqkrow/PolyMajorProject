#ifndef REGISTERCLINICIANGUI_H
#define REGISTERCLINICIANGUI_H

#include <QWidget>
#include <QtGui>
#include <QtCore>

namespace Ui {
class RegisterClinicianGui;
}

class RegisterClinicianGui : public QWidget
{
    Q_OBJECT
    
public:
    explicit RegisterClinicianGui(QWidget *parent = 0);
    ~RegisterClinicianGui();
    
private slots:
    void on_Back_clicked();
    void RegisterClinicianBack();

    void on_Register_clicked();


    void UpdateDefaults();

private:
    Ui::RegisterClinicianGui *ui;
    QTime GuiTime;
    QDate GuiDate;
};

#endif // REGISTERCLINICIANGUI_H
