#include "addMoniteur.h"
#include "ui_addMoniteur.h"

addMoniteur::addMoniteur(QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::addMoniteur)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout Moniteur");
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(QIcon(":/Assets/Images/icons/add_candidat.svg"));
    ui->dateEdit_naissanceCandidat->setDisplayFormat("yyyy-MM-dd");



}

addMoniteur::~addMoniteur()
{
    delete ui;
}

void addMoniteur::on_pushButton_Valider_clicked()
{
    moniteursTable.setCurrentRow(-1);

    moniteursTable.setNOM                 (ui->lineEdit_nom->text());
    moniteursTable.setPRENOM              (ui->lineEdit_prenom->text());
    moniteursTable.setDATE_DE_NAISSANCE   (ui->dateEdit_naissanceCandidat->text());
    moniteursTable.setADRESSE             (ui->lineEdit_adresseAr->text());
    moniteursTable.setPERMIS               (ui->lineEdit_numPermis->text());
    moniteursTable.setTELEPHONE           (ui->lineEdit_numTelephone->text());
    moniteursTable.setDATE_AJOUT    (QDate::currentDate());

    if(moniteursTable.currentRow() < 0)
        moniteursTable.insert() ;
    else
        moniteursTable.update() ;

    close();
}

void addMoniteur::on_pushButton_Annuler_clicked()
{
    close();
}

bool addMoniteur::verifToutBon()
{
    if ( ui->lineEdit_nom->text().isEmpty() )
    {
        return true;
    }
    else if ( ui->lineEdit_prenom->text().isEmpty() )
    {
        return true;
    }
    else if ( ui->lineEdit_numPermis->text().isEmpty() )
    {
        return true;
    }
    else if ( ui->lineEdit_prenom->text().isEmpty() )
    {
        return true;
    }

}

