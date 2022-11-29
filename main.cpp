#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qDebug() << QSqlDatabase::drivers();


    //QSqlDatabase BB = QSqlDatabase::addDatabase("QSQLITE", "BB");

    QDir databasePath;
    QString path = databasePath.currentPath()+"BB.db";
    QSqlDatabase BB = QSqlDatabase::addDatabase("QSQLITE");
    BB.setDatabaseName(path);
    BB.open();

    if( !BB.open())
    {
        qDebug() << BB.lastError();
        qFatal("Failed to Connect");
    }

    QSqlQuery *qry = new QSqlQuery(BB);
    //QSqlQuery *in = new QSqlQuery(BB);
    qry->exec("CREATE TABLE IF NOT EXISTS info (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30))");
    if(!qry->isActive())
        qWarning() << "ERROR: " << qry->lastError().text();

    qry->finish();
    qDebug("Connected!");

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
    qry->clear();
    w.show();
    return a.exec();
}
