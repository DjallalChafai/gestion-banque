#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QTcpSocket socket;

    //socket.connectToHost("localhost", 1234);

//    QDir databasePath;
//    QString path1 = databasePath.currentPath()+"BB.db";
//    QString path2 = databasePath.currentPath()+"RV.db";
//    QString path3 = databasePath.currentPath()+"N26.db";

    QSqlDatabase RV = QSqlDatabase::addDatabase("QSQLITE", "RV");
    RV.setHostName("127.0.0.1");
    RV.setPort(1234);

    QSqlDatabase BB = QSqlDatabase::addDatabase("QSQLITE", "BB");
    BB.setHostName("127.0.0.1");
    BB.setPort(1234);

    QSqlDatabase N26 = QSqlDatabase::addDatabase("QSQLITE", "N26");
    N26.setHostName("127.0.0.1");
    N26.setPort(1234);

//    BB.setDatabaseName(path1);
//    RV.setDatabaseName(path2);
//    N26.setDatabaseName(path3);


    BB.open();
    RV.open();
    N26.open();

    if( !BB.open() || !RV.open() || !N26.open())
    {
        qDebug() << BB.lastError();
        qDebug() << RV.lastError();
        qDebug() << N26.lastError();
        qFatal("Failed to Connect");
    }


    else
        qDebug("Connected!");

    QSqlQuery *qry1 = new QSqlQuery(BB);
//    if(socket.waitForConnected()){
//     socket.write("SELECT * FROM BB_info");
//    }

//    if(socket.waitForReadyRead()){
//        QByteArray response = socket.readAll();
//        qDebug() << "Réponse du Serveur: " << response;
//    }

    QSqlQuery *qry2 = new QSqlQuery(RV);
    QSqlQuery *qry3 = new QSqlQuery(N26);

    qry1->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER)");
    qry2->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER)");
    qry3->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER)");

//    qry1->exec("DROP TABLE info");
//    qry2->exec("DROP TABLE info");
//    qry3->exec("DROP TABLE info");
    if(!qry1->isActive() || !qry2->isActive() || !qry3->isActive())
    {
        qWarning() << "ERROR: " << qry1->lastError().text();
        qWarning() << "ERROR: " << qry2->lastError().text();
        qWarning() << "ERROR: " << qry3->lastError().text();
    }

    qry1->finish();

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Projet_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.show();

    return a.exec();
}
