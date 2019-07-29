#ifndef PRINTALL_H
#define PRINTALL_H

#include <QDialog>
#include "impression.h"

namespace Ui {
class printAll;
}

class printAll : public QDialog
{
    Q_OBJECT

public:
    explicit printAll(QWidget *parent = 0);
    ~printAll();

private slots:
    void on_pushButton_Annuler_clicked();

    void on_pushButton_imprimer_clicked();

private:
    Ui::printAll *ui;
    impression printer;
};

#endif // PRINTALL_H
