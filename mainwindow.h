#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QThread>
#include <QLocale>
#include <QMessageBox>
#include <QInputDialog>
#include <QTranslator>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTranslator>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtDebug>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_Ok_clicked();
        void on_Boursorama_clicked();
        void on_actionOuvrir_un_Compte_triggered();
        void on_actionFermer_un_compte_triggered();
        void on_Revolut_clicked();
        void on_N26_clicked();
        void on_actionSolde_d_un_Compte_triggered();
        void on_actionNum_ro_de_compte_triggered();
        void on_actionD_pot_sur_un_Compte_triggered();

    private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
