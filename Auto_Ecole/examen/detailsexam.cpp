#include "detailsexam.h"
#include "ui_detailsexam.h"

detailsExam::detailsExam(int index,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailsExam)
{
    ui->setupUi(this);
    this->setWindowTitle("Détail de l'examen");
    this->setWindowIcon(QIcon(":/Assets/Images/icons/details.ico"));
    ui->pushButton_annuler->hide();
    ui->dateEdit_Date->setDisplayFormat("yyyy-MM-dd");

    idExam=index;
    setEditable(false);

    tableExamens = new t_examens();
    tableInter = new t_inter();

    QStringList labels ={"id","DOSSIER","NOM","PRENOM","DATE DE NAISSANCE","NATURE EXAMEN","Supprimer"};


    ui->tableWidget->setColumnCount(labels.length());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->hideColumn(0);

    setValuesOnLineEdit();
    executeQuery();
}

detailsExam::~detailsExam()
{
    delete ui;
}

void detailsExam::setValuesOnLineEdit()
{
    tableExamens->whereid(idExam);


    ui->lineEdit_nomExaminateur->setText(tableExamens->getEXAMINATEUR());
    ui->lineEdit_Lieu->setText(tableExamens->getLIEU());
    ui->dateEdit_Date->setDate(tableExamens->getDATE());
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
    tableExamens->setDATE          (ui->dateEdit_Date->date());


    tableExamens->update() ;

}

void detailsExam::changeButtonState(QString title, bool isVisible)
{

    ui->pushButton_modifier->setText(title);
    ui->pushButton_annuler->setVisible(isVisible);

}

void detailsExam::executeQuery()
{

    ui->tableWidget->setRowCount(0);//delete all rows
    QSqlQuery query;
    query.exec("SELECT t_candidats.id, DOSSIER, NOM, PRENOM, DATE_DE_NAISSANCE, PROCHAIN_EXAMEN "
               "FROM t_candidats INNER JOIN t_inter "
               "ON t_candidats.id =t_inter.idCandidat"
               " WHERE t_inter.idExamen = "+ QString::number(idExam));

    int recordsNumber =0;

    while (query.next()) {

        Form *pWidget=new Form;

        QString id =  query.value(0).toString();
        QString DOSSIER = query.value(1).toString();
        QString NOM = query.value(2).toString();
        QString PRENOM = query.value(3).toString();
        QString DATE_DE_NAISSANCE = query.value(4).toString();
        QString NATURE_EXAMEN = query.value(5).toString();

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

void detailsExam::on_pushButton_modifier_clicked()
{
    if(ui->pushButton_modifier->text()=="Valider")
    {
        modifyOnDatabase();
        emit ui->pushButton_annuler->clicked(false);

    }
    else if(ui->pushButton_modifier->text()=="Modifier")
    {
        setEditable(true);
        changeButtonState("Valider",true);

    }
}

void detailsExam::on_pushButton_annuler_clicked()
{
    setEditable(false);
    setValuesOnLineEdit();

    ui->pushButton_annuler->setVisible(false);
    changeButtonState("Modifier",false);
}

void detailsExam::on_toolButton_ImprimerListe_clicked()
{
    QList<ModelExamList> myList;

    int NbrCode = 0, NbrM = 0, NbrCirc = 0;
    int rowCount =ui->tableWidget->rowCount();
    for(int i=0;i<rowCount;i++) {

        ModelExamList model;
        model.NumDossier =          ui->tableWidget->item(i,1)->text();
        model.Nom =                 ui->tableWidget->item(i,2)->text();
        model.Prenom =              ui->tableWidget->item(i,3)->text();
        model.Date_De_Naissance =   ui->tableWidget->item(i,4)->text();
        model.NatExamen =           ui->tableWidget->item(i,5)->text();
        model.cat = "B";

        if(model.NatExamen == "Code") NbrCode++;
        else if(model.NatExamen == "Circulation") NbrCirc++;
        else if(model.NatExamen == "Manoeuvre") NbrM++;

        myList.append(model);

    }
    printer.printListExamen(myList,tableExamens->getDATE(),rowCount,NbrCode,NbrM,NbrCirc);

}

void detailsExam::on_toolButton_Ajouter_clicked()
{
    AddInExam ad(idExam);
    ad.exec();
    executeQuery();

}

void detailsExam::on_toolButton_Supp_clicked()
{

    if(!msgQuestion("Attention!","êtes-vous sûr de vouloir supprimer ?"))
        return ;

    QString tmp="";
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {

        myForm=(Form*)ui->tableWidget->cellWidget(i,6);
        if(myForm->getState())
        {
            tmp=ui->tableWidget->item(i,0)->text();

            tableInter->where("idCandidat = "+tmp+" AND "+ QString::number(idExam));
            tableInter->removeCurrentRow();
            ui->tableWidget->removeRow(i);


        }


    }

}
