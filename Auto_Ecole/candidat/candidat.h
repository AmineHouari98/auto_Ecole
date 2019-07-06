#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <QWidget>
#include <myparentobject.h>
#include "addCandidat.h"
//#include "t_candidat.h"

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
    void on_btnNouveaucandidat_clicked();

private:
    Ui::candidat *ui;
   // t_candidat *candidatTable;
   // QSqlTableModel logTable;
};

#endif // CANDIDAT_H
