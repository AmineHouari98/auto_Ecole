#ifndef ADDVEHICULE_H
#define ADDVEHICULE_H


#include <QDialog>
#include <QDate>
#include <QIntValidator>
#include "t_vehicules.h"

namespace Ui {
class addVehicule;
}

class addVehicule
{
    Q_OBJECT

public:
    explicit addVehicule(QWidget *parent = 0, int id = -1);
    ~addVehicule();

private slots:
    void on_pushButton_Valider_clicked();
    void on_pushButton_Annuler_clicked();
    void setUpLineEdits();
    void on_pushButton_clicked();
private:
    Ui::addVehicule *ui;
    t_vehicules *tableVehicule;
    QList<QLineEdit*> lineList;
    void checkAll(bool);
};

#endif // ADDVEHICULE_H
