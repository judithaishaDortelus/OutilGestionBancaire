/**
 * \file validationFormat.h
 * \brief Fichier qui contient la déclaration des fonctions de validation.
 * \author Judith-Aisha Dortelus
 * \version 2.0
 * \    4/1/2025
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H
#include<iostream>
#include<string>
#include<array>

namespace util
{
const char LETTRE_ACCENT[] = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÑÒÓÔÕÖÙÚÛÜÝàáâãäåæçèéêëìíîïñòóôõöùúûüýÿ";
bool validerLettreAccent(char c);

bool validerFormatNom(const std::string& p_nom); 
        
bool validerJourMoisAnnee (int jour, int mois, int annee);
bool validerFormatDate (const std::string& p_ligne, int& p_jour, int& p_mois, int& p_annee);

bool validerFormatFichier(std::istream& p_is);

bool validerNombre(std::string& p_nombre);

} // namespace util

#endif /* VALIDATIONFORMAT_H */