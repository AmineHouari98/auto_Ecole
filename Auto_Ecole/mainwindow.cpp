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
    ui_moniteurs  = new moniteur(this);


    ui->tabWidget->addTab(ui_candidats, QIcon(":/Assets/Images/icons/client.svg"), "Candidats");
    ui->tabWidget->addTab(ui_impression, QIcon(":/Assets/Images/icons/print.svg"), "Impression");
    ui->tabWidget->addTab(ui_moniteurs, QIcon(":/Assets/Images/icons/print.svg"), "Moniteurs");


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

