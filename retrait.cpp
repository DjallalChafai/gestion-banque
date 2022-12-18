#include "retrait.h"
#include "ui_retrait.h"

retrait::retrait(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::retrait)
{
    ui->setupUi(this);
}

retrait::~retrait()
{
    delete ui;
}
