/**
 * \file Utilisation.cpp
 * \brief Programme minimaliste utilisant la classe Client avec différents comptes.
 * \author Judith-Aisha Dortelus
 * \version 1.0
 * \    4/7/2025
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

#include "Date.h"
#include "Compte.h"
#include "Epargne.h"
#include "Cheque.h"
#include "Client.h"
#include "validationFormat.h"

using namespace std;
using namespace util;
using namespace bancaire;
/**
int main ()
{
                                      // CLIENT //

  cout << "------------------------------------------------" << endl;
  cout << "   Bienvenue à l'outil de gestion de comptes   " << endl;
  cout << "------------------------------------------------" << endl;
  cout << "Saisir les informations sur le nouveau Client" << endl;
  
  // numéro de folio 
  unsigned noFolio;
  std::string folio;  
  bool folioInvalide = true;
  do
    {     
      cout << "Folio : " ;
      getline(cin, folio);

      if (validerNombre(folio))
        {
          noFolio = std::stoi(folio);
          if (noFolio >= 1000 && noFolio < 10000)
            {
              folioInvalide = false;
            }
          else
            {
              cout << "numéro incorrect, doit être dans l'intervalle [1000, 10000[, recommencez" << endl;
            }
        }
      
      else  {  cout << "numéro invalide, recommencez" << endl; }  
    } while (folioInvalide);
    
  // nom
  std::string nom;
  bool nomInvalide = true;
  do
    {
      cout << "Nom : " ;
      getline(cin, nom);
      
      if (!validerFormatNom(nom))
        {
          cout << "nom invalide, recommencez" << endl;
        } else { nomInvalide = false; }
    } while (nomInvalide);

  // prénom
  std::string prenom;
  bool prenomInvalide = true;
  do
    {
      cout << "Prénom : " ;
      getline(cin, prenom);
      
      if (!validerFormatNom(prenom))
        {
          cout << "prénom invalide, recommencez" << endl;
        } else { prenomInvalide = false; }
    } while (prenomInvalide);   
 
  // date de naissance
  int jour;
  int mois;
  int annee;
  bool dateNaissanceInvalide = true;
  do
    {
      cout << "Date de naissance" << endl;
      cout << "Le jour [1...31] : " ;
      cin >> jour;
      cin.ignore();
      
      cout << "Le mois [1...31] : " ;
      cin >> mois;
      cin.ignore();
      
      cout << "L'année : " ;
      cin >> annee;
      cin.ignore();
      
      if(annee < 1970 || annee > 2037)
        {
          cout << "année incorrect, doit être dans l'intervalle [1970, 2037], recommencez" << endl;
        }      
      
      else if (!Date::validerDate(jour, mois, annee))
        {
          cout << "date invalide, recommencez" << endl;
        } 
      else { dateNaissanceInvalide = false; }
    } while (dateNaissanceInvalide);
      
  // téléphone  
  std::string telephone;
  bool telephoneInvalide = true;
  do
    {
      cout << "Telephone : " ;
      getline(cin, telephone);
      
      if (telephone.empty())
        {
          cout << "téléphone invalide, recommencez" << endl;
        }
      
      std::string numerosTelephone;
      for (char c: telephone)
        {
          if (std::isdigit(c))
            {
              numerosTelephone += c;
            }
        }
      
      if (numerosTelephone.length() != 10)
        {
          cout << "téléphone incorrect, doit être un numéro local de 10 chiffres, recommencez" << endl;
        }
      else { telephoneInvalide = false; }
    } while (telephoneInvalide); 
 
    
  //créer un client avec paramètres reçus
  Date dateNaissance(jour, mois, annee);
  Client client1(noFolio, nom, prenom, dateNaissance, telephone);
  
  
                                        // CHEQUE //

  // info compte cheque
  cout << "Saisir les informations sur le nouveau compte Cheque" << endl;
    
  //numero compte cheque
  unsigned noCompteCheque; 
  std::string compteCheque;
  bool noCompteChequeInvalide = true;
  do
    {
      cout << "Numéro de compte? " ;
      getline(cin, compteCheque);
              
      if (validerNombre(compteCheque))
        {
          if(compteCheque[0] == '-')
            {
              cout << "numéro invalide, recommencez" << endl; 
            }
          else
            {
              noCompteCheque = std::stoi(compteCheque);
              if(noCompteCheque > 0)    
                {
                  noCompteChequeInvalide = false;
                }
              else
                {
                  cout << "numéro invalide, recommencez" << endl; 
                }
            }
        }                              
      else { cout << "numéro invalide, recommencez" << endl; }
    } while (noCompteChequeInvalide);
    
  // description cheque
  std::string descriptionCheque; 
  bool descriptionChequeInvalide = true;
  do
    {
      cout << "Description : " ;
      getline(cin, descriptionCheque);
      
      if (descriptionCheque.empty())
        {
          descriptionCheque = "Cheque";
          descriptionChequeInvalide = false;
        }
      else
        {
          descriptionChequeInvalide = false;
        }
    } while (descriptionChequeInvalide);
   
  // taux d'intérêt cheque
  double tauxInteretCheque; 
  std::string tauxCheque;
  double tauxInteretMinimum = 0.1; 
  bool tauxChequeInvalide = true;
  do
    {
      cout << "Taux d'intérêt : " ;
      getline(cin, tauxCheque);
              
      if (validerNombre(tauxCheque))
        {
          tauxInteretCheque = std::stod(tauxCheque);
          if(tauxInteretCheque > tauxInteretMinimum)
            {
              tauxChequeInvalide = false;
            }
          else { cout << "taux invalide, recommencez" << endl; }
        }                              
      else { cout << "taux invalide, recommencez" << endl; }
    } while (tauxChequeInvalide);
      
  // solde cheque
  double soldeCheque;       
  std::string soldeCheq;
  bool soldeInvalide = true;
  do
  {
    cout << "Solde : " ;            
    getline(cin, soldeCheq);           
      
    if (validerNombre(soldeCheq))
      {
        soldeCheque = std::stod(soldeCheq);
        soldeInvalide = false;
      }
    else
      {
        cout << "solde invalide, recommencez" << endl;
      }
  } while (soldeInvalide);
  
  // nombre de transaction
  unsigned nombreTransactions; 
  std::string nbrTransactions;
  bool nbrTransactionsInvalide = true;
  do
    {     
      cout << "Nombre de transaction : " ;
      getline(cin, nbrTransactions);           

      if (validerNombre(nbrTransactions))
        {
          nombreTransactions = std::stoi(nbrTransactions);
          if (nombreTransactions > 0 && nombreTransactions <= 40)
            {
              nbrTransactionsInvalide = false;
            }
          else
            {
              cout << "nombre incorrecte, le nobmre de transactions ne peut pas dépasser 40, recommencez" << endl;
            }
        }
      else  {  cout << "nombre incorrecte, recommencez" << endl; }  
    } while (nbrTransactionsInvalide);  
    
  // taux interet minimum
  std::string tauxMin;
  bool tauxMinChequeInvalide = true;
  do
    {
      cout << "Taux d'intérêt minimum : " ;         
      getline(cin, tauxMin);                       
      
      if (tauxMin.empty())
        {
          tauxInteretMinimum = 0.1;
          tauxMinChequeInvalide = false;
        }
      
      else if (validerNombre(tauxMin))
        {
          tauxInteretMinimum = std::stod(tauxMin);
          if(tauxInteretCheque > tauxInteretMinimum)
            {
              tauxMinChequeInvalide = false;
            }
          else { cout << "taux invalide, le taux minimum doit être plus petit que le taux d'intérêt, recommencez" << endl; }
        }
      
      else
        { cout << "taux invalide, recommencez" << endl; }
    } while (tauxMinChequeInvalide);  
    
  // crer un compte cheque pour client
  Cheque clientUnCheque(noCompteCheque, soldeCheque, tauxInteretCheque, nombreTransactions, tauxInteretMinimum, descriptionCheque);
  client1.ajouterCompte(clientUnCheque);
  
  
                                        // EPARGNE //
  
  // info compte epargne
  cout << "Saisir les informations sur le nouveau compte Epargne" << endl;
    
  //numero compte epargne
  unsigned noCompteEpargne; 
  std::string compteEpargne;
  bool noCompteEpargneInvalide = true;
  do
    {
      cout << "Numéro de compte? " ;             
      getline(cin, compteEpargne);
              
      if (validerNombre(compteEpargne))
        {
          if(compteEpargne[0] == '-')
            {
              cout << "numéro invalide, recommencez" << endl; 
            }
          else
            {
              noCompteEpargne = std::stoi(compteEpargne);
              if(noCompteEpargne > 0)    
                {
                  noCompteEpargneInvalide = false;
                }
              else
                {
                  cout << "numéro invalide, recommencez" << endl; 
                }
            }          
        }                              
      else { cout << "numéro invalide, recommencez" << endl; }
    } while (noCompteEpargneInvalide);
    
  // description epargne
  std::string descriptionEpargne; 
  bool descriptionEpargneInvalide = true;
  do
    {
      cout << "Description : " ;
      getline(cin, descriptionEpargne);
      
      if (descriptionEpargne.empty())               
        {
          descriptionEpargne = "Epargne";
          descriptionEpargneInvalide = false;
        }
      else
        {
          descriptionEpargneInvalide = false;
        }
    } while (descriptionEpargneInvalide);
  
   
  // taux d'intérêt epargne
  double tauxInteretEpargne; 
  std::string tauxEpargne;
  bool tauxEpargneInvalide = true;
  do
    {
      cout << "Taux d'intérêt : " ;
      getline(cin, tauxEpargne);
              
      if (validerNombre(tauxEpargne))
        {
          tauxInteretEpargne = std::stod(tauxEpargne);
          if(tauxInteretEpargne >= 0.1 && tauxInteretEpargne <= 3.5)        
            {
              tauxEpargneInvalide = false;
            }
          else { cout << "taux invalide, doit être minimum 0.1% et maximum 3.5%, recommencez" << endl; }
        }                              
      else { cout << "taux invalide, recommencez" << endl; }
    } while (tauxEpargneInvalide);
      
  // solde epargne
  double soldeEpargne;       
  std::string soldeEpar;
  bool soldeEpargneInvalide = true;
  do
  {
    cout << "Solde : " ;         
    getline(cin, soldeEpar);           
      
    if (validerNombre(soldeEpar))
      {
        soldeEpargne = std::stod(soldeEpar);
        if (soldeEpargne >= 0)
          {
            soldeEpargneInvalide = false;
          }
        else
          {
            cout << "solde invalide, recommencez" << endl;
          }
      }
    else
      {
        cout << "solde invalide, recommencez" << endl;
      }
  } while (soldeEpargneInvalide);    
 
  // créer un compte epargne pour client
  Epargne clientUnEpargne(noCompteEpargne, soldeEpargne, tauxInteretEpargne, descriptionEpargne);
  client1.ajouterCompte(clientUnEpargne);
  
  
                                      // RELEVÉ COMPTE CLIENT //
  
  //affichage du relevé de compte
  cout << endl;
  cout << "Relevé de compte" << endl;
  cout << "----------------" << endl;
  cout << client1.reqReleves () << endl;
  
  return 0;
}

*/