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

    SYS_PROPERTY(int, idCaisse)

    AUTO_PROPERTY(int, idTransaction)
    AUTO_PROPERTY(QString, TYPE)
    AUTO_PROPERTY(QString, MONTANT)
    AUTO_PROPERTY(QString, DATE)



    ;
public:
    enum TableName
    {
        _00idCaisse,
        _01idTransaction,
        _02TYPE,
        _03MONTANT,
        _04DATE

    };
};

#endif // T_CLIENT_H
