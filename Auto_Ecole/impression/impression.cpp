#include "impression.h"
#include "mydatabase.h"
#include "qtrpt.h"

impression::impression(QWidget *parent) : QWidget(parent) , ui(new Ui::impression)
{
    ui->setupUi(this);

}

void impression::printListExamen(QList<ModelExamList> myList,QString date)
{
    t_autoEcole *a = new t_autoEcole;
    int rows = myList.length();
    QtRPT *report = new QtRPT(this) ;
    report->loadReport(":/Templates/Liste_Examen.xml");
    report->recordCount.append(rows);

    for(int i= 0;i<myList.length();i++)
    {
        qDebug()<< myList.at(i).NumDossier
               << myList.at(i).Prenom
               << myList.at(i).Nom
               << myList.at(i).Date_De_Naissance
               << myList.at(i).NatExamen
               << myList.at(i).cat
               << QString::number(myList.at(i).NbrCandidats)
               << QString::number(myList.at(i).NbrCode)
               << QString::number(myList.at(i).NbrCirc)
               << QString::number(myList.at(i).NbrM);


    }

    connect(report, &QtRPT::setValue, [&](int recNo,
            QString paramName, QVariant &paramValue, const int reportPage){

        if(paramName == "NomAuto")           paramValue = a->getNOM() ;
        if(paramName == "AdresseAuto")       paramValue = a->getADRESSE();
        if(paramName == "NumTelAuto")        paramValue = a->getTELEPHONE();
        if(paramName == "WilayaAuto")        paramValue = "Oran";
        if(paramName == "Num")               paramValue = QString::number(recNo+1);
        if(paramName == "NumDossier") {
            if (ui->tableWidget->item(recNo,ModelExamList::_09NumDossier) == 0) return;
            paramValue = myList.at(recNo).NumDossier;
        }
        if(paramName == "Prenom") {
            if (ui->tableWidget->item(recNo,ModelExamList::_01Prenom) == 0) return;
            paramValue = myList.at(recNo).Prenom;
        }
        if(paramName == "Nom")            {
            if (ui->tableWidget->item(recNo,ModelExamList::_00Nom) == 0) return;
            if(QString(myList.at(recNo).Nom).length()>=8)paramValue = myList.at(recNo).Nom+"\n";
            else paramValue = myList.at(recNo).Nom;

        }
        if(paramName == "Date_De_Naissance") {
            if (ui->tableWidget->item(recNo,ModelExamList::_04Date_De_Naissance) == 0) return;
            paramValue = myList.at(recNo).Date_De_Naissance;
        }
        if(paramName == "NatExamen") {
            if (ui->tableWidget->item(recNo,ModelExamList::_02NatExamen) == 0) return;
            paramValue = myList.at(recNo).NatExamen;
        }
        if(paramName == "cat") {
            if (ui->tableWidget->item(recNo,ModelExamList::_03cat) == 0) return;
            paramValue = myList.at(recNo).cat;
        }
        if(paramName == "NbrCandidats") {
            if (ui->tableWidget->item(recNo,ModelExamList::_05NbrCandidats) == 0) return;
            paramValue = QString::number(myList.at(recNo).NbrCandidats);
        }
        if(paramName == "NbrCode") {
            if (ui->tableWidget->item(recNo,ModelExamList::_06NbrCode) == 0) return;
            paramValue = QString::number(myList.at(recNo).NbrCode);
        }
        if(paramName == "NbrCirc") {
            if (ui->tableWidget->item(recNo,ModelExamList::_08NbrCirc) == 0) return;
            paramValue = QString::number(myList.at(recNo).NbrCirc);
        }
        if(paramName == "NbrM") {
            if (ui->tableWidget->item(recNo,ModelExamList::_07NbrM) == 0) return;
            paramValue = QString::number(myList.at(recNo).NbrM);
        }
        if(paramName == "DateExamen") {
            paramValue = date;
        }



    });

    report->printExec();

}

impression::~impression()
{
    delete ui;
}

void impression::printBorderau(QList<ModelBordereau> myList)
{

}
//DONT TOUCH THIS CODE


//t_candidats *cad = new t_candidats;
//t_autoEcole *a = new t_autoEcole;
//int rows = cad->rowCount();
//QtRPT *report = new QtRPT(this) ;
//report->loadReport(":/Templates/Liste_Examen.xml");
//report->recordCount.append(rows);
//connect(report, &QtRPT::setValue, [&](int recNo,
//        QString paramName, QVariant &paramValue, const int reportPage){

//    if(paramName == "NomAuto")           paramValue = a->getNom() ;
//    if(paramName == "AdresseAuto")       paramValue = a->getAdresse();
//    if(paramName == "NumTelAuto")        paramValue = a->getNumTel();
//    if(paramName == "WilayaAuto")        paramValue = "Oran";
//    if(paramName == "Num")               paramValue = QString::number(recNo+1);
//    if(paramName == "Prenom")               {cad->setCurrentRow(recNo);paramValue = cad->getPrenom();}
//    if(paramName == "Nom")            {
//        cad->setCurrentRow(recNo);
//        if(cad->getNom().length()>=8)paramValue = cad->getNom()+"\n";
//        else paramValue = cad->getNom();

//    }
//    if(paramName == "Date_De_Naissance") {cad->setCurrentRow(recNo);paramValue = cad->getDate_De_Naissance();}
//    if(paramName == "Observations")      {cad->setCurrentRow(recNo);paramValue = "";}
//    if(paramName == "NbrCandidats")      paramValue = QString::number(rows);

//});

//report->printExec();
