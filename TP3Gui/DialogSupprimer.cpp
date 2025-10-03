/**
 * \file DialogSupprimer.cpp
 * \brief Implémentation de la classe DialogSupprimer
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 1.0
 * \    4/24/2025
 */

#include "DialogSupprimer.h"
#include "ui_DialogSupprimer.h"

/**
 * \brief Constructeur par défaut
 *        Construit une fenêtre de dialogue pour la suppression d'un compte
 *        en utilisant le framework Qt.
 * \post L'interface utilisateur est initialisée et prête à recevoir un numéro de compte.
 */
DialogSupprimer::DialogSupprimer ()
{
  widget.setupUi (this);
}

/**
 * \brief Destructeur de la classe DialogSupprimer
 */
DialogSupprimer::~DialogSupprimer () { }

/**
 * \brief Méthode accesseur retournant le numéro de compte entré
 * \return Un entier positif représentant le numéro de compte à supprimer
 */
unsigned DialogSupprimer::reqNoCompte() const
{
    return widget.lineEditNumeroCompte->text().toUInt();
}

/**
 * \brief Ferme la boîte de dialogue après validation de l'entrée.
 * \post Récupère le numéro de compte saisi et ferme la fenêtre avec accept().
 */
void DialogSupprimer::slotSupprimer()
{
    reqNoCompte();
    accept();
}