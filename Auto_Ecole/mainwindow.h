#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "candidat.h"
#include "impression.h"
#include "moniteur.h"
#include "examen.h"
#include "vehicule.h"


#include "myparentobject.h"
#include "MyDatabase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public MyParentObject
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString champVide = "completez les champs vides s'il vous plaît!";

private slots:
    void on_actionQuiter_triggered() { close(); }

    //void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    candidat *ui_candidats;
    impression *ui_impression;
    moniteur *ui_moniteurs;
    examen *ui_examens;
    vehicule *ui_vehicule;

};

#endif // MAINWINDOW_H
