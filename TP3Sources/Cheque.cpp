/**
 * \file Cheque.cpp
 * \brief Implémentation de la classe Cheque
 * \author Judith-Aisha Dortelus
 * \version 1.0
 * \    3/16/2025
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "Cheque.h"
#include "ContratException.h"

using namespace std;
namespace bancaire
{
/**             
 * \brief constructeur avec paramètres
 * 		  On construit un objet Cheque à partir de valeurs passées en paramètres.
 * 		  Les attributs sont assignés seulement si le compte cheque est considéré comme valide.
 * 		  Autrement, une erreur de précondition est générée.
 * \param[in] p_noCompte est un entier positif qui représente le numéro du compte cheque
 * \param[in] p_solde est un nombre décimale qui représente le solde du compte cheque
 * \param[in] p_tauxInteret est un nombre décimale qui représente le taux d'intérêt du compte cheque
 * \param[in] p_nombreTransactions est un entier positif qui représente le nombre de transactions du compte cheque
 * \param[in] p_tauxInteretMinimum est un nombre décimale qui represésente le taux d'intérêt minimum du compte cheque. Par défaut 0.1
 * \param[in] p_description est une chaîne de caractères qui représente la description du compte. Description par défaut "Cheque"
 * \pre p_tauxInteretMinimum, p_nombreTransactions doivent correspondre à un compte cheque valide
 * \post p_tauxInteretMinimum, p_nombreTransactions sont valides et l'objet construit a été initialisé à partir des attributs passés en paramètres
 */
Cheque::Cheque(unsigned p_noCompte, double p_solde, double p_tauxInteret, unsigned p_nombreTransactions, 
                        double p_tauxInteretMinimum, const std::string& p_description)
                  : Compte(p_noCompte, p_tauxInteret, p_solde, p_description, util::Date()), 
                    m_tauxInteretMinimum(p_tauxInteretMinimum), m_nombreTransactions(p_nombreTransactions)                              
{
  PRECONDITION (validerAttributsCheque(p_tauxInteretMinimum, p_nombreTransactions));
  PRECONDITION (p_tauxInteretMinimum < p_tauxInteret);
  
  POSTCONDITION (reqNbrTransactions() == p_nombreTransactions);
  POSTCONDITION (reqTauxInteretMinimum() == p_tauxInteretMinimum);
  
  INVARIANTS(); 
}


/**
 * \brief méthode accesseur retournant le nombre de transactions 
 * \return un entier positif qui représente le nombre de transactions
 */
unsigned Cheque::reqNbrTransactions() const
{
  return m_nombreTransactions;
}


/**
 * \brief méthode accesseur retournant le taux d'intérêt minimum
 * \return un nombre décimale qui représente le taux d'intérêt minimum
 */
double Cheque::reqTauxInteretMinimum() const
{
  return m_tauxInteretMinimum;
}


/**         
 * \brief Assigne le nombre de transactions à l'objet courant
 * \param[in] p_nombreTransactions est un entier positif qui représente le nombre de transactions du compte cheque
 * \pre p_nombreTransactions du compte cheque doit être <= 40
 * \post m_nombreTransactions prend la valeur du paramètre reçu en entrée
 */
void Cheque::asgNbrTransactions(unsigned p_nombreTransactions)
{
  PRECONDITION (p_nombreTransactions >= 0 && p_nombreTransactions <= 40);
  
  m_nombreTransactions = p_nombreTransactions; 
  
  POSTCONDITION (m_nombreTransactions == p_nombreTransactions);
  INVARIANTS ();
} 


/**     
 * \brief Vérifie la validité des attributs
 * \param[in] p_tauxInteretMinimum est un nombre décimale qui represésente le taux d'intérêt minimum du compte cheque. Par défaut 0.1
 * \param[in] p_nombreTransactions est un entier positif qui représente le nombre de transactions du compte cheque
 * \return un booléen indiquant si les attributs sont valides ou non
 */
bool Cheque::validerAttributsCheque(double p_tauxInteretMinimum, unsigned p_nombreTransactions)
{
  bool valide = false;
  
  if (p_tauxInteretMinimum >= 0.1)
    {
      if (p_nombreTransactions >= 0 && p_nombreTransactions <=40)
        {
          valide = true;
        }
    }
  return valide; 
}  


/**         
 * \brief Teste l'invariant de la classe Cheque. L'invariant de cette classe s'assure que le compte Cheque est valide
 */
void Cheque::verifieInvariant() const
{
  INVARIANT (Cheque::validerAttributsCheque(reqTauxInteretMinimum(), reqNbrTransactions()));
} 


/**
 * \brief Destructeur virtuelle de la classe Cheque
 */
Cheque::~Cheque()
{
  
}


/**         
 * \brief Méthode virtuelle calculant le taux d'intérêt du compte cheque
 * \return un nombre décimal 
 */
double Cheque::calculerInteret() const
{  
  if (reqSolde() >= 0)
    {
      return 0.0;
    }
  
  double interetCalculer = 0.0;
  
  if (m_nombreTransactions >= 0 && m_nombreTransactions <= 10)
    {
      interetCalculer = (reqTauxInteretMinimum()/100) * std::abs(reqSolde());
    }
  
  else if (m_nombreTransactions >= 11 && m_nombreTransactions <= 25)
    {
      interetCalculer = ((reqTauxInteretMinimum()/100) * 1.4) * std::abs(reqSolde());
    }
  
  else if (m_nombreTransactions > 25 && m_nombreTransactions <= 35)
    {
      interetCalculer = ((reqTauxInteretMinimum()/100) * 1.8) * std::abs(reqSolde());
    }
  
  else if (m_nombreTransactions > 35 && m_nombreTransactions <= 40)
    {
      interetCalculer = (reqTauxInteret()/100) * std::abs(reqSolde());         
    }
  
  return interetCalculer;
} 


/**             
 * \brief Méthode virtuelle retournant l'ensemble des attributs formatés
 * \return les informations du compte cheque formatée dans une chaîne de caractères
 */
std::string Cheque::reqCompteFormate() const
{
  ostringstream oss;
  
  oss << "Compte Cheque" << endl;
  oss << Compte::reqCompteFormate ();
  oss << "Nombre de transactions : " << reqNbrTransactions() << endl;
  oss << "Taux d'intérêt minimum : " << std::setprecision(3) << reqTauxInteretMinimum() << endl;
  oss << "Interet : " << std::setprecision(3) << calculerInteret() << "$" ;
  
  return oss.str();
} 


/** 
 * \brief Méthode virtuelle permettant de faire une copie sur le monceau de l'objet courant 
 * \return l'adresse du clone de l'objet courant dans un pointeur 
 */
std::unique_ptr<Compte> Cheque::clone() const 
{
  return std::make_unique<Cheque>(*this);
}

} // namespace bancaire