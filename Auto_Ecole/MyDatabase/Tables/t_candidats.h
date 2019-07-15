#ifndef T_CANDIDATS_H
#define T_CANDIDATS_H

#include "easyORM.h"

class t_candidats : public easyORM
{
    //    INIT_CURD(t_client) // add CURD methods( Create, Update, Read, Delete)
    Q_OBJECT
public:
    t_candidats() { init(this); }
    ~t_candidats() {;}

    SYS_PROPERTY(int,      id)

    AUTO_PROPERTY(int,     DOSSIER)
    AUTO_PROPERTY(QString, NOM)
    AUTO_PROPERTY(QString, PRENOM)
    AUTO_PROPERTY(QString, NOM_ARABE)
    AUTO_PROPERTY(QString, PRENOM_ARABE)
    AUTO_PROPERTY(QString, DATE_DE_NAISSANCE)
    AUTO_PROPERTY(QString, LIEU_DE_NAISSANCE)
    AUTO_PROPERTY(QString, NATIONALITE)
    AUTO_PROPERTY(QString, ADRESSE)
    AUTO_PROPERTY(QString,     CIN)
    AUTO_PROPERTY(QString,     TELEPHONE)
    AUTO_PROPERTY(int,     idDocuments)
    AUTO_PROPERTY(QString, DATE_INSCRIPTION)

    ;
public:
    enum TableName
    {
        _00idCandidat,
        _01DOSSIER,
        _02NOM,
        _03PRENOM,
        _04NOM_ARABE,
        _05PRENOM_ARABE,
        _06DATE_DE_NAISSANCE,
        _07LIEU_DE_NAISSANCE,
        _08NATIONALITE,
        _09ADRESSE,
        _10CIN,
        _11TELEPHONE,
        _12idDocuments,
        _13DATE_INSCRIPTION,
    };
};

#endif // T_CLIENT_H
