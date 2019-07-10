#include "examen.h"

examen::examen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::examen)
{
    ui->setupUi(this);
    setEditable(false);
    ui->pushButton_annuler->hide();
    ui->toolButton_back->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);

}

examen::~examen()
{
    delete ui;
}
