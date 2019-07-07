#include "impression.h"
#include "mydatabase.h"
#include "qtrpt.h"

impression::impression(QWidget *parent) : QWidget(parent)
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
