
#include "historique.h"

histrorique::histrorique()
{
    DATEE=QDateTime::currentDateTime();

}
histrorique::histrorique(QString IDC)
{

    DATEE=QDateTime::currentDateTime();
    this->IDC=IDC;

}
void histrorique::ajouter_historique()
{
    QSqlQuery query;
    query.prepare("INSERT INTO HISTORIQUE VALUES(ID_HISTORIQUE.nextval,:IDC,:DATE_HISTORIQUE ) ");
    query.bindValue(":IDC",IDC);
    query.bindValue(":DATE_HISTORIQUE",DATEE.toString());

    query.exec();


}
void histrorique::setIDC(QString IDC)
{
    this->IDC=IDC;
}

QSqlQueryModel * histrorique::afficherHistorique()
{
    QSqlQueryModel * model= new QSqlQueryModel();


        model->setQuery("select IDC,DATE_HISTORIQUE FROM HISTORIQUE order by id_historique DESC ;");



    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDC"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATEE"));


    return model;
}
