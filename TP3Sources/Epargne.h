/**
 * \file Epargne.h
 * \brief Fichier qui contient l'interface de la classe Epargne qui sert au maintien et à la manipulation des comptes epargnes.
 * \author Judith-Aisha Dortelus
 * \version 1.0
 * \    3/14/2025
 */

#ifndef EPARGNE_H
#define EPARGNE_H

#include <string>
#include <memory>

#include "Date.h"
#include "Compte.h"

namespace bancaire
{
/**
 * \class Epargne
 * \brief Classe sert au maintien et à la manipulation des comptes epargne.
 *
 *              La classe maintient dans un état cohérent ces renseignements.
 *              Elle valide ce qu'on veut lui assigner.
 *              Cette classe est une classe dérivée de la classe Compte permettant 
 *              à la classe Epargne de faire des traitements polymorphes basé sur la classe de base.
 *              La classe n'accepte que des comptes epargne valides, c'est la responsabilité
 *              de l'utilisateur de la classe de s'en asssurer.             
 * \invariant La validité peut être vérifiée avec la méthode static
 *              bool validerAttributsEpargne(solde, tauxInteret) 
 * 
 */
class Epargne : public Compte
{
public:
  Epargne(unsigned p_noCompte, double p_solde, double p_tauxInteret, const std::string& p_description = "Epargne");
 
  virtual ~Epargne(); 
  
  virtual double calculerInteret() const;
  virtual std::unique_ptr<Compte> clone() const override;
  virtual std::string reqCompteFormate() const; 
  
  static bool validerAttributsEpargne(double p_solde, double p_tauxInteret); 
  
private:
  void verifieInvariant() const;  
};

} // namespace bancaire


#endif /* EPARGNE_H */

