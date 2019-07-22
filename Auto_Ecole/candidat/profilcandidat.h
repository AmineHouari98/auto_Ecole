#ifndef PROFILCANDIDAT_H
#define PROFILCANDIDAT_H

#include <QDialog>
#include "t_candidats.h"
#include "t_caisse.h"
#include "t_documents.h"
#include "t_examens.h"
#include "detailsexam.h"

namespace Ui {
class profilCandidat;
}

class profilCandidat : public QDialog
{
    Q_OBJECT

public:
    explicit profilCandidat(QWidget *parent = 0);
    ~profilCandidat();
    void setValuesOnLineEdit(int);

private:
    Ui::profilCandidat *ui;
    t_candidats *tableCandidats;
    t_caisse *tableCaisse;
    t_documents *tableDocuments;

    void setEditable(bool);
    void modifyOnDatabase();
    void changeButtonState(QString,bool);

public slots:
    void on_pushButton_modifier_clicked();

    void on_pushButton_annuler_clicked();
private slots:
    void on_toolbtn_histExams_clicked();
};

#endif // PROFILCANDIDAT_H
