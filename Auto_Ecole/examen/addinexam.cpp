#include "addinexam.h"
#include "ui_addinexam.h"

AddInExam::AddInExam(int index,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInExam)
{
    ui->setupUi(this);

    idExam=index;

    tableInter = new t_inter();
    tableCandidats = new t_candidats;

    QStringList labels ={"id","DOSSIER","NOM","PRENOM","DATE DE NAISSANCE","NATURE EXAMEN","Supprimer"};

    tableInter->where("idExamen = "+QString::number(idExam));

    tableCandidats->where("id not in(select idCandidat from t_inter)");



    ui->tableWidget->setColumnCount(labels.length());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    //ui->tableWidget->hideColumn(0);



    int recordsNumber =0;


    for (int i=0;i<tableCandidats->rowCount();i++) {


        tableCandidats->setCurrentRow(i);

        Form *pWidget=new Form;

        QString id =                QString::number(tableCandidats->getid());
        QString DOSSIER =           tableCandidats->getDOSSIER();
        QString NOM =               tableCandidats->getNOM();
        QString PRENOM =            tableCandidats->getPRENOM();
        QString DATE_DE_NAISSANCE = tableCandidats->getDATE_DE_NAISSANCE().toString();
        QString NATURE_EXAMEN =     tableCandidats->getPROCHAIN_EXAMEN();

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        ui->tableWidget->setItem(recordsNumber, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(recordsNumber, 1, new QTableWidgetItem(DOSSIER));
        ui->tableWidget->setItem(recordsNumber, 2, new QTableWidgetItem(NOM));
        ui->tableWidget->setItem(recordsNumber, 3, new QTableWidgetItem(PRENOM));
        ui->tableWidget->setItem(recordsNumber, 4, new QTableWidgetItem(DATE_DE_NAISSANCE));
        ui->tableWidget->setItem(recordsNumber, 5, new QTableWidgetItem(NATURE_EXAMEN));
        ui->tableWidget->setCellWidget(recordsNumber, 6, pWidget);


        qDebug()<<DOSSIER<<NOM<<PRENOM<<DATE_DE_NAISSANCE<<NATURE_EXAMEN;

        recordsNumber++;


    }
}



AddInExam::~AddInExam()
{
    delete ui;
}

void AddInExam::on_pushButton_valider_clicked()
{
    QString tmp="";
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {

        myForm=(Form*)ui->tableWidget->cellWidget(i,6);
        if(myForm->getState())
        {
            tmp=ui->tableWidget->item(i,0)->text();
            qDebug()<<tmp;
            tableInter->setCurrentRow(-1);

            tableInter->setidCandidat(tmp.toInt());
            tableInter->setidExamen(idExam);

            tableInter->insert();



        }


    }

    close();

}

void AddInExam::on_pushButton_annuler_clicked()
{
    close();

}
