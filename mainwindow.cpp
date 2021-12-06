#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include<QIntValidator>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include<QMessageBox>
#include<QIntValidator>
#include<QPainter>
#include<QPdfWriter>
#include <QApplication>
#include <QIntValidator>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->le_cin->setValidator(new QIntValidator(0, 9999999, this));
ui->tab_employe->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    int CIN=ui->le_cin->text().toInt();
    int TEL=ui->le_tel->text().toInt();
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString DAATE=ui->le_date->text();
    QString SPECIALITE=ui->le_specialite->text();
    QString ADRESSE=ui->le_adresse->text();
 Employe E(CIN,TEL,NOM,PRENOM,DAATE,SPECIALITE,ADRESSE);
 bool test=E.ajouter();
 if (test)

 {ui->tab_employe->setModel(E.afficher());
     QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                            QObject::tr("successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("erreur.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pb_supprimer_clicked()
{
    Employe E;
    E.setCIN(ui->le_cin->text().toInt());
    bool test=E.supprimer();
    if (test)

    {

        ui->tab_employe->setModel(E.afficher());

        QMessageBox::information(nullptr, QObject::tr("suppression is open"),
                               QObject::tr("successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);


           }
               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("erreur.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->tab_employe->setModel(E.afficher());
}


void MainWindow::on_modifier_clicked()
{
    int CIN=ui->le_cin->text().toInt();
    int TEL=ui->le_tel->text().toInt();
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString ADRESSE=ui->le_adresse->text();
    QString SPECIALITE=ui->le_specialite->text();
    QString DAATE=ui->le_date->text();


    Employe E(CIN , TEL , NOM , PRENOM ,DAATE ,  SPECIALITE , ADRESSE);

bool test=E.modifier();

            QMessageBox msgBox;

            if(test)
                { ui->tab_employe->setModel(E.afficher());
                    msgBox.setText("Modification avec succes.");
                            ui->tab_employe->setModel(E.afficher());
                                        }
                                    else
                                        msgBox.setText("Echec de Modification!!!!!!");
                                        msgBox.exec();
}

void MainWindow::on_rechercher_clicked()
{


       Employe E1;
          E1.setCIN(ui->lineEdit_16 ->text().toInt());
          E1.setNOM(ui->lineEdit_16->text());

              ui->tab_employe->setModel(E1.chercheremployes(E1.getCIN(),E1.getNOM()));

              ui->le_cin->clear();
              ui->le_nom->clear();
              ui->le_prenom->clear();
              ui->le_date->clear();
              ui->le_specialite->clear();
              ui->le_tel->clear();
              ui->le_adresse->clear();

}

void MainWindow::on_tri_clicked()
{
    ui->tab_employe->setModel(E.trieremployes());


       int CIN=ui->le_cin->text().toInt();
       int TEL=ui->le_tel->text().toInt();
       QString NOM=ui->le_nom->text();
       QString PRENOM=ui->le_prenom->text();
       QString ADRESSE=ui->le_adresse->text();
       QString SPECIALITE=ui->le_specialite->text();
       QString DAATE=ui->le_date->text();
               Employe E(CIN,TEL,NOM,PRENOM,ADRESSE,SPECIALITE,DAATE);

               QMessageBox msg;
              if(E.trieremployes())
              {
                   ui->tab_employe->setModel(E.trieremployes());
                  msg.setText("Voilà la liste des employes avec tri croissant selon le CIN");
                  msg.exec();
              }


              ui->le_cin->clear();
              ui->le_tel->clear();
              ui->le_nom->clear();
              ui->le_prenom->clear();
              ui->le_adresse->clear();
              ui->le_specialite->clear();
              ui->le_date->clear();



}







void MainWindow::on_PDF_clicked()
{
    {
            QPdfWriter pdf("D:\Program Files\pdf\PDF_employes.pdf");

           QPainter painter(&pdf);
           int i = 4000;
                  painter.setPen(Qt::red);
                  painter.setFont(QFont("Time New Roman", 25));
                  painter.drawText(3000,1400,"Liste Des Employes");
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Time New Roman", 15));
                  painter.drawRect(100,100,9400,2500); // dimension ta3 rectangle eli fih liste
                  painter.drawRect(100,3000,9400,500);
                  painter.setFont(QFont("Time New Roman", 9));
                  painter.drawText(400,3300,"CIN");
                  painter.drawText(1350,3300,"NOM");
                  painter.drawText(2200,3300,"PRENOM");
                  painter.drawText(3400,3300,"ADRESSE");
                  painter.drawText(4400,3300,"SPECIALITE");
                  painter.drawText(6200,3300,"DAATE");
                  painter.drawRect(100,3000,9400,9000);

                  QSqlQuery query;
                  query.prepare("select * from EMPLOYE");
                  query.exec();
                  while (query.next())
                  {
                      painter.drawText(400,i,query.value(0).toString());
                      painter.drawText(1350,i,query.value(1).toString());
                      painter.drawText(2300,i,query.value(2).toString());
                      painter.drawText(3400,i,query.value(3).toString());
                      painter.drawText(4400,i,query.value(4).toString());
                      painter.drawText(6200,i,query.value(5).toString());



                     i = i + 350;
                  }
                  QMessageBox::information(this, QObject::tr("PDF Enregistré"),
                  QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_18_clicked()
{


        //ui->tab_employe->setCurrentIndex(1);
            QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from EMPLOYE where CIN < 100 ");
            float salaire=model->rowCount();
            model->setQuery("select * from EMPLOYE where CIN  between 100 and 200 ");
            float salairee=model->rowCount();
            model->setQuery("select * from EMPLOYE where CIN >200  ");
            float salaireee=model->rowCount();
            float total=salaire+salairee+salaireee;

            QString a=QString("CIN moins de 100  . "+QString::number((salaire*100)/total,'f',2)+"%" );
            QString b=QString("CIN entre 100 et 200 .  "+QString::number((salairee*100)/total,'f',2)+"%" );
            QString c=QString("CIN plus de 200 ."+QString::number((salaireee*100)/total,'f',2)+"%" );

            QPieSeries *series = new QPieSeries();
            series->append(a,salaire);
            series->append(b,salairee);
            series->append(c,salaireee);
            if (salaire!=0)
            {QPieSlice *slice = series->slices().at(0);
                slice->setLabelVisible();
                slice->setPen(QPen());}
            if ( salairee!=0)
            {
                // Add label, explode and define brush for 2nd slice
                QPieSlice *slice1 = series->slices().at(1);
                //slice1->setExploded();
                slice1->setLabelVisible();
            }
            if(salaireee!=0)
            {
                // Add labels to rest of slices
                QPieSlice *slice2 = series->slices().at(2);
                //slice1->setExploded();
                slice2->setLabelVisible();
            }
            // Create the chart widget
            QChart *chart = new QChart();
            // Add data to chart with title and hide legend
            chart->addSeries(series); // widget
            chart->setTitle("STATISTIQUE DES COMMANDE SELON IDC  "+ QString::number(total));
            chart->legend()->hide();
            // Used to display the chart
            QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(1000,500);
            chartView->show();

}
