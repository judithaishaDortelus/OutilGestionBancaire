# Outil de Gestion Bancaire
Outil de gestion bancaire développé en C++ avec interface Qt, mettant en oeuvre des principes de qualité logicielle rigoureux. Projet réalisé dans le cadre d'un cours à l'Université Laval.

### Qualité et robustesse:
- Contratx d'exception encadrant les responsabilités client-développeur
- Documentation générée via Doxygen
- Tests unitaires basés sur la théorie du contrat et automatisés avec GoogleTest

### Conception technique:
- Utilisation d'itérateurs de la STL pour la manipulation des conteneurs dynamiques
- Gestion de la mémoire via l'allocation dynamique, le polymorphisme et la destruction contrôlée
- Architesture modulaire et réutilisable

### Architecture modulaire:
- Intégration de modules préalablement testés facilitant le développement de l'interface utilisateur
- Interface graphique développée avec Qt

### Fonctionnalités principales:
- Ajout de clients
- Création et supression de comptes bancaires
- Ajustement du taux d'intérêt à appliquer au solde en fonction: du type de compte, du nombre de transactions et du solde initial
- Affichage des renseignements du client

### Technologies utilisées:
- C++
- GoogleTest
- Qt Creator
- Doxygen
- Apache NetBeans

### Aperçu de l'outil:
#### Saisie des informations clients
<img width="881" height="704" alt="01" src="https://github.com/user-attachments/assets/bf04469e-4372-493a-bd0b-1e93f7e0602f" />

#### Ajout de comptes
<img width="345" height="233" alt="02 0" src="https://github.com/user-attachments/assets/fc0439e9-519f-4d1c-a49e-f71aa0ef56e9" />
<img width="842" height="720" alt="02 1" src="https://github.com/user-attachments/assets/b31d3e13-1452-4ab7-b91a-c46155222d5a" />
<img width="878" height="703" alt="02 2" src="https://github.com/user-attachments/assets/eb531274-56f9-43af-bee8-e7bc1e292873" />

#### Mise à jour des informations liées au compte
<img width="860" height="683" alt="02 3" src="https://github.com/user-attachments/assets/e78b62d1-0782-4919-9c1d-4d6d59b228ac" />

#### Supression d'un compte
<img width="226" height="232" alt="03 0" src="https://github.com/user-attachments/assets/b949a188-a289-4fe4-bb99-0048521e4643" />
<img width="858" height="680" alt="03 1" src="https://github.com/user-attachments/assets/9aea1d51-99c6-43d5-91d7-0bcd94c5e88d" />
<img width="861" height="679" alt="03 2" src="https://github.com/user-attachments/assets/152c006c-6fbe-4066-9675-f702129d53ca" />





