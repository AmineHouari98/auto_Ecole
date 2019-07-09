#ifndef MONITEUR_H
#define MONITEUR_H

#include <QWidget>
#include <myparentobject.h>
#include "addMoniteur.h"
#include "t_moniteurs.h"
#include "t_caisse.h"


namespace Ui {
class moniteur;
}

class moniteur : public QWidget, public MyParentObject
{
    Q_OBJECT

public:
    explicit moniteur(QWidget *parent = 0);
    ~moniteur();

private slots:
    void on_toolButton_new_client_clicked();


    void on_btn_viewProfile_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_toolButton_back_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);


    void on_pushButton_modifier_clicked();

private:
    Ui::moniteur *ui;
    t_moniteurs *tableMoniteurs;
    t_caisse *tableCaisse;
    QSqlTableModel *caisseTable;
    void setValuesOnLineEdit(int);
    void setEditable(bool);
    void modifyOnDatabase();
    void changeButtonState(QString,bool);
};

#endif // MONITEUR_H
