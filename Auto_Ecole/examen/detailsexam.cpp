#include "detailsexam.h"
#include "ui_detailsexam.h"

detailsExam::detailsExam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailsExam)
{
    ui->setupUi(this);
    ui->pushButton_annuler->hide();

    setEditable(false);

    tableExamens = new t_examens();

    tableCaisse = new t_caisse();
    ui->tableView->setModel(tableCaisse->toModel());
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->hideColumn(t_caisse::_00idCaisse);
    ui->tableView->hideColumn(t_caisse::_01idTransaction);
    ui->tableView->hideColumn(t_caisse::_05user_type);
}

detailsExam::~detailsExam()
{
    delete ui;
}



void detailsExam::setValuesOnLineEdit(int index)
{
    tableExamens->whereid(index);

    QString date_string_on_db = tableExamens->getDATE();
    QDate Date = QDate::fromString(date_string_on_db,"dd/MM/yyyy");

    ui->lineEdit_nomExaminateur->setText(tableExamens->getEXAMINATEUR());
    ui->lineEdit_Lieu->setText(tableExamens->getLIEU());
    ui->dateEdit_Date->setDate(Date);

}

void detailsExam::setEditable(bool ok)
{
    ui->lineEdit_nomExaminateur->setEnabled(ok);
    ui->lineEdit_Lieu->setEnabled(ok);
    ui->dateEdit_Date->setEnabled(ok);

}

void detailsExam::modifyOnDatabase()
{
    tableExamens->setEXAMINATEUR   (ui->lineEdit_nomExaminateur->text());
    tableExamens->setLIEU          (ui->lineEdit_Lieu->text());
    tableExamens->setDATE          (ui->dateEdit_Date->text());


    tableExamens->update() ;

}

void detailsExam::changeButtonState(QString title, bool isVisible)
{

    ui->pushButton_modifier->setText(title);
    ui->pushButton_annuler->setVisible(isVisible);

}

void detailsExam::on_pushButton_modifier_clicked()
{
    if(ui->pushButton_modifier->text()=="Valider")
    {

        modifyOnDatabase();
        changeButtonState("Modifier",false);



    }
    if(ui->pushButton_modifier->text()=="Modifier")
    {
        setEditable(true);
        changeButtonState("Valider",true);
    }
}

void detailsExam::on_pushButton_annuler_clicked()
{
    setEditable(false);
    setValuesOnLineEdit(tableExamens->getid());
    ui->pushButton_annuler->setVisible(false);
    changeButtonState("Modifier",false);
}
