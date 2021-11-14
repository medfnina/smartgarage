#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QIntValidator>
#include"clients.h"
#include "smtp.h"
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cin->setValidator(new QIntValidator(0, 999999999, this));
    ui->tabclients->setModel(C.afficher());

    //for email tab
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
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
void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("alianoanderviarolegrand@gmail.com",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    if( !files.isEmpty() )
        smtp->sendMail("alianoanderviarolegrand@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("alianoanderviarolegrand@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}
//export excel
void MainWindow::on_export_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tabclients);

    //colums to export
    obj.addField(0, "cin", "char(20)");
    obj.addField(1, "nom", "char(20)");
    obj.addField(2, "prenom", "char(20)");
    obj.addField(3, "age", "char(20)");
    obj.addField(4, "adresse", "char(20)");
    obj.addField(5, "email", "char(20)");
    obj.addField(5, "num", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}

//stat
void MainWindow::on_stat_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();

}







void MainWindow::on_pushButton_7_clicked()
{
    clients C1;
      C1.setCIN(ui->cin ->text().toInt());
      C1.setNOM(ui->nom->text());

          ui->tabclients->setModel(C1.chercherclients(C1.getCIN(),C1.getNOM()));

          ui->cin->clear();
          ui->nom->clear();
          ui->prenom->clear();
          ui->age->clear();
          ui->adresse->clear();
          ui->email->clear();
          ui->num->clear();
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->tabclients->setModel(C.trierclients());


       int CIN=ui->cin->text().toInt();
       int AGE=ui->age->text().toInt();
       int NUM=ui->num->text().toInt();
       QString NOM=ui->nom->text();
       QString PRENOM=ui->prenom->text();
       QString ADRESSE=ui->adresse->text();
       QString EMAIL=ui->email->text();
               clients C(CIN,AGE,NUM,NOM,PRENOM,ADRESSE,EMAIL);

               QMessageBox msg;
              if(C.trierclients())
              {
                   ui->tabclients->setModel(C.trierclients());
                  msg.setText("Voilà la liste des Clients avec tri croissant selon l'CIN");
                  msg.exec();
              }


              ui->cin->clear();
              ui->nom->clear();
              ui->prenom->clear();
              ui->age->clear();
              ui->adresse->clear();
              ui->email->clear();
              ui->num->clear();
}
