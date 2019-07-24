#include "profilcandidat.h"
#include "ui_profilcandidat.h"

profilCandidat::profilCandidat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profilCandidat)
{
    ui->setupUi(this);
    ui->pushButton_annuler->hide();
    this->setWindowTitle("Profil du candidat");
    this->setWindowIcon(QIcon(":/Assets/Images/icons/profile1.ico"));

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
    tableCandidats = new t_candidats;
    tableDocuments = new t_documents;


    setEditable(false);

    tableCaisse = new t_caisse();
    ui->tableView->setModel(tableCaisse->toModel());
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->hideColumn(t_caisse::_00idCaisse);
    ui->tableView->hideColumn(t_caisse::_01idTransaction);
    ui->tableView->hideColumn(t_caisse::_05user_type);

}

void profilCandidat::setValuesOnLineEdit(int id)
{
    tableCandidats->whereid(id);

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
    ui->lineEdit_numDossier->setText(tableCandidats->getDOSSIER());


    tableCaisse->where("idTransaction = "+QString::number(tableCandidats->getid())+" AND user_type = 'C'" );
    tableCaisse->select();

    executeQuery(tableCandidats->getid());






}

void profilCandidat::setEditable(bool ok)
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
    ui->checkBox_photo->setEnabled(ok);
    ui->checkBox_groupage->setEnabled(ok);
    ui->checkBox_CIN->setEnabled(ok);
    ui->checkBox_residance->setEnabled(ok);
    ui->checkBox_Timbre->setEnabled(ok);
    ui->checkBox_AutoP->setEnabled(ok);
}

void profilCandidat::executeQuery(int index)
{

    QSqlQuery query;

    query.exec("SELECT Photo,Groupage,CIN,Residance,Timbre,Autorisation_Paternel,idCandidat "
               "FROM t_documents "
               "WHERE idCandidat = "+ QString::number(index));

    while (query.next()) {

        bool Photo                 =query.value(0).toBool();
        bool Groupage              =query.value(1).toBool();
        bool CIN                   =query.value(2).toBool();
        bool Residance             =query.value(3).toBool();
        bool Timbre                =query.value(4).toBool();
        bool Autorisation_Paternel =query.value(5).toBool();

        qDebug()<<QString::number(Photo);

        ui->checkBox_photo->setChecked(Photo);
        ui->checkBox_groupage->setChecked(Groupage);
        ui->checkBox_CIN->setChecked(CIN);
        ui->checkBox_residance->setChecked(Residance);
        ui->checkBox_Timbre->setChecked(Timbre);
        ui->checkBox_AutoP->setChecked(Autorisation_Paternel);

    }



}

void profilCandidat::modifyOnDatabase()
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
    tableCandidats->setDOSSIER             (ui->lineEdit_numDossier->text());

    tableCandidats->update() ;



    tableDocuments->setAutorisation_Paternel(ui->checkBox_AutoP->checkState());
    tableDocuments->setCIN(ui->checkBox_CIN->checkState());
    tableDocuments->setGroupage(ui->checkBox_groupage->checkState());
    tableDocuments->setPhoto(ui->checkBox_photo->checkState());
    tableDocuments->setResidance(ui->checkBox_residance->checkState());
    tableDocuments->setTimbre(ui->checkBox_Timbre->checkState());

    tableDocuments->update();

    tableCandidats->select();

}

void profilCandidat::changeButtonState(QString title, bool isVisible)
{
    ui->pushButton_modifier->setText(title);
    ui->pushButton_annuler->setVisible(isVisible);
}

void profilCandidat::on_pushButton_modifier_clicked()
{
    if(ui->pushButton_modifier->text()=="Valider")
    {
        modifyOnDatabase();
        emit ui->pushButton_annuler->clicked(false);

    }
    else if(ui->pushButton_modifier->text()=="Modifier")
    {
        setEditable(true);
        changeButtonState("Valider",true);

    }
}

void profilCandidat::on_pushButton_annuler_clicked()
{
    setEditable(false);
    setValuesOnLineEdit(tableCandidats->getid());

    ui->pushButton_annuler->setVisible(false);
    changeButtonState("Modifier",false);
}

profilCandidat::~profilCandidat()
{
    delete ui;
}

void profilCandidat::on_toolbtn_histExams_clicked()
{

}


void profilCandidat::on_toolButton_Modifier_clicked()
{
    //learn to point cursor on the method or enum and then press F1 to find more help and option :)
    /*
    This enum describes actions which will initiate item editing.
    QAbstractItemView::NoEditTriggers:    No editing possible.
    QAbstractItemView::CurrentChanged:    Editing start whenever current item changes.
    QAbstractItemView::DoubleClicked:    Editing starts when an item is double clicked.
    QAbstractItemView::SelectedClicked:    Editing starts when clicking on an already selected item.
    QAbstractItemView::EditKeyPressed:    Editing starts when the platform edit key has been pressed over an item.
    QAbstractItemView::AnyKeyPressed:    Editing starts when any key is pressed over an item.
    QAbstractItemView::AllEditTriggers:    Editing starts for all above actions.
    The EditTriggers type is a typedef for QFlags<EditTrigger>. It stores an OR combination of EditTrigger values.
    */
    ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers); // TODO : badlha , prc paramter alledittriggers dertha tchanba ,
    ui->tableView->setCurrentIndex( ui->tableView->currentIndex());
    ui->tableView->setFocus();
}

void profilCandidat::on_toolButton_Ajouter_clicked()
{
    AjouterPaiment ap();

}

void profilCandidat::on_toolButton_Supprimer_clicked()
{


}
