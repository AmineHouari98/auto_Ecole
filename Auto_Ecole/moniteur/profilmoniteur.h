#ifndef PROFILMONITEUR_H
#define PROFILMONITEUR_H

#include <QDialog>
#include "t_caisse.h"
#include "t_moniteurs.h"

namespace Ui {
class profilMoniteur;
}

class profilMoniteur : public QDialog
{
    Q_OBJECT

public:
    explicit profilMoniteur(QWidget *parent = 0);
    ~profilMoniteur();
    void setValuesOnLineEdit(int);

public slots:
        void on_pushButton_modifier_clicked();

private:
    Ui::profilMoniteur *ui;
    t_caisse *tableCaisse;
    t_moniteurs *tableMoniteurs;
    void setEditable(bool);
    void modifyOnDatabase();
    void changeButtonState(QString,bool);
};

#endif // PROFILMONITEUR_H
