/**
 * \file DialogAjoutEpargne.cpp
 * \brief Implémentation de la classe DialogAjoutEpargne
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 1.0
 * \    4/15/2025
 */

#include "DialogAjoutEpargne.h"
#include <QMessageBox>

/** 
 * \brief constructeur par défaut
 * 		  On construit un objet DialogAjoutEpargne en utilisant le frameworkQT.
 *                C'est la fenêtre d'ajout d'un compte Epargne du GUI.		  
 * \post L'objet construit a été initialisé et les informations du client peuvent être entrée.
 */
DialogAjoutEpargne::DialogAjoutEpargne ()
{
  widget.setupUi (this);
}

/**
 * \brief Destructeur de la classe DialogAjoutEpargne
 */
DialogAjoutEpargne::~DialogAjoutEpargne () { }

/** 
 * \brief méthode accesseur retournant le numéro de compte entrée
 * \return un entier positif représentant le numéro de compte
 */
unsigned DialogAjoutEpargne::reqNoCompte() const
{
  return widget.noCompteEpargne->text().toInt();
}

/** 
 * \brief méthode accesseur retournant le taux d'intérêt entrée
 * \return un nombre décimal représentant le taux d'intérêt
 */
double DialogAjoutEpargne::reqTauxInteret() const
{
  return widget.tauxInteretEpargne->text().toDouble();
}

/** 
 * \brief méthode accesseur retournant le solde entrée
 * \return un nombre décimal représentant le solde
 */
double DialogAjoutEpargne::reqSolde() const
{
 return widget.soldeEpargne->text().toDouble();
}

/** 
 * \brief méthode accesseur retournant la description du compte entrée ou 'Epargne' par défaut
 * \return une chaîne de caractère représentant la description du compte
 */
QString DialogAjoutEpargne::reqDescription() const
{
  QString description = widget.descriptionEpargne->text().trimmed();
  if (description.isEmpty())
    {
      description = "Epargne";
    }
  
  return description;
}

/**         
 * \brief Méthode ajoutant un compte Epargne vecteur de comptes
 * \post L'objet construit a été initialisé et est affiché sur l'interface d'accueil.
 */
void DialogAjoutEpargne::slotAjoutEpargne()
{
  if (reqNoCompte() <= 0)
    {
      QString message("Le numéro de compte doit être plus grand que 0");
      QMessageBox::information(this, "ERREUR", message);            
      return;
    }
  
  if (reqTauxInteret() < 0.1 || reqTauxInteret() > 3.5)
    {
      QString message("Le taux d'intérêt doit être entre 0.1 % et 3.5 %");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }
  
  if (reqSolde() < 0)
    {
      QString message("Le solde doit être positif ou nul");
      QMessageBox::information(this, "ERREUR", message);
      return;      
    } 
   
  accept();
}