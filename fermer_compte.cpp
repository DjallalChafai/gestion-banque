#include "fermer_compte.hpp"
#include "ui_fermer_compte.h"

Fermer_Compte::Fermer_Compte(QWidget *parent) : QDialog(parent), ui(new Ui::Fermer_Compte) {
    ui->setupUi(this);
    QPixmap bkgnd(":/assets/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

Fermer_Compte::~Fermer_Compte() {
    delete ui;
}

void Fermer_Compte::on_Annuler_clicked() {
    close();
}

void Fermer_Compte::on_Ok_clicked() {
    QString email = ui->email->text();
    QString password = ui->password->text();

    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    qDebug() << email << password;

    if(socket.waitForConnected()){
        if(ui->Banque->currentText() == "Boursorama") {
            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);

            qry->prepare( "DELETE FROM info WHERE email = ? AND password = ?" );
            qry->addBindValue(email);
            qry->addBindValue(password);
            qry->exec();

            if(qry->lastError().type() == QSqlError::NoError){
                qDebug() << "Data was successfully deleted into the DB";
            }
        }

        if(ui->Banque->currentText() == "Revolut") {
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

        if(ui->Banque->currentText() == "N26") {
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

        socket.close();
    }

    else {
        qDebug() << "Could not connect to the MySQL server";
    }

    close();
}