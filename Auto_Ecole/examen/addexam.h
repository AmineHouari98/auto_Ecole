#ifndef ADDEXAM_H
#define ADDEXAM_H

#include <QDialog>
#include "myparentobject.h"
#include "t_examens.h"

namespace Ui {
class addExam;
}

class addExam : public QDialog,public MyParentObject
{
    Q_OBJECT

public:
    explicit addExam(QWidget *parent = 0);
    ~addExam();

private slots:
    void on_radioButton_Manuel_clicked();

    void on_radioButton_Auto_clicked();

    void on_pushButton_Valider_clicked();

    void on_pushButton_Annuler_clicked();

private:
    Ui::addExam *ui;
    t_examens examsTable;
    void setAuto(bool);
    void setManual(bool);
    void addOnTable(QString,QString,QString);
};

#endif // ADDEXAM_H
