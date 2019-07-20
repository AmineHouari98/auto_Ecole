#ifndef IMPRESSION_H
#define IMPRESSION_H

#include <QWidget>
#include "dataModels.h"

class impression : public QWidget
{
    Q_OBJECT
public:
    explicit impression(QWidget *parent = nullptr);
    void printListExamen(QList<ModelExamList>,QString,int Cand,int code,int man ,int circ);
    void printBorderau(QList<ModelBordereau>);

signals:

public slots:
};

#endif // IMPRESSION_H
