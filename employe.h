#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>

class Employe
{
public:
    Employe();
    Employe(int,int,QString,QString,QString,QString,QString);
    int getCIN();
    int getTEL();
    QString getNOM();
    QString getPRENOM();
    QString getDAATE();
    QString getSPECIALITE();
    QString getADRESSE();
    void setCIN(int);
    void setTEL(int);
    void setNOM(QString);
    void setPRENOM(QString);
    void setDAATE(QString);
    void setSPECIALITE(QString);
    void setADRESSE(QString);

private:
int CIN , TEL ;
QString  NOM , PRENOM , DAATE, SPECIALITE ,ADRESSE;
};

#endif // EMPLOYE_H
