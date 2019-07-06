#include "impression.h"

impression::impression(QWidget *parent) : QWidget(parent)
{

}
//DONT TOUCH THIS CODE


//t_candidats *cad = new t_candidats;
//t_autoEcole *a = new t_autoEcole;
//int rows = cad->rowCount();
//QtRPT *report = new QtRPT(this) ;
//report->loadReport(":/Templates/Bodereau.xml");
//report->recordCount.append(rows);
//int i=0;
//connect(report, &QtRPT::setValue, [&](int recNo,
//        QString paramName, QVariant &paramValue, const int reportPage){

//    if(paramName == "NomAuto")           paramValue = a->getNom() ;
//    if(paramName == "AdresseAuto")       paramValue = a->getAdresse();
//    if(paramName == "NumTelAuto")        paramValue = a->getNumTel();
//    if(paramName == "WilayaAuto")        paramValue = "Oran";
//    if(paramName == "num")               paramValue = QString::number(recNo+1);
//    if(paramName == "Nom")               {cad->setCurrentRow(recNo);paramValue = cad->getNom();}
//    if(paramName == "Prenom")            {cad->setCurrentRow(recNo);paramValue = cad->getPrenom();}
//    if(paramName == "Date_De_Naissance") {cad->setCurrentRow(recNo);paramValue = cad->getDate_De_Naissance();}
//    if(paramName == "Observations")      {cad->setCurrentRow(recNo);paramValue = "";}


//});

//report->printExec();
