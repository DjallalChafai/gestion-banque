#include "mainwindow.hpp"

int main(int argc, char *argv[]) {
    // application Qt
    QApplication a(argc, argv);

    // initialisation de la connexion socket
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    // attente de connexion
    if (socket.waitForConnected()) {

        // base de données Boursorama
        QSqlDatabase BB = QSqlDatabase::addDatabase("QMYSQL", "bb");
        BB.setHostName("127.0.0.1");
        BB.setUserName("root");
        BB.setDatabaseName("bb");
        BB.open();
        if (BB.open()) {
            QSqlQuery *qry1 = new QSqlQuery(BB);
            if (qry1->isActive()) {
                qry1->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER, balance INTEGER)");
            } else {
                qWarning() << "ERROR: " << qry1->lastError().text();
            }
            BB.close();
        } else {
            qDebug() << BB.lastError().text();
            qFatal("Failed to connect!");
        }

        // base de données Revolut
        QSqlDatabase RV = QSqlDatabase::addDatabase("QMYSQL", "rv");
        RV.setHostName("127.0.0.1");
        RV.setUserName("root");
        RV.setDatabaseName("rv");
        RV.open();
        if (RV.open()) {
            QSqlQuery *qry2 = new QSqlQuery(RV);
            if (qry2->isActive()) {
                qry2->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER, balance INTEGER)");
            } else {
                qWarning() << "ERROR: " << qry2->lastError().text();
            }
            RV.close();
        } else {
            qDebug() << RV.lastError().text();
            qFatal("Failed to connect!");
        }

        // base de données N26
        QSqlDatabase N26 = QSqlDatabase::addDatabase("QMYSQL", "n26");
        N26.setHostName("127.0.0.1");
        N26.setUserName("root");
        N26.setDatabaseName("n26");
        N26.open();
        if (N26.open()) {
            QSqlQuery *qry3 = new QSqlQuery(N26);
            if (qry3->isActive()) {
                qry3->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER, balance INTEGER)");
            } else {
                qWarning() << "ERROR: " << qry3->lastError().text();
            }
            BB.close();
        } else {
            qDebug() << N26.lastError().text();
            qFatal("Failed to connect!");
        }
        socket.close();

    // si absence de connexion à la base de données
    } else {
        qFatal("Could not connect to MySQL server!");
    }

    // traductions et textes pour l'interface graphique
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.show();

    return a.exec();
}
