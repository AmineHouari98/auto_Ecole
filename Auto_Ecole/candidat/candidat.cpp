#include "candidat.h"
#include "ui_candidat.h"

candidat::candidat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::candidat)
{
    ui->setupUi(this);

    setEditable(false);
    ui->pushButton_annuler->hide();
    ui->toolButton_back->setVisible(false);
    const QStringList listWilaya ={
        "1-أدرار"
        ,"2-الشلف"
        ,"3-الأغواط"
        ,"4-أم البواقي"
        ,"5-باتنة"
        ,"6-بجاية"
        ,"7-بسكرة"
        ,"8-بشار"
        ,"9-البليدة"
        ,"10-البويرة"
        ,"11-تمنراست"
        ,"12-تبسة"
        ,"13-تلمسان"
        ,"14-تيارت"
        ,"15-تيزي وزو"
        ,"16-الجزائر"
        ,"17-الجلفة"
        ,"18-جيجل"
        ,"19-سطيف"
        ,"20-سعيدة"
        ,"21-سكيكدة"
        ,"22-سيدي بلعباس"
        ,"23-عنابة"
        ,"24-قالمة"
        ,"25-قسنطينة"
        ,"26-المدية"
        ,"27-مستغانم"
        ,"28-المسيلة"
        ,"29-معسكر"
        ,"30-ورقلة"
        ,"31-وهران"
        ,"32-البيض"
        ,"33-اليزي"
        ,"34-برج بوعريريج"
        ,"35-بومرداس"
        ,"36-الطارف"
        ,"37-تندوف"
        ,"38-تسمسيلت"
        ,"39-الوادي"
        ,"40-خنشلة"
        ,"41-سوق أهراس"
        ,"42-تيبازة"
        ,"43-ميلة"
        ,"44-عين الدفلى"
        ,"45-النعامة"
        ,"46-عين تموشنت"
        ,"47-غرداية"
        ,"48-غليزان"};



    ui->comboBox_wilaya->addItems(listWilaya);
    ui->stackedWidget->setCurrentIndex(0);

    tableCandidats = new t_candidats();
    tableCandidats->select();
    ui->tableView->setModel(tableCandidats->toModel());
    ui->widget->setTableView(ui->tableView);
    ui->widget->setModel(tableCandidats);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->hideColumn(t_candidats::_00idCandidat);
    ui->tableView->hideColumn(t_candidats::_12idDocuments);



    tableCaisse = new t_caisse();
    caisseTable = new QSqlTableModel(this);
    caisseTable->setTable(tableCaisse->tableName());
    ui->tableView_2->setModel(caisseTable);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_2->hideColumn(t_caisse::_00idCaisse);
    ui->tableView_2->hideColumn(t_caisse::_01idTransaction);


}



candidat::~candidat()
{
    delete ui;
}

void candidat::on_toolButton_new_client_clicked()
{
    addCandidat addCandidat;
    addCandidat.exec();
    tableCandidats->select();
}

void candidat::on_btn_viewProfile_clicked()
{    
    setValuesOnLineEdit(ui->tableView->currentIndex().row());
    ui->stackedWidget->setCurrentIndex(1);
}

void candidat::on_stackedWidget_currentChanged(int arg1)
{
    if (arg1 == 0 ) {
        ui->toolButton_new_client->setVisible(true);
        ui->btn_viewProfile->setVisible(true);
        ui->toolButton_back->setVisible(false);
    }

    else {
        ui->toolButton_new_client->setVisible(false);
        ui->btn_viewProfile->setVisible(false);
        ui->toolButton_back->setVisible(true);

    }



}

void candidat::on_toolButton_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void candidat::on_tableView_doubleClicked(const QModelIndex &index)
{
    setValuesOnLineEdit(index.row());
    ui->stackedWidget->setCurrentIndex(1);
}

void candidat::setValuesOnLineEdit(int index)
{
    tableCandidats->setCurrentRow(index);

    QString date_string_on_db = tableCandidats->getDATE_DE_NAISSANCE();
    QDate Date = QDate::fromString(date_string_on_db,"dd/MM/yyyy");

    ui->comboBox_wilaya->setCurrentIndex(ui->comboBox_wilaya->findText(tableCandidats->getLIEU_DE_NAISSANCE(),Qt::MatchContains));

    ui->lineEdit_nom->setText(tableCandidats->getNOM());
    ui->lineEdit_prenom->setText(tableCandidats->getPRENOM());
    ui->lineEdit_nomAr->setText(tableCandidats->getNOM_ARABE());
    ui->lineEdit_prenomAr->setText(tableCandidats->getPRENOM_ARABE());
    ui->dateEdit_naissanceCandidat->setDate(Date);
    ui->lineEdit_adresseAr->setText(tableCandidats->getADRESSE());
    ui->lineEdit_numCin->setText(tableCandidats->getCIN());
    ui->lineEdit_numTelephone->setText(tableCandidats->getTELEPHONE());
    ui->lineEdit_nationnalite->setText(tableCandidats->getNATIONALITE());
    ui->lineEdit_numDossier->setText(QString::number(tableCandidats->getDOSSIER()));


    caisseTable->setFilter("idTransaction = "+QString::number(tableCandidats->getidCandidat()));
    caisseTable->select();

}

void candidat::setEditable(bool ok)
{
    ui->lineEdit_nom->setEnabled(ok);
    ui->lineEdit_prenom->setEnabled(ok);
    ui->lineEdit_nomAr->setEnabled(ok);
    ui->lineEdit_prenomAr->setEnabled(ok);
    ui->dateEdit_naissanceCandidat->setEnabled(ok);
    ui->lineEdit_adresseAr->setEnabled(ok);
    ui->lineEdit_numCin->setEnabled(ok);
    ui->lineEdit_numTelephone->setEnabled(ok);
    ui->lineEdit_nationnalite->setEnabled(ok);
    ui->lineEdit_numDossier->setEnabled(ok);
    ui->comboBox_wilaya->setEnabled(ok);

}

void candidat::modifyOnDatabase()
{
    QString wilaya=ui->comboBox_wilaya->itemText(ui->comboBox_wilaya->currentIndex());

    QStringList selectedWilaya =wilaya.split("-");
    qDebug()<<selectedWilaya.at(0)+"    "+selectedWilaya.at(1);

    tableCandidats->setNOM                 (ui->lineEdit_nom->text());
    tableCandidats->setPRENOM              (ui->lineEdit_prenom->text());
    tableCandidats->setNOM_ARABE           (ui->lineEdit_nomAr->text());
    tableCandidats->setPRENOM_ARABE        (ui->lineEdit_prenomAr->text());
    tableCandidats->setDATE_DE_NAISSANCE   (ui->dateEdit_naissanceCandidat->text());
    tableCandidats->setLIEU_DE_NAISSANCE   (selectedWilaya.at(1));
    tableCandidats->setADRESSE             (ui->lineEdit_adresseAr->text());
    tableCandidats->setCIN                 (ui->lineEdit_numCin->text());
    tableCandidats->setTELEPHONE           (ui->lineEdit_numTelephone->text());
    tableCandidats->setNATIONALITE         (ui->lineEdit_nationnalite->text());
    tableCandidats->setDOSSIER             (ui->lineEdit_numDossier->text().toInt());

    tableCandidats->update() ;

}

void candidat::changeButtonState(QString title, bool isVisible)
{

    ui->pushButton_modifier->setText(title);

    ui->pushButton_annuler->setVisible(isVisible);

}

void candidat::on_pushButton_modifier_clicked()
{
    if(ui->pushButton_modifier->text()=="Valider")
    {
        candidat::on_pushButton_annuler_clicked();
        modifyOnDatabase();
    }

    if(ui->pushButton_modifier->text()=="Modifier")
    {
        setEditable(true);
        changeButtonState("Valider",true);

    }
}

void candidat::on_pushButton_annuler_clicked()
{
   setEditable(false);
   ui->pushButton_annuler->setVisible(false);
   changeButtonState("Modifier",false);
}
