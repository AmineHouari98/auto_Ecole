#include "impression.h"
#include "mydatabase.h"
#include "qtrpt.h"

impression::impression(QWidget *parent) : QWidget(parent)
{


}

void impression::printListExamen(QList<ModelExamList> myList,QString date,int Cand,int code,int man ,int circ)
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
               << myList.at(i).cat;


    }



    connect(report, &QtRPT::setValue, [&](int recNo,
            QString paramName, QVariant &paramValue, const int reportPage){

        if(paramName == "NOMAUTO")           paramValue = a->getNOM() ;
        if(paramName == "ADRESSEAUTO")       paramValue = a->getADRESSE();
        if(paramName == "NUMTELAUTO")        paramValue = a->getTELEPHONE();
        if(paramName == "NUM")               paramValue = QString::number(recNo+1);
        if(paramName == "NUMDOSSIER") {
            paramValue = myList.at(recNo).NumDossier;
        }
        if(paramName == "PRENOM") {
            paramValue = myList.at(recNo).Prenom;
        }
        if(paramName == "NOM")            {
            if(QString(myList.at(recNo).Nom).length()>=8)paramValue = myList.at(recNo).Nom+"\n";
            else paramValue = myList.at(recNo).Nom;

        }
        if(paramName == "DATENAISSANCE") {
            paramValue = myList.at(recNo).Date_De_Naissance;
        }
        if(paramName == "NATEXAMEN") {
            paramValue = myList.at(recNo).NatExamen;
        }
        if(paramName == "CAT") {
            paramValue = myList.at(recNo).cat;
        }
        if(paramName == "CANDIDATS") {
            paramValue = QString::number(Cand);
        }
        if(paramName == "CODE") {
            paramValue = QString::number(code);
        }
        if(paramName == "CIRC") {
            paramValue = QString::number(circ);
        }
        if(paramName == "CMAN") {
            paramValue = QString::number(man);
        }
        if(paramName == "CDATE") {
            paramValue = date;
        }



    });

    report->printExec();

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
