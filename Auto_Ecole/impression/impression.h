#ifndef IMPRESSION_H
#define IMPRESSION_H

#include <QWidget>
#include "dataModels.h"



namespace Ui {
class impression;
}

class impression : public QWidget
{
    Q_OBJECT
public:
    explicit impression(QWidget *parent = nullptr);
    ~impression();

    void printListExamen(QList<ModelExamList>,QString);
    void printBorderau(QList<ModelBordereau>);


signals:

public slots:

private:
    Ui::impression *ui;

};

#endif // IMPRESSION_H
