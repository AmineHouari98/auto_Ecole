#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <QWidget>
#include <myparentobject.h>
#include "addCandidat.h"
#include "profilcandidat.h"
#include "t_candidats.h"
#include "t_caisse.h"
#include "t_documents.h"


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



private:
    Ui::candidat *ui;
    t_candidats *tableCandidats;
    void openDetails();


};

#endif // CANDIDAT_H
