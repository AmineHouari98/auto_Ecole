#ifndef LISTEXAM_H
#define LISTEXAM_H

#include <QObject>

class ModelExamList
{
    public:
    QString Nom, Prenom,NatExamen,cat,Date_De_Naissance,NumDossier;

    int NbrCandidats=0,NbrCode=0, NbrM=0, NbrCirc=0;



    enum TableName
    {
       _00Nom, _01Prenom,_02NatExamen,_03cat,_04Date_De_Naissance,
        _05NbrCandidats,_06NbrCode, _07NbrM, _08NbrCirc, _09NumDossier
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
