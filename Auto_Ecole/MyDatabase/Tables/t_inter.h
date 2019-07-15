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

    SYS_PROPERTY(int,  id)
    AUTO_PROPERTY(int, idExamen)
    AUTO_PROPERTY(int, idCandidat)

    ;
public:
    enum TableName
    {
        _00id,
        _01idExamen,
        _03idCandidat
    };
};




#endif // T_INTER_H
