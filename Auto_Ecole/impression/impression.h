#ifndef IMPRESSION_H
#define IMPRESSION_H

#include <QWidget>
#include <QDate>
#include "dataModels.h"
#include "mydatabase.h"


class impression : public QWidget
{
    Q_OBJECT
public:
    explicit impression(QWidget *parent = nullptr);
    void printListExamen(QList<ModelExamList>,QDate,int Cand,int code,int man ,int circ);
    void printBorderau(QList<ModelBordereau>);
    void printAllCandidat(QString,QString);
signals:

public slots:


private:
    t_candidats *cad;
    t_autoEcole *a ;
};

#endif // IMPRESSION_H
