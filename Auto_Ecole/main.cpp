#include "mainwindow.h"
#include <QApplication>
#include <mydatabase.h>

#include "t_autoecole.h"
#include "t_caisse.h"
#include "t_candidats.h"
#include "t_documents.h"
#include "t_moniteurs.h"
#include "t_vehicules.h"
#include "t_examens.h"
#include "t_inter.h"

void fillDatabase();

int main(int argc, char *argv[])
{
    MyDatabase myDatabase;
    if(!myDatabase.initMYSQL("localhost",3306,"root","","test"))
    //if(!myDatabase.initSQLITE3())
        return 1 ;

    t_autoEcole autoecole;
    t_caisse caisse   ;
    t_candidats candidats;
    t_documents documents;
    t_moniteurs moniteurs;
    t_vehicules vehicules;
    t_examens examens;
    t_inter inter;

    myDatabase.createTable(&autoecole);
    myDatabase.createTable(&caisse);
    myDatabase.createTable(&candidats);
    myDatabase.createTable(&documents);
    myDatabase.createTable(&moniteurs);
    myDatabase.createTable(&vehicules);
    myDatabase.createTable(&examens);
    myDatabase.createTable(&inter);

    qDebug() << myDatabase.tables();

    fillDatabase();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    autoecole.select();
    //qDebug() << autoecole.getNom();

    return a.exec();
}

void fillDatabase()
{
    t_autoEcole autoecole;
    autoecole.select();

    autoecole.setADRESSE("Bloc : B ilot : I 01 Local n°2 au Rez de chaussée des 700 logements Hai Sabah /2éme tranche commune de Sidi Chami");
    autoecole.setNOM("auto-école wafaa");
    autoecole.setTELEPHONE("0697 53 83 55 / 0791 43 69 53");
    autoecole.setNUMERO_REGISTRE(3115);
    autoecole.insert();


}
