/**
 * \file CompteException.h contenant la déclaration de la classe CompteException et de ses héritiers
 * \brief Hiérarchie de classe pour la gestion des erreurs par lors de l'exécution du programme
 *
 * Ces classes constituent la hiérarchie pour la gestion des exceptions 
 * liées aux comptes. Elle maintient les données nécessaires afin de
 * signaler les erreurs se produisant lors de l'exécution du programme. 
 *      
 * Classes:
 *      std::runtime_error          Classe de base des exceptions logiques.
 *      CompteException             Classe de base des exceptions de contrat.
 *      CompteDejaPresentException  Classe de gestion des erreurs d'assertion.
 *      CompteAbsentException       Classe de gestion des erreurs de précondition.
 * 
 * Attributs:  
 *      std::string m_raison        Il a une erreur lors de l'exécution du programme.
 *
 * \author Judith-Aisha & Michaël Denis
 * \version 1.0
 * \ 4/14/2025
 */

#ifndef COMPTEEXCEPTION_H
#define COMPTEEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * \class CompteException
 * \brief Classe de base des exceptions du compte.
 */
class CompteException : public std::runtime_error
{
public:
  CompteException(const std::string& p_raison); 
};

/**
 * \class CompteDejaPresentException
 * \brief Classe pour la gestion d'erreur lors de l'ajout d'un compte doublon
 */
class CompteDejaPresentException : public CompteException
{
public:
  CompteDejaPresentException(const std::string& p_raison);
};

/**
 * \class CompteAbsentException
 * \brief Classe pour la gestion d'erreur lors de l'effacement d'un compte absent
 */
class CompteAbsentException : public CompteException
{
public:
  CompteAbsentException(const std::string& p_raison);
};

#endif /* COMPTEEXCEPTION_H */

