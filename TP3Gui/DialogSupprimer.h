/**
 * \file DialogSupprimer.h
 * \brief GUI minimaliste pour la suppression d'un compte bancaire.
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 1.0
 * \    4/24/2025
 */

#ifndef _DIALOGSUPPRIMER_H
#define _DIALOGSUPPRIMER_H

#include "ui_DialogSupprimer.h"

/**
 * \class DialogSupprimer
 * \brief Classe GUI permettant la suppression d'un compte bancaire.
 *
 *              Cette classe fournit une interface utilisateur, construite avec Qt, pour saisir
 *              le numéro d'un compte à supprimer. Elle offre un slot pour valider l'entrée
 *              et fermer la boîte de dialogue. La suppression effective du compte est gérée
 *              par la fenêtre principale après la fermeture du dialogue.
 *
 * \slotSupprimer Slot déclenché pour valider l'entrée et fermer la boîte de dialogue.
 */
class DialogSupprimer : public QDialog
{
  Q_OBJECT
  
public:
  DialogSupprimer ();
  virtual ~DialogSupprimer ();
  unsigned reqNoCompte() const;
signals:
    void compteSupprime(unsigned int numeroCompte);
private slots:
    void slotSupprimer();
private:
  Ui::DialogSupprimer widget;
};

#endif /* _DIALOGSUPPRIMER_H */