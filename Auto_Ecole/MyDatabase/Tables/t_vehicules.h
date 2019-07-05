#ifndef T_VEHICULES_H
#define T_VEHICULES_H

#include "easyORM.h"

class t_vehicules : public easyORM
{
    //    INIT_CURD(t_client) // add CURD methods( Create, Update, Read, Delete)
    Q_OBJECT
public:
    t_vehicules() { init(this); }
    ~t_vehicules() {;}

    SYS_PROPERTY(int, idVehicule)

    AUTO_PROPERTY(QString, Matricule)
    AUTO_PROPERTY(QString, Modele)
    AUTO_PROPERTY(QString, Annee)
    AUTO_PROPERTY(QString, Type)
    AUTO_PROPERTY(int, idCaisse)


    ;
public:
    enum TableName
    {
        _00idVoiture,
        _01Matricule,
        _02Modele,
        _03Annee,
        _04Type,
        _05idCaisse

    };
};

#endif // T_CLIENT_H
