#ifndef T_CAISSE_H
#define T_CAISSE_H

#include "easyORM.h"

class t_caisse : public easyORM
{
    //    INIT_CURD(t_client) // add CURD methods( Create, Update, Read, Delete)
    Q_OBJECT
public:
    t_caisse() { init(this); }
    ~t_caisse() {;}

    SYS_PROPERTY(int, id)

    AUTO_PROPERTY(int, idTransaction)
    AUTO_PROPERTY(QString, TYPE)
    AUTO_PROPERTY(QString, MONTANT)
    AUTO_PROPERTY(QString, DATE)
    AUTO_PROPERTY(QString, user_type)


    ;
public:
    enum TableName
    {
        _00idCaisse,
        _01idTransaction,
        _02TYPE,
        _03MONTANT,
        _04DATE,
        _05user_type

    };
};

#endif // T_CLIENT_H
