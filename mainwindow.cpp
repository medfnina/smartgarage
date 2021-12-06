#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "COMMANDE.h"
#include <QApplication>
#include <QMessageBox>
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


MainWindow::MainWindow(QWidget *parent) :
     QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_IDC_3->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_commande_2->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_2_clicked()

    {
        int IDC=ui->le_IDC_3->text().toInt();//convertie la chaine de caractere en entier


        QString DESCRIPTION=ui->le_DESCRIPTION_3->text();
        QString DATEE=ui->le_DATEE_3->text();



        Commande C (IDC ,DESCRIPTION, DATEE); //on cree ajouter puis on appel ajout




    bool test=C.ajouter(); //recupere la valeur de retour //inserer Commande
         if(test)
     //si requete executee :qmessagebox::info
          {
             ui->tab_commande_2->setModel(C.afficher());







             QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                        QObject::tr("ajout successful.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              C.ajouter_OP("commande ajoute",QDate::currentDate());


                    }
                        else
                            QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                        QObject::tr("ajout failed.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }





void MainWindow::on_pb_supprimer_2_clicked()
{
    Commande C1 ; C1.setIDC((ui->le_IDC_SUPP_2->text().toInt()));
    bool test=C1.supprimer((C1.getIDC()));

    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Suppression effectuée\n"
                            "Click Cancel non to exit.") , QMessageBox :: Cancel);
       ui->tab_commande_2->setModel((C.afficher()));//refrerch
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                  QObject::tr("Suppression non effectuée.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        ui->tab_commande_2->setModel((C.afficher()));


}




void MainWindow::on_pb_modifier_2_clicked()
{
    int IDC = ui->le_IDC_5->text().toInt();
   QString DES = ui->le_DESCRIPTION_5->text();
   QString DATE= ui->le_DATEE_5->text();



    Commande C(IDC,DES,DATE);
    bool test = C.modifier(C.getIDC(),C.getDATEE(),C.getDESCRIPTION());
         if (test)
         {

             ui->tab_commande_2->setModel(C.afficher());
             QMessageBox::information(nullptr,"MODIFER Commande","MODFIER AJOUTEE");
         }
         else
         {
             QMessageBox::warning(nullptr,"MODIFER Commande","Commande NON MODIFER");
         }
}









void MainWindow::on_pb_stat_2_clicked()
{
    //ui->tab_commande->setCurrentIndex(1);
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from COMMANDE where IDC < 100 ");
        float salaire=model->rowCount();
        model->setQuery("select * from COMMANDE where IDC  between 100 and 200 ");
        float salairee=model->rowCount();
        model->setQuery("select * from COMMANDE where IDC >200  ");
        float salaireee=model->rowCount();
        float total=salaire+salairee+salaireee;

        QString a=QString("moins de 100 IDC . "+QString::number((salaire*100)/total,'f',2)+"%" );
        QString b=QString("entre 100 et 200 IDC.  "+QString::number((salairee*100)/total,'f',2)+"%" );
        QString c=QString("plus de 200 ANS."+QString::number((salaireee*100)/total,'f',2)+"%" );

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




void MainWindow::on_trier_activated()


{

   if (ui->trier->currentText()=="trier par IDC")
    {
   ui->tab_commande_2->setModel(C.trierCommandeParIDC());


   }
   else
       if(ui->trier->currentText()=="trier par DESCRIPTION")
       {
           ui->tab_commande_2->setModel(C.trierCommandeParDESCRIPTION());


       }
   else
          {
           ui->tab_commande_2->setModel(C.trierCommandeParDATEE());



       }


}







void MainWindow::on_tab_commande_2_cellActivated(int row, int column)
{
    ui->tab_commande_2->setModel(C.afficher());

}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    ui->tab_commande_2->setModel(C.recherche(arg1));
}
QString language ="FR";
void MainWindow::on_comboBox_activated(const QString &arg1)
{

    language = ui->comboBox->currentText();

          if(language == "FR"){
            //  ui->trier->setText("Trier ");

              ui->lineEdit->setText("recherche");
              ui->pb_stat_2->setText("consulter statistique");
              ui->pb_supprimer_2->setText("supprimer");
              ui->pb_ajouter_2->setText("ajouter");
              ui->pb_modifier_2->setText("modifier");

          }else {
              //ui->trier->setText(" order ");

              ui->lineEdit->setText("search");
              ui->pb_stat_2->setText("consult statistics");
              ui->pb_supprimer_2->setText("delete");
              ui->pb_ajouter_2->setText("add");
              ui->pb_modifier_2->setText("update");





          }
}
