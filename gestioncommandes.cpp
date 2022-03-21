#include "gestioncommandes.h"

GestionCommandes::GestionCommandes(){

}
GestionCommandes::GestionCommandes(int id_compte, int id_commande){
    this->id_compte=id_compte;
    this->id_commande=id_commande;
}
QSqlQueryModel * GestionCommandes::afficherCommandes1(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT commandes.id_commande, commandes.PJ, comptes.N_compte, comptes.nom_compte, comptes.type_compte, comptes.solde_compte FROM commandes JOIN comptes ON commandes.n_compte = comptes.n_compte;");
    return model;
}
QSqlQueryModel * GestionCommandes::afficherComboBoxCommandes(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT id_commande FROM commandes;");
    return model;
}
QSqlQueryModel * GestionCommandes::afficherComboBoxCompte(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT n_compte FROM comptes;");
    return model;
}
bool GestionCommandes::EtablirCompte(){
    QSqlQuery query;
    query.prepare("UPDATE Commandes set N_Compte = :idCompte  WHERE id_commande = :idCommande;");
    query.bindValue(":idCompte", id_compte);
    query.bindValue(":idCommande", id_commande);
    return query.exec();
}
