/**
 * \file GestionCompteGUI.cpp
 * \brief Implémentation de la classe GestionCompteGUI
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 1.0
 * \    4/15/2025
 */

#include "GestionCompteGUI.h"
#include "DialogAjoutEpargne.h"
#include "Epargne.h"
#include "DialogAjoutCheque.h"
#include "Cheque.h"
#include "DialogSupprimer.h"
#include "CompteException.h"
#include <QMessageBox>


/** 
 * \brief constructeur par défaut
 * 		  On construit un objet GestionCompteGUI en utilisant le frameworkQT.
 *                C'est la fenêtre d'accueil du GUI.
 * 		  Les attributs assignés sont celui d'un client par défaut. 
 * \post L'objet construit a été initialisé et les informations du client sont affichés.
 */
GestionCompteGUI::GestionCompteGUI () : m_client(3333, "Roti", "Poulet", util::Date(07, 9, 1988), "3336669999")
{
  widget.setupUi (this);
  widget.afficherClient->setPlainText(m_client.reqReleves().c_str());
}


/**
 * \brief Destructeur de la classe GestionCompteGUI
 */
GestionCompteGUI::~GestionCompteGUI () { }


/**         
 * \brief Méthode ajoutant un compte Epargne vecteur de comptes
 * \post L'objet construit a été initialisé et est affiché sur l'interface d'accueil.
 */
void GestionCompteGUI::slotAjoutEpargne()
{
  DialogAjoutEpargne ajoutEpargne;
  if (ajoutEpargne.exec())
    {
      try
        {
          bancaire::Epargne ep(ajoutEpargne.reqNoCompte(),
                               ajoutEpargne.reqSolde(),
                               ajoutEpargne.reqTauxInteret(),
                               ajoutEpargne.reqDescription().toStdString());
          m_client.ajouterCompte(ep);
        
        }
      catch(CompteDejaPresentException& e)
        {
          QString message = (e.what());
          QMessageBox::information(this, "ERREUR:CE COMPTE EXISTE DÉJA", message);
        }
    }
  widget.afficherClient->setPlainText(m_client.reqReleves().c_str());
}


/**         
 * \brief Méthode ajoutant un compte Cheque vecteur de comptes
 * \post L'objet construit a été initialisé et est affiché sur l'interface d'accueil.
 */
void GestionCompteGUI::slotAjoutCheque()
{
  DialogAjoutCheque ajoutCheque;
  if (ajoutCheque.exec())
    {
      try
        {
          bancaire::Cheque ch(ajoutCheque.reqNoCompte(),        
                              ajoutCheque.reqSolde(),
                              ajoutCheque.reqTauxInteret(),
                              ajoutCheque.reqNbTransactions(),
                              ajoutCheque.reqTauxInteretMinimum(),
                              ajoutCheque.reqDescription().toStdString());
          m_client.ajouterCompte(ch);
        }
      catch(CompteDejaPresentException& e)
        {
          QString message = (e.what());
          QMessageBox::information(this, "ERREUR:CE COMPTE EXISTE DÉJA", message);
        }
    }
  widget.afficherClient->setPlainText(m_client.reqReleves().c_str());
}

/**
 * \brief Supprime un compte du client si le numéro entré est valide.
 * 
 * Ouvre la boîte de dialogue DialogSupprimer. Si un numéro de compte est fourni,
 * tente de le supprimer. Affiche une erreur si le compte est absent.
 * Met à jour l'affichage du relevé client.
 */
void GestionCompteGUI::slotSupprimer()
{
    DialogSupprimer supp;

    if (supp.exec()) {
        try {
            unsigned int numeroCompte = supp.reqNoCompte();

            m_client.supprimerCompte(numeroCompte);
        }
        catch (CompteAbsentException &e) {
            QString message = e.what();
            QMessageBox::information(this, "ERREUR", message);
        }
    }

    widget.afficherClient->setPlainText(m_client.reqReleves().c_str());
}