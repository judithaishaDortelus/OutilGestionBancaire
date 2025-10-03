/**
 * \file GestionCompteGUI.h
 * \brief GUI d'un programme minimaliste pour la gestion de compte du client. 
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 1.0
 * \    4/15/2025
 */

#ifndef _GESTIONCOMPTEGUI_H
#define _GESTIONCOMPTEGUI_H

#include "ui_GestionCompteGUI.h"
#include "Client.h"

/**
 * \class GestionCompteGUI
 * \brief Classe GUI d'acceuil servant à la gestion des comptes du client.
 *
 *              La classe maintient dans un état cohérent ces renseignements et
 *              est construit en utilisant le framework Qt.           
 *              Cette classe contient les interfaces pour l'ajout des comptes
 *              Epargne et Cheque du client également à supprimer un compte si nécessaire.
 *              La classe ajoute et suprrime que des comptes si le cas est valide.
 *              C'est la responsabilité de l'utilisateur de la classe de s'en asssurer.  
 *            
 * \slotAjoutEpargne Slot de l'interface pour l'ajout d'un compte Epargne
 * \slotAjoutCheque  Slot de l'interface d'acceuil pour l'ajout d'un compte Cheque 
 * \slotSuprrimer    Slot de l'interface pour supprimer un compte existant du client,
 *                   après confirmation par boîte de dialogue. Gère les cas d'erreur.
 */
class GestionCompteGUI : public QMainWindow
{
  Q_OBJECT
public:
  GestionCompteGUI ();
  virtual ~GestionCompteGUI ();
  
  private slots:
      void slotAjoutEpargne();
      void slotAjoutCheque();
      void slotSupprimer();
      
private:
  Ui::GestionCompteGUI widget;
  bancaire::Client m_client;
};

#endif /* _GESTIONCOMPTEGUI_H */
