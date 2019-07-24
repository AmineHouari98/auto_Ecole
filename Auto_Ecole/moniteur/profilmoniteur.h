#ifndef PROFILMONITEUR_H
#define PROFILMONITEUR_H

#include <QDialog>
#include "t_caisse.h"
#include "t_moniteurs.h"

#include "ajouterpaiment.h"
#include "myparentobject.h"

namespace Ui {
class profilMoniteur;
}

class profilMoniteur : public QDialog,public MyParentObject
{
    Q_OBJECT

public:
    explicit profilMoniteur(QWidget *parent = 0);
    ~profilMoniteur();
    void setValuesOnLineEdit(int);

public slots:
    void on_pushButton_modifier_clicked();
    void on_pushButton_annuler_clicked();
private slots:
    void on_toolButton_Modifier_clicked();
    void on_toolButton_Ajouter_clicked();
    void on_toolButton_Supprimer_clicked();
private:
    Ui::profilMoniteur *ui;
    t_caisse *tableCaisse;
    t_moniteurs *tableMoniteurs;
    QStringList list={"kholsa","Autre"};

    void setEditable(bool);
    void modifyOnDatabase();
    void changeButtonState(QString,bool);
};

#endif // PROFILMONITEUR_H
