#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtrpt.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Auto Ecole lhaj gal3ah");


    ui_candidats  = new candidat(this);
    ui_impression = new impression(this);


    ui->tabWidget->addTab(ui_candidats, QIcon(":/Assets/Images/icons/client.svg"), "Candidats");
    //TODO: change the icon for printing UI
    ui->tabWidget->addTab(ui_impression, QIcon(":/Assets/Images/icons/client.svg"), "Impression");


    bool ok = true ;
    int tmp = getSettings("ui->tabWidget->currentIndex()").toInt(&ok);
    if(!ok) tmp = 0 ;
    ui->tabWidget->setCurrentIndex(tmp);
}

MainWindow::~MainWindow()
{
    setSettings("ui->tabWidget->currentIndex()", ui->tabWidget->currentIndex());

    delete ui;
}

/*void MainWindow::on_tabWidget_currentChanged(int index)
{
    //if(index == 2 ) historique->refresh();
    //if(index == 3 ) solde->refresh();
   // if(index == 4 ) stock->refresh();
    if(index == 5 ) Candidat->refresh();
    //if(index == 6 ) fournisseurs->refresh();
    //if(index == 7 ) loads->refresh();
}*/

void MainWindow::on_pushButton_clicked()
{
    t_candidats *cad = new t_candidats;
    t_autoEcole *a = new t_autoEcole;
    int rows = cad->rowCount();
    QtRPT *report = new QtRPT(this) ;
    report->loadReport(":/Templates/Bodereau.xml");
    report->recordCount.append(rows);
    int i=0;
    connect(report, &QtRPT::setValue, [&](int recNo,
            QString paramName, QVariant &paramValue, const int reportPage){

        if(paramName == "NomAuto")           paramValue = a->getNom() ;
        if(paramName == "AdresseAuto")       paramValue = a->getAdresse();
        if(paramName == "NumTelAuto")        paramValue = a->getNumTel();
        if(paramName == "WilayaAuto")        paramValue = "Oran";
        if(paramName == "num")               paramValue = QString::number(recNo+1);
        if(paramName == "Nom")               {cad->setCurrentRow(recNo);paramValue = cad->getNom();}
        if(paramName == "Prenom")            {cad->setCurrentRow(recNo);paramValue = cad->getPrenom();}
        if(paramName == "Date_De_Naissance") {cad->setCurrentRow(recNo);paramValue = cad->getDate_De_Naissance();}
        if(paramName == "Observations")      {cad->setCurrentRow(recNo);paramValue = "";}


    });

    report->printExec();
}
