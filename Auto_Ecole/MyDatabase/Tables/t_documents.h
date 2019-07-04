#ifndef T_CLIENT_H
#define T_CLIENT_H

#include "easyORM.h"

class t_documents : public easyORM
{
    //    INIT_CURD(t_client) // add CURD methods( Create, Update, Read, Delete)
    Q_OBJECT
public:
    t_documents() { init(this); }
    ~t_documents() {;}

    SYS_PROPERTY(int, idDocuments)

    AUTO_PROPERTY(int, Photo)
    AUTO_PROPERTY(bool, Groupage)
    AUTO_PROPERTY(bool, CIN)
    AUTO_PROPERTY(bool, Residance)
    AUTO_PROPERTY(bool, Timbre)
    AUTO_PROPERTY(bool, Autorisation_Paternel)


    ;
public:
    enum TableName
    {
        _00idDocuments,
        _01Photo,
        _02Groupage,
        _03CIN,
        _04Residance,
        _05Timbre,
        _06Autorisation_Paternel

    };
};

#endif // T_CLIENT_H
