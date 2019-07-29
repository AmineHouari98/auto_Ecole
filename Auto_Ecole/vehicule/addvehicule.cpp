#include "addvehicule.h"
#include "ui_addVehicule.h"

addVehicule::addVehicule(QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::addVehicule)
{

    ui->setupUi(this);
    setUpLineEdits();
    this->setWindowTitle("Ajout Vehicule");
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(QIcon(":/Assets/Images/icons/add.svg"));

}

void addVehicule::setUpLineEdits()
{
    // tbaya3 of textfields
    /*ui->lineEdit_numTelephone->setText("");
    ui->lineEdit_numTelephone->setInputMask("09 99 99 99 99");


    ui->spinBox_ins->setRange(10000,50000);
    ui->spinBox_PrE->setRange(0,4500);

    ui->lineEdit_numCin->setMaxLength(9);
    ui->lineEdit_numDossier->setMaxLength(7);*/
}


void addVehicule::on_pushButton_Valider_clicked()
{
    /*if(checkIntegrity(lineList)<lineList.length())
    {
        msgWarning("Attention",champVide);
    }
    else
    {
        candidatsTable.setCurrentRow(-1);
        QString wilaya=ui->comboBox_wilaya->itemText(ui->comboBox_wilaya->currentIndex());

        QStringList selectedWilaya =wilaya.split("-");
        qDebug()<<selectedWilaya.at(0)+"    "+selectedWilaya.at(1);


        candidatsTable.setNOM                 (ui->lineEdit_nom->text());
        candidatsTable.setPRENOM              (ui->lineEdit_prenom->text());
        candidatsTable.setNOM_ARABE           (ui->lineEdit_nomAr->text());
        candidatsTable.setPRENOM_ARABE        (ui->lineEdit_prenomAr->text());
        candidatsTable.setDATE_DE_NAISSANCE   (ui->dateEdit_naissanceCandidat->text());
        candidatsTable.setLIEU_DE_NAISSANCE   (selectedWilaya.at(1));
        candidatsTable.setADRESSE             (ui->lineEdit_adresseAr->text());
        candidatsTable.setCIN                 (ui->lineEdit_numCin->text());
        candidatsTable.setTELEPHONE           (ui->lineEdit_numTelephone->text());
        candidatsTable.setNATIONALITE         (ui->lineEdit_nationnalite->text());
        candidatsTable.setDOSSIER             (ui->lineEdit_numDossier->text());
        candidatsTable.setDATE_INSCRIPTION    (QDate::currentDate().toString("dd/MM/yyyy"));



        documentsTable->setCurrentRow(-1);

        documentsTable->setAutorisation_Paternel(ui->checkBox_APaternel->checkState());
        documentsTable->setCIN(ui->checkBox_CIN->checkState());
        documentsTable->setGroupage(ui->checkBox_Groupage->checkState());
        documentsTable->setPhoto(ui->checkBox_Photo->checkState());
        documentsTable->setResidance(ui->checkBox_Residence->checkState());
        documentsTable->setTimbre(ui->checkBox_Timbre->checkState());


        candidatsTable.insert() ;
        documentsTable->insert();

        close();
    }*/

}

void addVehicule::on_pushButton_Annuler_clicked()
{
    //close();
}

void addVehicule::on_pushButton_clicked()
{
   /* if(ui->pushButton->text()=="Tout Cocher")
    {
        checkAll(true);
    }
    else if (ui->pushButton->text()=="Tout Décocher")
    {
        checkAll(false);
    }*/

}

void addVehicule::checkAll(bool ok)
{
    /*ui->checkBox_APaternel->setChecked(ok);
    ui->checkBox_CIN->setChecked(ok);
    ui->checkBox_Groupage->setChecked(ok);
    ui->checkBox_Photo->setChecked(ok);
    ui->checkBox_Residence->setChecked(ok);
    ui->checkBox_Timbre->setChecked(ok);*/

}
