/**
 * \file Compte.cpp
 * \brief Implémentation de la classe Compte
 * \author Judith-Aisha Dortelus
 * \version 1.0
 * \    3/14/2025
 */

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Compte.h"
#include "ContratException.h"

using namespace std;
namespace bancaire
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Compte à partir de valeurs passées en paramètres.
 * 		  Les attributs sont assignés seulement si le compte est considéré comme valide.
 * 		  Autrement, une erreur de précondition est générée.
 * \param[in] p_noCompte est un entier positif qui représente le numéro du compte
 * \param[in] p_tauxInteret est un nombre décimale qui représente le taux d'intérêt du compte
 * \param[in] p_solde est un nombre décimale qui représente le solde du compte
 * \param[in] p_description est une chaîne de caractères qui représente la description du compte
 * \param[in] p_dateOuverture héritié de la classe date, reçoit trois entiers en paramètre représentant la date d'ouverture du compte
 * \pre p_noCompte, p_tauxInteret, p_description doivent correspondre à un compte valide
 * \post L'objet construit a été initialisé à partir des attributs passés en paramètres
 */
Compte::Compte(unsigned p_noCompte, double p_tauxInteret, double p_solde, 
               const std::string& p_description, const util::Date& p_dateOuverture)
                    : m_noCompte(p_noCompte), m_tauxInteret(p_tauxInteret), m_solde(p_solde), 
                      m_description(p_description), m_dateOuverture(p_dateOuverture)
{
  PRECONDITION (Compte::validerAttributs(p_noCompte, p_tauxInteret, p_description));
  
  POSTCONDITION (reqNoCompte() == p_noCompte);
  POSTCONDITION (reqTauxInteret() == p_tauxInteret);
  POSTCONDITION (reqSolde() == p_solde);
  POSTCONDITION (reqDescription() == p_description);
  POSTCONDITION (reqDateOuverture() == p_dateOuverture.reqDateFormatee());
  
  INVARIANTS();
}


/**
 * \brief méthode accesseur retournant le numéro du compte
 * \return un entier positif qui représente le numéro du compte
 */
unsigned Compte::reqNoCompte () const
{
  return m_noCompte;
}


/**
 * \brief méthode accesseur retournant le taux d'intérêt du compte
 * \return un nombre décimale qui représente le taux d'intérêt du compte
 */
double Compte::reqTauxInteret() const
{
  return m_tauxInteret;
}


/**
 * \brief méthode accesseur retournant le solde du compte
 * \return un nombre décimale qui représente le solde du compte
 */
double Compte::reqSolde () const
{
  return m_solde;
}


/** 
 * \brief méthode accesseur retournant la description du compte
 * \return un objet string qui représente la description du compte
 */
const string Compte::reqDescription() const
{
  return m_description;
}


/** 
 * \brief méthode accesseur retournant la date d'ouverture du compte
 * \return un objet string qui représente la date d'ouverture du compte
 */
const string Compte::reqDateOuverture() const
{
  return m_dateOuverture.reqDateFormatee();
}


/** 
 * \brief Assigne un taux d'intérêt à l'objet courant
 * \param[in] p_tauxInteret est un nombre décimale qui représente le taux d'intérêt du compte
 * \pre p_tauxInteret du compte doit être >= 0.0
 * \post m_tauxInteret prend la valeur du paramètre reçu en entrée
 */
void Compte::asgTauxInteret(double p_tauxInteret)
{
  PRECONDITION (p_tauxInteret >= 0.0);
  
  m_tauxInteret = p_tauxInteret;    
  
  POSTCONDITION (m_tauxInteret == p_tauxInteret);
  INVARIANTS ();
}


/** 
 * \brief Assigne un solde à l'objet courant
 * \param[in] p_solde est un nombre décimale qui représente le solde du compte
 * \pre p_solde du compte doit être != 0
 * \post m_solde prend la valeur du paramètre reçu en entrée
 */
void Compte::asgSolde(double p_solde)
{
  PRECONDITION (p_solde != 0);
  
  m_solde = p_solde; 
  
  POSTCONDITION (m_solde == p_solde);
  INVARIANTS ();
}


/** 
 * \brief Assigne une description à l'objet courant
 * \param[in] p_description est une chaîne de caractères qui représente la description du compte
 * \pre p_description du compte ne peut pas être une chaîne de caractère vide
 * \post m_description prend la valeur du paramètre reçu en entrée
 */
void Compte::asgDescription(const std::string& p_description)
{ 
  PRECONDITION (!p_description.empty());
  
  m_description = p_description;  
  
  POSTCONDITION (m_description == p_description);
  INVARIANTS();
}


/**
 * \brief Vérifie la validité des attributs
 * \param[in] p_noCompte est un entier positif qui représente le numéro du compte
 * \param[in] p_tauxInteret est un nombre décimale qui représente le taux d'intérêt du compte
 * \param[in] p_description est une chaîne de caractères qui représente la description du compte
 * \return un booléen indiquant si les attributs sont valides ou non
 */
bool Compte::validerAttributs(unsigned p_noCompte, double p_tauxInteret, const std::string& p_description)
{
  bool valide = false;
  if (p_noCompte > 0)
    {
      if (p_tauxInteret >= 0.0)
        {       
          if (!p_description.empty())   
            {             
              valide = true;
            }
        }
    }
  return valide;
} 


/** 
 * \brief Teste l'invariant de la classe Compte. L'invariant de cette classe s'assure que le compte est valide
 */
void Compte::verifieInvariant() const
{
  INVARIANT (Compte::validerAttributs(m_noCompte, m_tauxInteret, m_description));
} 


/**
 * \brief Destructeur virtuelle de la classe Compte
 */
Compte::~Compte() 
{
  
}


/**
 * \brief Méthode calculant le taux d'intérêt du compte
 * \return un nombre décimal 
 */
double Compte::calculerInteret() const
{
  return 0.0;
}


/**
 * \brief Méthode retournant l'ensemble des attributs formatés.
 * \return les informations du compte formatée dans une chaîne de caractères
 */
std::string Compte::reqCompteFormate() const
{
  ostringstream oss;
   
  oss << "Numero : " << reqNoCompte() << endl;
  oss << "Description : " << reqDescription() << endl;
  oss << "Date d'ouverture : " << reqDateOuverture() << endl;
  oss << "Taux d'intérêt : " << std::setprecision(3) << reqTauxInteret() << endl;
  oss << "Solde : " << std::fixed << setprecision(0) << reqSolde() << "$" << endl;
   
  return oss.str();
}

} // namespace bancaire