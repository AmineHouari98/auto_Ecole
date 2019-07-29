#ifndef ADDCANDIDAT_H
#define ADDCANDIDAT_H

#include <QDialog>
#include <QDate>
#include <QIntValidator>
#include "t_candidats.h"
#include "t_documents.h"
#include "myparentobject.h"

namespace Ui {
class addCandidat;
}

class addCandidat : public QDialog , public MyParentObject
{
     Q_OBJECT

public:
    explicit addCandidat(QWidget *parent = 0, int id = -1);

    ~addCandidat();

private slots:
    void on_pushButton_Valider_clicked();
    void on_pushButton_Annuler_clicked();
    void setUpLineEdits();
    void on_pushButton_clicked();
private:
    Ui::addCandidat *ui;
    t_candidats candidatsTable;
    t_documents *documentsTable;
    QList<QLineEdit*> lineList;
    void checkAll(bool);
};

#endif // ADDCANDIDAT_H
