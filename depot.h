#ifndef DEPOT_H
#define DEPOT_H

#include <QDialog>

namespace Ui {
class depot;
}

class depot : public QDialog
{
    Q_OBJECT

public:
    explicit depot(QWidget *parent = nullptr);
    ~depot();

private:
    Ui::depot *ui;
};

#endif // DEPOT_H
