/**
 * \file CompteTesteur.cpp
 * \brief Test unitaire de la classe Compte
 * \author Judith-Aisha Dortélus
 * \version 1.0
 * \    3/24/2025
 * A tester:
 *          Compte(unsigned p_noCompte, double p_tauxInteret, double p_solde, 
 *                 const std::string& p_description, const util::Date& p_dateOuverture);
 *          unsigned reqNoCompte () const;
 *          double reqTauxInteret() const;
 *          double reqSolde () const;
 *          const std::string reqDescription() const;
 *          const std::string reqDateOuverture() const;
 *          void asgTauxInteret(double p_tauxInteret);
 *          void asgSolde(double p_solde);
 *          void asgDescription(const std::string& p_description); 
 *          
 *          virtual double calculerInteret() const;
 *          virtual std::string reqCompteFormate() const=0;
 *          static bool validerAttributs(unsigned p_noCompte, double p_tauxInteret, const std::string& p_description);
 */
#include <stdlib.h>
#include<gtest/gtest.h>

#include <iostream>
#include <string>
#include <sstream>

#include "Date.h"
#include "Compte.h"
#include "ContratException.h"

using namespace std; 
using namespace bancaire;

/**
 * \class CompteTest
 * \brief Classe de test permettant de tester la classe abstraite Compte
 */
class CompteTest: public Compte
{
public:
  CompteTest(unsigned p_noCompte, double p_tauxInteret, double p_solde, 
                const std::string& p_description, const util::Date& p_dateOuverture)
: Compte(p_noCompte, p_tauxInteret, p_solde, p_description, p_dateOuverture) {};

virtual std::unique_ptr<Compte> clone() const
{
  return std::make_unique<CompteTest>(*this);
} 

virtual std::string reqCompteFormate() const
{
  return Compte::reqCompteFormate();
}

};


/** 
 * \brief Test du constructeur avec paramètres de Compte(unsigned p_noCompte, double p_tauxInteret, double p_solde, 
 *                                                          const std::string& p_description, const util::Date& p_dateOuverture)
 *        cas valide:
 *          constructeurParametreValide : Création d'une compte valide à l'aide du constructeur par paramètres
 *
 *        cas invalides:
 *          noCompteInvalide: numéro de compte <= 0
 *          tauxInteretInvalide : taux d'intérêt <0
 *          descriptionInvalide : description du compte contient une chaîne de caractère vide
 */
TEST(Compte, constructeurParametreValide)        //Quand plusieurs paramètre faire UN TEST pour le chaque attribut du constructeur
{                                               // Faire d'autres TEST pour CHAQUE cas ou le paramètre est invalide - THROW (lancement erreur) - violatiotion precondition du  du contrat
  CompteTest monCompte(2, 0.1, 1001, "description", util::Date(06, 9, 2017));
  
  ASSERT_EQ (monCompte.reqNoCompte(), 2);       // ASSERT_EQ - (expected, actual) - exepected == actual 
  ASSERT_EQ (monCompte.reqTauxInteret(), 0.1);  
  ASSERT_EQ (monCompte.reqSolde(), 1001); 
  ASSERT_EQ (monCompte.reqDescription(), "description"); //ASSERT_STREQ - conçu pour comparer des char - utiliser EQ pour comparer des strings
  ASSERT_EQ (monCompte.reqDateOuverture(), "Mercredi le 06 septembre 2017");
}
        // numéro de compte invalide
TEST (Compte, constructeurParametre_noCompteInvalide)
{
  ASSERT_THROW(CompteTest monCompte(0, 0.2, 1302, "description", util::Date(01, 3, 2000)), PreconditionException)
    << "Le numéro de compte doit être plus grand 0";
}

        // taux d'intérêt invalide
TEST(Compte, constructeurParametre_tauxInteretInvalide)
{
  ASSERT_THROW(CompteTest monCompte(3, -1, 1111, "DESCRIPTION", util::Date(8, 3, 1990)), PreconditionException)
    << "Le taux d'intérêt doit être plus grand ou égale à 0.0" ;
}       

        // description invalide
TEST(Compte, constructeurParametre_descriptionInvalide)
{
  ASSERT_THROW(CompteTest monCompte(9302, 0.0, 21, "", util::Date(04, 11, 1978)), PreconditionException)
    << "La description du compte ne peut pas être vide" ;
}


/**
 * \brief  Test de la méthode static bool Compte::validerAttributs(unsigned p_noCompte, double p_tauxInteret, string& p_description)
 * 	cas valide:
 *          AttributsVrai: vérifier les attributs d'un objet compte valide
 *          NoCompteFaux: vérifier un numéro de compte invalide
 *          TauxInteretFaux: vérifier un taux d'intérêt invalide
 *          DescriptionFaux: vérifier une description invalide
 * 	cas invalide: 
 *          aucun d'identifié
 */                                      
TEST(Compte, validationAttributs_vrai)
{
  ASSERT_TRUE(Compte::validerAttributs(45, 0.3, "La description des attributs est valide"));
}
TEST (Compte, validationNoCompte_faux)
{
  ASSERT_FALSE(Compte::validerAttributs(0, 0.0, "Description numéro de compte - Faux"));
}
TEST(Compte, validationTauxInteret_faux)
{
  ASSERT_FALSE(Compte::validerAttributs(6, -0.2, "Description des taux d'intérêts - Faux"));
}
TEST(Compte, validationDescription_faux)
{
  ASSERT_FALSE(Compte::validerAttributs(90, 0.16, ""));
}


/**
 * \class UnCompte
 * \brief création d'une fixture pour des tests de la classe Compte
 */
class UnCompte: public::testing::Test
{
public:
  UnCompte():
    t_compte(333, 0.0, 666, "description du compte", util::Date(03, 9, 1999))
    {
      
    }
  CompteTest t_compte;
};


/**
 * \brief Test de la méthode unsigned reqNoCompte () const
 *        cas valide:
 *          reqNoComptes: test du numéro de compte et objet compte valide
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompte, reqNoComptes)
{
  ASSERT_EQ(333, t_compte.reqNoCompte());
}


/**
 * \brief Test de la méthode double reqTauxInteret() const
 *        cas valide:
 *          reqTauxInterets: test du taux d'intérêt et objet compte valide 
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompte, reqTauxInterets)
{
  ASSERT_EQ(0.0, t_compte.reqTauxInteret());
}


/**
 * \brief Test de la méthode double reqSolde () const
 *        cas valide:
 *          reqSoldes: test du solde et objet compte valide 
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompte, reqSoldes)
{
  ASSERT_EQ(666, t_compte.reqSolde());
}


/**
 * \brief Test de la méthode const std::string reqDescription() const
 *        cas valide:
 *          reqDescriptions: test de la description et objet compte valide 
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompte, reqDescriptions)
{
  ASSERT_EQ("description du compte", t_compte.reqDescription());
}


/**
 * \brief Test de la méthode const std::string reqDateOuverture() const;
 *        cas valide:
 *          reqDateOuvertures: test de la date d'ouverture et objet compte valide 
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompte, reqDateOuvertures)
{
  ASSERT_EQ("Vendredi le 03 septembre 1999", t_compte.reqDateOuverture());
}


/** 
 * \brief Test de la méthode virtual std::string reqCompteFormate() const
 *        cas valide:
 *          reqComptesFormates: test des informations formatés en string et objet compte valide 
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompte, reqComptesFormates)
{
  string compteTestFormate = 
            "Numero : 333\n"
            "Description : description du compte\n"
            "Date d'ouverture : Vendredi le 03 septembre 1999\n"         
            "Taux d'intérêt : 0\n"
            "Solde : 666$\n" ;
  
  ASSERT_EQ(compteTestFormate, t_compte.reqCompteFormate());
}


/**
 * \brief Test de la méthode void asgTauxInteret(double p_tauxInteret)
 *     	cas valide:
 *          asgTauxInteretValide: assigner un nouveau taux d'intérêt >= 0.0 
 *   	cas invalide:
 *          asgTauxInteretInvalide: assigner un nouveau taux d'intérêt < 0.0 	
 */
TEST_F(UnCompte, asgTauxInteretValide)
{
  t_compte.asgTauxInteret(0.3);
  ASSERT_EQ(0.3, t_compte.reqTauxInteret());
}
TEST_F(UnCompte, asgTauxInteretInvalide)
{
  ASSERT_THROW(t_compte.asgTauxInteret(-0.2), PreconditionException);
}


/**
 * \brief Test de la méthode void asgSolde(double p_solde)
 *     	cas valide:
 *          asgSoldeValide: assigner un nouveau solde != 0
 *   	cas invalide:
 *          asgSoldeInvalide: assigner un nouveau solde == 0	
 */
TEST_F(UnCompte, asgSoldeValide)
{
  t_compte.asgSolde(23.67);
  ASSERT_EQ(23.67, t_compte.reqSolde());
}
TEST_F(UnCompte, asgSoldeInvalide)
{
  ASSERT_THROW(t_compte.asgSolde(0), PreconditionException);
}


/**
 * \brief Test de la méthode void asgDescription(const std::string& p_description)
 *     	cas valide:
 *          asgDescriptionValide: assigner une nouvelle description non vide
 *   	cas invalide:
 *          asgDescriptionInvalide: assigner une nouvelle description vide 
 */
TEST_F(UnCompte, asgDescriptionValide)
{
  t_compte.asgDescription("changeons la description");
  ASSERT_EQ("changeons la description", t_compte.reqDescription ());
}
TEST_F(UnCompte, asgDescriptionInvalide)
{
  ASSERT_THROW(t_compte.asgDescription(""), PreconditionException);
}


/**
 * \brief Test de la méthode virtual double calculerInteret() const
 *     	cas valide:
 *          calculInteret: retourne 0 dans la classe compte
 *   	cas invalide: 
 *          aucun d'identifié
 */
TEST_F(UnCompte, calculInteret)
{
  ASSERT_EQ(0, t_compte.calculerInteret());
}


/** 
 * \brief Test de la méthode virtual std::unique_ptr<Compte> clone() const;
 *        cas valide:
 *          clonePointeurCompte: test du pointeur et de la méthode clone et objet compte valide 
 *        cas invalide:
 *          aucun d'identifié
 */
TEST_F(UnCompte, clonePointeurCompte)
{
  std::unique_ptr<Compte> clonePtrCompte = t_compte.clone();
  ASSERT_EQ(t_compte.reqCompteFormate(), clonePtrCompte->reqCompteFormate());
}
