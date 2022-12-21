#include "depot.hpp"
#include "ui_depot.h"

depot::depot(QWidget *parent) : QDialog(parent), ui(new Ui::depot) {
    ui->setupUi(this);
    QPixmap bkgnd(":/assets/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

depot::~depot() {
    delete ui;
}

void depot::on_button_rejected() {
    close();
}

void depot::on_button_accepted() {
    QString account_number1 = ui->account1->text();
    QString amount = ui->montant->text();

    // connexion à la base de données
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    if(socket.waitForConnected()){
        if(ui->Banque1->currentText() == "Boursorama") {
            // sélection de la base de données
            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);

            // requête SQL à la base de données
            qry->prepare("SELECT balance FROM info WHERE account_number = ?");
            qry->addBindValue(account_number1);
            qry->exec();
            qDebug()<< qry->first();

            // affichage du message réponse (si succès ou erreur)
            if (qry->first() == true) {
                QMessageBox::warning(this, tr("Thank you"), tr("Deposit was successfully done!"));

            } else {
                QMessageBox::warning(this, tr("We are sorry"), tr("Account could not be found!"));
            }
        }
        socket.close();
    }
}