#ifndef VEHICULE_H
#define VEHICULE_H

#include <QWidget>
#include <myparentobject.h>


namespace Ui {
class vehicule;
}

class vehicule : public QWidget, public MyParentObject
{
    Q_OBJECT

public:
    explicit vehicule(QWidget *parent = 0);
    ~vehicule();

private slots:
    void on_toolButton_newVehicule_clicked();

    void on_btn_viewVehicule_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::vehicule *ui;
    void openDetails();
};

#endif // VEHICULE_H
