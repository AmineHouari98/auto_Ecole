#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Auto Ecole lhaj gal3ah");
    Candidat  = new candidat(this);
    ui->tabWidget->addTab(Candidat, QIcon(":/Assets/Images/icons/client.svg"), "Candidat");

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
