#include "mainwindow.h"

class SqlThread : public QThread {
    //Q_OBJECT
    public:
        SqlThread(QSqlDatabase db, QObject *parent = nullptr) : QThread(parent), m_db(db) {}
    protected:
        void run() override {
            QSqlQuery query(m_db);
            query.exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY AUTO_INCREMENT, firstname VARCHAR(30), lastname VARCHAR(30), address VARCHAR(30), email VARCHAR(30), phone INTEGER, password VARCHAR(30), account_number INTEGER, balance INTEGER, epargne BOOLEAN NOT NULL DEFAULT 0)");
        }
    private:
        QSqlDatabase m_db;
};

int main(int argc, char *argv[]) {
    // application Qt
    QApplication a(argc, argv);

    // initialisation de la connexion socket
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    // attente de connexion
    if (socket.waitForConnected()) {

        // création de la base de données n°1 (boursorama)
        QSqlDatabase db1 = QSqlDatabase::addDatabase("QMYSQL", "bb");
        // connexion à la base de données
        db1.setHostName("127.0.0.1");
        db1.setUserName("root");
        db1.setDatabaseName("bb");
        if (!db1.open()) {
            QMessageBox::warning(0, QMessageBox::tr("Problem"), db1.lastError().text());
        } else {
            // création de la table "info" dans la base de données n°1 dans un thread séparé
            SqlThread *thread1 = new SqlThread(db1);
            thread1->start();
        }

        // création de la base de données n°2 (revolut)
        QSqlDatabase db2 = QSqlDatabase::addDatabase("QMYSQL", "rv");
        // connexion à la base de données
        db2.setHostName("127.0.0.1");
        db2.setUserName("root");
        db2.setDatabaseName("rv");
        if (!db2.open()) {
            QMessageBox::warning(0, QMessageBox::tr("Problem"), db2.lastError().text());
        } else {
            // création de la table "info" dans la base de données n°2 dans un thread séparé
            SqlThread *thread2 = new SqlThread(db2);
            thread2->start();
        }

        // création de la base de données n°3 (n26)
        QSqlDatabase db3 = QSqlDatabase::addDatabase("QMYSQL", "n26");
        // connexion à la base de données
        db3.setHostName("127.0.0.1");
        db3.setUserName("root");
        db3.setDatabaseName("n26");
        if (!db3.open()) {
            QMessageBox::warning(0, QMessageBox::tr("Problem"), db3.lastError().text());
        } else {
            // création de la table "info" dans la base de données n°2 dans un thread séparé
            SqlThread *thread3 = new SqlThread(db3);
            thread3->start();
        }

        // fermeture de la connexion socket
        socket.close();
    } else {
        // si absence de connexion à la base de données
        QMessageBox msgBox;
        msgBox.setWindowTitle(QMessageBox::tr("Failed to connect!"));
        msgBox.setText(QMessageBox::tr("Could not connect to the MySQl server."));
        msgBox.setInformativeText(QMessageBox::tr("Make sure that MySQL server is running and you have entered the correct connection parameters."));
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.exec();
		qDebug() << "coucou";
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
