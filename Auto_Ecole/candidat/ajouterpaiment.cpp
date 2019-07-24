#include "ajouterpaiment.h"
#include "ui_ajouterpaiment.h"

AjouterPaiment::AjouterPaiment(int index,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterPaiment)
{
    candidat=index;
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    tableCaisse = new t_caisse;
}

AjouterPaiment::~AjouterPaiment()
{

    delete ui;
}

void AjouterPaiment::on_comboBox_currentIndexChanged(const QString &arg1)
{
    type=arg1;
    if(arg1 == "Autre")ui->lineEdit->setEnabled(true);
    else ui->lineEdit->setEnabled(false);
}


void AjouterPaiment::on_pushButton_2_clicked()
{
    close();
}

void AjouterPaiment::on_pushButton_clicked()
{

    tableCaisse->setCurrentRow(-1);
    tableCaisse->setDATE(QDate::currentDate().toString());
    tableCaisse->setidTransaction(candidat);
    tableCaisse->setTYPE(type);
    tableCaisse->setMONTANT(ui->spinBox->value());
    tableCaisse->setuser_type("C");



    close();
}
