#ifndef SOLDE_COMPTE_H
#define SOLDE_COMPTE_H

#include <QDialog>
#include <QtDebug>
#include <QMessageBox>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QTcpSocket>

namespace Ui {
    class Solde_Compte;
}

class Solde_Compte : public QDialog {
    Q_OBJECT

    public:
        explicit Solde_Compte(QWidget *parent = nullptr);
        ~Solde_Compte();

    private slots:
        void on_Annuler_clicked();
        void on_Ok_clicked();

    private:
        Ui::Solde_Compte *ui;
};

#endif // SOLDE_COMPTE_H
