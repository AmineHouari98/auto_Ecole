#include "ajouterpaiment.h"
#include "ui_ajouterpaiment.h"

AjouterPaiment::AjouterPaiment(QStringList list,int index,int caisseId,QString user_type,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterPaiment)
{

    ui->setupUi(this);

    myCaisseId=caisseId;
    myIndex=index;
    u_type=user_type;

    ui->comboBox->addItems(list);
    ui->lineEdit->setEnabled(false);
    ui->spinBox->setMaximum(INT_MAX);
    type=ui->comboBox->currentText();


    tableCaisse = new t_caisse;



    if(myCaisseId>-1)
    {
        tableCaisse->whereid(caisseId);

        if(!list.contains(tableCaisse->getTYPE()))
        {
            ui->comboBox->setCurrentIndex(ui->comboBox->findText("Autre",Qt::MatchContains));
            ui->lineEdit->setEnabled(true);
            ui->lineEdit->setText(tableCaisse->getTYPE());
        }
        else ui->comboBox->setCurrentIndex(ui->comboBox->findText(tableCaisse->getTYPE(),Qt::MatchContains));

        ui->spinBox->setValue(tableCaisse->getMONTANT().toInt());

    }
    else tableCaisse->setCurrentRow(-1);
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

    }
    else
    {
        ui->lineEdit->setEnabled(false);

    }
    type=arg1;

}

void AjouterPaiment::on_pushButton_2_clicked()
{
    close();
}

void AjouterPaiment::on_pushButton_clicked()
{

    tableCaisse->setDATE(QDate::currentDate());
    tableCaisse->setidTransaction(myIndex);
    if(type=="Autre")
        tableCaisse->setTYPE(ui->lineEdit->text());
    else
        tableCaisse->setTYPE(type);
    tableCaisse->setMONTANT(QString::number(ui->spinBox->value()));
    tableCaisse->setuser_type(u_type);

    if(myCaisseId>-1)tableCaisse->update();
    else tableCaisse->insert();

    close();
}
