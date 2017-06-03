#ifndef CHANGEIPADD_H
#define CHANGEIPADD_H

#include <QWidget>
#include <QtGui>
#include <QtCore>

namespace Ui {
class ChangeIpadd;
}

class ChangeIpadd : public QWidget
{
    Q_OBJECT
    
public:
    explicit ChangeIpadd(QWidget *parent = 0);
    ~ChangeIpadd();
    
private:
    Ui::ChangeIpadd *ui;
    QTime GuiTime;
    QDate GuiDate;
private slots:

    void UpdateDefaults();
    void on_back_clicked();
    void on_Clear_clicked();
    void on_Set_clicked();
};

#endif // CHANGEIPADD_H
