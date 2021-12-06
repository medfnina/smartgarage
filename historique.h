#ifndef HISTRORIQUE_H
#define HISTRORIQUE_H
#include <QDateTime>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class histrorique
{
public:
    histrorique();
    histrorique(QString);
    void setIDC(QString);

    void ajouter_historique();
    QSqlQueryModel * afficherHistorique();

private:
    QString IDC;
    QDateTime DATEE;
};

#endif // HISTRORIQUE_H
