#include "solde_compte.hpp"
#include "ui_solde_compte.h"

Solde_Compte::Solde_Compte(QWidget *parent) : QDialog(parent), ui(new Ui::Solde_Compte) {
    ui->setupUi(this);
    QPixmap bkgnd(":/assets/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

Solde_Compte::~Solde_Compte() {
    delete ui;
}

void Solde_Compte::on_Annuler_clicked() {
    close();
}


void Solde_Compte::on_Ok_clicked() {
    QString account_number = ui->account_number->text();
    QString password = ui->passwd->text();

    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    if(socket.waitForConnected()){
        if(ui->menu_deroulant->currentText() == "Boursorama") {
            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);

            QSqlTableModel *model = new QSqlTableModel(this, BB);
            model->setTable("info");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->select();

            qry->prepare("SELECT balance FROM info WHERE account_number = ? AND password = ?");
            qry->addBindValue(account_number);
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
            ui->tableView->setColumnHidden(7,true);

            if(qry->lastError().type() == QSqlError::NoError){
                qDebug() << "Data was successfully deleted into the DB";
            }
        }

        if(ui->menu_deroulant->currentText() == "Revolut"){
            QSqlDatabase RV = QSqlDatabase::database("rv");
            QSqlQuery *qry = new QSqlQuery(RV);

            QSqlTableModel *model = new QSqlTableModel(this, RV);
            model->setTable("info");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->select();

            qry->prepare("SELECT balance FROM info WHERE account_number = ? AND password = ?");
            qry->addBindValue(account_number);
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
            ui->tableView->setColumnHidden(7,true);

            if(qry->lastError().type() == QSqlError::NoError){
                qDebug() << "Data was successfully deleted into the DB";
            }
        }

        if(ui->menu_deroulant->currentText() == "N26") {
            QSqlDatabase N26 = QSqlDatabase::database("n26");
            QSqlQuery *qry = new QSqlQuery(N26);

            QSqlTableModel *model = new QSqlTableModel(this, N26);
            model->setTable("info");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->select();

            qry->prepare("SELECT balance FROM info WHERE account_number = ? AND password = ?");
            qry->addBindValue(account_number);
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
            ui->tableView->setColumnHidden(7,true);

            if(qry->lastError().type() == QSqlError::NoError){
                qDebug() << "Data was successfully deleted into the DB";
            }
        }

        socket.close();
    }

    else
    {
        qDebug() << "Could not connect to the MySQL server";
    }

}