#ifndef DEPOT_H
#define DEPOT_H

#include <QDialog>
#include <QtDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QIcon>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QTcpSocket>

namespace Ui {
    class depot;
}

class depot : public QDialog {
    Q_OBJECT

    public:
        explicit depot(QWidget *parent = nullptr);
        ~depot();

    private slots:
        void on_button_rejected();
        void on_button_accepted();

    private:
        Ui::depot *ui;
};

#endif // DEPOT_H