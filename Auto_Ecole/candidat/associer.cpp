#include "associer.h"
#include "ui_associer.h"
#include <QDebug>

Associer::Associer(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Associer)
{
    ui->setupUi(this);

    tableExamens = new t_examens;
    tableInter = new t_inter;



    QString date = QDate::currentDate().toString("yyyy-MM-dd");


    tableExamens->where("DATE >= '"+date+"'");
    tableExamens->select();

    ui->comboBox->setModel(tableExamens->toModel());
    ui->comboBox->setModelColumn(t_examens::_03DATE);

    tableInter->setCurrentRow(-1);
    tableInter->setidCandidat(id);




}

Associer::~Associer()
{
    delete ui;
}

void Associer::on_pushButton_Annuler_clicked()
{
    close();
}

void Associer::on_pushButton_Valider_clicked()
{

    tableExamens->setCurrentRow(ui->comboBox->currentIndex());
    tableInter->setidExamen(tableExamens->getid());

    tableInter->insert();
    tableInter->select();
    close();

}
