#ifndef T_DOCUMENTS_H
#define T_DOCUMENTS_H

#include "easyORM.h"

class t_documents : public easyORM
{
    //    INIT_CURD(t_client) // add CURD methods( Create, Update, Read, Delete)
    Q_OBJECT
public:
    t_documents() { init(this); }
    ~t_documents() {;}

    SYS_PROPERTY(int, id)
    AUTO_PROPERTY(int, idCandidat)
    AUTO_PROPERTY(bool, Photo)
    AUTO_PROPERTY(bool, Groupage)
    AUTO_PROPERTY(bool, CIN)
    AUTO_PROPERTY(bool, Residance)
    AUTO_PROPERTY(bool, Timbre)
    AUTO_PROPERTY(bool, Autorisation_Paternel)


    ;
public:
    enum TableName
    {
        _00id,
        _01idCandidat,
        _02Photo,
        _03Groupage,
        _04CIN,
        _05Residance,
        _06Timbre,
        _07Autorisation_Paternel

    };
};

#endif // T_CLIENT_H
