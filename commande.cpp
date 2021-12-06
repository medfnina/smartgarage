#include "Commande.h"
#include<QDate>
#include<QSqlQuery>
#include <QtDebug>
Commande::Commande()
{

}

Commande::Commande(int IDC,QString DESCRIPTION,QString DATEE)
{
   this->IDC=IDC;
    this->DESCRIPTION=DESCRIPTION;
    this->DATEE=DATEE;

}

QString Commande::getDESCRIPTION(){return DESCRIPTION;}
QString Commande::getDATEE(){return DATEE;}
    int Commande::getIDC(){return IDC;}

void Commande::setDESCRIPTION(QString DESCRIPTION ){this->DESCRIPTION=DESCRIPTION;}
void Commande::setDATEE(QString DATEE){this->DATEE=DATEE;}
void Commande::setIDC(int IDC){this->IDC=IDC;}


bool Commande::ajouter()
{


    QSqlQuery query;
       query.prepare("INSERT INTO COMMANDE(IDC,DESCRIPTION,DATEE) VALUES (:IDC,:DESCRIPTION,:DATEE)");
       QString res= QString::number(IDC);
       query.bindValue(":IDC",IDC);
       query.bindValue(":DESCRIPTION",DESCRIPTION);
       query.bindValue(":DATEE",DATEE);

       return query.exec();




}
QSqlQueryModel * Commande::afficher()
{
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select * from COMMANDE ");
        model->setHeaderData(0,Qt::Horizontal,"IDC");
        model->setHeaderData(1,Qt::Horizontal,"DESCRIPTION");
        model->setHeaderData(2,Qt::Horizontal,"DATEE");


        return model ;
}
bool Commande::supprimer(int IDC)
{

    QSqlQuery query;
        query.prepare("DELETE FROM commande where IDC=:IDC");
        QString res= QString::number(IDC);
        query.bindValue(":IDC",res);
        return query.exec();


}

bool Commande::modifier(int IDC, QString DESCRIPTION, QString DATEE)

{


QSqlQuery query;
   query.prepare("UPDATE commande SET IDC=:IDC,DESCRIPTION=:DESCRIPTION,DATEE=:DATEE, WHERE IDC=:IDC");
   QString res= QString::number(IDC);
   query.bindValue(":IDC",res);
   query.bindValue(":DESCRIPTION",DESCRIPTION);
   query.bindValue(":DATEE",DATEE);
   return query.exec();

}

bool Commande::ajouter_OP(QString nom, QDate dateaa )
{
    QSqlQuery query;
    query.prepare("INSERT INTO HISTORIQUE( NOM,DATEA)""VALUES (:nom,:datea)");
    query.bindValue(":nom",nom);
    query.bindValue(":datea",dateaa);

    return query.exec();
}

QSqlQueryModel * Commande::afficher_OP()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM HISTORIQUE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));


    return model;
}




 QSqlQueryModel * Commande::trierCommandeParIDC()
 {

     QSqlQuery * q = new  QSqlQuery ();
            QSqlQueryModel * model = new  QSqlQueryModel ();
            q->prepare("SELECT * FROM COMMANDE order by IDC ASC");
            q->exec();
            model->setQuery(*q);
            return model;
 }


 QSqlQueryModel * Commande::trierCommandeParDESCRIPTION()
 {

     QSqlQuery * q = new  QSqlQuery ();
            QSqlQueryModel * model = new  QSqlQueryModel ();
            q->prepare("SELECT * FROM COMMANDE order by DESCRIPTION ASC");
            q->exec();
            model->setQuery(*q);
            return model;
 }


 QSqlQueryModel * Commande::trierCommandeParDATEE()
 {

     QSqlQuery * q = new  QSqlQuery ();
            QSqlQueryModel * model = new  QSqlQueryModel ();
            q->prepare("SELECT * FROM COMMANDE order by DATEE ASC");
            q->exec();
            model->setQuery(*q);
            return model;
 }


 QSqlQueryModel * Commande::recherche(QString a)
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM commande WHERE (IDC LIKE '%"+a+"%' OR DESCRIPTION LIKE '%"+a+"%' OR DATEE LIKE '%"+a+"%') ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDC"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESCRIPTION"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATEE"));


     return model;
 }
