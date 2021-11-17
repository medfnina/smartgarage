#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clients.h"
#include "exportexcelobject.h"
#include "stat_combo.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>



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

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();
    void sendMail();

    void mailSent(QString);

    void browse();


    void on_export_excel_clicked();

    void on_stat_clicked();

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_trier_clicked();

    void on_rechercher_clicked();

    void on_loadde_clicked();

    void on_supprimer1_cursorPositionChanged(int arg1, int arg2);

    void on_loadUP_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_refresh_clicked();

    void on_browseBtn_clicked();

    void on_file_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    clients C;
    QStringList files;
    stat_combo *s;
};
#endif // MAINWINDOW_H
