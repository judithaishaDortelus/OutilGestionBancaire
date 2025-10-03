/**
 * \file main.cpp
 * \brief Programme minimaliste utilisant la classe Client avec différents comptes pour intégré au framework QT
 * \author Judith-Aisha Dortelus & Michaël Denis
 * \version 1.0
 * \    4/15/2025
 */

#include <QApplication>
#include "GestionCompteGUI.h"

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  GestionCompteGUI FenetrePrincipale;
  FenetrePrincipale.show();

  return app.exec ();
}
