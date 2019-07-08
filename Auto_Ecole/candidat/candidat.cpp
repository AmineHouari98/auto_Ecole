#include "candidat.h"
#include "ui_candidat.h"

candidat::candidat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::candidat)
{
    ui->setupUi(this);
    ui->toolButton_back->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
    candidatsTable = new t_candidats();
    candidatsTable->select();
    ui->tableView->setModel(candidatsTable->toModel());
    ui->widget->setTableView(ui->tableView);
    ui->widget->setModel(candidatsTable);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->hideColumn(t_candidats::_00idCandidat);
    ui->tableView->hideColumn(t_candidats::_12idDocuments);

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



void candidat::on_btn_viewProfile_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void candidat::on_stackedWidget_currentChanged(int arg1)
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

void candidat::on_toolButton_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
