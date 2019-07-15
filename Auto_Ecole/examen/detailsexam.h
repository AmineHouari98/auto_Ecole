#ifndef DETAILSEXAM_H
#define DETAILSEXAM_H

#include <QDialog>
#include "t_caisse.h"
#include "t_examens.h"
#include "t_candidats.h"

namespace Ui {
class detailsExam;
}

class detailsExam : public QDialog
{
    Q_OBJECT

public:
    explicit detailsExam(QWidget *parent = 0);
    ~detailsExam();
    void setValuesOnLineEdit(int);

public slots:
    void on_pushButton_modifier_clicked();

private slots:
    void on_pushButton_annuler_clicked();

private:
    Ui::detailsExam *ui;
    t_caisse *tableCaisse;
    t_examens *tableExamens;
    void setEditable(bool);
    void modifyOnDatabase();
    void changeButtonState(QString,bool);
};

#endif // DETAILSEXAM_H
