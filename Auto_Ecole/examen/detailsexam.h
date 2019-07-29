#ifndef DETAILSEXAM_H
#define DETAILSEXAM_H

#include <QDialog>
#include <QSqlQuery>
#include <QCheckBox>

#include "t_examens.h"
#include "t_candidats.h"
#include "t_inter.h"

#include "dataModels.h"
#include "impression.h"
#include "form.h"
#include "myparentobject.h"
#include "addinexam.h"

namespace Ui {
class detailsExam;
}

class detailsExam : public QDialog,public MyParentObject
{
    Q_OBJECT

public:
    explicit detailsExam(int index =-1,QWidget *parent = 0);
    ~detailsExam();

public slots:
    void on_pushButton_modifier_clicked();

private slots:
    void on_pushButton_annuler_clicked();

    void on_toolButton_ImprimerListe_clicked();

    void on_toolButton_Ajouter_clicked();

    void on_toolButton_Supp_clicked();

private:
    Ui::detailsExam *ui;
    t_examens *tableExamens;
    t_inter *tableInter;
    impression printer;

    Form *myForm = nullptr;
    int idExam;



    void setValuesOnLineEdit();
    void executeQuery();
    void setEditable(bool);
    void modifyOnDatabase();
    void changeButtonState(QString,bool);
};

#endif // DETAILSEXAM_H
