#include "mainwindow.hpp"

using namespace std;

void connect(QString database) {
    // connexion à la base de données
    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL", database);
    DB.setHostName("127.0.0.1");
    DB.setUserName("root");
    DB.setDatabaseName(database);
    if (DB.open()) {
        // création de la table info si elle n'existe pas
        QSqlQuery *qry = new QSqlQuery(DB);
        if (qry->isActive()) {
            qry->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER, balance INTEGER)");
        } else {
            // si erreur de création de la table
            qWarning() << "ERROR: " << qry->lastError().text();
        }
        DB.close();
    } else {
        // si erreur de connexion
        qDebug() << DB.lastError().text();
        qFatal("Failed to connect!");
    }
}

int main(int argc, char *argv[]) {
    // application Qt
    QApplication a(argc, argv);

    // initialisation de la connexion socket
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    // attente de connexion
    if (socket.waitForConnected()) {

        // connexion et initialisation des bases de données
        thread boursorama(connect, "bb");
        thread revolut(connect, "rv");
        thread n26(connect, "n26");

        // attente de la fin des threads (synchronisation)
        boursorama.join();
        revolut.join();
        n26.join();

        // fermeture de la connexion socket
        socket.close();

    // si absence de connexion à la base de données
    } else {
        qDebug() << "Could not connect to the MySQL server";
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

    // affichage de l'interface graphique
    MainWindow w;
    w.show();

    // boucle d'évènements
    return a.exec();
}