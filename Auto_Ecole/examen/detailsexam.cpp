#include "detailsexam.h"
#include "ui_detailsexam.h"
#include <QSqlQuery>

detailsExam::detailsExam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailsExam)
{
    ui->setupUi(this);
    ui->pushButton_annuler->hide();

    setEditable(false);

    tableExamens = new t_examens();
    tableInter = new t_inter();

    QStringList labels ={"NOM","PRENOM","DATE DE NAISSANCE","LIEU DE NAISSANCE","Supprimer"};


    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

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



    QSqlQuery query;
    query.exec("SELECT NOM, PRENOM, DATE_DE_NAISSANCE, LIEU_DE_NAISSANCE "
               "FROM t_candidats INNER JOIN t_inter "
               "ON t_candidats.id =t_inter.idCandidat"
               " WHERE t_inter.idExamen = "+ QString::number(index));

    int recordsNumber =0;
    while (query.next()) {
        QString NOM = query.value(0).toString();
        QString PRENOM = query.value(1).toString();
        QString DATE_DE_NAISSANCE = query.value(2).toString();
        QString LIEU_DE_NAISSANCE = query.value(3).toString();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        ui->tableWidget->setItem(recordsNumber, 0, new QTableWidgetItem(NOM));
        ui->tableWidget->setItem(recordsNumber, 1, new QTableWidgetItem(PRENOM));
        ui->tableWidget->setItem(recordsNumber, 2, new QTableWidgetItem(DATE_DE_NAISSANCE));
        ui->tableWidget->setItem(recordsNumber, 3, new QTableWidgetItem(LIEU_DE_NAISSANCE));

        recordsNumber++;

    }





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
        emit ui->pushButton_annuler->clicked(false);



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
