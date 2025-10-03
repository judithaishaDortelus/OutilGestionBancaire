/**
 * \file Client.h
 * \brief Fichier qui contient l'interface de la classe Client qui sert à la gestion des comptes du client.
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 2.0
 * \    4/14/2025
 */

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <memory>
#include <vector>

#include "Date.h"
#include "Compte.h"
#include "Epargne.h"
#include "Cheque.h"

namespace bancaire
{
/**
 * \class Client
 * \brief Classe sert à la gestion des comptes du client.
 *
 *              La classe maintient dans un état cohérent ces renseignements.
 *              Elle valide ce qu'on veut lui assigner.
 *              Cette classe contient tous les comptes du client dans 
 *              un conteneur de type vector et accède aux classes dérivées
 *              de la classe Compte via des pointeurs intelligents.
 *              La classe client est une forme canonique de coplien et respecte le
 *              principe de responsabilité unique pour la gestion de la mémoire dans
 *              le cas d'allocations dynamiques.
 *              La classe n'accepte que des clients valides, c'est la responsabilité
 *              de l'utilisateur de la classe de s'en asssurer.             
 * \invariant La validité peut être vérifiée avec la méthode static 
 *              bool validerAttributsClient(noFolio, nom, prenom, dateNaissance, telephone)
 * 
 */
class Client
{
public:
  Client(unsigned p_noFolio, const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, const std::string& p_telephone); 
  Client(const Client& p_client);       
  Client& operator=(const Client& p_client);  
  
  unsigned reqNoFolio() const;
  const std::string reqTelephone() const;   
  const std::string reqNom() const;
  const std::string reqPrenom() const;
  const std::string reqDateNaissance() const;
  
  size_t reqNbrComptes() const;                                       
  
  bool operator<(const Client& p_noFolio) const; 

  void ajouterCompte (const Compte& p_nouveauCompte);
  void supprimerCompte (int p_noCompte);
  std::string reqClientFormate() const;
  std::string reqReleves() const;

  static bool validerAttributsClient(unsigned p_noFolio, const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, const std::string& p_telephone);
  std::string reqTelephoneFormate() const;
  
private:
  unsigned m_noFolio; 
  std::string m_nom;    
  std::string m_prenom; 
  std::string m_telephone;  
  util::Date m_dateNaissance;
  std::vector<std::unique_ptr<Compte>> m_vComptes; 
  
  bool compteEstDejaPresent(int p_noCompte) const;
  void verifieInvariant() const; 
};

} // namespace bancaire

#endif /* CLIENT_H */

