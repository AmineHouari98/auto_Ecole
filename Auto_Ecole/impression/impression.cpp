#include "impression.h"
#include "mydatabase.h"
#include "qtrpt.h"

impression::impression(QWidget *parent) : QWidget(parent)
{


}

void impression::printListExamen(QList<ModelExamList> myList)
{
    t_autoEcole *a = new t_autoEcole;
    int rows = myList.length();
    QtRPT *report = new QtRPT(this) ;
    report->loadReport(":/Templates/Liste_Examen.xml");
    report->recordCount.append(rows);
    connect(report, &QtRPT::setValue, [&](int recNo,
            QString paramName, QVariant &paramValue, const int reportPage){

        if(paramName == "NomAuto")           paramValue = a->getNom() ;
        if(paramName == "AdresseAuto")       paramValue = a->getAdresse();
        if(paramName == "NumTelAuto")        paramValue = a->getNumTel();
        if(paramName == "WilayaAuto")        paramValue = "Oran";
        if(paramName == "Num")               paramValue = QString::number(recNo+1);
        if(paramName == "NumDossier")        paramValue = myList.at(recNo).NumDossier;
        if(paramName == "Prenom")            paramValue = myList.at(recNo).Prenom;
        if(paramName == "Nom")            {

            if(QString(myList.at(recNo).Nom).length()>=8)paramValue = myList.at(recNo).Nom+"\n";
            else paramValue = myList.at(recNo).Nom;

        }
        if(paramName == "Date_De_Naissance") paramValue = myList.at(recNo).Date_De_Naissance;
        if(paramName == "NatExamen")         paramValue = myList.at(recNo).NatExamen;
        if(paramName == "cat")               paramValue = myList.at(recNo).cat;
        if(paramName == "NbrCandidats")      paramValue = QString::number(myList.at(recNo).NbrCandidats);
        if(paramName == "NbrCode")           paramValue = QString::number(myList.at(recNo).NbrCode);
        if(paramName == "NbrCirc")           paramValue = QString::number(myList.at(recNo).NbrCirc);
        if(paramName == "NbrM")              paramValue = QString::number(myList.at(recNo).NbrM);




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
