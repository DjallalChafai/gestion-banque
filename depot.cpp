#include "depot.h"
#include "ui_depot.h"

depot::depot(QWidget *parent) : QDialog(parent), ui(new Ui::depot) {
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

depot::~depot() {
    // destruction de l'interface graphique
    delete ui;
}

void depot::on_button_rejected() {
    // fermeture de la fenêtre
    close();
}

void depot::on_button_accepted() {
    // récupération des données entrées par l'utilisateur
    QString account_number1 = ui->account1->text();
    QString amount = ui->montant->text();

    // connexion à la base de données
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    // attente de connexion
    if (socket.waitForConnected()) {
        if(ui->Banque1->currentText() == "Boursorama") {
            // sélection de la base de données
            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);
            QSqlQuery *qry2 = new QSqlQuery(BB);

            // requête SQL à la base de données
            qry2->prepare("SELECT balance FROM info WHERE account_number = ?");
            qry2->addBindValue(account_number1);
            qry2->exec();
            qDebug()<< qry2->first();

            // affichage du message réponse (si succès ou erreur)
            if (qry2->first() == true && amount.toInt() > 0) {
                QMessageBox::information(this, tr("Thank you"), tr("Deposit was successfully done!"));
                qry->prepare("UPDATE info SET balance = balance + ? WHERE account_number = ?");
                qry->addBindValue(amount);
                qry->addBindValue(account_number1);
                qry->exec();
            }

            else if (qry2->first() == false) {
                QMessageBox::warning(this, tr("We are sorry"), tr("Account could not be found!"));
            }

            else if (amount.toInt() < 0){
                QMessageBox::warning(this, tr("We are sorry"), tr("The amount could not be negative"));
            }
        }

        if(ui->Banque1->currentText() == "N26") {
            // sélection de la base de données
            QSqlDatabase N26 = QSqlDatabase::database("n26");
            QSqlQuery *qry = new QSqlQuery(N26);
            QSqlQuery *qry2 = new QSqlQuery(N26);

            // requête SQL à la base de données
            qry2->prepare("SELECT balance FROM info WHERE account_number = ?");
            qry2->addBindValue(account_number1);
            qry2->exec();
            qDebug()<< qry2->first();

            // affichage du message réponse (si succès ou erreur)
            if (qry2->first() == true && amount.toInt() > 0) {
                QMessageBox::information(this, tr("Thank you"), tr("Deposit was successfully done!"));
                qry->prepare("UPDATE info SET balance = balance + ? WHERE account_number = ?");
                qry->addBindValue(amount);
                qry->addBindValue(account_number1);
                qry->exec();
            }

            else if (qry2->first() == false) {
                QMessageBox::warning(this, tr("We are sorry"), tr("Account could not be found!"));
            }

            else if (amount.toInt() < 0){
                QMessageBox::warning(this, tr("We are sorry"), tr("The amount could not be negative"));
            }
        }

        if(ui->Banque1->currentText() == "Revolut") {
            // sélection de la base de données
            QSqlDatabase RV = QSqlDatabase::database("rv");
            QSqlQuery *qry = new QSqlQuery(RV);
            QSqlQuery *qry2 = new QSqlQuery(RV);

            // requête SQL à la base de données
            qry2->prepare("SELECT balance FROM info WHERE account_number = ?");
            qry2->addBindValue(account_number1);
            qry2->exec();
            qDebug()<< qry2->first();

            // affichage du message réponse (si succès ou erreur)
            if (qry2->first() == true && amount.toInt() > 0) {
                QMessageBox::information(this, tr("Thank you"), tr("Deposit was successfully done!"));
                qry->prepare("UPDATE info SET balance = balance + ? WHERE account_number = ?");
                qry->addBindValue(amount);
                qry->addBindValue(account_number1);
                qry->exec();
            }

            else if (qry2->first() == false) {
                QMessageBox::warning(this, tr("We are sorry"), tr("Account could not be found!"));
            }

            else if (amount.toInt() < 0){
                QMessageBox::warning(this, tr("We are sorry"), tr("The amount could not be negative"));
            }
        }

        // fermeture de la connexion socket
        socket.close();
    }
}
