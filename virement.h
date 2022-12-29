#ifndef VIREMENT_H
#define VIREMENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class virement;
}

class virement : public QDialog
{
    Q_OBJECT

public:
    explicit virement(QWidget *parent = nullptr);
    ~virement();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::virement *ui;
};

#endif // VIREMENT_H
