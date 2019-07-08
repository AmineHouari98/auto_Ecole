#include "addCandidat.h"
#include "ui_addCandidat.h"

addCandidat::addCandidat(QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::addCandidat)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout Candidat");
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(QIcon(":/Assets/Images/icons/add_candidat.svg"));


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


}

addCandidat::~addCandidat()
{
    delete ui;
}

void addCandidat::on_pushButton_Valider_clicked()
{
    //TODO:change database codage to UTF8
    candidatsTable.setCurrentRow(-1);
    QString wilaya=ui->comboBox_wilaya->itemText(ui->comboBox_wilaya->currentIndex());

    QStringList selectedWilaya =wilaya.split("-");
    qDebug()<<selectedWilaya.at(0)+"    "+selectedWilaya.at(1);

    candidatsTable.setNom                 (ui->lineEdit_nom->text());
    candidatsTable.setPrenom              (ui->lineEdit_prenom->text());
    candidatsTable.setNom_Ar              (ui->lineEdit_nomAr->text());
    candidatsTable.setPrenom_Ar           (ui->lineEdit_prenomAr->text());
    candidatsTable.setDate_De_Naissance   (ui->dateEdit_naissanceCandidat->text());
    candidatsTable.setLieu_De_Naissance_Ar(selectedWilaya.at(1));
    candidatsTable.setAdresse_Ar          (ui->lineEdit_adresseAr->text());
    candidatsTable.setNum_CIN             (ui->lineEdit_numCin->text().toInt());
    candidatsTable.setNum_Tel             (ui->lineEdit_numTelephoneCandidat->text().toInt());
    candidatsTable.setDate_Inscription    (QDate::currentDate().toString());


    if(candidatsTable.currentRow() < 0)
        candidatsTable.insert() ;
    else
        candidatsTable.update() ;

    close();
}

void addCandidat::on_pushButton_Annuler_clicked()
{
    close();
}

