/**
 * \file Cheque.h
 * \brief Fichier qui contient l'interface de la classe Cheque qui sert au maintien et à la manipulation des comptes cheques.
 * \author Judith-Aisha Dortelus
 * \version 1.0
 * \    3/16/2025
 */

#ifndef CHEQUE_H
#define CHEQUE_H

#include <string>
#include <memory>

#include "Date.h"
#include "Compte.h"

namespace bancaire
{
/**
 * \class Cheque
 * \brief Classe sert au maintien et à la manipulation des comptes cheque.
 *
 *              La classe maintient dans un état cohérent ces renseignements.
 *              Elle valide ce qu'on veut lui assigner.
 *              Cette classe est une classe dérivée de la classe Compte permettant 
 *              à la classe Cheque de faire des traitements polymorphes basé sur la classe de base.
 *              La classe n'accepte que des comptes valides, c'est la responsabilité
 *              de l'utilisateur de la classe de s'en asssurer.             
 * \invariant La validité peut être vérifiée avec la méthode static
 *              bool validerAttributsEpargne(tauxInteretMinimum, nombreTransations)
 * 
 */
class Cheque : public Compte
{
public:
  Cheque(unsigned p_noCompte, double p_solde, double p_tauxInteret, unsigned p_nombreTransactions, 
            double p_tauxInteretMinimum = 0.1, const std::string& p_description = "Cheque");

  unsigned reqNbrTransactions() const;
  double reqTauxInteretMinimum() const;
  
  void asgNbrTransactions(unsigned p_nombreTransactions);
  
  virtual ~Cheque(); 
  
  virtual double calculerInteret() const;
  virtual std::string reqCompteFormate() const;
  virtual std::unique_ptr<Compte> clone() const override;
  
  static bool validerAttributsCheque(double p_tauxInteretMinimum, unsigned p_nombreTransations); 
  
private:
  unsigned m_nombreTransactions;
  double m_tauxInteretMinimum;
  
  void verifieInvariant() const;  
};

} // namespace bancaire

#endif /* CHEQUE_H */

