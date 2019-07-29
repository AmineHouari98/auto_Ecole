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

    SYS_PROPERTY(int, id)

    AUTO_PROPERTY(QString, MATRICULE)
    AUTO_PROPERTY(QString, MODELE)
    AUTO_PROPERTY(QString, ANNEE)
    AUTO_PROPERTY(QString, TYPE)
    AUTO_PROPERTY(QString, PROPRIETAIRE)


    ;
public:
    enum TableName
    {
        _00idVoiture,
        _01Matricule,
        _02Modele,
        _03Annee,
        _04Type,
        _05PROPRIETAIRE

    };
};

#endif // T_CLIENT_H
