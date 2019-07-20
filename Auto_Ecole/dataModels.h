#ifndef LISTEXAM_H
#define LISTEXAM_H

#include <QObject>

class ModelExamList
{
    public:
    QString Nom, Prenom,NatExamen,cat,Date_De_Naissance,NumDossier;



    enum TableName
    {
       _00Nom, _01Prenom,_02NatExamen,_03cat,_04Date_De_Naissance,
         _05NumDossier
    };

};

class ModelBordereau
{

public:
    QString Nom, Prenom,Date_De_Naissance;


    enum TableName
    {
       _00Nom, _01Prenom,_02Date_De_Naissance

    };

};

#endif // LISTEXAM_H
