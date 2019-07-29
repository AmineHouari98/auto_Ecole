#include "printall.h"
#include "ui_printall.h"

printAll::printAll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::printAll)
{
    ui->setupUi(this);
    ui->dateEdit_1->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit_2->setDisplayFormat("yyyy-MM-dd");

}

printAll::~printAll()
{
    delete ui;
}

void printAll::on_pushButton_Annuler_clicked()
{
    close();
}

void printAll::on_pushButton_imprimer_clicked()
{

    printer.printAllCandidat(ui->dateEdit_1->date().toString("yyyy-MM-dd")
                             ,ui->dateEdit_2->date().toString("yyyy-MM-dd"));

    close();
}
