#ifndef ADDMONITEUR_H
#define ADDMONITEUR_H

#include <QDialog>
#include <QDate>
#include "t_moniteurs.h"

namespace Ui {
class addMoniteur;
}

class addMoniteur : public QDialog
{
     Q_OBJECT

public:
    explicit addMoniteur(QWidget *parent = 0, int id = -1);
    ~addMoniteur();

private slots:
    void on_pushButton_Valider_clicked();
    void on_pushButton_Annuler_clicked();
    bool verifToutBon();
private:
    Ui::addMoniteur *ui;
    t_moniteurs moniteursTable;
};

#endif // ADDMONITEUR_H
