#include "fermer_compte.hpp"
#include "ui_fermer_compte.h"

Fermer_Compte::Fermer_Compte(QWidget *parent) : QDialog(parent), ui(new Ui::Fermer_Compte) {
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

Fermer_Compte::~Fermer_Compte() {
    // destruction de l'interface graphique
    delete ui;
}

void Fermer_Compte::on_Annuler_clicked() {
    // fermeture de la fenêtre
    close();
}

void Fermer_Compte::on_Ok_clicked() {
    // récupération des données entrées par l'utilisateur
    QString email = ui->email->text();
    QString password = ui->password->text();

    // initialisation de la connexion socket
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    // attente de connexion
    if (socket.waitForConnected()) {
        if (ui->Banque->currentText() == "Boursorama") {
            // connexion à la base de données
            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);

            // requête SQL
            qry->prepare( "DELETE FROM info WHERE email = ? AND password = ?" );
            qry->addBindValue(email);
            qry->addBindValue(password);
            qry->exec();

            // affichage du résultat de la requête
            if(qry->lastError().type() == QSqlError::NoError) {
                qDebug() << "Data was successfully deleted into the DB";
            }
        }

        if (ui->Banque->currentText() == "Revolut") {
            QSqlDatabase RV = QSqlDatabase::database("rv");
            QSqlQuery *qry = new QSqlQuery(RV);

            qry->prepare( "DELETE FROM info WHERE email = ? AND password = ?" );
            qry->addBindValue(email);
            qry->addBindValue(password);
            qry->exec();

            if(qry->lastError().type() == QSqlError::NoError) {
                qDebug() << "Data was successfully deleted into the DB";
            }
        }

        if (ui->Banque->currentText() == "N26") {
            QSqlDatabase N26 = QSqlDatabase::database("n26");
            QSqlQuery *qry = new QSqlQuery(N26);

            qry->prepare( "DELETE FROM info WHERE email = ? AND password = ?" );
            qry->addBindValue(email);
            qry->addBindValue(password);
            qry->exec();

            if(qry->lastError().type() == QSqlError::NoError) {
                qDebug() << "Data was successfully deleted into the DB";
            }
        }

        // fermeture de la connexion socket
        socket.close();
    } else {
        // affichage d'un message d'erreur
        qDebug() << "Could not connect to the MySQL server";
    }

    // fermeture de la fenêtre
    close();
}