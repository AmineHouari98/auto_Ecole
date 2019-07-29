#ifndef ASSOCIER_H
#define ASSOCIER_H

#include <QDialog>
#include <QDate>

#include "t_inter.h"
#include "t_examens.h"

namespace Ui {
class Associer;
}

class Associer : public QDialog
{
    Q_OBJECT

public:
    explicit Associer(int id =-1,QWidget *parent = 0);
    ~Associer();

private slots:
    void on_pushButton_Annuler_clicked();

    void on_pushButton_Valider_clicked();

private:
    Ui::Associer *ui;
    t_inter *tableInter;
    t_examens *tableExamens;
};

#endif // ASSOCIER_H
