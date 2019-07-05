#include "mainwindow.h"
#include <QApplication>
#include <mydatabase.h>

#include "t_autoecole.h"
#include "t_caisse.h"
#include "t_candidats.h"
#include "t_documents.h"
#include "t_moniteurs.h"
#include "t_vehicules.h"

int main(int argc, char *argv[])
{
    MyDatabase myDatabase;
    if(!myDatabase.initMYSQL("localhost",3303,"root","","test"))
        return 1 ;

    t_autoEcole autoecole;
    t_caisse caisse   ;
    t_candidats candidats;
    t_documents documents;
    t_moniteurs moniteurs;
    t_vehicules vehicules;

    myDatabase.createTable(&autoecole);
    myDatabase.createTable(&caisse   );
    myDatabase.createTable(&candidats);
    myDatabase.createTable(&documents);
    myDatabase.createTable(&moniteurs);
    myDatabase.createTable(&vehicules);

    qDebug() << myDatabase.tables();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
