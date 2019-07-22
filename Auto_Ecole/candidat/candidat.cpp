#include "candidat.h"
#include "ui_candidat.h"

candidat::candidat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::candidat)
{
    ui->setupUi(this);


    tableCandidats = new t_candidats();
    tableCandidats->select();
    ui->tableView->setModel(tableCandidats->toModel());
    ui->widget->setTableView(ui->tableView);
    ui->widget->setModel(tableCandidats);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
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
    tableCandidats->select();
}

void candidat::on_btn_viewProfile_clicked()
{
    // essaye de faire un truc du genre le bouton devient cliquable que quand quelqu'un est selectionné dans la table en bas
    openDetails();
}

void candidat::on_tableView_doubleClicked(const QModelIndex &index)
{
    openDetails();
}

void candidat::openDetails()
{
    tableCandidats->setCurrentRow(ui->tableView->currentIndex().row());
    profilCandidat pCandidat;
    pCandidat.setValuesOnLineEdit(tableCandidats->getid());
    pCandidat.exec();
    tableCandidats->select();

}

