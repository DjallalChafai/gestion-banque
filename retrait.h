#ifndef RETRAIT_H
#define RETRAIT_H

#include <QDialog>
#include <QMessageBox>
#include <QTcpSocket>
#include <QtSql>

namespace Ui {
    class retrait;
}

class retrait : public QDialog {
    Q_OBJECT

    public:
        explicit retrait(QWidget *parent = nullptr);
        ~retrait();

private slots:
    void on_button_accepted();

    void on_button_rejected();

private:
        Ui::retrait *ui;
};

#endif // RETRAIT_H
