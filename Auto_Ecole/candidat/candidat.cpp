#include "candidat.h"
#include "ui_candidat.h"

candidat::candidat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::candidat)
{
    ui->setupUi(this);
    ui->toolButton_back->setVisible(false);
}



candidat::~candidat()
{
    delete ui;
}

void candidat::on_btnNouveaucandidat_clicked()
{
    addCandidat addCandidat;
    addCandidat.exec();
    //candidatTable->select();
}
