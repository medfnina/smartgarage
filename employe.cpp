#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QPagedPaintDevice>
#include<QPainter>
#include <QSqlTableModel>
#include<QPdfWriter>
Employe::Employe()
{
CIN=0 ; TEL=0 ; NOM="" ; PRENOM="" ; DAATE="" ; SPECIALITE="" ; ADRESSE="" ;
}
Employe::Employe(int CIN , int TEL , QString NOM , QString PRENOM , QString DAATE , QString SPECIALITE , QString ADRESSE )
{this->CIN=CIN ; this->TEL=TEL ; this->NOM=NOM ; this->PRENOM=PRENOM ; this->DAATE=DAATE ; this->SPECIALITE=SPECIALITE ; this->ADRESSE=ADRESSE;}
int Employe::getCIN(){return CIN;}
int Employe::getTEL(){return TEL;}
QString Employe::getNOM(){return NOM;}
QString Employe::getPRENOM(){return PRENOM;}
QString Employe::getDAATE(){return DAATE;}
QString Employe::getSPECIALITE(){return SPECIALITE;}
QString Employe::getADRESSE(){return ADRESSE;}
void Employe::setCIN(int CIN){this->CIN=CIN;}
void Employe::setTEL(int TEL){this->TEL=TEL;}
void Employe::setNOM(QString NOM){this->NOM=NOM;}
void Employe::setPRENOM(QString PRENOM){this->PRENOM=PRENOM ;}
void Employe::setDAATE(QString DAATE){this->DAATE=DAATE;}
void Employe::setSPECIALITE(QString SPECIALITE){this->SPECIALITE=SPECIALITE ;}
void Employe::setADRESSE(QString ADRESSE){this->ADRESSE=ADRESSE;}



bool Employe::ajouter()
{bool test=false;

    QSqlQuery query;
QString cin_string=QString::number(CIN);
QString tel_string=QString::number(TEL);
                      query.prepare("INSERT INTO EMPLOYE (CIN, NOM , PRENOM, DAATE,SPECIALITE, ADRESSE, TEL  ) "
                        "VALUES (:CIN, :NOM, :PRENOM, :DAATE, :SPECIALITE, :ADRESSE, :TEL)");
          query.bindValue(":CIN", CIN);
          query.bindValue(":NOM", NOM);
          query.bindValue(":PRENOM", PRENOM);
          query.bindValue(":DAATE", DAATE);
          query.bindValue(":SPECIALITE", SPECIALITE);
          query.bindValue(":ADRESSE", ADRESSE);
          query.bindValue(":TEL", TEL);
          test=query.exec();
 return test;
}

QSqlQueryModel* Employe::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT * FROM EMPLOYE");

             model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAATE"));
             model->setHeaderData(5, Qt::Horizontal, QObject::tr("SPECIALITE"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
             model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEL"));




       return model;
   }


bool Employe::supprimer()
{
    QSqlQuery query;
         query.prepare("Delete from EMPLOYE where CIN=:cin");
         query.bindValue(":cin", CIN);

         return query.exec();
}


bool Employe::modifier()
{
    QSqlQuery query;
    QString res= QString::number(CIN);
    query.prepare("UPDATE employe set TEL=:TEL,SPECIALITE=:SPECIALITE,ADRESSE=:ADRESSE,DAATE=:DAATE,PRENOM=:PRENOM,NOM=:NOM where CIN=:CIN");

    query.bindValue(":CIN", CIN);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":DAATE", DAATE);
    query.bindValue(":SPECIALITE", SPECIALITE);
    query.bindValue(":ADRESSE", ADRESSE);
    query.bindValue(":TEL", TEL);
    return query.exec();
}


QSqlQueryModel * Employe::chercheremployes(int CIN,QString NOM)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from employe where cin = :cin or nom = :nom ");
    query.bindValue(":cin",CIN);
    query.bindValue(":nom",NOM);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("daate"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("specialite"));

    return model;
}


QSqlQueryModel* Employe::trieremployes()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM employe ORDER BY cin ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("TEL"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DAATE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SPECIALITE"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));

    return model;
}

void  Employe::telechargerPDF()
{


                      QPdfWriter pdf("D:\Program Files\exporter_pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::blue);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"LISTES DES EMPLOYES");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial",14));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial",11));
                         painter.drawText(200,3300,"CIN");
                         painter.drawText(1300,3300,"TEL");
                         painter.drawText(2200,3300,"NOM");
                         painter.drawText(3200,3300,"PRENOM");
                         painter.drawText(5300,3300,"DAATE");
                         painter.drawText(6700,3300,"SPECIALITE");
                         painter.drawText(7000,3300,"ADRESSE");


                         QSqlQuery query;
                         //query.prepare("select * from joueurs where id='"+val+"'");
                         query.prepare("select * from EMPLOYE");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(2).toString());
                             painter.drawText(2200,i,query.value(3).toString());
                             painter.drawText(3200,i,query.value(1).toString());
                             painter.drawText(5300,i,query.value(4).toString());
                             painter.drawText(6700,i,query.value(5).toString());
                             painter.drawText(7000,i,query.value(6).toString());
                             painter.drawText(7500,i,query.value(7).toString());


                            i = i + 500;
                         }}
