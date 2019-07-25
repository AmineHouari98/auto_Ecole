#include "impression.h"
#include "qtrpt.h"

impression::impression(QWidget *parent) : QWidget(parent)
{

    cad = new t_candidats;
    a = new t_autoEcole;


}

void impression::printListExamen(QList<ModelExamList> myList,QString date,int Cand,int code,int man ,int circ)
{
    int rows = myList.length();
    QtRPT *report = new QtRPT(this) ;
    report->loadReport(":/Templates/Liste_Examen.xml");
    report->recordCount.append(rows);

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



void impression::printAllCandidat(QString date1,QString date2)
{
    cad->where(" DATE_INSCRIPTION BETWEEN '"+date1+"' AND '"+date2+"';");
    int rows = cad->rowCount();
    QtRPT *report = new QtRPT(this) ;
    report->loadReport(":/Templates/All_Candidat.xml");
    report->recordCount.append(rows);

    connect(report, &QtRPT::setValue, [&](int recNo,
            QString paramName, QVariant &paramValue, const int reportPage){

        if(paramName == "DATE1") {paramValue = date1;}
        if(paramName == "DATE2") {paramValue = date2;}
        if(paramName == "DATE3") {paramValue = QDate::currentDate().toString("dd/MM/yyyy") ;}


        if(paramName == "DOSSIER") {cad->setCurrentRow(recNo);paramValue = cad->getDOSSIER();}
        if(paramName == "PRENOM")  {cad->setCurrentRow(recNo);paramValue = cad->getPRENOM();}
        if(paramName == "NOM"){
            cad->setCurrentRow(recNo);
            if(QString(cad->getNOM()).length()>=7)paramValue = cad->getNOM()+"\n";
            else paramValue = cad->getNOM();

        }
        if(paramName == "NOM_ARABE")
        {
            cad->setCurrentRow(recNo);
            if(QString(cad->getNOM_ARABE()).length()>=7)paramValue = cad->getNOM_ARABE()+"\n";
            else paramValue = cad->getNOM_ARABE();

        }
        if(paramName == "PRENOM_ARABE") {cad->setCurrentRow(recNo);paramValue = cad->getPRENOM_ARABE();}
        if(paramName == "DATE")         {cad->setCurrentRow(recNo);paramValue = cad->getDATE_DE_NAISSANCE();}
        if(paramName == "LIEU")         {cad->setCurrentRow(recNo);paramValue = cad->getLIEU_DE_NAISSANCE();}
        if(paramName == "NATIONALITE")  {cad->setCurrentRow(recNo);paramValue = cad->getNATIONALITE();}
        if(paramName == "CIN")          {cad->setCurrentRow(recNo);paramValue = cad->getCIN();}
        if(paramName == "TELEPHONE")    {cad->setCurrentRow(recNo);paramValue = cad->getTELEPHONE();}
        if(paramName == "PROCHAIN_EXAMEN") {cad->setCurrentRow(recNo);paramValue = cad->getDATE_INSCRIPTION();}
        if(paramName == "DATE_INSCRIPTION") {cad->setCurrentRow(recNo);paramValue = cad->getPROCHAIN_EXAMEN();}
        if(paramName == "WILAYA") {paramValue = "Oran";}



    });

    report->printExec();

}

void impression::printBorderau(QList<ModelBordereau> myList)
{
    int rows = cad->rowCount();
    QtRPT *report = new QtRPT(this) ;
    report->loadReport(":/Templates/Liste_Examen.xml");
    report->recordCount.append(rows);
    connect(report, &QtRPT::setValue, [&](int recNo,
            QString paramName, QVariant &paramValue, const int reportPage){

        if(paramName == "wilaya")        paramValue = "Oran";
        if(paramName == "Num")               paramValue = QString::number(recNo+1);
        if(paramName == "Prenom")               {cad->setCurrentRow(recNo);paramValue = cad->getPRENOM();}
        if(paramName == "Nom")            {
            cad->setCurrentRow(recNo);
            if(cad->getNOM().length()>=8)paramValue = cad->getNOM()+"\n";
            else paramValue = cad->getNOM();

        }
        if(paramName == "Date_De_Naissance") {cad->setCurrentRow(recNo);paramValue = cad->getDATE_DE_NAISSANCE();}
        if(paramName == "Observations")      {cad->setCurrentRow(recNo);paramValue = "";}
        if(paramName == "NbrCandidats")      paramValue = QString::number(rows);

    });

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
