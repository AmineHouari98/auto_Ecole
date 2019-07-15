#ifndef LISTEXAM_H
#define LISTEXAM_H

#include <QObject>

class ModelExamList
{
    public:
    QString Nom, Prenom,NatExamen,cat,Date_De_Naissance;

    int NbrCandidats,NbrCode, NbrM, NbrCirc,NumDossier;

    void calc(){
        NbrCandidats++;
        if(NatExamen == "Code") NbrCode++;
        else if(NatExamen == "Circuit")Nbr
        else if(NatExamen == "Manoeuvre")
    }

    enum TableName
    {
       _00Nom, _01Prenom,_02NatExamen,_03cat,_04Date_De_Naissance,
        _05NbrCandidats,_06NbrCode, _07NbrM, _08NbrCirc
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
