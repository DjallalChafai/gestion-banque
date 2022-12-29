#include "epargne.h"
#include "ui_epargne.h"

epargne::epargne(QWidget *parent) : QDialog(parent), ui(new Ui::epargne)
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

epargne::~epargne()
{
    delete ui;
}


void epargne::on_Banque_highlighted(int index)
{
    switch (index){
        case 0:
            ui->taux->setText("Taux de 2%");
        break;

        case 1:
            ui->taux->setText("Taux de 1.5%");
        break;

        case 2:
            ui->taux->setText("Taux de 1.35%");
        break;
    }
}

void epargne::timer(){
    QString account_number1 = ui->account->text();
    QString amount = ui->amount->text();

    // connexion à la base de données
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    // création d'un timer pour l'épargne
    QTimer *timer = new QTimer(this);
    timer->start(10000);

    if(socket.waitForConnected()){

        if(timer->remainingTime() == 0){
            if(ui->Banque->currentText() == "Boursorama") {
                // sélection de la base de données
                QSqlDatabase BB = QSqlDatabase::database("bb");
                QSqlQuery *qry = new QSqlQuery(BB);
                QSqlQuery *qry2 = new QSqlQuery(BB);

                // requête SQL à la base de données
                qry2->prepare("SELECT balance FROM info WHERE account_number = ? AND epargne = 1");
                qry2->addBindValue(account_number1);
                qry2->exec();
                qDebug()<< qry2->result();

                //message d'erreur si le solde est nul
                if(qry2->result() == 0){
                    QMessageBox::warning(this, tr("Balance null"), tr("Your balance is null"));
                }

                // affichage du message réponse (si succès ou erreur)
                if (qry2->first() == true && amount.toInt() >= 0) {
                    qry->prepare("UPDATE info SET balance = balance + ? + ((balance + ?) * 2/100) WHERE account_number = ? AND epargne = 1");
                    qry->addBindValue(amount);
                    qry->addBindValue(account_number1);
                    qry->exec();
                }

                else if (qry2->first() == false) {
                    QMessageBox::warning(this, tr("We are sorry"), tr("Account could not be found!"));
                }
            }

            if(ui->Banque->currentText() == "N26") {
                // sélection de la base de données
                QSqlDatabase N26 = QSqlDatabase::database("n26");
                QSqlQuery *qry = new QSqlQuery(N26);
                QSqlQuery *qry2 = new QSqlQuery(N26);

                // requête SQL à la base de données
                qry2->prepare("SELECT balance FROM info WHERE account_number = ? AND epargne = 1");
                qry2->addBindValue(account_number1);
                qry2->exec();
                qDebug()<< qry2->first();

                // affichage du message réponse (si succès ou erreur)
                if (qry2->first() == true && amount.toInt() >= 0) {
                    qry->prepare("UPDATE info SET balance = balance + ? + ((balance + ?) * 1.5/100) WHERE account_number = ? AND epargne = 1");
                    qry->addBindValue(amount);
                    qry->addBindValue(account_number1);
                    qry->exec();
                }

                else if (qry2->first() == false) {
                    QMessageBox::warning(this, tr("We are sorry"), tr("Account could not be found!"));
                }
            }

            if(ui->Banque->currentText() == "Revolut") {
                // sélection de la base de données
                QSqlDatabase RV = QSqlDatabase::database("rv");
                QSqlQuery *qry = new QSqlQuery(RV);
                QSqlQuery *qry2 = new QSqlQuery(RV);

                // requête SQL à la base de données
                qry2->prepare("SELECT balance FROM info WHERE account_number = ? AND epargne = 1");
                qry2->addBindValue(account_number1);
                qry2->exec();
                qDebug()<< qry2->first();

                // affichage du message réponse (si succès ou erreur)
                if (qry2->first() == true && amount.toInt() >= 0) {
                    qry->prepare("UPDATE info SET balance = balance + ? + ((balance + ?) * 1.35/100) WHERE account_number = ? AND epargne = 1");
                    qry->addBindValue(amount);
                    qry->addBindValue(account_number1);
                    qry->exec();
                }

                else if (qry2->first() == false) {
                    QMessageBox::warning(this, tr("We are sorry"), tr("Account could not be found!"));
                }
            }
        }
        socket.close();
    }
}

void epargne::on_OK_clicked()
{
    QString account_number1 = ui->account->text();
    QString amount = ui->amount->text();

    // connexion à la base de données
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    // création d'un timer pour l'épargne
    QTimer *timer = new QTimer(this);
    timer->start(10000);

    if(socket.waitForConnected()){

        if(timer->remainingTime() == 0){
            if(ui->Banque->currentText() == "Boursorama") {
                // sélection de la base de données
                QSqlDatabase BB = QSqlDatabase::database("bb");
                QSqlQuery *qry = new QSqlQuery(BB);
                QSqlQuery *qry2 = new QSqlQuery(BB);

                // requête SQL à la base de données
                qry2->prepare("SELECT balance FROM info WHERE account_number = ? AND epargne = 1");
                qry2->addBindValue(account_number1);
                qry2->exec();
                qDebug()<< qry2->result();

                //message d'erreur si le solde est nul
                if(qry2->result() == 0){
                    QMessageBox::warning(this, tr("Balance null"), tr("Your balance is null"));
                }

                // affichage du message réponse (si succès ou erreur)
                if (qry2->first() == true && amount.toInt() >= 0) {
                    qry->prepare("UPDATE info SET balance = balance + ? + ((balance + ?) * 2/100) WHERE account_number = ? AND epargne = 1");
                    qry->addBindValue(amount);
                    qry->addBindValue(account_number1);
                    qry->exec();
                }

                else if (qry2->first() == false) {
                    QMessageBox::warning(this, tr("We are sorry"), tr("Account could not be found!"));
                }
            }

            if(ui->Banque->currentText() == "N26") {
                // sélection de la base de données
                QSqlDatabase N26 = QSqlDatabase::database("n26");
                QSqlQuery *qry = new QSqlQuery(N26);
                QSqlQuery *qry2 = new QSqlQuery(N26);

                // requête SQL à la base de données
                qry2->prepare("SELECT balance FROM info WHERE account_number = ? AND epargne = 1");
                qry2->addBindValue(account_number1);
                qry2->exec();
                qDebug()<< qry2->first();

                // affichage du message réponse (si succès ou erreur)
                if (qry2->first() == true && amount.toInt() >= 0) {
                    qry->prepare("UPDATE info SET balance = balance + ? + ((balance + ?) * 1.5/100) WHERE account_number = ? AND epargne = 1");
                    qry->addBindValue(amount);
                    qry->addBindValue(account_number1);
                    qry->exec();
                }

                else if (qry2->first() == false) {
                    QMessageBox::warning(this, tr("We are sorry"), tr("Account could not be found!"));
                }
            }

            if(ui->Banque->currentText() == "Revolut") {
                // sélection de la base de données
                QSqlDatabase RV = QSqlDatabase::database("rv");
                QSqlQuery *qry = new QSqlQuery(RV);
                QSqlQuery *qry2 = new QSqlQuery(RV);

                // requête SQL à la base de données
                qry2->prepare("SELECT balance FROM info WHERE account_number = ? AND epargne = 1");
                qry2->addBindValue(account_number1);
                qry2->exec();
                qDebug()<< qry2->first();

                // affichage du message réponse (si succès ou erreur)
                if (qry2->first() == true && amount.toInt() >= 0) {
                    qry->prepare("UPDATE info SET balance = balance + ? + ((balance + ?) * 1.35/100) WHERE account_number = ? AND epargne = 1");
                    qry->addBindValue(amount);
                    qry->addBindValue(account_number1);
                    qry->exec();
                }

                else if (qry2->first() == false) {
                    QMessageBox::warning(this, tr("We are sorry"), tr("Account could not be found!"));
                }
            }
        }
        socket.close();
    }
}


void epargne::on_Cancel_clicked()
{
    close();
}

