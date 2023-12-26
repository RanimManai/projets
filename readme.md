# E-ELECTION
*Ranim MANAI*
```
E-ELECTION est un système de gestion d'élections basique implémenté en langage C.
Il estconçu pour permettre la participation d'électeurs, de candidats et d'administrateurs.
Il fournit une interface en ligne de commande pour interagir avec le système en fonction du rôle de l'utilisateur.
```
## Fonctionnalités
### Électeurs
```
Voter: Les électeurs peuvent voter pour des candidats lors d'une élection spécifique.
Participer aux élections: Les électeurs peuvent participer à des élections en fonction de leur admissibilité.
```
### Candidats
```
Consulter les votes: Les candidats peuvent consulter le nombre de votes qu'ils ont reçus lors d'une élection.
Participer aux élections: Les candidats peuvent se présenter à des élections enregistrées dans le système.
```
### Administrateurs
```
Créer de nouveaux comptes: Les administrateurs peuvent créer de nouveaux comptes administrateurs, de candidats et d'électeurs.
Organiser des élections: Les administrateurs peuvent créer de nouvelles élections et ajouter des candidats à ces élections.
Mettre à jour les informations des candidats:
Les administrateurs peuvent mettre à jour les informations des candidats, y compris leur nom, prénom et mot de passe.
Gérer les résultats des élections: Les administrateurs peuvent consulter les résultats des élections et déclarer les gagnants.
```
## Comment commencer
**Compilation:** Compilez le programme à l'aide d'un compilateur C.  
**Execution:** Exécutez le programme compilé.  
**Sélection du rôle:** Choisissez le rôle approprié en tant qu'électeur, candidat ou administrateur.  
**ID et mot de passe:** Entrez les identifiants requis (ID et mot de passe) pour accéder aux fonctionnalités spécifiques du rôle.  
**Interaction:** Suivez les invites du programme pour effectuer des actions en fonction du rôle sélectionné.  
## Structure du Projet
```
E-election.c: Le fichier principal contenant la logique du programme.
files\: Répertoire contenant les fichiers CSV pour stocker les informations des utilisateurs
et le fichier txt pour stocker les elections.
files\elections\: Répertoire contenant les fichiers CSV pour chaque élection.
```
### Fichiers CSV
```
electeur.csv: Stocke les informations des électeurs.
candidat.csv: Stocke les informations des candidats.
admin.csv: Stocke les informations des administrateurs.
elections/*.csv: Chaque fichier stocke les résultats d'une élection spécifique.
```
### Fichier TXT
```
elections.txt: Stocke les IDs de tous les élections.
```
