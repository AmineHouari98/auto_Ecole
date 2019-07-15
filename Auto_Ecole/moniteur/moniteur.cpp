#include "moniteur.h"
#include "ui_moniteur.h"

moniteur::moniteur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::moniteur)
{
    ui->setupUi(this);



    tableMoniteurs = new t_moniteurs();
    tableMoniteurs->select();
    ui->tableView->setModel(tableMoniteurs->toModel());
    ui->widget->setTableView(ui->tableView);
    ui->widget->setModel(tableMoniteurs);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableView->hideColumn(t_candidats::_12idDocuments);
//    ui->tableView->hideColumn(t_candidats::_00idCandidat);



}



moniteur::~moniteur()
{
    delete ui;
}

void moniteur::on_toolButton_new_client_clicked()
{
    addMoniteur addM;
    addM.exec();
    tableMoniteurs->select();
}

void moniteur::on_btn_viewProfile_clicked()
{    


}

void moniteur::on_tableView_doubleClicked(const QModelIndex &index)
{
    openDetails();
}

void moniteur::openDetails()
{
    tableMoniteurs->setCurrentRow(ui->tableView->currentIndex().row());
    profilMoniteur pMoniteur;
    pMoniteur.setValuesOnLineEdit(tableMoniteurs->getid());
    pMoniteur.exec();
    tableMoniteurs->select();

}
