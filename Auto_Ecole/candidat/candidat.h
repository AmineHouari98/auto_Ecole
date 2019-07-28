#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <QWidget>
#include <myparentobject.h>

#include "addCandidat.h"
#include "profilcandidat.h"
#include "associer.h"

#include "t_candidats.h"
#include "t_caisse.h"
#include "t_documents.h"
#include "t_inter.h"


#include "impression.h"


namespace Ui {
class candidat;
}

class candidat : public QWidget, public MyParentObject
{
    Q_OBJECT

public:
    explicit candidat(QWidget *parent = 0);
    ~candidat();

private slots:
    void on_toolButton_new_client_clicked();

    void on_btn_viewProfile_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);



    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::candidat *ui;
    t_candidats *tableCandidats;
    impression printer;
    void openDetails();


};

#endif // CANDIDAT_H
