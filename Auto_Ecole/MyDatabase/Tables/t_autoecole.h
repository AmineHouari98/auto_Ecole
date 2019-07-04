#ifndef T_CLIENT_H
#define T_CLIENT_H

#include "easyORM.h"

class t_autoEcole : public easyORM
{
    //    INIT_CURD(t_client) // add CURD methods( Create, Update, Read, Delete)
    Q_OBJECT
public:
    t_autoEcole() { init(this); }
    ~t_autoEcole() {;}

    AUTO_PROPERTY(int, NumRegistre)
    AUTO_PROPERTY(QString, Nom)
    AUTO_PROPERTY(QString, Adresse)
    AUTO_PROPERTY(int, NumTel)
    ;
public:
    enum TableName
    {
        _00numRegistre,
        _01Nom,
        _02Adresse,
        _03NumTel,

    };
};

#endif // T_CLIENT_H
