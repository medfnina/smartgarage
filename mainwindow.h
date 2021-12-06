#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"employe.h"
#include "employe.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>



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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_modifier_clicked();

    void on_rechercher_clicked();

    void on_tri_clicked();


    void on_pushButton_13_clicked();

    void on_PDF_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;
};
#endif // MAINWINDOW_H
