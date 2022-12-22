#include "numero_compte.h"
#include "ui_numero_compte.h"

Numero_Compte::Numero_Compte(QWidget *parent) : QDialog(parent), ui(new Ui::Numero_Compte) {
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

Numero_Compte::~Numero_Compte() {
    // destruction de l'interface graphique
    delete ui;
}

void Numero_Compte::on_Annuler_clicked() {
    // fermeture de la fenêtre
    close();
}


void Numero_Compte::on_Ok_clicked() {
    // récupération des données entrées par l'utilisateur
    QString email = ui->email->text();
    QString password = ui->password->text();

    // initialisation de la connexion socket
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    // attente de connexion
    if (socket.waitForConnected()) {
        if(ui->Banque->currentText() == "Boursorama") {
            // connexion à la base de données
            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);

            // affichage du solde
            QSqlTableModel *model = new QSqlTableModel(this, BB);
            model->setTable("info");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->select();

            // requête SQL
            qry->prepare("SELECT account_number FROM info WHERE email = ? AND password = ?");
            qry->addBindValue(email);
            qry->addBindValue(password);
            qry->exec();

            // affichage du résultat de la requête
            ui->tableView->setModel(model);

            // masquage des colonnes inutiles
            ui->tableView->setColumnHidden(0,true);
            ui->tableView->setColumnHidden(1,true);
            ui->tableView->setColumnHidden(2,true);
            ui->tableView->setColumnHidden(3,true);
            ui->tableView->setColumnHidden(4,true);
            ui->tableView->setColumnHidden(5,true);
            ui->tableView->setColumnHidden(6,true);
            ui->tableView->setColumnHidden(8,true);

            // affichage d'un message de succès
            if (qry->first() == true) {
                QMessageBox::information(this, tr("Success"), tr("Data was successfully found into the DB"));
            }

            // affichage d'un message d'erreur
            else {
                QMessageBox::warning(this, tr("Problem"), tr("Data was not found into the DB"));
            }
        }

        if (ui->Banque->currentText() == "Revolut") {
            QSqlDatabase RV = QSqlDatabase::database("rv");
            QSqlQuery *qry = new QSqlQuery(RV);

            QSqlTableModel *model = new QSqlTableModel(this, RV);
            model->setTable("info");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->select();

            qry->prepare("SELECT account_number FROM info WHERE email = ? AND password = ?");
            qry->addBindValue(email);
            qry->addBindValue(password);
            qry->exec();

            ui->tableView->setModel(model);

            ui->tableView->setColumnHidden(0,true);
            ui->tableView->setColumnHidden(3,true);
            ui->tableView->setColumnHidden(4,true);
            ui->tableView->setColumnHidden(5,true);
            ui->tableView->setColumnHidden(6,true);
            ui->tableView->setColumnHidden(8,true);

            // affichage d'un message de succès
            if (qry->first() == true) {
                QMessageBox::information(this, tr("Success"), tr("Data was successfully found into the DB"));
            }

            // affichage d'un message d'erreur
            else {
                QMessageBox::warning(this, tr("Problem"), tr("Data was not found into the DB"));
            }
        }

        if (ui->Banque->currentText() == "N26") {
            QSqlDatabase N26 = QSqlDatabase::database("n26");
            QSqlQuery *qry = new QSqlQuery(N26);

            QSqlTableModel *model = new QSqlTableModel(this, N26);
            model->setTable("info");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->select();

            qry->prepare("SELECT account_number FROM info WHERE email = ? AND password = ?");
            qry->addBindValue(email);
            qry->addBindValue(password);
            qry->exec();

            ui->tableView->setModel(model);

            ui->tableView->setColumnHidden(0,true);
            ui->tableView->setColumnHidden(1,true);
            ui->tableView->setColumnHidden(2,true);
            ui->tableView->setColumnHidden(3,true);
            ui->tableView->setColumnHidden(4,true);
            ui->tableView->setColumnHidden(5,true);
            ui->tableView->setColumnHidden(6,true);
            ui->tableView->setColumnHidden(8,true);

            // affichage d'un message de succès
            if (qry->first() == true) {
                QMessageBox::information(this, tr("Success"), tr("Data was successfully found into the DB"));
            }

            // affichage d'un message d'erreur
            else {
                QMessageBox::warning(this, tr("Problem"), tr("Data was not found into the DB"));
            }
        }

        // fermeture de la connexion socket
        socket.close();
    }

    else {
        // affichage d'un message d'erreur
        QMessageBox::critical(this, tr("Problem"), tr("Could not connect to the MySQL server"));
    }
}
