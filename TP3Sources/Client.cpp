/**
 * \file Client.cpp
 * \brief Implémentation de la classe Client
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 2.0
 * \    4/14/2025
 */

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Client.h"
#include "validationFormat.h"
#include "ContratException.h"
#include "CompteException.h"


using namespace std;
namespace bancaire
{         
/** 
 * \brief constructeur avec paramètres
 * 		  On construit un objet Client à partir de valeurs passées en paramètres.
 * 		  Les attributs sont assignés seulement si l'objet est considéré comme valide.
 * 		  Autrement, une erreur de précondition est générée.
 * \param[in] p_noFolio est un entier positif qui représente le numéro de folio du client
 * \param[in] p_nom est une chaîne de caractères qui représente le nom du client
 * \param[in] p_prenom est une chaîne de caractères qui représente le prénom du client
 * \param[in] p_dateNaissance héritié de la classe date, reçoit trois entiers en paramètre représentant la date de naissance du client
 * \param[in] p_telephone est une chaîne de caractères qui représente le numéro de téléphone du client
 * \pre p_noFolio, p_nom, p_prenom, p_dateNaissance, p_telephone doivent correspondre à un client valide
 * \post L'objet construit a été initialisé à partir des attributs passés en paramètres
 */
Client::Client(unsigned p_noFolio, const std::string& p_nom, const std::string& p_prenom, 
               const util::Date& p_dateNaissance, const std::string& p_telephone) 
               : m_noFolio(p_noFolio), m_nom(p_nom), m_prenom(p_prenom), 
                 m_dateNaissance(p_dateNaissance), m_telephone(p_telephone)
{
  PRECONDITION (Client::validerAttributsClient(p_noFolio, p_nom, p_prenom, p_dateNaissance, p_telephone));
  
  POSTCONDITION (reqNoFolio() == p_noFolio);
  POSTCONDITION (reqNom() == p_nom);
  POSTCONDITION (reqPrenom() == p_prenom);
  POSTCONDITION (reqDateNaissance() == p_dateNaissance.reqDateFormatee ());
  POSTCONDITION (reqTelephone() == p_telephone);
  
  INVARIANTS();
}


/** 
 * \brief constructeur de copie
 *                Forme canonique de coplien.
 * 		  Permet de faire une copie en profondeur des attributs de l'objet Client.
 *                Clone dans un vecteur les comptes associé à l'objet courant permettant au
 *                nouveau client de posséder sa propre copie des comptes.
 *                Cette copie est indépendante et ne modifie pas le comportement des comptes du client ultérieur. 
 *                
 * \param[in] p_client représente le client à copier
 * \post L'objet construit a été initialisé à partir de l'attribut passé en paramètre
 * \post m_vComptes contient une copie indépendante de p_client
 */
Client::Client(const Client& p_client) : m_noFolio(p_client.m_noFolio), m_nom(p_client.m_nom), m_prenom(p_client.m_prenom), 
                                         m_dateNaissance(p_client.m_dateNaissance), m_telephone(p_client.m_telephone)
{  
  for (auto& element: p_client.m_vComptes)
    {
      m_vComptes.push_back(element-> clone());    
    }
  
  POSTCONDITION (reqClientFormate() == p_client.reqClientFormate());
  POSTCONDITION (reqReleves() == p_client.reqReleves ());
  POSTCONDITION (reqNbrComptes() == p_client.reqNbrComptes());
  
  INVARIANTS();
}                                                 


/** 
 * \brief Opérateur de copie
 * 		  Forme canonique de coplien via la surcharge de l'opérateur= .
 * 		  Permet de faire une copie en profondeur des attributs de l'objet Client.
 *                Clone/Remplace dans le vecteur les comptes associé à l'objet courant permettant au
 *                nouveau client de posséder sa propre copie des comptes.
 *                Cette copie est indépendante et ne modifie pas le comportement des comptes du client ultérieur. 
 *                
 * \param[in] p_client représente le client à copier
 * \return une référence sur l'objet courant
 * \pre p_client doit être différent de l'objet courant
 * \post L'objet construit a été initialisé à partir de l'attribut passé en paramètre
 * \post m_vComptes contient une copie indépendante des attributs de p_client
 */
Client& Client::operator=(const Client& p_client)
{
  PRECONDITION (!(this == &p_client))

  m_noFolio = p_client.m_noFolio;
  m_nom = p_client.m_nom;
  m_prenom = p_client.m_prenom;
  m_dateNaissance = p_client.m_dateNaissance;
  m_telephone = p_client.m_telephone;
    
  m_vComptes.clear();
  for (auto& element : p_client.m_vComptes)
    {
      m_vComptes.push_back(element-> clone());
    }
  return *this;
  
  POSTCONDITION (reqClientFormate() == p_client.reqClientFormate());
  POSTCONDITION (reqReleves() == p_client.reqReleves ());
  POSTCONDITION (reqNbrComptes() == p_client.reqNbrComptes());
  
  INVARIANTS();
}


/** 
 * \brief méthode accesseur retournant le numéro de folio 
 * \return un entier positif qui représente le numéro de folio 
 */
unsigned Client::reqNoFolio() const
{
  return m_noFolio;
}
  

/** 
 * \brief méthode accesseur retournant le numero de téléphone 
 * \return une chaîne de caractères qui représente le numéro de telephone
 */
const std::string Client::reqTelephone() const
{
  return m_telephone;
}


/** 
 * \brief méthode accesseur retournant le nom
 * \return une chaîne de caractères qui représente le nom
 */
const std::string Client::reqNom() const
{
  return m_nom;
}
  

/** 
 * \brief méthode accesseur retournant le prénom
 * \return une chaîne de caractères qui représente le prénom
 */  
const std::string Client::reqPrenom() const
{
  return m_prenom;
}
  

/** 
 * \brief méthode accesseur retournant la date de naissance
 * \return une chaîne de caractères qui représente la date de naissance
 */  
const std::string Client::reqDateNaissance() const
{
  return m_dateNaissance.reqDateFormatee();
}


/** 
 * \brief méthode accesseur retournant le nombre de comptes que le client possède
 * \return un nombre entier positif représentant le nombre de comptes
 */
size_t Client::reqNbrComptes() const
{
  return m_vComptes.size();
}


/** 
 * \brief surcharge de l'opérateur <
 * \param[in] p_noFolio à comparer au numéro de folio courant 
 * \return un booléen indiquant si le numéro de folio courant est plus petit que le numéro de folio passée en paramètre
 */
bool Client::operator<(const Client& p_noFolio) const
{
  if (m_noFolio < p_noFolio.m_noFolio)
    {
      return true;
    }
  else { return false; }
}


/**         
 * \brief Méthode ajoutant un compte au vecteur de comptes
 * \param[in] p_nouveauCompte représente le nouveau compte à ajouter dans le vecteur 
 * \post L'objet construit a été initialisé à partir de l'attribut passé en paramètre
 */
void Client::ajouterCompte(const Compte& p_nouveauCompte)
{
    if (compteEstDejaPresent(p_nouveauCompte.reqNoCompte()))
    {
        throw CompteDejaPresentException(p_nouveauCompte.reqCompteFormate());
    }

    m_vComptes.push_back(p_nouveauCompte.clone());
    
    INVARIANTS();
}


/**         
 * \brief Méthode supprimant un compte de la liste de comptes
 * \param[in] p_noComte représente le compte à supprimer dans le vecteur 
 * \post L'objet passé en paramètre a été supprimé 
 */
void Client::supprimerCompte(int p_noCompte)
{
    if (!compteEstDejaPresent(p_noCompte))
    {
        throw CompteAbsentException("Le compte n'est pas présent dans la liste.");
    }

    for (auto iter = m_vComptes.begin(); iter != m_vComptes.end(); ++iter)
    {
        if ((*iter)->reqNoCompte() == p_noCompte)
        {
            m_vComptes.erase(iter);
            INVARIANTS();
            return;
        }
    }
}


/** 
 * \brief Méthode retournant l'ensemble des attributs formatés.
 * \return les informations d'un client formatée dans une chaîne de caractères
 */
std::string Client::reqClientFormate() const
{
  ostringstream oss;
  
  oss << "Client no de folio : " << reqNoFolio() << endl;
  oss << reqPrenom() << " " << reqNom() << endl;
  oss << "Date de naissance : " << reqDateNaissance() << endl;
  oss << reqTelephoneFormate() << endl;

  return oss.str();
}


/** 
 * \brief Méthode retournant l'ensemble des attributs et comptes formatés
 * \return les informations d'un client et de ses comptes formatées dans une chaîne de caractères
 */
std::string Client::reqReleves() const
{
  ostringstream oss;
  
  oss << reqClientFormate() ;
  
  for (const auto& element : m_vComptes)
    {
      oss << element->reqCompteFormate() << endl;
    }
  return oss.str();
}


/**     
 * \brief Vérifie la validité des attributs
 * \param[in] p_noFolio est un entier positif qui représente le numéro de folio du client
 * \param[in] p_nom est une chaîne de caractères qui représente le nom du client
 * \param[in] p_prenom est une chaîne de caractères qui représente le prénom du client
 * \param[in] p_dateNaissance héritié de la classe date, reçoit trois entiers en paramètre représentant la date de naissance du client
 * \param[in] p_telephone est une chaîne de caractères qui représente le numéro de téléphone du client
 * \return un booléen indiquant si les attributs sont valides ou non
 */
bool Client::validerAttributsClient(unsigned p_noFolio, const std::string& p_nom, const std::string& p_prenom,
                                    const util::Date& p_dateNaissance, const std::string& p_telephone)
{
  bool valide = false;
  if (p_noFolio >= 1000 && p_noFolio < 10000)
    {
      if (util::validerFormatNom(p_nom) && util::validerFormatNom (p_prenom))
        {
          if (util::Date::validerDate(p_dateNaissance.reqJour(), p_dateNaissance.reqMois(), p_dateNaissance.reqAnnee()))
            {
              if (p_dateNaissance.reqAnnee() >= 1970 && p_dateNaissance.reqAnnee() <= 2037)
                {        
                  if (!p_telephone.empty())                 
                    {
                      std::string numerosTelephone;
                      for (char c : p_telephone)
                        {
                          if (std::isdigit(c))
                            {
                              numerosTelephone += c;
                            }
                        }                     
                      if (numerosTelephone.length() == 10)
                        {                               
                          valide = true;
                        }                                
                    }
                }
            }
        }
    }
  return valide;
}


/** 
 * \brief Teste l'invariant de la classe Client. L'invariant de cette classe s'assure que la classe est valide
 */
void Client::verifieInvariant() const
{
  INVARIANT(Client::validerAttributsClient(m_noFolio, m_nom, m_prenom, m_dateNaissance, m_telephone));
}


/** 
 * \brief Méthode retournant le numéro de telephone formaté
 * \return le numéro de téléphone du client formatée dans une chaîne de caractères ainsi "000 000-0000"
 */
std::string Client::reqTelephoneFormate() const
{
  std::string numerosTelephone;
  for (char c : m_telephone)
    {
      if (std::isdigit(c))
      {
        numerosTelephone += c;
      }
    }  
  std::string numeroFormate;
  numeroFormate.reserve(12);
  for (int i = 0; i < numerosTelephone.length(); i++)
    {
      if (i == 3)
        {
          numeroFormate += ' ';
        }
      else if (i == 6)
        {
          numeroFormate += '-';
        }
      numeroFormate += numerosTelephone[i];
    }
  return numeroFormate;         
}

/**     
 * \brief Vérifie si le numéro de compte existe déjà
 * \param[in] p_noCompte est un entier positif représentant le numéro de compte du client
 * \return un booléen indiquant si le compte est déja présent dans le vecteur ou non 
 */
bool Client::compteEstDejaPresent(int p_noCompte) const
{
    for (auto iter = m_vComptes.begin(); iter != m_vComptes.end(); ++iter)
    {
        if ((*iter)->reqNoCompte() == p_noCompte)
        {
            return true;
        }
    }
    return false;
}

} // namespace bancaire
