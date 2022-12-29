#include "virement.h"
#include "ui_virement.h"

virement::virement(QWidget *parent) : QDialog(parent), ui(new Ui::virement)
{
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

virement::~virement()
{
    delete ui;
}

void virement::on_buttonBox_rejected()
{
    close();
}


void virement::on_buttonBox_accepted()
{
    QString account_number1 = ui->account_number1->text();
    QString account_number2 = ui->account_number2->text();
    QString amount = ui->Amount->text();

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
            if (qry2->first() == true && amount.toInt() >= 0) {
                qry->prepare("UPDATE info SET balance = balance - ? WHERE account_number = ?");
                qry->addBindValue(amount);
                qry->addBindValue(account_number1);
                qry->exec();
            }

            else if (qry2->first() == false) {
                QMessageBox::warning(this, tr("We are sorry"), tr("Account1 could not be found!"));
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
            if (qry2->first() == true && amount.toInt() >= 0) {
                qry->prepare("UPDATE info SET balance = balance - ? WHERE account_number = ?");
                qry->addBindValue(amount);
                qry->addBindValue(account_number1);
                qry->exec();
            }

            else if (qry2->first() == false) {
                QMessageBox::warning(this, tr("We are sorry"), tr("Account1 could not be found!"));
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
            if (qry2->first() == true && amount.toInt() >= 0) {
                qry->prepare("UPDATE info SET balance = balance - ? WHERE account_number = ?");
                qry->addBindValue(amount);
                qry->addBindValue(account_number1);
                qry->exec();
            }

            else if (qry2->first() == false) {
                QMessageBox::warning(this, tr("We are sorry"), tr("Account1 could not be found!"));
            }
        }

        if(ui->Banque2->currentText() == "Boursorama") {
            // sélection de la base de données
            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);
            QSqlQuery *qry2 = new QSqlQuery(BB);

            // requête SQL à la base de données
            qry2->prepare("SELECT balance FROM info WHERE account_number = ?");
            qry2->addBindValue(account_number2);
            qry2->exec();
            qDebug()<< qry2->first();

            // affichage du message réponse (si succès ou erreur)
            if (qry2->first() == true && amount.toInt() >= 0) {
                QMessageBox::information(this, tr("Thank you"), tr("Transfer was successfully done!"));
                qry->prepare("UPDATE info SET balance = balance + ? WHERE account_number = ?");
                qry->addBindValue(amount);
                qry->addBindValue(account_number2);
                qry->exec();
            }

            else if (qry2->first() == false) {
                QMessageBox::warning(this, tr("We are sorry"), tr("Account2 could not be found!"));
            }

            else if (amount.toInt() < 0){
                QMessageBox::warning(this, tr("We are sorry"), tr("The amount could not be negative or null"));
            }
        }

        if(ui->Banque2->currentText() == "N26") {
            // sélection de la base de données
            QSqlDatabase N26 = QSqlDatabase::database("n26");
            QSqlQuery *qry = new QSqlQuery(N26);
            QSqlQuery *qry2 = new QSqlQuery(N26);

            // requête SQL à la base de données
            qry2->prepare("SELECT balance FROM info WHERE account_number = ?");
            qry2->addBindValue(account_number2);
            qry2->exec();
            qDebug()<< qry2->first();

            // affichage du message réponse (si succès ou erreur)
            if (qry2->first() == true && amount.toInt() >= 0) {
                QMessageBox::information(this, tr("Thank you"), tr("Transfer was successfully done!"));
                qry->prepare("UPDATE info SET balance = balance + ? WHERE account_number = ?");
                qry->addBindValue(amount);
                qry->addBindValue(account_number2);
                qry->exec();
            }

            else if (qry2->first() == false) {
                QMessageBox::warning(this, tr("We are sorry"), tr("Account2 could not be found!"));
            }

            else if (amount.toInt() < 0){
                QMessageBox::warning(this, tr("We are sorry"), tr("The amount could not be negative or null"));
            }
        }

        if(ui->Banque2->currentText() == "Revolut") {
            // sélection de la base de données
            QSqlDatabase RV = QSqlDatabase::database("rv");
            QSqlQuery *qry = new QSqlQuery(RV);
            QSqlQuery *qry2 = new QSqlQuery(RV);

            // requête SQL à la base de données
            qry2->prepare("SELECT balance FROM info WHERE account_number = ?");
            qry2->addBindValue(account_number2);
            qry2->exec();
            qDebug()<< qry2->first();

            // affichage du message réponse (si succès ou erreur)
            if (qry2->first() == true && amount.toInt() >= 0) {
                QMessageBox::information(this, tr("Thank you"), tr("Transfer was successfully done!"));
                qry->prepare("UPDATE info SET balance = balance + ? WHERE account_number = ?");
                qry->addBindValue(amount);
                qry->addBindValue(account_number2);
                qry->exec();
            }

            else if (qry2->first() == false) {
                QMessageBox::warning(this, tr("We are sorry"), tr("Account2 could not be found!"));
            }

            else if (amount.toInt() < 0){
                QMessageBox::warning(this, tr("We are sorry"), tr("The amount could not be negative or null"));
            }
        }

        // fermeture de la connexion socket
        socket.close();
    }
}

