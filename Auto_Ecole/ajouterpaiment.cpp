#include "ajouterpaiment.h"
#include "ui_ajouterpaiment.h"

AjouterPaiment::AjouterPaiment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterPaiment)
{

    ui->setupUi(this);
    ui->comboBox->addItems(myList);
    ui->lineEdit->setEnabled(false);
    ui->spinBox->setMaximum(INT_MAX);
    type=ui->comboBox->currentText();
    tableCaisse = new t_caisse;
}

AjouterPaiment::~AjouterPaiment()
{

    delete ui;
}

void AjouterPaiment::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Autre")
    {
        ui->lineEdit->setEnabled(true);
        type=ui->lineEdit->text();

    }
    else
    {
        ui->lineEdit->setEnabled(false);
        type=arg1;

    }
}

void AjouterPaiment::on_pushButton_2_clicked()
{
    close();
}

void AjouterPaiment::on_pushButton_clicked()
{

    tableCaisse->setCurrentRow(-1);
    tableCaisse->setDATE(QDate::currentDate().toString());
    tableCaisse->setidTransaction(index);
    tableCaisse->setTYPE(type);
    tableCaisse->setMONTANT(QString::number(ui->spinBox->value()));
    tableCaisse->setuser_type("C");
    tableCaisse->insert();

    close();
}
