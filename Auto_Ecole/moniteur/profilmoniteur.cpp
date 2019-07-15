#include "profilmoniteur.h"
#include "ui_profilmoniteur.h"

profilMoniteur::profilMoniteur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profilMoniteur)
{
    ui->setupUi(this);
    ui->pushButton_annuler->hide();

    setEditable(false);

    tableMoniteurs = new t_moniteurs();

    tableCaisse = new t_caisse();
    ui->tableView->setModel(tableCaisse->toModel());
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->hideColumn(t_caisse::_00idCaisse);
    ui->tableView->hideColumn(t_caisse::_01idTransaction);
    ui->tableView->hideColumn(t_caisse::_05user_type);

}

profilMoniteur::~profilMoniteur()
{
    delete ui;
}

void profilMoniteur::setValuesOnLineEdit(int index)
{
    tableMoniteurs->whereid(index);

    QString date_string_on_db = tableMoniteurs->getDATE_DE_NAISSANCE();
    QDate Date = QDate::fromString(date_string_on_db,"dd/MM/yyyy");

    ui->lineEdit_nom->setText(tableMoniteurs->getNOM());
    ui->lineEdit_prenom->setText(tableMoniteurs->getPRENOM());
    ui->dateEdit_naissanceCandidat->setDate(Date);

    ui->lineEdit_adresseAr->setText(tableMoniteurs->getADRESSE());
    ui->lineEdit_numCin->setText(tableMoniteurs->getPERMIS());
    ui->lineEdit_numTelephone->setText(tableMoniteurs->getTELEPHONE());


    tableCaisse->where("idTransaction = "+QString::number(tableMoniteurs->getid())+" AND user_type = 'M'" );
    tableCaisse->select();
}

void profilMoniteur::setEditable(bool ok)
{
    ui->lineEdit_nom->setEnabled(ok);
    ui->lineEdit_prenom->setEnabled(ok);
    ui->dateEdit_naissanceCandidat->setEnabled(ok);
    ui->lineEdit_adresseAr->setEnabled(ok);
    ui->lineEdit_numCin->setEnabled(ok);
    ui->lineEdit_numTelephone->setEnabled(ok);
}

void profilMoniteur::modifyOnDatabase()
{
    tableMoniteurs->setNOM                 (ui->lineEdit_nom->text());
    tableMoniteurs->setPRENOM              (ui->lineEdit_prenom->text());
    tableMoniteurs->setDATE_DE_NAISSANCE   (ui->dateEdit_naissanceCandidat->text());
    tableMoniteurs->setADRESSE             (ui->lineEdit_adresseAr->text());
    tableMoniteurs->setPERMIS              (ui->lineEdit_numCin->text());
    tableMoniteurs->setTELEPHONE           (ui->lineEdit_numTelephone->text());

    tableMoniteurs->update() ;

}

void profilMoniteur::changeButtonState(QString title, bool isVisible)
{

    ui->pushButton_modifier->setText(title);
    ui->pushButton_annuler->setVisible(isVisible);

}

void profilMoniteur::on_pushButton_modifier_clicked()
{
    if(ui->pushButton_modifier->text()=="Valider")
    {

        modifyOnDatabase();
        emit ui->pushButton_annuler->clicked(false);



    }
    if(ui->pushButton_modifier->text()=="Modifier")
    {
        setEditable(true);
        changeButtonState("Valider",true);
    }
}

void profilMoniteur::on_pushButton_annuler_clicked()
{
    setEditable(false);
    setValuesOnLineEdit(tableMoniteurs->getid());
    ui->pushButton_annuler->setVisible(false);
    changeButtonState("Modifier",false);
}
