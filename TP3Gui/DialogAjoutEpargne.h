/**
 * \file DialogAjoutEpargne.h
 * \brief GUI d'un programme minimaliste pour l'ajout d'un compte Epargne.
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 1.0
 * \    4/15/2025
 */

#ifndef _DIALOGAJOUTEPARGNE_H
#define _DIALOGAJOUTEPARGNE_H

#include "ui_DialogAjoutEpargne.h"
#include "Epargne.h"


/**
 * \class DialogAjoutEpargne
 * \brief Classe GUI servant à la création d'un compte Epargne. 
 *
 *              La classe maintient dans un état cohérent ces renseignements et
 *              est construit en utilisant le framework Qt.           
 *              Cette classe contient l'interface pour l'ajout d'un compte Epargne.
 *              La classe n'accepte qu'un compte Epargne valide.
 *              C'est la responsabilité de l'utilisateur de la classe de s'en asssurer.  
 *            
 * \slotAjoutEpargne Slot de l'interface pour l'ajout d'un compte Epargne
 * 
 */
class DialogAjoutEpargne : public QDialog
{
  Q_OBJECT
public:
  DialogAjoutEpargne ();
  virtual ~DialogAjoutEpargne ();
  
  unsigned reqNoCompte() const;
  double reqTauxInteret() const;
  double reqSolde() const;
  QString reqDescription() const;
  
  private slots:
   void slotAjoutEpargne();

private:
  Ui::DialogAjoutEpargne widget;

};                      
            
#endif /* _DIALOGAJOUTEPARGNE_H */
