#ifndef T_EXAMENS_H
#define T_EXAMENS_H
#include "easyORM.h"

class t_examens : public easyORM
{
    //    INIT_CURD(t_client) // add CURD methods( Create, Update, Read, Delete)
    Q_OBJECT
public:
    t_examens() { init(this); }
    ~t_examens() {;}

    SYS_PROPERTY(int,      idExamen)
    AUTO_PROPERTY(QString, EXAMINATEUR)
    AUTO_PROPERTY(QString, DATE)
    AUTO_PROPERTY(QString, LIEU)
    AUTO_PROPERTY(int,     idInter)

    ;
public:
    enum TableName
    {
        _00idExamen,
        _01EXAMINATEUR,
        _03DATE,
        _04LIEU,
        _05idInter
    };
};

#endif // T_EXAMENS_H
