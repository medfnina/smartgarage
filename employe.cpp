#include "employe.h"

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
