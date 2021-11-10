#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QIntValidator>
#include"clients.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cin->setValidator(new QIntValidator(0, 9999999, this));
    ui->tabclients->setModel(C.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ajouter_clicked()
{
    int CIN=ui->cin->text().toInt();
    QString NOM=ui->nom->text();
    QString PRENOM=ui->prenom->text();
    int AGE=ui->age->text().toInt();
    QString ADRESSE=ui->adresse->text();
    QString EMAIL=ui->email->text();
    int NUM=ui->num->text().toInt();


    clients C(CIN,AGE,NUM,NOM,PRENOM,ADRESSE,EMAIL);
    bool test=C.ajouter();
    if (test)

    {ui->tabclients->setModel(C.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                               QObject::tr("successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

           }
               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("erreur.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}








void MainWindow::on_supprimer_clicked()
{
    clients C;
    C.setCIN(ui->supprimer1->text().toInt());
    bool test=C.supprimer(C.getCIN());
    if (test)

    {
        //refresh
        ui->tabclients->setModel(C.afficher());

        QMessageBox::information(nullptr, QObject::tr("suppression is open"),
                               QObject::tr("successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);


           }
               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("erreur.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_clicked()
 {
    int cin=ui->cin->text().toInt();
    int age=ui->age->text().toInt();
    int num=ui->num->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString adresse=ui->adresse->text();
    QString email=ui->email->text();


     clients C(cin,age,num,nom,prenom,adresse,email);

            bool test=C.modifier(C.getCIN(),C.getAGE(),C.getNUM(),C.getNOM(),C.getPRENOM(),C.getADRESSE(),C.getEMAIL());

            QMessageBox msgBox;

            if(test)
                { ui->tabclients->setModel(C.afficher());
                    msgBox.setText("Modification avec succes.");
                            ui->tabclients->setModel(C.afficher());
                                        }
                                    else
                                        msgBox.setText("Echec de Modification!!!!!!");
                                        msgBox.exec();
}
