#ifndef MONITEUR_H
#define MONITEUR_H

#include <QWidget>
#include <myparentobject.h>
#include "addMoniteur.h"
#include "t_moniteurs.h"
#include "profilmoniteur.h"


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

    void on_tableView_doubleClicked(const QModelIndex &index);


private:
    Ui::moniteur *ui;
    t_moniteurs *tableMoniteurs;
    void openDetails();

};

#endif // MONITEUR_H
