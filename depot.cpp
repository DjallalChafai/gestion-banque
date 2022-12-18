#include "depot.h"
#include "ui_depot.h"

depot::depot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depot)
{
    ui->setupUi(this);
}

depot::~depot()
{
    delete ui;
}
