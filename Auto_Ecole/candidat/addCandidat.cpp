#include "addCandidat.h"
#include "ui_addCandidat.h"

addCandidat::addCandidat(QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::addCandidat)
{
    ui->setupUi(this);
    this->setWindowTitle("ajouter Candidat");

}

addCandidat::~addCandidat()
{
    delete ui;
}

void addCandidat::on_btnAjoutCandidat_accepted()
{
    close();
}

void addCandidat::on_btnAnnulerAjoutCandidat_accepted()
{

}
