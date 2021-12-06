#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Commande.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_modifier_2_clicked();



/*
    void on_pb_IDC_clicked();

    void on_pb_DESCRIPTION_clicked();

    void on_pb_DATEE_clicked();
*/



    void on_pb_stat_2_clicked();

    void on_checkBox_4_stateChanged(int arg1);



    void on_trier_activated();




    void on_tab_commande_2_cellActivated(int row, int column);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Commande C ;



};

#endif // MAINWINDOW_H
