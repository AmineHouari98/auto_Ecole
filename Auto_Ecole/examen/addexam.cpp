#include "addexam.h"
#include "ui_addexam.h"

addExam::addExam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addExam)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout Examen");
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(QIcon(":/Assets/Images/icons/add_candidat.svg"));

    ui->dateEdit_Date->setDisplayFormat("yyyy-MM-dd");

    setManual(true);
    setAuto(false);
}

addExam::~addExam()
{
    delete ui;
}

void addExam::on_radioButton_Manuel_clicked()
{
    setManual(true);
    setAuto(false);
}

void addExam::on_radioButton_Auto_clicked()
{
    setManual(false);
    setAuto(true);
}

void addExam::on_pushButton_Valider_clicked()
{
    if(ui->radioButton_Manuel->isChecked())
    {
        addOnTable(
                    ui->lineEdit_nomExaminateur->text(),
                    ui->lineEdit_Lieu->text(),
                    ui->dateEdit_Date->date()

                    );

    }
    else if(ui->radioButton_Auto->isChecked())
    {

        //TODO: implement auto add

    }
    close();

}

void addExam::on_pushButton_Annuler_clicked()
{
    close();
}

void addExam::setAuto(bool ok)
{
    ui->radioButton_Auto->setChecked(ok);
    ui->spinBox->setEnabled(ok);

}

void addExam::setManual(bool ok)
{
    ui->radioButton_Manuel->setChecked(ok);
    ui->lineEdit_Lieu->setEnabled(ok);
    ui->lineEdit_nomExaminateur->setEnabled(ok);
    ui->dateEdit_Date->setEnabled(ok);

}

void addExam::addOnTable(QString examinateur, QString lieu, QDate date)
{
    examsTable.setCurrentRow(-1);

    examsTable.setEXAMINATEUR       (examinateur);
    examsTable.setLIEU              (lieu);
    examsTable.setDATE              (date);

    examsTable.insert() ;

}
