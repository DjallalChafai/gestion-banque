#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/Images/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Annuler_clicked()
{
    close();
}


void Dialog::on_Ok_clicked()
{
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    if(socket.waitForConnected()){
        QString firstName = ui->firstName->text();
        QString lastName = ui->lastName->text();
        QString address = ui->address->text();
        QString email = ui->email->text();
        QString phone = ui->phone->text();
        QString password = ui->password->text();


        qDebug() << firstName << lastName;

        if(ui->Banque->currentText() == "Boursorama"){
            int r = 0;
            r = rand() % 1000000000 + 10000000000;

            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);

            qry->prepare( "INSERT INTO info (firstname, lastname, address, email, phone, password, account_number) VALUES (?, ?, ?, ?, ?, ?, ?)" );
            qry->addBindValue(firstName);
            qry->addBindValue(lastName);
            qry->addBindValue(address);
            qry->addBindValue(email);
            qry->addBindValue(phone);
            qry->addBindValue(password);
            qry->addBindValue(r);
            qry->exec();

            if(qry->lastError().type() == QSqlError::NoError){
                qDebug() << "Data was successfully inserted into the DB";
            }

            if(!qry->isActive())
            {
                qWarning() << "ERROR: " << qry->lastError().text();
            }


            qDebug() << "Wsh mon Bou";
        }

        if(ui->Banque->currentText() == "Revolut"){
            int r = 0;
            r = rand() % 1000000000 + 10000000000;

            QSqlDatabase RV = QSqlDatabase::database("rv");
            QSqlQuery *qry = new QSqlQuery(RV);

            qry->prepare( "INSERT INTO info (firstname, lastname, address, email, phone, password, account_number) VALUES (?, ?, ?, ?, ?, ?, ?)" );
            qry->addBindValue(firstName);
            qry->addBindValue(lastName);
            qry->addBindValue(address);
            qry->addBindValue(email);
            qry->addBindValue(phone);
            qry->addBindValue(password);
            qry->addBindValue(r);
            qry->exec();

            if(qry->lastError().type() == QSqlError::NoError){
                qDebug() << "Data was successfully inserted into the DB";
            }

            if(!qry->isActive())
            {
                qWarning() << "ERROR: " << qry->lastError().text();
            }


            qDebug() << "Wsh mon reuv";
        }

        if(ui->Banque->currentText() == "N26"){
            int r = 0;
            r = rand() % 1000000000 + 10000000000;

            QSqlDatabase N26 = QSqlDatabase::database("n26");
            QSqlQuery *qry = new QSqlQuery(N26);

            qry->prepare( "INSERT INTO info (firstname, lastname, address, email, phone, password, account_number) VALUES (?, ?, ?, ?, ?, ?, ?)" );
            qry->addBindValue(firstName);
            qry->addBindValue(lastName);
            qry->addBindValue(address);
            qry->addBindValue(email);
            qry->addBindValue(phone);
            qry->addBindValue(password);
            qry->addBindValue(r);
            qry->exec();

            if(qry->lastError().type() == QSqlError::NoError){
                qDebug() << "Data was successfully inserted into the DB";
            }

            if(!qry->isActive())
            {
                qWarning() << "ERROR: " << qry->lastError().text();
            }


            qDebug() << "Wsh mon Nigger";
        }

        socket.close();
    }

    else
    {
        qDebug() << "Could not connect to the MySQL server";
    }

    close();
}

