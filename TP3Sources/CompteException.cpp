/**
 * \file CompteException.cpp
 * \brief Implantation de la classe CompteException et de ses héritiers
 * \author Judith-Aisha & Michaël Denis
 * \version 2.0
 * \    4/14/2025
 */

#include "CompteException.h"
#include <sstream>

using namespace std;

/**
 * \brief Constructeur de la classe de base CompteException
 * \param p_raison chaîne de caractères représentant la raison décrivant la source de l'erreur
 */
CompteException::CompteException(const std::string& p_raison)
                : runtime_error(p_raison) {}

/**
 * \brief Constructeur de la classe CompteDejaPresentException
 * \param p_raison chaîne de caractères représentant la raison décrivant la source de l'erreur
 */
CompteDejaPresentException::CompteDejaPresentException(const std::string& p_raison)
                          : CompteException(p_raison) {std::string what(p_raison);}

/**
 * \brief Constructeur de la classe CompteAbsentException
 * \param p_raison chaîne de caractères représentant la raison décrivant la source de l'erreur
 */
CompteAbsentException::CompteAbsentException(const std::string& p_raison)
                     : CompteException(p_raison) {std::string what(p_raison);}
