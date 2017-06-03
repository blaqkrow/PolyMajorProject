#ifndef REGIMENOPTION_H
#define REGIMENOPTION_H

#include <QWidget>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QtGui>
#include <QtCore>
#include <QCompleter>

//extern int regimen_Option_Count;

namespace Ui {
class RegimenOption;

}

class RegimenOption : public QWidget
{
    Q_OBJECT

public:
    explicit RegimenOption(QWidget *parent = 0);
    ~RegimenOption();

private slots:
    void on_Back_clicked();
    void regimenGuiBack();
    void regimenInfusionGui();
    void on_Regimen1_clicked();

    void on_Regimen2_clicked();

    void on_Regimen3_clicked();


    void on_doubleSpinBox_valueChanged(const QString &arg1);


    void UpdateDefaults();
private:
    Ui::RegimenOption *ui;
    QTime GuiTime;
    QDate GuiDate;


};

#endif // REGIMENOPTION_H
