#ifndef BORDEREAU_H
#define BORDEREAU_H

#include <QDialog>

namespace Ui {
class Bordereau;
}

class Bordereau : public QDialog
{
    Q_OBJECT

public:
    explicit Bordereau(QWidget *parent = 0);
    ~Bordereau();

private:
    Ui::Bordereau *ui;
};

#endif // BORDEREAU_H
