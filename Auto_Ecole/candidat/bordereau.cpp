#include "bordereau.h"
#include "ui_bordereau.h"

Bordereau::Bordereau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bordereau)
{
    ui->setupUi(this);
}

Bordereau::~Bordereau()
{
    delete ui;
}
