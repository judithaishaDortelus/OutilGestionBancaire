/**
 * \file ClientTesteur.cpp
 * \brief Test unitaire de la classe Client
 * \author Judith-Aisha Dortélus & Michaël Denis
 * \version 2.0
 * \    4/14/2025
 * A tester:                 
 *          Client(unsigned p_noFolio, const std::string& p_nom, const std::string& p_prenom, 
 *                  const util::Date& p_dateNaissance, const std::string& p_telephone);             
 *          Client(const Client& p_client);               
 *          Client& operator=(const Client& p_client);  
 *          unsigned reqNoFolio() const;
 *          const std::string reqTelephone() const;   
 *          const std::string reqNom() const;
 *          const std::string reqPrenom() const;
 *          const std::string reqDateNaissance() const;
 *          size_t reqNbrComptes() const;                                       
 *          bool operator<(const Client& p_noFolio) const; 
 *          std::string reqClientFormate() const;
 *          std::string reqReleves() const;
 *          static bool validerAttributsClient(unsigned p_noFolio, const std::string& p_nom, const std::string& p_prenom,
 *                                             const util::Date& p_dateNaissance, const std::string& p_telephone);
 *          std::string reqTelephoneFormate() const;
 * 
 *          void ajouterCompte (const Compte& p_nouveauCompte);
 *          void supprimerCompte (int p_noCompte);
 * 
 * 
 */
#include <stdlib.h>
#include<gtest/gtest.h>

#include <iostream>
#include <string>
#include <sstream>

#include "Date.h"
#include "Compte.h"
#include "Cheque.h"
#include "Client.h"
#include "validationFormat.h"
#include "ContratException.h"
#include "CompteException.h"

using namespace std; 
using namespace bancaire;

/**    
 * \brief Test du constructeur avec paramètres Client(unsigned p_noFolio, const std::string& p_nom, const std::string& p_prenom, 
 *                                                    const util::Date& p_dateNaissance, const std::string& p_telephone)
 *        cas valide:
 *          constructeurParametreValide : Création d'un objet Client valide à l'aide du constructeur par paramètres
 *
 *        cas invalides:
 *          noFolioInvalide : numéro de folio < 1000 || >= 10'000
 *          telephoneInvalide : numéro de téléphone du client contient une chaîne de caractère vide || > 10 nombres || < 10 nombres
 *          anneeNaissanceInvalide : année de naissance < 1970 || > 2037
 */
TEST(Client, constructeurParametreValide)        
{                                               
  Client client1(1001, "Doe", "Jane", util::Date(02, 07, 1972), "333 111 9999");
  
  ASSERT_EQ (client1.reqNoFolio(), 1001);       
  ASSERT_EQ (client1.reqNom(), "Doe"); 
  ASSERT_EQ (client1.reqPrenom(), "Jane");
  ASSERT_EQ (client1.reqDateNaissance(), "Dimanche le 02 juillet 1972");  
  ASSERT_EQ (client1.reqTelephone(), "333 111 9999");
}

// numéro de folio invalide
TEST (Client, constructeurParametre_noFolioInvalide)
{
  ASSERT_THROW(Client client1(10000, "Deep", "Jonas", util::Date(07, 07, 1977), "1114447676"), PreconditionException)
    << "Le numéro de folio doit être plus grand ou égale à 1000 et plus petit que 10 000" ;
}

// téléphone invalide
TEST(Client, constructeurParametre_telephoneInvalide)
{
  ASSERT_THROW(Client client1(9999, "Tubies", "Tele", util::Date(02, 10, 2030), " "), PreconditionException)
    << "Le numéro de téléphone ne peut pas être vide" ; 
  
  ASSERT_THROW(Client client1(9999, "Tubies", "Tele", util::Date(02, 10, 2030), "1116 444 7676"), PreconditionException)
    << "Le numéro de téléphone doit être de 10 chiffres" ; 
}

// année de naissance invalide
TEST(Client, constructeurParametre_anneeNaissanceInvalide)
{
  ASSERT_THROW(Client client1(3009, "Népo", "Litano", util::Date(9, 05, 1969), "222 444 6666"), PreconditionException)
    << "L'année de naissance doit être entre 1970 et 2037" ;
  
  ASSERT_THROW(Client client1(3009, "Népo", "Litano", util::Date(9, 05, 2038), "222 444 6666"), PreconditionException)
    << "L'année de naissance doit être entre 1970 et 2037" ; 
}


/**
 * \brief  Test de la méthode static bool validerAttributsClient(unsigned p_noFolio, const std::string& p_nom, const std::string& p_prenom,
 *                                                               const util::Date& p_dateNaissance, const std::string& p_telephone)
 * 	cas valide:
 *          AttributsVrai: vérifier les attributs d'un objet client valide
 *          noFolioFaux: vérifier le numéro de folio du client invalide
 *          anneeNaissanceFaux: vérifier l'année de naissance invalide
 *          telephoneFaux : vérifier le numéro de téléphone invalide
 * 
 * 	cas invalide: 
 *          aucun d'identifié
 */             
TEST(Client, validationAttributs_vrai)
{
  ASSERT_TRUE(Client::validerAttributsClient(2002, "Masse", "Manie", util::Date(27, 02, 1988), "666 666 9999"));
}
TEST (Client, validationNoFolio_faux)
{
  ASSERT_FALSE(Client::validerAttributsClient(999, "Poe", "Ja", util::Date(23, 07, 1999), "666666 9999"));
}
TEST(Client, validationAnneeNaissance_faux)
{
  ASSERT_FALSE(Client::validerAttributsClient(1008, "Que", "Soe", util::Date(17, 01, 2040), "666-6669999"));
}
TEST(Client, validationTelephoneFaux_faux)
{
  ASSERT_FALSE(Client::validerAttributsClient(3333, "Maye", "Pol", util::Date(7, 10, 2033), "666 9666 9999"));
}


/**    
 * \brief Test du constructeur de copie Client(const Client& p_client)
 *        cas valide:
 *          constructeurCopieValide : Création d'un objet Client valide à partir de l'objet passé en paramètre
 *
 *        cas invalides:
 *          aucun d'identifié
 */
TEST (Client, constructeurCopieValide)
{
  Client client1(3333, "Dwet", "Filan", util::Date(18, 9, 1991), "777 666 3344");
  Epargne clientEpargne1(1300, 69.69, 2.1);
  Cheque clientCheque1(55, 3200, 5.4, 40);
  
  client1.ajouterCompte(clientEpargne1);
  client1.ajouterCompte(clientCheque1);
  
  Client client2(client1);
  
  ASSERT_EQ (client1.reqClientFormate(), client2.reqClientFormate ());
  ASSERT_EQ (client1.reqReleves(), client2.reqReleves());
  ASSERT_EQ (client1.reqNbrComptes(), client2.reqNbrComptes());
} 


/**  
 * \brief Test de l'opérateur de copie Client& operator=(const Client& p_client)
 *        cas valide:
 *          operateurCopieValide : Création d'un objet Client valide à partir de l'objet passé en paramètre
 *
 *        cas invalides:
 *          parametreInvalide : l'objet client en paramètre est le même que l'objet courant
 */
TEST (Client, operateurCopieValide)
{
  Client client1(3333, "Dwet", "Filan", util::Date(18, 9, 1991), "777 666 3344");
  Epargne clientEpargne1(1300, 69.69, 2.1);
  Cheque clientCheque1(55, 3200, 5.4, 40);
  
  client1.ajouterCompte(clientEpargne1);
  client1.ajouterCompte(clientCheque1);
  
  Client client2(6666, "Tewd", "Nalif", util::Date(8, 02, 2001), "333 444 6666");
  Epargne clientEpargne2(3100, 77.77, 1.1);
  
  client2.ajouterCompte(clientEpargne2);
  
  ASSERT_NE (client1.reqClientFormate(), client2.reqClientFormate ());
  ASSERT_NE (client1.reqReleves(), client2.reqReleves());
  ASSERT_NE (client1.reqNbrComptes(), client2.reqNbrComptes());
  
  client2 = client1;
  
  ASSERT_EQ (client1.reqClientFormate(), client2.reqClientFormate ());
  ASSERT_EQ (client1.reqReleves(), client2.reqReleves());
  ASSERT_EQ (client1.reqNbrComptes(), client2.reqNbrComptes());
}

// l'objet en paramètre invalide 
TEST (Client, operateurCopie_parametreInvalide)
{
  Client client1(6666, "Sal", "Limas", util::Date(9, 03, 2012), "3339991212");
  ASSERT_THROW(client1 = client1, PreconditionException)
    << "L'affectation de l'objet est invalide puisqu'ils sont identiques" ;
}


/** 
 * \class UnClient
 * \brief création d'une fixture pour des tests de la classe Client
 */

class UnClient: public::testing::Test
{
public:
  UnClient():
    t_unClient(1002, "Li", "Samone", util::Date(03, 9, 2022), "123 4449999")
    {
      
    }
  Client t_unClient;
};


/** 
 * \brief Test de la méthode unsigned reqNoFolio() const
 *        cas valide:
 *          reqNoFolio: test du numéro de folio et objet client valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnClient, reqNoFolio)
{
  ASSERT_EQ(1002, t_unClient.reqNoFolio());
} 


/** 
 * \brief Test de la méthode const std::string reqTelephone() const
 *        cas valide:
 *          reqTelephone: test du numéro de téléphone et objet client valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnClient, reqTelephone)
{
  ASSERT_EQ("123 4449999", t_unClient.reqTelephone());
}


/** 
 * \brief Test de la méthode const std::string reqNom() const
 *        cas valide:
 *          reqNom: test du nom et objet client valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnClient, reqNom)
{
  ASSERT_EQ("Li", t_unClient.reqNom());
}


/** 
 * \brief Test de la méthode const std::string reqPrenom() const
 *        cas valide:
 *          reqPrenom: test du prénom et objet client valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnClient, reqPrenom)
{
  ASSERT_EQ("Samone", t_unClient.reqPrenom());
}


/** 
 * \brief Test de la méthode const std::string reqDateNaissance() const
 *        cas valide:
 *          reqDateNaissance: test de la date de naissance et objet client valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnClient, reqDateNaissance)
{
  ASSERT_EQ("Samedi le 03 septembre 2022", t_unClient.reqDateNaissance());
}


/** 
 * \brief Test de la méthode std::string reqTelephoneFormate() const
 *        cas valide:
 *          reqTelephoneFormate: test du numéro de téléphone formaté et objet client valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnClient, reqTelephoneFormate)
{
  ASSERT_EQ("123 444-9999", t_unClient.reqTelephoneFormate());
}


/** 
 * \brief Test de la méthode std::string reqClientFormate() const
 *        cas valide:
 *          reqClientFormate: test des informations du client formaté et objet client valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnClient, reqClientFormate)
{
  std::ostringstream oss;
  
  oss << "Client no de folio : " << t_unClient.reqNoFolio() << endl;
  oss << t_unClient.reqPrenom() << " " << t_unClient.reqNom() << endl;
  oss << "Date de naissance : " << t_unClient.reqDateNaissance() << endl;
  oss << t_unClient.reqTelephoneFormate() << endl;
  
  ASSERT_EQ(oss.str(), t_unClient.reqClientFormate());
}


/**     
 * \brief Test de la méthode size_t reqNbrComptes() const
 *     Cas valide:
 *       nbrComptes : test du nombre de comptes que le client possède et objet valide 
 *     Cas invalide: 
 *       aucun d'identifié
 */
TEST_F (UnClient, nbrComptes)
{
  Epargne unClientEpargne(777, 67.66, 1.7);
  t_unClient.ajouterCompte(unClientEpargne);
  
  Client t_unClient2(t_unClient);
  ASSERT_EQ(1, t_unClient.reqNbrComptes());
  ASSERT_EQ(t_unClient.reqNbrComptes(), t_unClient2.reqNbrComptes());
  
  Epargne unClient2Epargne(333, 66.66, 2.1);
  t_unClient2.ajouterCompte(unClient2Epargne);
  
  ASSERT_EQ(2, t_unClient2.reqNbrComptes());
  ASSERT_NE(t_unClient.reqNbrComptes(), t_unClient2.reqNbrComptes());
}


/** 
 * \brief Test de la méthode bool operator<(const Client& p_noFolio) const
 *        cas valide:
 *          folioPlusPetit: test de l'opérateur de comparaison < sur le numéro de folio de deux objets client valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnClient, folioPlusPetit)
{
  Client t_unClient2(2222, "Luis", "Rameno", util::Date(06, 06, 2011), "9992229999");
  
  ASSERT_LT(t_unClient.reqNoFolio(), t_unClient2.reqNoFolio());
  ASSERT_GT(t_unClient2.reqNoFolio(), t_unClient.reqNoFolio());
  
  ASSERT_TRUE(t_unClient < t_unClient2);
  ASSERT_FALSE(t_unClient2 < t_unClient);
}


/** 
 * \brief Test de la méthode std::string reqReleves() const
 *        cas valide:
 *          reqReleves: test des informations et comptes du client formaté et objet client valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnClient, reqReleves)
{
  Epargne unClientTestEpargne(222, 77.77, 3.1);
  Cheque unClientTestCheque(111, 1200, 2.4, 37);
  
  t_unClient.ajouterCompte(unClientTestEpargne);
  t_unClient.ajouterCompte(unClientTestCheque);   
  
  Client t_unClient2(t_unClient);
  
  ASSERT_EQ (t_unClient.reqReleves(), t_unClient2.reqReleves());
}

/**
 * \brief Test de la méthode void ajouterCompte (const Compte& p_nouveauCompte)
 *     Cas valide:
 *       ajoutCompte : ajout d'un compte au vecteur de comptes associé au client
 *     Cas invalide: 
 *       ajoutCompte : ajout d'un compte avec un compte déjà existant
 */
TEST_F (UnClient, ajouterCompte)
{
  Epargne unClientEpargne(222, 77.77, 3.1);
  Cheque unClientCheque(111, 1200, 2.4, 37);
  
  t_unClient.ajouterCompte(unClientEpargne);
  t_unClient.ajouterCompte(unClientCheque);
 
  ASSERT_EQ(2, t_unClient.reqNbrComptes());  
}

TEST_F (UnClient, ajouterCompte_DejaPresent_Exception)
{
  
  Cheque compte1(12345, 1000.0, 0.5, 33);

  t_unClient.ajouterCompte(compte1);

  ASSERT_THROW(t_unClient.ajouterCompte(compte1), CompteDejaPresentException);
}

/**
 * \brief Test de la méthode void supprimerCompte (int p_noCompte)
 *     Cas valide:
 *       suppression d’un compte existant dans la liste du client
 *     Cas invalide:
 *       tentative de suppression d’un compte non présent → exception attendue
 */

TEST_F(UnClient, SupprimerCompte_Valide)
{
  Epargne UnCompteE(22, 22.22, 0.3);
  t_unClient.ajouterCompte(UnCompteE);
  t_unClient.supprimerCompte(22);
  
  ASSERT_EQ(0, t_unClient.reqNbrComptes());
}

TEST_F(UnClient, SupprimerCompte_Absent_Exception)
{
  ASSERT_THROW(t_unClient.supprimerCompte(12345), CompteAbsentException);
}