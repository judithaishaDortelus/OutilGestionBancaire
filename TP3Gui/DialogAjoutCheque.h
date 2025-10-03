/**
 * \file DialogAjoutCheque.h
 * \brief GUI d'un programme minimaliste pour l'ajout d'un compte Cheque.
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 1.0
 * \    4/21/2025
 */

#ifndef _DIALOGAJOUTCHEQUE_H
#define _DIALOGAJOUTCHEQUE_H

#include "ui_DialogAjoutCheque.h"

/**
 * \class DialogAjoutCheque
 * \brief Classe GUI servant à la création d'un compte Cheque. 
 *
 *              La classe maintient dans un état cohérent ces renseignements et
 *              est construit en utilisant le framework Qt.           
 *              Cette classe contient l'interface pour l'ajout d'un compte Cheque.
 *              La classe n'accepte qu'un compte Cheque valide.
 *              C'est la responsabilité de l'utilisateur de la classe de s'en asssurer.  
 *            
 * \slotAjoutEpargne Slot de l'interface pour l'ajout d'un compte Cheque
 * 
 */
class DialogAjoutCheque : public QDialog
{
  Q_OBJECT
public:
  DialogAjoutCheque ();
  virtual ~DialogAjoutCheque ();
  
  unsigned reqNoCompte() const;
  double reqTauxInteret() const;
  double reqSolde() const;
  QString reqDescription() const;
  unsigned reqNbTransactions() const;
  double reqTauxInteretMinimum() const;
  
  private slots:
    void slotAjoutCheque();
    
private:
  Ui::DialogAjoutCheque widget;
};

#endif /* _DIALOGAJOUTCHEQUE_H */
