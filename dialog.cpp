#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
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

Dialog::~Dialog() {
    // destruction de l'interface graphique
    delete ui;
}

void Dialog::on_Annuler_clicked() {
    // fermeture de la fenêtre
    close();
}


void Dialog::on_Ok_clicked() {
    // récupération des données entrées par l'utilisateur
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    // attente de connexion
    if (socket.waitForConnected()) {
        QString firstName = ui->firstName->text();
        QString lastName = ui->lastName->text();
        QString address = ui->address->text();
        QString email = ui->email->text();
        QString phone = ui->phone->text();
        QString password = ui->password->text();
        
        if (ui->Banque->currentText() == "Boursorama") {
            int r = 0;
            r = rand() % 1000000000 + 10000000000;

            int b = 100;

            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);

            qry->prepare("INSERT INTO info (firstname, lastname, address, email, phone, password, account_number, balance) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
            qry->addBindValue(firstName);
            qry->addBindValue(lastName);
            qry->addBindValue(address);
            qry->addBindValue(email);
            qry->addBindValue(phone);
            qry->addBindValue(password);
            qry->addBindValue(r);
            qry->addBindValue(b);
            qry->exec();

            if(qry->lastError().type() == QSqlError::NoError) {
                QMessageBox::information(this, tr("Success"), tr("Data was successfully inserted into the DB"));
            }

            if(!qry->isActive()) {
                QMessageBox::critical(this, tr("Problem"), qry->lastError().text());
            }
        }

        if(ui->Banque->currentText() == "Revolut") {
            int r = 0;
            r = rand() % 1000000000 + 10000000000;

            int b = 100;

            QSqlDatabase RV = QSqlDatabase::database("rv");
            QSqlQuery *qry = new QSqlQuery(RV);

            qry->prepare("INSERT INTO info (firstname, lastname, address, email, phone, password, account_number, balance) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
            qry->addBindValue(firstName);
            qry->addBindValue(lastName);
            qry->addBindValue(address);
            qry->addBindValue(email);
            qry->addBindValue(phone);
            qry->addBindValue(password);
            qry->addBindValue(r);
            qry->addBindValue(b);
            qry->exec();

            if(qry->lastError().type() == QSqlError::NoError){
                QMessageBox::information(this, tr("Success"), tr("Data was successfully inserted into the DB"));
            }

            if(!qry->isActive())
            {
                QMessageBox::critical(this, tr("Problem"), qry->lastError().text());
            }
        }

        if(ui->Banque->currentText() == "N26"){
            int r = 0;
            r = rand() % 1000000000 + 10000000000;

            int b = 100;

            QSqlDatabase N26 = QSqlDatabase::database("n26");
            QSqlQuery *qry = new QSqlQuery(N26);

            qry->prepare("INSERT INTO info (firstname, lastname, address, email, phone, password, account_number, balance) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
            qry->addBindValue(firstName);
            qry->addBindValue(lastName);
            qry->addBindValue(address);
            qry->addBindValue(email);
            qry->addBindValue(phone);
            qry->addBindValue(password);
            qry->addBindValue(r);
            qry->addBindValue(b);
            qry->exec();

            if(qry->lastError().type() == QSqlError::NoError) {
                QMessageBox::information(this, tr("Success"), tr("Data was successfully inserted into the DB"));
            }

            if(!qry->isActive())
            {
                QMessageBox::critical(this, tr("Problem"), qry->lastError().text());
            }
        }

        // fermeture de la fenêtre
        socket.close();
    } else {
        // affichage d'un message d'erreur
        QMessageBox::critical(this, tr("Problem"), tr("Could not connect to the MySQL server"));
    }

    // fermeture de la fenêtre
    close();
}
