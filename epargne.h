#ifndef EPARGNE_H
#define EPARGNE_H
using namespace std;

#include <QDialog>
#include <QTcpSocket>
#include <QtSql>
#include <QMessageBox>
#include <iostream>
#include <thread>

namespace Ui {
class epargne;
}

class epargne : public QDialog
{
    Q_OBJECT

public:
    explicit epargne(QWidget *parent = nullptr);
    void timer();
    ~epargne();

private slots:
    void on_Banque_highlighted(int index);

    void on_OK_clicked();

    void on_Cancel_clicked();

private:
    Ui::epargne *ui;
};

#endif // EPARGNE_H
