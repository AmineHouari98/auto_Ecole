#ifndef AJOUTERPAIMENT_H
#define AJOUTERPAIMENT_H

#include <QDialog>
#include <QDate>
#include "t_caisse.h"

namespace Ui {
class AjouterPaiment;
}

class AjouterPaiment : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterPaiment(QStringList list={""},int index=-1,int caisseId=-1,QString user_type="",QWidget *parent = 0);
    ~AjouterPaiment();


private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AjouterPaiment *ui;
    t_caisse *tableCaisse;
    QString type;
    QString u_type;
    int myIndex;
    int myCaisseId;
};

#endif // AJOUTERPAIMENT_H
