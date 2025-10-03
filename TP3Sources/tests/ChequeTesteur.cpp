/**
 * \file ChequeTesteur.cpp
 * \brief Test unitaire de la classe Cheque
 * \author Judith-Aisha Dortélus
 * \version 1.0
 * \    3/28/2025
 * A tester:
 *          Cheque(unsigned p_noCompte, double p_solde, double p_tauxInteret, unsigned p_nombreTransactions, 
 *                 double p_tauxInteretMinimum = 0.1, const std::string& p_description = "Cheque");
 *          unsigned reqNbrTransactions() const;
 *          double reqTauxInteretMinimum() const;
 *          void asgNbrTransactions(unsigned p_nombreTransactions);
 *          virtual double calculerInteret() const;
 *          virtual std::string reqCompteFormate() const;  
 *          virtual std::unique_ptr<Compte> clone() const override;      
 *          static bool validerAttributsCheque(double p_tauxInteretMinimum, unsigned p_nombreTransations);
 */
#include <stdlib.h>
#include<gtest/gtest.h>

#include <iostream>
#include <string>
#include <sstream>

#include "Date.h"
#include "Compte.h"
#include "Cheque.h"
#include "ContratException.h"

using namespace std; 
using namespace bancaire;

/** 
 * \brief Test du constructeur avec paramètres Cheque(unsigned p_noCompte, double p_solde, double p_tauxInteret, unsigned p_nombreTransactions, 
 *                                                          double p_tauxInteretMinimum = 0.1, const std::string& p_description = "Cheque")
 *        cas valide:
 *          constructeurParametreValide : Création d'une compte cheque valide à l'aide du constructeur par paramètres
 *
 *        cas invalides:
 *          nbrTransactionsInvalide: nombre de transaction < 0 || nombre de transaction > 40
 *          tauxInteretMinimumInvalide : taux d'intérêt minimum < 0.1
 */
TEST(Cheque, constructeurParametreValide)        
{                                               
  Cheque compteCheque(514, -3000, 2.7, 26);
  
  ASSERT_EQ (compteCheque.reqNoCompte(), 514);       
  ASSERT_EQ (compteCheque.reqSolde(), -3000); 
  ASSERT_EQ (compteCheque.reqTauxInteret(), 2.7);
  ASSERT_EQ (compteCheque.reqNbrTransactions(), 26);  
  ASSERT_EQ (compteCheque.reqTauxInteretMinimum(), 0.1);
  ASSERT_EQ (compteCheque.reqDescription(), "Cheque"); 
}

// nombre de transaction invalide
TEST (Cheque, constructeurParametre_nbrTransactionsInvalide)
{
  ASSERT_THROW(Cheque compteCheque(977, -944.20, 1.7, 43), PreconditionException)
    << "Le nombre de transactions doit être plus grand que 0 et plus petit ou égale à 40";
}

// taux d'intérêt minimum invalide
TEST(Cheque, constructeurParametre_tauxInteretMinimumInvalide)
{
  ASSERT_THROW(Cheque compteCheque(1021, 999.99, 0, 34, 0.0), PreconditionException)
    << "Le taux d'intérêt minimum doit être plus grand que 0 %" ; 
  
  ASSERT_THROW(Cheque compteCheque(1021, 999.99, 0.2, 34, 0.5), PreconditionException)
    << "Le taux d'intérêt minimum doit être plus petit que le taux d'intérêt" ;   
}


/** 
 * \brief  Test de la méthode static bool validerAttributsCheque(double p_tauxInteretMinimum, unsigned p_nombreTransations)
 * 	cas valide:
 *          AttributsVrai: vérifier les attributs d'un objet cheque valide
 *          nbrTransactionsFaux: vérifier le nombre de transactions du compte cheque invalide
 *          tauxInteretMinimumFaux: vérifier un taux d'intérêt minimum invalide
 * 	cas invalide: 
 *          aucun d'identifié
 */                
TEST(Cheque, validationAttributs_vrai)
{
  ASSERT_TRUE(Cheque::validerAttributsCheque(0.5, 40));
}
TEST (Cheque, validationNbrTransactions_faux)
{
  ASSERT_FALSE(Cheque::validerAttributsCheque(0.2, 47));
}
TEST(Cheque, validationTauxInteretMinimum_faux)
{
  ASSERT_FALSE(Cheque::validerAttributsCheque(0.0, 36));
}


/** 
 * \class UnCompteCheque
 * \brief création d'une fixture pour des tests de la classe Cheque
 */
class UnCompteCheque: public::testing::Test
{
public:
  UnCompteCheque():
    t_compteCheque(4454, -2100, 3.7, 13)
    {
      
    }
  Cheque t_compteCheque;
};


/** 
 * \brief Test de la méthode unsigned reqNbrTransactions() const
 *        cas valide:
 *          reqNbrTransactions: test du nombre de transaction et objet cheque valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompteCheque, reqNbrTransactions)
{
  ASSERT_EQ(13, t_compteCheque.reqNbrTransactions());
}


/** 
 * \brief Test de la méthode double reqTauxInteretMinimum() const
 *        cas valide:
 *          reqTauxInteretMin: test du taux d'intérêt minimum du compte et objet cheque valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompteCheque, reqTauxInteretMin)
{
  ASSERT_EQ(0.1, t_compteCheque.reqTauxInteretMinimum());
}


/** 
 * \brief Test de la méthode void asgNbrTransactions(unsigned p_nombreTransactions)
 *     	cas valide:
 *          asgNbrTransacValide: assigner un nouveau nombre de transaction > 0 && <= 40
 *   	cas invalide:
 *          asgNbrTransacInvalide: assigner un nouveau nombre de transaction <0 || >40
 */
TEST_F(UnCompteCheque, asgNbrTransacValide)
{
  t_compteCheque.asgNbrTransactions(38);
  ASSERT_EQ(38, t_compteCheque.reqNbrTransactions());
}
TEST_F(UnCompteCheque, asgNbrTransacInvalide)
{
  ASSERT_THROW(t_compteCheque.asgNbrTransactions(41), PreconditionException);
  ASSERT_THROW(t_compteCheque.asgNbrTransactions(-1), PreconditionException);
}


/** 
 * \brief Test de la méthode virtual double calculerInteret() const
 *     	cas valide:
 *          calculInteretCheque: retourne le produit du solde et du taux d'interet minimum, du taux d'interet du compte 
 *                                      ou de 0.0 (si le solde est positif) selon le nombre de transactions dans le compte cheque
 *   	cas invalide: 
 *          aucun d'identifié
 */
TEST_F(UnCompteCheque, calculInteretCheque)
{ 
        //0 à 10 transactions
  t_compteCheque.asgNbrTransactions(3);
  ASSERT_DOUBLE_EQ(2.1, t_compteCheque.calculerInteret());
  
        // 11 à 25 transactions
  t_compteCheque.asgNbrTransactions(13);
  ASSERT_DOUBLE_EQ(2.94, t_compteCheque.calculerInteret());
  
        // 26 à 35 transactions
  t_compteCheque.asgNbrTransactions(30);
  ASSERT_DOUBLE_EQ(3.78, t_compteCheque.calculerInteret());
  
       // 35 à 40 transactions
  t_compteCheque.asgNbrTransactions(38);
  ASSERT_DOUBLE_EQ(77.7, t_compteCheque.calculerInteret());

       // si le solde est positif 
  Cheque compteCheque(55, 3200, 5.4, 40);
  ASSERT_DOUBLE_EQ(0, compteCheque.calculerInteret());
}


/**  
 * \brief Test de la méthode virtual std::string reqCompteFormate() const
 *        cas valide:
 *          reqChequeFormates: test des informations formatés en string et objet cheque valide 
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompteCheque, reqChequeFormates)
{
  std::ostringstream oss;
  
  oss << "Compte Cheque" << endl;
  oss << "Numero : " << t_compteCheque.reqNoCompte() << endl;
  oss << "Description : " << t_compteCheque.reqDescription() << endl;
  oss << "Date d'ouverture : " << t_compteCheque.reqDateOuverture() << endl;
  oss << "Taux d'intérêt : " << t_compteCheque.reqTauxInteret() << endl;
  oss << "Solde : " << t_compteCheque.reqSolde() << "$" << endl;
  oss << "Nombre de transactions : " << t_compteCheque.reqNbrTransactions() << endl;
  oss << "Taux d'intérêt minimum : " << t_compteCheque.reqTauxInteretMinimum() << endl;
  oss << "Interet : " << t_compteCheque.calculerInteret() << "$" ;

  ASSERT_EQ(oss.str(), t_compteCheque.reqCompteFormate());
}


/** 
 * \brief Test de la méthode virtual std::unique_ptr<Compte> clone() const override;
 *        cas valide:
 *          clonePointeurCheque: test du pointeur et de la méthode clone et objet cheque valide 
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompteCheque, clonePointeurCheque)
{
  std::unique_ptr<Compte> clonePtrCheque = t_compteCheque.clone();
  ASSERT_EQ(t_compteCheque.reqCompteFormate(), clonePtrCheque->reqCompteFormate());
}
