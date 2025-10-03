# Outil de Gestion Bancaire
Outil de gestion bancaire en C++ avec interface Qt développé en appliquant des principes de qualité logicielle rigoureuse. Projet réalisé dans le cadre d'un cours à l'Université Laval.

### Qualité et robustesse
- Contrat d'exception encadrant les responsabilités client-développeur
- Documentation généré via Doxygen
- Tests unitaires basés sur la théorie du contrat et automatisés avec GoogleTest

### Conception technique
- Utilisation d'itérateurs de la STL pour la manippulation des conteneurs dynamiques
- Gestion de la mémoire via l'allocation dynamique, polymorphisme et destruction contrôlée

### Architecture modulaire et réutilisable
- Intégration de modules préablement testés facilitant le développement de l'interface utilisateur
- Interface graphique développée avec QT

### Principales fonctionnalités
- Ajout de clients
- Création et supression de comptes bancaires
- Ajustement du taux d'intérêt a appliqué au solde en fonction: du type de compte, du nombre de transaction et du solde initial
- Affichage des renseignements du client

### Technologies utilisées:
- C++
- GoogleTest
- Qt Creator
- Doxygen
- Apache NetBeans
