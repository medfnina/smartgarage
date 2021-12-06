#include "connection.h"

connection::connection()
{

}
bool connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2A25_SG");
db.setUserName("aziz");//inserer nom de l'utilisateur
db.setPassword("temani");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void connection::closeconnection(){db.close();}
