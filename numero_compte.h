#ifndef NUMERO_COMPTE_H
#define NUMERO_COMPTE_H

#include <QDialog>
#include <QtDebug>
#include <QMessageBox>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QTcpSocket>

namespace Ui {
    class Numero_Compte;
}

class Numero_Compte : public QDialog {
    Q_OBJECT

    public:
        explicit Numero_Compte(QWidget *parent = nullptr);
        ~Numero_Compte();

    private slots:
        void on_Annuler_clicked();
        void on_Ok_clicked();

    private:
        Ui::Numero_Compte *ui;
    };

#endif // NUMERO_COMPTE_H
