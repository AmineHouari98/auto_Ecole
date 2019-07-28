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

namespace Ui {
class detailsExam;
}

class detailsExam : public QDialog,public MyParentObject
{
    Q_OBJECT

public:
    explicit detailsExam(QWidget *parent = 0);
    ~detailsExam();
    void setValuesOnLineEdit(int);
    void executeQuery(int);

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



    void setEditable(bool);
    void modifyOnDatabase();
    void changeButtonState(QString,bool);
};

#endif // DETAILSEXAM_H
