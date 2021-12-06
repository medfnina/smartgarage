#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Commande
{

public:
    Commande();
    Commande(int, QString , QString );

    QString getDESCRIPTION();
    QString getDATEE();

    int getIDC();

    void setDESCRIPTION(QString );
    void setDATEE(QString );

   void setIDC(int );

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int IDC, QString DESCRIPTION, QString DATEE);

    QSqlQueryModel * recherche(QString a);

    bool ajouter_OP(QString,QDate);
       QSqlQueryModel * afficher_OP();

        QSqlQueryModel * trierCommandeParIDC();
        QSqlQueryModel * trierCommandeParDESCRIPTION();
       QSqlQueryModel * trierCommandeParDATEE();
private:
    QString DESCRIPTION , DATEE  ;
    int IDC;


};

#endif // COMMANDE_H
