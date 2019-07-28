#ifndef ADDINEXAM_H
#define ADDINEXAM_H

#include <QDialog>
#include "t_candidats.h"
#include "t_inter.h"
#include "form.h"


namespace Ui {
class AddInExam;
}

class AddInExam : public QDialog
{
    Q_OBJECT

public:
    explicit AddInExam(int index=-1,QWidget *parent = 0);
    ~AddInExam();

private slots:
    void on_pushButton_valider_clicked();

    void on_pushButton_annuler_clicked();

private:
    Ui::AddInExam *ui;
    t_candidats *tableCandidats;
    t_inter *tableInter;
    int idExam;
    Form *myForm;
};

#endif // ADDINEXAM_H
