#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <QWidget>
#include <myparentobject.h>
#include "addCandidat.h"
#include "t_candidats.h"
#include "t_caisse.h"


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

    void on_stackedWidget_currentChanged(int arg1);

    void on_toolButton_back_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);


    void on_pushButton_modifier_clicked();

    void on_pushButton_annuler_clicked();

private:
    Ui::candidat *ui;
    t_candidats *tableCandidats;
    t_caisse *tableCaisse;
    QSqlTableModel *caisseTable;
    void setValuesOnLineEdit(int);
    void setEditable(bool);
    void modifyOnDatabase();
    void changeButtonState(QString,bool);
};

#endif // CANDIDAT_H
