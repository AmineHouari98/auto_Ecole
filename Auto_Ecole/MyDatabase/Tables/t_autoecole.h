#ifndef T_AUTOECOLE_H
#define T_AUTOECOLE_H

#include "easyORM.h"

class t_autoEcole : public easyORM
{
    //    INIT_CURD(t_client) // add CURD methods( Create, Update, Read, Delete)
    Q_OBJECT
public:
    t_autoEcole() { init(this); }
    ~t_autoEcole() {;}

    AUTO_PROPERTY(int, NUMERO_REGISTRE)
    AUTO_PROPERTY(QString, NOM)
    AUTO_PROPERTY(QString, ADRESSE)
    AUTO_PROPERTY(QString, TEL)
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
