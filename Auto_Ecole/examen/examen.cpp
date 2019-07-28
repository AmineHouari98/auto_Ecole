#include "examen.h"
#include "ui_examen.h"

examen::examen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::examen)
{
    ui->setupUi(this);

    tableExamens = new t_examens();
    tableExamens->select();
    ui->tableView->setModel(tableExamens->toModel());
    ui->widget->setTableView(ui->tableView);
    ui->widget->setModel(tableExamens);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->hideColumn(t_examens::_00idExamen);
    ui->tableView->hideColumn(t_examens::_05idInter);

}


void examen::on_toolButton_new_exam_clicked()
{
    addExam addE;
    addE.exec();
    tableExamens->select();
}

void examen::on_btn_viewDetails_clicked()
{
    if(ui->tableView->currentIndex().row()<0) msgWarning("Erreur","Selectionné un Examen dans le tableau pour voir ses détails");
    else openDetails();
}

void examen::on_tableView_doubleClicked(const QModelIndex &index)
{
    openDetails();
}

void examen::openDetails()
{
    tableExamens->setCurrentRow(ui->tableView->currentIndex().row());
    detailsExam detailE;
    detailE.setValuesOnLineEdit(tableExamens->getid());
    detailE.executeQuery(tableExamens->getid());
    detailE.exec();
    tableExamens->select();

}



examen::~examen()
{
    delete ui;
}
