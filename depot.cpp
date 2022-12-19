#include "depot.h"
#include "ui_depot.h"

depot::depot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depot)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/Images/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

depot::~depot()
{
    delete ui;
}

void depot::on_button_rejected()
{
    close();
}


void depot::on_button_accepted()
{
    QString account_number1 = ui->account1->text();
    QString amount = ui->montant->text();

    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    if(socket.waitForConnected()){
        if(ui->Banque1->currentText() == "Boursorama"){
            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);

            qry->prepare("SELECT balance FROM info WHERE account_number = ?");
            qry->addBindValue(account_number1);
            qry->exec();
            qDebug()<< qry->first();

            if(qry->first() == true){
                QMessageBox::warning(this, tr("Thank you"), tr("Deposit was successfully done"));

            }

            else if (qry->first() == false){
                QMessageBox::warning(this, tr("We are sorry"), tr("Account1 could not be found"));
            }
        }
        socket.close();
    }
}

