/**
 * \file Compte.h
 * \brief Fichier qui contient l'interface de la classe Compte qui sert au maintien et à la manipulation des comptes.
 * \author Judith-Aisha Dortelus
 * \version 1.0
 * \    3/14/2025
 */

#ifndef COMPTE_H
#define COMPTE_H

#include <string>
#include <memory>

#include "Date.h"

namespace bancaire
{
/**
 * \class Compte
 * \brief Classe sert au maintien et à la manipulation des comptes.
 *
 *              La classe maintient dans un état cohérent ces renseignements.
 *              Elle valide ce qu'on veut lui assigner.
 *              Cette classe peut aussi servir comme classe de base permettant 
 *              aux classes dérivée de faire des traitements polymorphes pour toute
 *              la hierarchie de la classe.
 *              La classe n'accepte que des comptes valides, c'est la responsabilité
 *              de l'utilisateur de la classe de s'en asssurer.             
 * \invariant La validité peut être vérifiée avec la méthode static
 *              bool Compte::validerAttributs(noCompte, tauxInteret, description)
 * 
 */
class Compte
{
public:
  Compte(unsigned p_noCompte, double p_tauxInteret, double p_solde, const std::string& p_description, const util::Date& p_dateOuverture);
  
  unsigned reqNoCompte () const;
  double reqTauxInteret() const;
  double reqSolde () const;
  
  const std::string reqDescription() const;
  const std::string reqDateOuverture() const;
  
  void asgTauxInteret(double p_tauxInteret);
  void asgSolde(double p_solde);
  void asgDescription(const std::string& p_description); 
  
  virtual ~Compte(); 
  
  virtual std::unique_ptr<Compte> clone() const=0; 
  virtual double calculerInteret() const; 
  virtual std::string reqCompteFormate() const; 
  
  static bool validerAttributs(unsigned p_noCompte, double p_tauxInteret, const std::string& p_description); 
   
private:
  unsigned m_noCompte;
  double m_tauxInteret;
  double m_solde;
  std::string m_description;
  util::Date m_dateOuverture; 
  
  void verifieInvariant() const;  
};

} // namespace bancaire

#endif /* COMPTE_H */

