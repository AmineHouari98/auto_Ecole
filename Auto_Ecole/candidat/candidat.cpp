#include "candidat.h"
#include "ui_candidat.h"

candidat::candidat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::candidat)
{
    ui->setupUi(this);
    candidatsTable = new t_candidats();
    candidatsTable->select();
    ui->tableView->setModel(candidatsTable->toModel());

    ui->widget->setTableView(ui->tableView);
    ui->widget->setModel(candidatsTable);
}



candidat::~candidat()
{
    delete ui;
}


void candidat::on_toolButton_new_client_clicked()
{
    addCandidat addCandidat;
    addCandidat.exec();
    candidatsTable->select();
}
