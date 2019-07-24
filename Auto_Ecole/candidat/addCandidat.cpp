#include "addCandidat.h"
#include "ui_addCandidat.h"


addCandidat::addCandidat(QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::addCandidat)
{
    ui->setupUi(this);
    setUpLineEdits();
    this->setWindowTitle("Ajout Candidat");
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(QIcon(":/Assets/Images/icons/add_candidat.ico"));

    documentsTable = new t_documents;


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
    ui->lineEdit_nationnalite->setText("جزائرية");



    lineList.append(ui->lineEdit_nom);
    lineList.append(ui->lineEdit_prenom);
    lineList.append(ui->lineEdit_nomAr);
    lineList.append(ui->lineEdit_prenomAr);
    lineList.append(ui->lineEdit_adresseAr);
    lineList.append(ui->lineEdit_numCin);
    lineList.append(ui->lineEdit_numTelephone);
    lineList.append(ui->lineEdit_nationnalite);
    lineList.append(ui->lineEdit_numDossier);

}

addCandidat::~addCandidat()
{
    delete ui;
}
void addCandidat::setUpLineEdits()
{
    // tbaya3 of textfields
    ui->lineEdit_numTelephone->setMaxLength(13);
    //ui->lineEdit_numTelephone->setValidator(new QIntValidator(0,max,this));

    ui->spinBox_ins->setRange(10000,50000);
    ui->spinBox_PrE->setRange(0,4500);

    ui->lineEdit_numCin->setMaxLength(9);
    ui->lineEdit_numDossier->setMaxLength(7);
}


void addCandidat::on_pushButton_Valider_clicked()
{
    if(checkIntegrity(lineList)<lineList.length())
    {
        msgWarning("Attention",champVide);
    }
    else
    {
        candidatsTable.setCurrentRow(-1);
        QString wilaya=ui->comboBox_wilaya->itemText(ui->comboBox_wilaya->currentIndex());

        QStringList selectedWilaya =wilaya.split("-");
        qDebug()<<selectedWilaya.at(0)+"    "+selectedWilaya.at(1);


        candidatsTable.setNOM                 (ui->lineEdit_nom->text());
        candidatsTable.setPRENOM              (ui->lineEdit_prenom->text());
        candidatsTable.setNOM_ARABE           (ui->lineEdit_nomAr->text());
        candidatsTable.setPRENOM_ARABE        (ui->lineEdit_prenomAr->text());
        candidatsTable.setDATE_DE_NAISSANCE   (ui->dateEdit_naissanceCandidat->text());
        candidatsTable.setLIEU_DE_NAISSANCE   (selectedWilaya.at(1));
        candidatsTable.setADRESSE             (ui->lineEdit_adresseAr->text());
        candidatsTable.setCIN                 (ui->lineEdit_numCin->text());
        candidatsTable.setTELEPHONE           (ui->lineEdit_numTelephone->text());
        candidatsTable.setNATIONALITE         (ui->lineEdit_nationnalite->text());
        candidatsTable.setDOSSIER             (ui->lineEdit_numDossier->text());
        candidatsTable.setDATE_INSCRIPTION    (QDate::currentDate().toString());



        documentsTable->setCurrentRow(-1);

        documentsTable->setAutorisation_Paternel(ui->checkBox_APaternel->checkState());
        documentsTable->setCIN(ui->checkBox_CIN->checkState());
        documentsTable->setGroupage(ui->checkBox_Groupage->checkState());
        documentsTable->setPhoto(ui->checkBox_Photo->checkState());
        documentsTable->setResidance(ui->checkBox_Residence->checkState());
        documentsTable->setTimbre(ui->checkBox_Timbre->checkState());


        candidatsTable.insert() ;
        documentsTable->insert();

        close();
    }

}

void addCandidat::on_pushButton_Annuler_clicked()
{
    close();
}

void addCandidat::on_pushButton_clicked()
{
    if(ui->pushButton->text()=="Tout Cocher")
    {
        checkAll(true);
    }
    else if (ui->pushButton->text()=="Tout Décocher")
    {
        checkAll(false);
    }

}

void addCandidat::checkAll(bool ok)
{
    ui->checkBox_APaternel->setChecked(ok);
    ui->checkBox_CIN->setChecked(ok);
    ui->checkBox_Groupage->setChecked(ok);
    ui->checkBox_Photo->setChecked(ok);
    ui->checkBox_Residence->setChecked(ok);
    ui->checkBox_Timbre->setChecked(ok);

}


