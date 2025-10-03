/**
 * \file EpargneTesteur.cpp
 * \brief Test unitaire de la classe Epargne
 * \author Judith-Aisha Dortélus
 * \version 1.0
 * \    3/26/2025
 * A tester:
 *          Epargne(unsigned p_noCompte, double p_solde, double p_tauxInteret, const std::string& p_description = "Epargne");
 *          virtual double calculerInteret() const;
 *          virtual std::unique_ptr<Compte> clone() const override;
 *          virtual std::string reqCompteFormate() const;
 *          static bool validerAttributsEpargne(double p_solde, double p_tauxInteret); 
 */
#include <stdlib.h>
#include<gtest/gtest.h>

#include <iostream>
#include <string>
#include <sstream>

#include "Date.h"
#include "Compte.h"
#include "Epargne.h"
#include "ContratException.h"

using namespace std; 
using namespace bancaire;

/** 
 * \brief Test du constructeur avec paramètres Epargne(unsigned p_noCompte, double p_solde, double p_tauxInteret, 
 *                                                        const std::string& p_description = "Epargne")
 *        cas valide:
 *          constructeurParametreValide : Création d'une compte cheque valide à l'aide du constructeur par paramètres
 *
 *        cas invalides:
 *          soldeEpargneInvalide: solde epargne < 0
 *          tauxInteretInvalide : taux d'intérêt < 0.1 || taux d'intérêt > 3.5
 */
TEST(Epargne, constructeurParametreValide)        
{                                               
  Epargne compteEpargne(33, 2500, 3.1);
  
  ASSERT_EQ (compteEpargne.reqNoCompte(), 33);       
  ASSERT_EQ (compteEpargne.reqSolde(), 2500); 
  ASSERT_EQ (compteEpargne.reqTauxInteret(), 3.1);  
  ASSERT_EQ (compteEpargne.reqDescription(), "Epargne"); 
}
        // solde epargne invalide
TEST (Epargne, constructeurParametre_soldeEpargneInvalide)
{
  ASSERT_THROW(Epargne compteEpargne(999, -10.99, 2.2), PreconditionException)
    << "Le solde du compte epargne doit être plus grand ou égale à 0";
}

        // taux d'intérêt invalide
TEST(Epargne, constructeurParametre_tauxInteretInvalide)
{
  ASSERT_THROW(Epargne compteEpargne(1001, 9.99, 0.0), PreconditionException)
    << "Le taux d'intérêt doit être plus grand ou égale 0.1% et plus petit ou égale à 3,5%" ;
  
  ASSERT_THROW(Epargne compteEpargne(1030, 1112, 3.6), PreconditionException)
    << "Le taux d'intérêt doit être plus grand ou égale 0.1% et plus petit ou égale à 3,5%" ;  
}       


/**
 * \brief  Test de la méthode static bool validerAttributsEpargne(double p_solde, double p_tauxInteret)
 * 	cas valide:
 *          AttributsVrai: vérifier les attributs d'un objet epargne valide
 *          soldeEpargneFaux: vérifier un numéro de compte epargne invalide
 *          TauxInteretFaux: vérifier un taux d'intérêt invalide
 * 	cas invalide: 
 *          aucun d'identifié
 */                                      
TEST(Epargne, validationAttributs_vrai)
{
  ASSERT_TRUE(Epargne::validerAttributsEpargne(33.33, 0.3));
}
TEST (Epargne, validationSoldeEpargne_faux)
{
  ASSERT_FALSE(Epargne::validerAttributsEpargne(-13.05, 3.4));
}
TEST(Epargne, validationTauxInteret_faux)
{
  ASSERT_FALSE(Epargne::validerAttributsEpargne(67, 0.0));
}


/**
 * \class UnCompteEpargne
 * \brief création d'une fixture pour des tests de la classe Epargne
 */
class UnCompteEpargne: public::testing::Test
{
public:
  UnCompteEpargne():
    t_compteEpargne(1300, 70.00, 3.3)
    {
      
    }
  Epargne t_compteEpargne;
};


/**
 * \brief Test de la méthode virtual double calculerInteret() const
 *     	cas valide:
 *          calculInteretEpargne: retourne le produit du solde par le taux d'intérêt 
 *   	cas invalide: 
 *          aucun d'identifié
 */
TEST_F(UnCompteEpargne, calculInteretEpargne)
{
  ASSERT_EQ(231.00, t_compteEpargne.calculerInteret());
}


/** 
 * \brief Test de la méthode virtual std::string reqCompteFormate() const
 *        cas valide:
 *          reqEpargneFormates: test des informations formatés en string et objet epargne valide 
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompteEpargne, reqEpargneFormates)
{
  std::ostringstream oss;
  
  oss << "Compte Epargne" << endl;
  oss << "Numero : " << t_compteEpargne.reqNoCompte() << endl;
  oss << "Description : " << t_compteEpargne.reqDescription() << endl;
  oss << "Date d'ouverture : " << t_compteEpargne.reqDateOuverture() << endl;
  oss << "Taux d'intérêt : " << t_compteEpargne.reqTauxInteret() << endl;
  oss << "Solde : " << t_compteEpargne.reqSolde() << "$" << endl;
  oss << "Interet : " << t_compteEpargne.calculerInteret()/100 << "$" ;

  ASSERT_EQ(oss.str(), t_compteEpargne.reqCompteFormate());
}


/** 
 * \brief Test de la méthode virtual std::unique_ptr<Compte> clone() const override;
 *        cas valide:
 *          clonePointeurEpargne: test du pointeur et de la méthode clone et objet epargne valide 
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompteEpargne, clonePointeurEpargne)
{
  std::unique_ptr<Compte> clonePtrEpargne = t_compteEpargne.clone();
  ASSERT_EQ(t_compteEpargne.reqCompteFormate(), clonePtrEpargne->reqCompteFormate());
}
