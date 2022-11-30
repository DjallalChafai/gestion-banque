#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ok_clicked();

    void on_Boursorama_clicked();

    void on_actionOuvrir_un_Compte_triggered();

    void on_actionFermer_un_compte_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
