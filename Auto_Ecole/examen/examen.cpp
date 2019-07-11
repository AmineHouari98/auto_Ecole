#include "examen.h"
#include "ui_examen.h"

examen::examen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::examen)
{
    ui->setupUi(this);
    //    setEditable(false);
    //    ui->pushButton_annuler->hide();
    //    ui->toolButton_back->setVisible(false);
    //    ui->stackedWidget->setCurrentIndex(0);


    //    setEditable(false);
    //    ui->pushButton_annuler->hide();
    //    ui->toolButton_back->setVisible(false);

    //    ui->stackedWidget->setCurrentIndex(0);

    //    tableMoniteurs = new t_moniteurs();
    //    tableMoniteurs->select();
    //    ui->tableView->setModel(tableMoniteurs->toModel());
    //    ui->widget->setTableView(ui->tableView);
    //    ui->widget->setModel(tableMoniteurs);
    //    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //    ui->tableView->hideColumn(t_candidats::_00idCandidat);
    //    ui->tableView->hideColumn(t_candidats::_12idDocuments);



    //    tableCaisse = new t_caisse();
    //    caisseTable = new QSqlTableModel(this);
    //    caisseTable->setTable(tableCaisse->tableName());
    //    ui->tableView_2->setModel(caisseTable);
    //    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //    ui->tableView_2->hideColumn(t_caisse::_00idCaisse);
    //    ui->tableView_2->hideColumn(t_caisse::_01idTransaction);


}


void examen::on_toolButton_new_client_clicked()
{
    //    addMoniteur addM;
    //    addM.exec();
    //    tableMoniteurs->select();
}

void examen::on_btn_viewProfile_clicked()
{
    //    setValuesOnLineEdit(ui->tableView->currentIndex().row());
    //    ui->stackedWidget->setCurrentIndex(1);
}

void examen::on_stackedWidget_currentChanged(int arg1)
{
    if (arg1 == 0 ) {
        ui->toolButton_new_client->setVisible(true);
        ui->btn_viewProfile->setVisible(true);
        ui->toolButton_back->setVisible(false);
    }

    else {
        ui->toolButton_new_client->setVisible(false);
        ui->btn_viewProfile->setVisible(false);
        ui->toolButton_back->setVisible(true);

    }



}

void examen::on_toolButton_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void examen::on_tableView_doubleClicked(const QModelIndex &index)
{
    setValuesOnLineEdit(index.row());
    ui->stackedWidget->setCurrentIndex(1);
}

void examen::setValuesOnLineEdit(int index)
{
    //    tableMoniteurs->setCurrentRow(index);

    //    QString date_string_on_db = tableMoniteurs->getDATE_DE_NAISSANCE();
    //    QDate Date = QDate::fromString(date_string_on_db,"dd/MM/yyyy");

    //    ui->lineEdit_nom->setText(tableMoniteurs->getNOM());
    //    ui->lineEdit_prenom->setText(tableMoniteurs->getPRENOM());
    //    ui->dateEdit_naissanceCandidat->setDate(Date);

    //    ui->lineEdit_adresseAr->setText(tableMoniteurs->getADRESSE());
    //    ui->lineEdit_numCin->setText(tableMoniteurs->getPERMIS());
    //    ui->lineEdit_numTelephone->setText(tableMoniteurs->getTELEPHONE());

    //    caisseTable->setFilter("idTransaction = "+QString::number(tableMoniteurs->getidMoniteur()));
    //    caisseTable->select();

}

void examen::setEditable(bool ok)
{
    //    ui->lineEdit_nom->setEnabled(ok);
    //    ui->lineEdit_prenom->setEnabled(ok);
    //    ui->dateEdit_naissanceCandidat->setEnabled(ok);
    //    ui->lineEdit_adresseAr->setEnabled(ok);
    //    ui->lineEdit_numCin->setEnabled(ok);
    //    ui->lineEdit_numTelephone->setEnabled(ok);
}

void examen::modifyOnDatabase()
{
    //    tableMoniteurs->setNOM                 (ui->lineEdit_nom->text());
    //    tableMoniteurs->setPRENOM              (ui->lineEdit_prenom->text());
    //    tableMoniteurs->setDATE_DE_NAISSANCE   (ui->dateEdit_naissanceCandidat->text());
    //    tableMoniteurs->setADRESSE             (ui->lineEdit_adresseAr->text());
    //    tableMoniteurs->setPERMIS              (ui->lineEdit_numCin->text());
    //    tableMoniteurs->setTELEPHONE           (ui->lineEdit_numTelephone->text());

    //    tableMoniteurs->update() ;

}

void examen::changeButtonState(QString title, bool isVisible)
{

    //    ui->pushButton_modifier->setText(title);
    //    ui->pushButton_annuler->setVisible(isVisible);

}

void examen::on_pushButton_modifier_clicked()
{
    //    if(ui->pushButton_modifier->text()=="Valider")
    //    {

    //        modifyOnDatabase();
    //        changeButtonState("Modifier",false);



    //    }
    //    if(ui->pushButton_modifier->text()=="Modifier")
    //    {
    //        setEditable(true);
    //        changeButtonState("Valider",true);
    //    }
}


void examen::initTableWidget()
{
    QStringList header ={"DOSSIER","NOM","PRENOM","DDN","NATURE","RESULTAT","RETIRER"};
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(header);

}

examen::~examen()
{
    delete ui;
}
