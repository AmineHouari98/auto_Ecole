#ifndef ADDCANDIDAT_H
#define ADDCANDIDAT_H

#include <QDialog>
#include <QDate>
#include "t_candidats.h"
#include "myparentobject.h"

namespace Ui {
class addCandidat;
}

class addCandidat : public QDialog
{
     Q_OBJECT

public:
    explicit addCandidat(QWidget *parent = 0, int id = -1);
    ~addCandidat();

private slots:
    void on_pushButton_Valider_clicked();
    void on_pushButton_Annuler_clicked();
    bool verifToutBon();
private:
    Ui::addCandidat *ui;
    t_candidats candidatsTable;
};

#endif // ADDCANDIDAT_H
