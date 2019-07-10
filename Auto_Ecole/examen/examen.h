#ifndef EXAMEN_H
#define EXAMEN_H

#include <QWidget>
#include <myparentobject.h>

namespace Ui {
class examen;
}

class examen : public QWidget, public MyParentObject
{
    Q_OBJECT
public:
    explicit examen(QWidget *parent = 0);
    ~examen();

private:
    Ui::examen *ui;
    void changeButtonState(QString,bool);
};

#endif // EXAMEN_H
