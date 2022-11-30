#include "fermer_compte.h"
#include "ui_fermer_compte.h"

Fermer_Compte::Fermer_Compte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fermer_Compte)
{
    ui->setupUi(this);
}

Fermer_Compte::~Fermer_Compte()
{
    delete ui;
}

void Fermer_Compte::on_Annuler_clicked()
{
    close();
}

