#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
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

    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    qDebug() << firstName << lastName;
    QSqlQuery qry;
    if(ui->Banque->currentText() == "Boursorama"){
        qDebug() << "Wsh mon reuf";
    }
    qry.prepare( "INSERT INTO info (firstname, lastname) VALUES (?, ?)" );
    qry.addBindValue(firstName);
    qry.addBindValue(lastName);
    qry.exec();
}

