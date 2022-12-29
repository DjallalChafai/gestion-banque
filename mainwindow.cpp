#include "mainwindow.h"
#include "dialog.h"
#include "virement.h"
#include "fermer_compte.h"
#include "solde_compte.h"
#include "numero_compte.h"
#include "depot.h"
#include "retrait.h"
#include "epargne.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    // initialisation de l'interface graphique
    ui->setupUi(this);
    // chargement de l'image de fond
    QPixmap bkgnd(":/assets/background.jpg");
    // redimensionnement de l'image de fond
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    // application de l'image de fond
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow() {
    // destruction de l'interface graphique
    delete ui;
}

void MainWindow::on_Ok_clicked() {
    // récupération des données entrées par l'utilisateur
    close();
}

void MainWindow::on_actionOuvrir_un_Compte_triggered() {
    // ouverture et affichage de la fenêtre
    Dialog d;
    d.setModal(true);
    d.exec();
}

void MainWindow::on_Boursorama_clicked() {

    QSqlDatabase BB = QSqlDatabase::database("bb");

    QSqlQuery *qry = new QSqlQuery(BB);
    qry->prepare("SELECT * FROM info");

    QSqlTableModel *model = new QSqlTableModel(this, BB);
    model->setTable("info");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("firstname"));
    model->setHeaderData(2, Qt::Horizontal, tr("lastname"));
    model->setHeaderData(3, Qt::Horizontal, tr("address"));
    model->setHeaderData(4, Qt::Horizontal, tr("email"));
    model->setHeaderData(5, Qt::Horizontal, tr("phone"));
    model->setHeaderData(6, Qt::Horizontal, tr("password"));
    model->setHeaderData(7, Qt::Horizontal, tr("account_number"));
    model->setHeaderData(8, Qt::Horizontal, tr("balance"));
    model->setHeaderData(9, Qt::Horizontal, tr("épargne"));

    ui->SqlView->setModel(model);

    if(!qry->exec())    //affichage message d'erreur ou de succès
      QMessageBox::warning(this, tr("Problem"), qry->lastError().text());

    else
      QMessageBox::information(this, tr("Success"), tr("DB has been selected"));
}


void MainWindow::on_actionFermer_un_compte_triggered() {
    // ouverture et affichage de la fenêtre
    Fermer_Compte f;
    f.setModal(true);
    f.exec();
}


void MainWindow::on_Revolut_clicked() {
    QSqlDatabase RV = QSqlDatabase::database("rv");

    QSqlQuery *qry = new QSqlQuery(RV);
    qry->prepare("SELECT * FROM info");

    QSqlTableModel *model = new QSqlTableModel(this, RV);
    model->setTable("info");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("firstname"));
    model->setHeaderData(2, Qt::Horizontal, tr("lastname"));
    model->setHeaderData(3, Qt::Horizontal, tr("address"));
    model->setHeaderData(4, Qt::Horizontal, tr("email"));
    model->setHeaderData(5, Qt::Horizontal, tr("phone"));
    model->setHeaderData(6, Qt::Horizontal, tr("password"));
    model->setHeaderData(7, Qt::Horizontal, tr("account_number"));
    model->setHeaderData(8, Qt::Horizontal, tr("balance"));
    model->setHeaderData(9, Qt::Horizontal, tr("épargne"));

    ui->SqlView->setModel(model);

    if( !qry->exec() )  //affichage message d'erreur ou de succès
        QMessageBox::warning(this, tr("Problem"), qry->lastError().text());

    else
        QMessageBox::information(this, tr("Success"), tr("DB has been selected"));
}


void MainWindow::on_N26_clicked() {
    QSqlDatabase N26 = QSqlDatabase::database("n26");

    QSqlQuery *qry = new QSqlQuery(N26);
    qry->prepare("SELECT * FROM info");

    QSqlTableModel *model = new QSqlTableModel(this, N26);
    model->setTable("info");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("firstname"));
    model->setHeaderData(2, Qt::Horizontal, tr("lastname"));
    model->setHeaderData(3, Qt::Horizontal, tr("address"));
    model->setHeaderData(4, Qt::Horizontal, tr("email"));
    model->setHeaderData(5, Qt::Horizontal, tr("phone"));
    model->setHeaderData(6, Qt::Horizontal, tr("password"));
    model->setHeaderData(7, Qt::Horizontal, tr("account_number"));
    model->setHeaderData(8, Qt::Horizontal, tr("balance"));
    model->setHeaderData(9, Qt::Horizontal, tr("épargne"));

    ui->SqlView->setModel(model);

    if( !qry->exec() )  //affichage message d'erreur ou de succès
        QMessageBox::warning(this, tr("Problem"), qry->lastError().text());

    else
        QMessageBox::information(this, tr("Success"), tr("DB has been selected"));

}


void MainWindow::on_actionSolde_d_un_Compte_triggered() {
    // ouverture et affichage de la fenêtre
    Solde_Compte s;
    s.setModal(true);
    s.exec();
}


void MainWindow::on_actionNum_ro_de_compte_triggered() {
    // ouverture et affichage de la fenêtre
    Numero_Compte num;
    num.setModal(true);
    num.exec();
}


void MainWindow::on_actionD_pot_sur_un_Compte_triggered() {
    // ouverture et affichage de la fenêtre
    depot d;
    d.setModal(true);
    d.exec();
}

void MainWindow::on_actionRetrait_d_un_Compte_triggered() {
    // ouverture et affichage de la fenêtre
    retrait r;
    r.setModal(true);
    r.exec();
}


void MainWindow::on_actionVirement_triggered() {
    //ouverture et affichage de la fenêtre
    virement v;
    v.setModal(true);
    v.exec();
}


void MainWindow::on_action_pargne_triggered() {
    //ouverture et affichage de la fenêtre
    epargne e;
    e.setModal(true);
    e.exec();
}

