#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <QWidget>
#include <myparentobject.h>
#include "addCandidat.h"
#include "tables/t_candidats.h"


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

private:
    Ui::candidat *ui;
    t_candidats *candidatsTable;
    QSqlTableModel logTable;
};

#endif // CANDIDAT_H
