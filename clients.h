#ifndef CLIENTS_H
#define CLIENTS_H

#include <QString>
#include"connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>


class clients
{
public:
    clients();
    clients(int,int,int,QString,QString,QString,QString);
    int getCIN();
    int getAGE();
    int getNUM();
    QString getNOM();
    QString getPRENOM();
    QString getEMAIL();
    QString getADRESSE();
    void setCIN(int);
    void setAGE(int);
    void setNUM(int);
    void setNOM(QString);
    void setPRENOM(QString);
    void setEMAIL(QString);
    void setADRESSE(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,int,int,QString,QString,QString,QString );
    QSqlQueryModel*  chercherclients(int,QString);
    QSqlQueryModel* trierclients();
private:
int CIN , AGE , NUM ;
QString  NOM , PRENOM , EMAIL, ADRESSE;
};


#endif // CLIENTS_H
