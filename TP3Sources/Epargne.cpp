/**
 * \file Epargne.cpp
 * \brief Implémentation de la classe Epargne
 * \author Judith-Aisha Dortelus
 * \version 1.0
 * \    3/14/2025
 */

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Epargne.h"
#include "ContratException.h"

using namespace std;
namespace bancaire
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Epargne à partir de valeurs passées en paramètres.
 * 		  Les attributs sont assignés seulement si le compte epargne est considéré comme valide.
 * 		  Autrement, une erreur de précondition est générée.
 * \param[in] p_noCompte est un entier positif qui représente le numéro du compte epargne
 * \param[in] p_solde est un nombre décimale qui représente le solde du compte epargne
 * \param[in] p_dateOuverture héritié de la classe date, reçoit trois entiers en paramètre représentant la date d'ouverture du compte epargne
 * \param[in] p_tauxInteret est un nombre décimale qui représente le taux d'intérêt du compte epargne
 * \param[in] p_description est une chaîne de caractères qui représente la description du compte. Description par défaut "Epargne"
 * \pre p_solde, p_tauxInteret doivent correspondre à un compte epargne valide 
 */
Epargne::Epargne(unsigned p_noCompte, double p_solde, double p_tauxInteret, const std::string& p_description)       //, const util::Date& p_dateOuverture
                  : Compte(p_noCompte, p_tauxInteret, p_solde, p_description, util::Date())                                   
{
  PRECONDITION (Epargne::validerAttributsEpargne(p_solde, p_tauxInteret));
  
  INVARIANTS();
}


/**
 * \brief Vérifie la validité des attributs
 * \param[in] p_solde est un nombre décimale qui représente le solde du compte epargne
 * \param[in] p_tauxInteret est un nombre décimale qui représente le taux d'intérêt du compte epargne
 * \return un booléen indiquant si les attributs sont valides ou non
 */
bool Epargne::validerAttributsEpargne(double p_solde, double p_tauxInteret)
{
  bool valide = false;
  
  if (p_tauxInteret >= 0.1 && p_tauxInteret <= 3.5)
    {
      if (p_solde >= 0)
        {
          valide = true;
        }
    }
  return valide;
}


/** 
 * \brief Teste l'invariant de la classe Epargne. L'invariant de cette classe s'assure que le compte Epargne est valide
 */
void Epargne::verifieInvariant() const
{
  INVARIANT (Epargne::validerAttributsEpargne(reqSolde(), reqTauxInteret()));
}


/**
 * \brief Destructeur virtuelle de la classe Compte
 */ 
Epargne::~Epargne()
{
  
}


/**
 * \brief Méthode virtuelle calculant le taux d'intérêt du compte epargne
 * \return un nombre étant le produit du taux d'intérêt et du solde 
 */
double Epargne::calculerInteret() const
{
  return reqSolde() * reqTauxInteret();
}


/** 
 * \brief Méthode virtuelle permettant de faire une copie sur le monceau de l'objet courant 
 * \return l'adresse du clone de l'objet courant dans un pointeur 
 */
std::unique_ptr<Compte> Epargne::clone() const 
{
  return std::make_unique<Epargne>(*this);
}


/**
 * \brief Méthode virtuelle retournant l'ensemble des attributs formatés.
 * \return les informations du compte epargne formatée dans une chaîne de caractères
 */
std::string Epargne::reqCompteFormate() const
{
  ostringstream oss;
  
  oss << "Compte Epargne" << endl;
  oss << Compte::reqCompteFormate ();
  oss << "Interet : " << std::setprecision(3) << calculerInteret()/100 << "$" ;
  
  return oss.str();
}

} // namespace bancaire