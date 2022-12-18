#include "mainwindow.h"
#include "dialog.h"
#include "fermer_compte.h"
#include "solde_compte.h"
#include "numero_compte.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/Images/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Ok_clicked()
{
    close();
}

void MainWindow::on_actionOuvrir_un_Compte_triggered()
{
    Dialog d;
    d.setModal(true);
    d.exec();
}

void MainWindow::on_Boursorama_clicked()
{

    QSqlDatabase BB = QSqlDatabase::database("bb");

    QSqlQuery *qry = new QSqlQuery(BB);
    qry->prepare( "SELECT * FROM info" );

    QSqlTableModel *model = new QSqlTableModel(this, BB);
    model->setTable("info");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("firstname"));
    model->setHeaderData(2, Qt::Horizontal, tr("lastname"));
    model->setHeaderData(3, Qt::Horizontal, tr("address"));
    model->setHeaderData(4, Qt::Horizontal, tr("email"));
    model->setHeaderData(5, Qt::Horizontal, tr("phone"));
    model->setHeaderData(6, Qt::Horizontal, tr("password"));
    model->setHeaderData(7, Qt::Horizontal, tr("account_number"));
    model->setHeaderData(8, Qt::Horizontal, tr("balance"));

    ui->SqlView->setModel(model);

    if( !qry->exec() )
      qDebug() << qry->lastError();

    else
      qDebug( "Selected!" );
}


void MainWindow::on_actionFermer_un_compte_triggered()
{
    Fermer_Compte f;
    f.setModal(true);
    f.exec();
}


void MainWindow::on_Revolut_clicked()
{
    QSqlDatabase RV = QSqlDatabase::database("rv");

    QSqlQuery *qry = new QSqlQuery(RV);

    QSqlTableModel *model = new QSqlTableModel(this, RV);
    model->setTable("info");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("firstname"));
    model->setHeaderData(2, Qt::Horizontal, tr("lastname"));
    model->setHeaderData(3, Qt::Horizontal, tr("address"));
    model->setHeaderData(4, Qt::Horizontal, tr("email"));
    model->setHeaderData(5, Qt::Horizontal, tr("phone"));
    model->setHeaderData(6, Qt::Horizontal, tr("password"));
    model->setHeaderData(7, Qt::Horizontal, tr("account_number"));
    model->setHeaderData(8, Qt::Horizontal, tr("balance"));

    ui->SqlView->setModel(model);

    //qry->prepare( "SELECT * FROM info" );
    if( !qry->exec() )
      qDebug() << qry->lastError();
    else
        qDebug( "Selected!" );
}


void MainWindow::on_N26_clicked()
{
    QSqlDatabase N26 = QSqlDatabase::database("n26");

    QSqlQuery *qry = new QSqlQuery(N26);

    QSqlTableModel *model = new QSqlTableModel(this, N26);
    model->setTable("info");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("firstname"));
    model->setHeaderData(2, Qt::Horizontal, tr("lastname"));
    model->setHeaderData(3, Qt::Horizontal, tr("address"));
    model->setHeaderData(4, Qt::Horizontal, tr("email"));
    model->setHeaderData(5, Qt::Horizontal, tr("phone"));
    model->setHeaderData(6, Qt::Horizontal, tr("password"));
    model->setHeaderData(7, Qt::Horizontal, tr("account_number"));
    model->setHeaderData(8, Qt::Horizontal, tr("balance"));

    ui->SqlView->setModel(model);

    qry->prepare( "SELECT * FROM info" );
    if( !qry->exec() )
      qDebug() << qry->lastError();

    else
      qDebug( "Selected!" );

}


void MainWindow::on_actionSolde_d_un_Compte_triggered()
{
    Solde_Compte s;
    s.setModal(true);
    s.exec();
}


void MainWindow::on_actionNum_ro_de_compte_triggered()
{
    Numero_Compte num;
    num.setModal(true);
    num.exec();
}

