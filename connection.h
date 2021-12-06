#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>



class connection
{
private:
    QSqlDatabase db;
public:
    connection();
     bool createconnection();
     void closeconnection();
};

#endif // CONNECTION_H
