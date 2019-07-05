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

    SYS_PROPERTY(int, idCandidat)

    AUTO_PROPERTY(int, numDossier)
    AUTO_PROPERTY(QString, Nom)
    AUTO_PROPERTY(QString, Prenom)
    AUTO_PROPERTY(QString, Nom_Ar)
    AUTO_PROPERTY(QString, Prenom_Ar)
    AUTO_PROPERTY(QString, Date_De_Naissance)
    AUTO_PROPERTY(QString, Lieu_De_Naissance_Ar)
    AUTO_PROPERTY(QString, AdresseAr)

    AUTO_PROPERTY(QString, Date_Inscription)
    AUTO_PROPERTY(int, Num_Tel)
    AUTO_PROPERTY(int, idDocuments)

    ;
public:
    enum TableName
    {
        _00idCandidat,
        _01numDossier,
        _02Nom,
        _03Prenom,
        _04Nom_Ar,
        _05Prenom_Ar,
        _06Date_De_Naissance,
        _07Lieu_De_Naissance_Ar,
        _08AdresseAr,
        _09Date_Inscription,
        _10Num_Tel,
        _11idDocuments

    };
};

#endif // T_CLIENT_H
