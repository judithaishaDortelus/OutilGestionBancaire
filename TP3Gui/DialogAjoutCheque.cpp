/**
 * \file DialogAjoutCheque.cpp
 * \brief Implémentation de la classe DialogAjoutCheque
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 1.0
 * \    4/21/2025
 */

#include "DialogAjoutCheque.h"
#include <QMessageBox>

/** 
 * \brief constructeur par défaut
 * 		  On construit un objet DialogAjoutCheque en utilisant le frameworkQT.
 *                C'est la fenêtre d'ajout d'un compte Cheque du GUI.		  
 * \post L'objet construit a été initialisé et les informations du client peuvent être entrée.
 */
DialogAjoutCheque::DialogAjoutCheque ()
{
  widget.setupUi (this);
}

/**
 * \brief Destructeur de la classe DialogAjoutCheque
 */
DialogAjoutCheque::~DialogAjoutCheque () { }

/** 
 * \brief méthode accesseur retournant le numéro de compte entrée
 * \return un entier positif représentant le numéro de compte
 */
unsigned DialogAjoutCheque::reqNoCompte() const
{
  return widget.noCompteCheque->text().toUInt();
}

/** 
 * \brief méthode accesseur retournant le taux d'intérêt entrée
 * \return un nombre décimal représentant le taux d'intérêt
 */
double DialogAjoutCheque::reqTauxInteret() const
{
  return widget.tauxInteretCheque->text().toDouble();
}

/** 
 * \brief méthode accesseur retournant le solde entrée
 * \return un nombre décimal représentant le solde
 */
double DialogAjoutCheque::reqSolde() const
{
  return widget.soldeCheque->text().toDouble();
}

/** 
 * \brief méthode accesseur retournant la description du compte entrée ou 'Cheque' par défaut
 * \return une chaîne de caractère représentant la description du compte
 */
QString DialogAjoutCheque::reqDescription() const
{
  QString description = widget.descriptionCheque->text().trimmed();
  if (description.isEmpty())
    {
      description = "Cheque";
    }
  return description;
}

/** 
 * \brief méthode accesseur retournant le nombre de transaction
 * \return un entier positif représentant le nombre de transactions du compte
 */
unsigned DialogAjoutCheque::reqNbTransactions() const
{
  return widget.nbTransactions->text().toUInt();
}

/** 
 * \brief méthode accesseur retournant le taux d'intérêt minimum entrée
 * \return un nombre décimal représentant le taux d'intérêt minimum du compte
 */
double DialogAjoutCheque::reqTauxInteretMinimum() const
{
  QString tauxMinTxt = widget.tauxMinimum->text().trimmed();
  
  if (tauxMinTxt.isEmpty())
    {
      return 0.1;
    }
  return tauxMinTxt.toDouble();
}

/**         
 * \brief Méthode ajoutant un compte Cheque vecteur de comptes
 * \post L'objet construit a été initialisé et est affiché sur l'interface d'accueil.
 */
void DialogAjoutCheque::slotAjoutCheque()
{
  if (reqNoCompte() <= 0)
    {
      QString message("Le numéro de compte doit être plus grand que 0");
      QMessageBox::information(this, "ERREUR", message);            
      return;
    }
  
  if (reqTauxInteret() <= 0.1)
    {
      QString message("Le taux d'intérêt minimum doit être plus grand que 0.1%");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }   
  
  if (widget.soldeCheque->text().trimmed().isEmpty())
    {
      QString message("Le solde ne peut pas être vide");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }
  
  if (reqNbTransactions() > 40 || widget.nbTransactions->text().trimmed().isEmpty())
    {
      QString message("Le nombre de transaction ne peut pas dépasser 40 et ne peut pas être vide");
      QMessageBox::information(this, "ERREUR", message);
      return;      
    } 
  
  if (reqTauxInteretMinimum() < 0.1)
    {
      QString message("Le taux d'intérêt minimum doit être plus grand que 0%");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }     
  
  if (reqTauxInteret() < reqTauxInteretMinimum())
    {
      QString message("Le taux d'intérêt minimum ne peut pas être plus grand que le taux d'intérêt");
      QMessageBox::information(this, "ERREUR", message);
      return;
    } 
  
  accept();
}
