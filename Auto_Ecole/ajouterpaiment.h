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
    explicit AjouterPaiment(QWidget *parent = 0);
    ~AjouterPaiment();
    int index;
    QStringList myList;

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AjouterPaiment *ui;
    QString type;
    t_caisse *tableCaisse;
};

#endif // AJOUTERPAIMENT_H
