#include "selector.h"
#include "ui_selector.h"

Selector::Selector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selector)
{
    ui->setupUi(this);
}

Selector::~Selector()
{
    delete ui;
}
