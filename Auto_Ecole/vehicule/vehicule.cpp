#include "vehicule.h"
#include "ui_vehicule.h"

vehicule::vehicule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vehicule)
{
     ui->setupUi(this);
}


vehicule::~vehicule()
{
    delete ui;
}

void vehicule::on_toolButton_newVehicule_clicked()
{
    /*addCandidat addCandidat;
    addCandidat.exec();
    tableCandidats->select();*/
}

void vehicule::on_btn_viewVehicule_clicked()
{
    /*if(tableCandidats->getid()== 0) msgWarning("Erreur","Selectionné un candidat dans le tableau pour voir ses informations");
    else openDetails();*/
}

void vehicule::on_tableView_doubleClicked(const QModelIndex &index)
{
   //openDetails();
}



void vehicule::openDetails()
{
    /*tableCandidats->setCurrentRow(ui->tableView->currentIndex().row());
    profilCandidat pCandidat;
    pCandidat.setValuesOnLineEdit(tableCandidats->getid());
    qDebug()<<QString::number(tableCandidats->getid());
    pCandidat.exec();
    tableCandidats->select();*/

}
