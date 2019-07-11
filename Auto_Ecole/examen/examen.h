#ifndef EXAMEN_H
#define EXAMEN_H

#include <QWidget>
#include <myparentobject.h>
#include "t_examens.h"
#include "t_candidats.h"

namespace Ui {
class examen;
}

class examen : public QWidget, public MyParentObject
{
    Q_OBJECT
public:
    explicit examen(QWidget *parent = 0);
    ~examen();

private slots:
    void on_toolButton_new_client_clicked();

    void on_btn_viewProfile_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_toolButton_back_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);


    void on_pushButton_modifier_clicked();

private:
    Ui::examen *ui;
    void changeButtonState(QString,bool);
    t_examens *tableExamens;
    t_candidats *tableCandidats;
    QSqlTableModel *candidatsTable;
    void setValuesOnLineEdit(int);
    void setEditable(bool);
    void modifyOnDatabase();
    void initTableWidget();
};

#endif // EXAMEN_H
