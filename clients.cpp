#include "clients.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include<QObject>


clients::clients()
{
CIN=0 ; AGE=0 ; NOM="" ; PRENOM="" ; NUM=0 ; EMAIL="" ; ADRESSE="" ;
}
clients::clients(int CIN , int AGE, int NUM  , QString NOM , QString PRENOM , QString EMAIL , QString ADRESSE )
{this->CIN=CIN ; this->AGE=AGE ; this->NOM=NOM ; this->PRENOM=PRENOM ; this->NUM=NUM ; this->EMAIL=EMAIL ; this->ADRESSE=ADRESSE;}
int clients::getCIN(){return CIN;}
int clients::getAGE(){return AGE;}
int clients::getNUM(){return NUM;}
QString clients::getNOM(){return NOM;}
QString clients::getPRENOM(){return PRENOM;}
QString clients::getEMAIL(){return EMAIL;}
QString clients::getADRESSE(){return ADRESSE;}

void clients::setCIN(int CIN){this->CIN=CIN;}
void clients::setAGE(int AGE){this->AGE=AGE;}
void clients::setNUM(int NUM){this->NUM=NUM;}
void clients::setNOM(QString NOM){this->NOM=NOM;}
void clients::setPRENOM(QString PRENOM){this->PRENOM=PRENOM ;}
void clients::setEMAIL(QString EMAIL){this->EMAIL=EMAIL ;}
void clients::setADRESSE(QString ADRESSE){this->ADRESSE=ADRESSE;}

bool clients::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(CIN);
         query.prepare("INSERT INTO clients (cin, nom, prenom, age , adresse, email,num) "
                       "VALUES (:cin, :nom, :prenom, :age, :adresse, :email, :num)");
         query.bindValue(":cin", id_string);
         query.bindValue(":nom", NOM);
         query.bindValue(":prenom", PRENOM);
         query.bindValue(":age", AGE);
         query.bindValue(":adresse", ADRESSE);
         query.bindValue(":email", EMAIL);
         query.bindValue(":num", NUM);
         return query.exec();
}

QSqlQueryModel* clients::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT* FROM clients");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("num"));




    return model;
}

bool clients::supprimer(int CIN)
{
    QSqlQuery query;
         query.prepare("Delete from clients where cin=:cin");
         query.bindValue(":cin", CIN); //bin

         return query.exec();
}
bool clients::modifier(int cin,int age,int num,QString nom,QString prenom,QString adresse,QString email)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("UPDATE clients set num=:num,email=:email,adresse=:adresse,age=:age,prenom=:prenom,nom=:nom where cin=:cin");

        QString id_string= QString::number(cin);
    query.bindValue(":cin", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":num", num);
    return query.exec();
}

QSqlQueryModel * clients::chercherclients(int cin,QString nom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from clients where cin like :cin or nom like :nom ");
    query.bindValue(":cin",CIN);// CIN VARIABLE LOCAL BA3D BCH NA3MALOU APPEL BIL getIDANIM()
    query.bindValue(":nom",NOM);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("num"));

    return model;
}

QSqlQueryModel* clients::trierclients()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM clients ORDER BY cin ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("num"));

    return model;
}
