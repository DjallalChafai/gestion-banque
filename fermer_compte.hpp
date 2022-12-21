#ifndef FERMER_COMPTE_H
#define FERMER_COMPTE_H

#include <QDialog>
#include <QtDebug>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QTcpSocket>

namespace Ui {
class Fermer_Compte;
}

class Fermer_Compte : public QDialog
{
    Q_OBJECT

public:
    explicit Fermer_Compte(QWidget *parent = nullptr);
    ~Fermer_Compte();

private slots:
    void on_Annuler_clicked();

    void on_Ok_clicked();

private:
    Ui::Fermer_Compte *ui;
};

#endif // FERMER_COMPTE_H
