#ifndef T_MONITEURS_H
#define T_MONITEURS_H

#include "easyORM.h"

class t_moniteurs : public easyORM
{
    //    INIT_CURD(t_client) // add CURD methods( Create, Update, Read, Delete)
    Q_OBJECT
public:
    t_moniteurs() { init(this); }
    ~t_moniteurs() {;}

    SYS_PROPERTY(int,      id)

    AUTO_PROPERTY(QString, NOM)
    AUTO_PROPERTY(QString, PRENOM)
    AUTO_PROPERTY(QString, DATE_DE_NAISSANCE)
    AUTO_PROPERTY(QString, ADRESSE)
    AUTO_PROPERTY(QString,     PERMIS)
    AUTO_PROPERTY(QString,     TELEPHONE)
    AUTO_PROPERTY(QString, DATE_AJOUT)
    ;
public:
    enum TableName
    {
        _00idMoniteur,
        _01NOM,
        _02PRENOM,
        _03DATE_DE_NAISSANCE,
        _04ADRESSE,
        _05PERMIS,
        _06TELEPHONE,
        _07DATE_AJOUT

    };
};

#endif // T_CLIENT_H
