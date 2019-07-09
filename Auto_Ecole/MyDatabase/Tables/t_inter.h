#ifndef T_INTER_H
#define T_INTER_H

#include "easyORM.h"

class t_inter : public easyORM
{
    //    INIT_CURD(t_client) // add CURD methods( Create, Update, Read, Delete)
    Q_OBJECT
public:
    t_inter() { init(this); }
    ~t_inter() {;}

    SYS_PROPERTY(int,      idInter)

    AUTO_PROPERTY(int, idCandidat)
    AUTO_PROPERTY(int, idExamen)

    ;
public:
    enum TableName
    {
        _00idInter,
        _01idCandidat,
        _02idExamen
    };
};

#endif // T_INTER_H
