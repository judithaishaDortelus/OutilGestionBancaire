/**
 * \file UtilisationTP3.cpp
 * \brief Programme minimaliste utilisant la classe Client avec différents comptes.
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 1.0
 * \    4/15/2025
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

int main ()
{
  Client client1(3333, "Roti", "Poulet", Date(07, 9, 1988), "3336669999");
  
  
                          // test exception ajouterCompte //
  Cheque cheque1(20, 33.33, 2.3, 33);
  client1.ajouterCompte(cheque1);
  
  //client1.ajouterCompte(cheque1);
  //cout << client1.reqReleves() << endl;   // exception CompteDejaPresentException est bien lancé

  Epargne epargne1(22, 22.22, 0.3);
  client1.ajouterCompte(epargne1);
  cout << client1.reqReleves() << endl;
 
  
                             // test exception supprimerCompte //
  client1.supprimerCompte(20);
  cout << client1.reqReleves() << endl;
  
  //client1.supprimerCompte(33);
  //cout << client1.reqReleves() << endl;   // exception CompteAbsentException est bien lancé
  
  return 0;
}

// Client(unsigned p_noFolio, const std::string& p_nom, const std::string& p_prenom, 
//          const util::Date& p_dateNaissance, const std::string& p_telephone); 

// Cheque(unsigned p_noCompte, double p_solde, double p_tauxInteret, unsigned p_nombreTransactions, 
//        double p_tauxInteretMinimum = 0.1, const std::string& p_description = "Cheque");

// Epargne(unsigned p_noCompte, double p_solde, double p_tauxInteret, const std::string& p_description = "Epargne");