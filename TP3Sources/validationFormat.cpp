/**
 * \file ValidationFormat.cpp
 * \brief Implémentation des fonctions de validationFormat
 * \author Judith-Aisha Dortelus
 * \version 2.0
 * \    4/1/2025
 */

#include "validationFormat.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <string>

#include "Date.h"
#include "Compte.h"

using namespace std;
namespace util
{

/** 
 * \brief valide si le caractère contient un accent ou non
 * \param[in] c un caractère représentant une lettre à valider dans une chaîne de caractères
 * \return un booléen indiquant si le caractère est un accent ou non
 */
bool validerLettreAccent(char c)
{
  bool valide = false;
  for (int i = 0; LETTRE_ACCENT[i] != '\0'; i++)
    {
      if (c == LETTRE_ACCENT[i])
        {
          valide = true;
        }
    }
  return valide;
}

/** 
 * \brief valide le format d'un nom
 * \param[in] p_nom une chaîne de caractère repésentant un nom
 * \return un booléen indiquant si le nom contient des caractère spéciaux ou chiffres ou non
 */
bool validerFormatNom(const std::string& p_nom)
{
  bool valide = false;
  
  if (!p_nom.empty()) 
    {
      if (p_nom.front() != ' ' && p_nom.front() != '-' && p_nom.back() != ' ' && p_nom.back() != '-' ) 
        {
          char lettrePrecedente = '\0';
          bool caractereInvalide = false;
          for (char c : p_nom) 
            { 
              if (std::isalpha(c) || validerLettreAccent(c)) 
                {
                  lettrePrecedente = c; 
                }
              
              else if (c ==' ' || c == '-')  
                {
                  if (lettrePrecedente == ' ' || lettrePrecedente == '-') 
                    {
                      caractereInvalide = true; 
                    } 
                lettrePrecedente = c; 
                }
              
               else
                 {
                   caractereInvalide = true; 
                 }
            }
          
          if (caractereInvalide == false) 
            {
              valide = true; 
            }
                                      
        } 
      
    }
  return valide;
}

/** 
 * \brief valide le jour, mois et l'année 
 * \param[in] jour un entier représentant le jour
 * \param[in] mois un entier représentant le mois
 * \param[in] annee un entier représentant le annee
 * \return un booléen indiquant si les paramètres représentent des données valides
 */
bool validerJourMoisAnnee (int jour, int mois, int annee)
{
  return (jour > 0 && jour <= 31) && (mois > 0 && mois <=12) && (annee > 0 && annee <= 2025);
}

/**
 * \brief Valide le format d'une date reçu en entrée
 * \param[in] p_ligne une chaîne de caractères représentant un flux d'entrée
 * \param[in] p_jour un entier représentant le jour de la date
 * \param[in] p_mois un entier représentant  le mois de la date
 * \param[in] p_annee un entier représentant l'année de la date
 * \return un booléen indiquant si la date est valide ou non
 */
bool validerFormatDate (const std::string& p_ligne, int& p_jour, int& p_mois, int& p_annee)
{
  bool dateValide = false;
  
  if (p_ligne.length() == 10)
    {
      if (p_ligne[2] == ' ' && p_ligne[5] == ' ')
        {
          for (int i = 0; i < p_ligne.length(); i++)
            {
              if (i != 2 || i != 5)
                {
                  if (isdigit(p_ligne[i]))
                    {
                      dateValide = true;
                    }
                } 
            }
          if (dateValide == true)
            {
              p_jour = stoi(p_ligne.substr(0, 2));
              p_mois = stoi(p_ligne.substr(3, 2));
              p_annee = stoi(p_ligne.substr(6, 4));
              
              dateValide = validerJourMoisAnnee(p_jour, p_mois, p_annee);
            }
          
        } else {dateValide = false; }
      
    } else {dateValide = false; }
  
  return dateValide;
}

/** 
 * \brief valide le format d'un fichier de données texte
 * \param[in] p_is une chaîne de caractère repésentant un flux d'entrée 
 * \return un booléen indiquant si le format des données dans le fichier sont valides ou non
 */
bool validerFormatFichier(std::istream& p_is)
{
  bool valide = false;
  string ligne;
  bool ligneInvalide = false;
  
  if (getline(p_is, ligne) && !ligne.empty() && validerFormatNom(ligne)) // 1ere ligne - NOM 
    {
      if (getline(p_is, ligne) && !ligne.empty() && validerFormatNom(ligne)) // 2e ligne - PRÉNOM 
        {       
          int jour;
          int mois;
          int annee;
          
          if (getline(p_is, ligne) && !ligne.empty()) // 3e ligne - DATE 
           { 
            if (validerFormatDate(ligne, jour, mois, annee))
              {              
                if (getline(p_is, ligne) && !ligne.empty()) // 4e ligne - TELEPHONE 
                  {
                    if (getline(p_is, ligne) && !ligne.empty()) // 5e ligne - FOLIO   
                    {
                      ligneInvalide = false; // lignes des fichiers sont valides 
                    }                                        
                } else { ligneInvalide = true; }  
                            
              } else { ligneInvalide = true; }     
          
        } else { ligneInvalide = true; }  
      
    } else { ligneInvalide = true; }  
      
  } else { ligneInvalide = true; } 
  
  bool ligneCompteInvalide = false;
  
  while (ligneCompteInvalide == false) // 6e ligne - boucler tant que c'est CHEQUE ou EPARGNE et lignes valides
    {
      getline(p_is, ligne);
      if (!ligne.empty())  // 6e ligne - CHEQUE ou EPARGNE s
        {         
          if (ligne == "cheque") //**
            {
              if (getline(p_is, ligne) && !ligne.empty()) // 7e ligne - NUMCOMPTE
                {
                  unsigned int numCompte; 
                  
                  if (getline(p_is, ligne) && !ligne.empty()) // 8e ligne - TAUX INTERET
                    {
                      double tauxInteret = 0.0; 
                  
                    if (getline(p_is, ligne) && !ligne.empty()) // 9e ligne - SOLDE
                      {
                        double solde = 0.00; 
                      
                        if (getline(p_is, ligne) && !ligne.empty()) // 10e ligne - DESCRIPTION
                          {
                            string description;
                            
                            if (getline(p_is, ligne) && !ligne.empty()) // 11e ligne - TRANSACTIONS
                              {
                                unsigned int nbrTransactions = 0; 
                                
                                if (getline(p_is, ligne) && !ligne.empty()) // 12 ligne - MINTAUXINTERET
                                  {
                                    double minTauxInteret = 0.0; 
                                    ligneCompteInvalide = false;
                                    ligneInvalide = false;
                                  }
                                  else { ligneCompteInvalide = true; }
                                
                              } else { ligneCompteInvalide = true; }
                            
                           } else { ligneCompteInvalide = true; }

                       } else { ligneCompteInvalide = true; }
                      
                    } else { ligneCompteInvalide = true; }

                } else { ligneCompteInvalide = true; }
              
            }                  
         
           else if (ligne == "epargne")
            {
              if (getline(p_is, ligne) && !ligne.empty()) // 7e ligne - NUMCOMPTE
                {
                  unsigned int numCompte; 
                  
                  if (getline(p_is, ligne) && !ligne.empty()) // 8e ligne - TAUX INTERET
                    {
                      double tauxInteret = 0.0; 
                  
                     if (getline(p_is, ligne) && !ligne.empty()) // 9e ligne - SOLDE
                      {
                        double solde = 0.00; //
                      
                        if (getline(p_is, ligne) && !ligne.empty()) // 10e ligne - DESCRIPTION
                          {
                            string description;                          
           
                            if (getline(p_is, ligne) && !ligne.empty()) 
                              {
                                int jour;
                                int mois;
                                int annee;

                                if (getline(p_is, ligne) && !ligne.empty()) // 11e ligne - DATE
                                  { 
                                    if (validerFormatDate(ligne, jour, mois, annee))
                                      {                        
                                        ligneCompteInvalide = false; // lignes des fichiers sont valides                        
                                        ligneInvalide = false;
                                      } else { ligneCompteInvalide = true; } 

                                   } else { ligneCompteInvalide = true; }  

                               } else { ligneCompteInvalide = true; } 

                            } else { ligneCompteInvalide = true; } 

                       } else { ligneCompteInvalide = true; }  
                      
                    } else { ligneCompteInvalide = true; }  
                  
                } else { ligneCompteInvalide = true; }  
              
            } else { ligneCompteInvalide = true; }      
          
        } else { ligneCompteInvalide = true; } // si la ligne du fichier est vide, on sort de la boucle
  
  }
  
  if (ligneInvalide == false) 
    {
      valide = true;
    }
 
  return valide;
}

/** 
 * \brief valide le format d'un nombre
 * \param[in] p_nombre une chaîne de caractère repésentant un nombre
 * \return un booléen indiquant si la chaîne de caractère p_nombre est constitué de chiffres valides ou non 
 */
bool validerNombre(std::string& p_nombre)
{
  if (p_nombre.empty())
    {
      return false;
    }
  
  bool point = false;
  bool nombre = false;
  bool negatif = false;
  for (char c : p_nombre)
    {
      if (c == '.')
        {
          if (point)
            {
              return false;
              point = true;
            }
        }
      else if (p_nombre[0] == '-')
        {
          if(negatif)
            {
              return false;
              negatif = true;
            }
        }
      else if (!isdigit(c))
        {
          return false;
        }   
      else
        {
          nombre = true;
        }
    }
  return true;
}


} // namespace util