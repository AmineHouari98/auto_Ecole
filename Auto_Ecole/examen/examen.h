#ifndef EXAMEN_H
#define EXAMEN_H

#include <QWidget>
#include <myparentobject.h>
#include "addexam.h"
#include "detailsexam.h"
#include "t_examens.h"

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
    void on_toolButton_new_exam_clicked();

    void on_btn_viewDetails_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);


private:
    Ui::examen *ui;
    t_examens *tableExamens;
    void openDetails();
};

#endif // EXAMEN_H
