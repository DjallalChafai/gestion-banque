#include "retrait.hpp"
#include "ui_retrait.h"

retrait::retrait(QWidget *parent) : QDialog(parent), ui(new Ui::retrait) {
    // initialisation de l'interface graphique
    ui->setupUi(this);
}

retrait::~retrait() {
    // destruction de l'interface graphique
    delete ui;
}