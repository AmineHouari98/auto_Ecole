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
    if(ui->tableView->currentIndex().row()<0) msgWarning("Erreur","Selectionné un candidat dans le tableau pour voir ses informations");
    else openDetails();
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
    qDebug()<<QString::number(tableCandidats->getid());
    pCandidat.exec();
    tableCandidats->select();

}


void candidat::on_toolButton_clicked()
{
    printAll pa;
    pa.exec();
}

void candidat::on_toolButton_2_clicked()
{
    if(ui->tableView->currentIndex().row()<0) msgWarning("Erreur","Selectionné un candidat dans le tableau pour l'Associer a un Examen");
    else{
        tableCandidats->setCurrentRow(ui->tableView->currentIndex().row());
        Associer as(tableCandidats->getid());
        as.exec();
    }
}
