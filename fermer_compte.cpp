#include "fermer_compte.h"
#include "ui_fermer_compte.h"

Fermer_Compte::Fermer_Compte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fermer_Compte)
{
    ui->setupUi(this);
}

Fermer_Compte::~Fermer_Compte()
{
    delete ui;
}

void Fermer_Compte::on_Annuler_clicked()
{
    close();
}


void Fermer_Compte::on_Ok_clicked()
{
    QString email = ui->email->text();
    QString password = ui->password->text();

    qDebug() << email << password;

    if(ui->Banque->currentText() == "Boursorama"){
        QSqlDatabase BB = QSqlDatabase::database("BB");
        QSqlQuery *qry = new QSqlQuery(BB);

        qry->prepare( "DELETE FROM info WHERE email = ? AND password = ?" );
        qry->addBindValue(email);
        qry->addBindValue(password);
        qry->exec();


        qDebug() << "Salut mon Bou";
    }

    if(ui->Banque->currentText() == "Revolut"){
        QSqlDatabase RV = QSqlDatabase::database("RV");
        QSqlQuery *qry = new QSqlQuery(RV);

        qry->prepare( "DELETE FROM info WHERE email = ? AND password = ?" );
        qry->addBindValue(email);
        qry->addBindValue(password);
        qry->exec();


        qDebug() << "Salut mon reuv";
    }

    if(ui->Banque->currentText() == "N26"){
        QSqlDatabase N26 = QSqlDatabase::database("N26");
        QSqlQuery *qry = new QSqlQuery(N26);

        qry->prepare( "DELETE FROM info WHERE email = ? AND password = ?" );
        qry->addBindValue(email);
        qry->addBindValue(password);
        qry->exec();


        qDebug() << "Salut mon Nigger";
    }

    close();
}

