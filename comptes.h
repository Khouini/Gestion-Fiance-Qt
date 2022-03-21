#ifndef COMPTES_H
#define COMPTES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Comptes
{
    int Numero, Solde;
    QString Nom, Classe, Type ;
public:
    Comptes();
    Comptes(int, QString, QString, QString,  float);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * trier(QString, QString);
    QSqlQueryModel * recherche(QString);
    QSqlQueryModel * rechercheID(QString);
};

#endif // COMPTES_H
