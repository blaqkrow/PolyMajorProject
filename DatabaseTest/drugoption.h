#ifndef DRUGOPTION_H
#define DRUGOPTION_H

#include <QWidget>
#include <QtGui>
#include <QtCore>

namespace Ui {
class DrugOption;
}

class DrugOption : public QWidget
{
    Q_OBJECT
    
public:
    explicit DrugOption(QWidget *parent = 0);
    ~DrugOption();
    
private slots:
    void on_Back_clicked();

    void on_Ok_clicked();

    void UpdateDefaults();
private:
    Ui::DrugOption *ui;

    QTime GuiTime;
    QDate GuiDate;
};

#endif // DRUGOPTION_H
