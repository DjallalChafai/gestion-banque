#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    if(socket.waitForConnected()){
        qDebug() << "wsh bg";

        QSqlDatabase RV = QSqlDatabase::addDatabase("QMYSQL", "rv");
        RV.setHostName("127.0.0.1");
        RV.setUserName("root");
        RV.setDatabaseName("rv");

        QSqlDatabase BB = QSqlDatabase::addDatabase("QMYSQL", "bb");
        BB.setHostName("127.0.0.1");
        BB.setUserName("root");
        BB.setDatabaseName("bb");

        QSqlDatabase N26 = QSqlDatabase::addDatabase("QMYSQL", "n26");
        N26.setHostName("127.0.0.1");
        N26.setUserName("root");
        N26.setDatabaseName("n26");

        BB.open();
        RV.open();
        N26.open();

        if( BB.open() && RV.open() && N26.open())
        {
            QSqlQuery *qry1 = new QSqlQuery(BB);
            QSqlQuery *qry2 = new QSqlQuery(RV);
            QSqlQuery *qry3 = new QSqlQuery(N26);

            qry1->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER)");
            qry2->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER)");
            qry3->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER)");

            if(!qry1->isActive()|| !qry2->isActive() || !qry3->isActive())
            {
                qWarning() << "ERROR: " << qry1->lastError().text();
                qWarning() << "ERROR: " << qry2->lastError().text();
                qWarning() << "ERROR: " << qry3->lastError().text();
            }

            BB.close();
            RV.close();
            N26.close();


        }

        else
        {
            qDebug() << BB.lastError().text();
            qDebug() << RV.lastError().text();
            qDebug() << N26.lastError().text();
            qFatal("Failed to Connect");
        }

        socket.close();
    }

    else
    {
        qDebug() << "Could not connect to the MySQL server";
    }

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
