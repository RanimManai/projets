#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct ELECTEUR {
    int id;
    char nom[20];
    char prenom[20];
};
typedef struct ELECTEUR electeur;

struct CANDIDAT {
    char nom[20];
    char prenom[20];
    char mdp[20];
    int id;
};
typedef struct CANDIDAT candidat;

struct ADMIN {
    int id;
    char mdp[20];
};
typedef struct ADMIN admin;
struct ELECTION {
    int code;
    int nbCandidats;
    int candidats[50];
};
typedef struct ELECTION election;
int isAdminIdExists(int id, admin *adminList, int numAdmins) {
    for (int i = 0; i < numAdmins; ++i) {
        if (adminList[i].id == id) {
            return 1; 
        }
    }
    return 0; 
}
void felection(int electionId) {
    char filename[50];
    sprintf(filename, "files\\elections\\%d.csv", electionId);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erreur lors en ouvreant le fichier CSV  %d.csv.\n", electionId);
        return;
    }

    char line[256];
    fgets(line, sizeof(line), file);

    int electorId, candidateId;
    printf("Entrez ID d'un electeur ID (0 pour voir tous les candidats): ");
    scanf("%d", &electorId);
    
    if (electorId == 0) {
        printf("Tous les candidats d'election %d:\n",electionId);
        int electorId2;
        while (fscanf(file, "%d,%d", &electorId2, &candidateId) == 2) {
            if (electorId2==0){ printf("CANDIDAT ID: %d\n", candidateId);}
           
        }
    } else {
        printf("L'Electeur ID %d a voté pour :\n",electorId);
        while (fscanf(file, "%d,%d", &electorId, &candidateId) == 2) {
            if (electorId != 0) {
                printf("CANDIDAT ID: %d\n", candidateId);
            }
        }
    }

    fclose(file);
    candidateId=0;
    do{printf("Voulez vous savoir le gagnant? (0 pour non)\n");
    scanf("%d",&candidateId); 
    file = fopen(filename, "r");
    if (!file) {
        perror("Erreur en ouvreant fichier csv d'election.");
        return;
    }
    fgets(line, sizeof(line), file);

    int candidateVotes[100] = {0};
    while (fscanf(file, "%d,%d", &electorId, &candidateId) == 2) {
        if (electorId != 0) {
            candidateVotes[candidateId]++;
        }
    }

    fclose(file);

    int maxVotes = -1;
    int winningCandidate = -1;

    for (int i = 1; i < 100; ++i) {
        if (candidateVotes[i] > maxVotes) {
            maxVotes = candidateVotes[i];
            winningCandidate = i;
        }
    }

    printf("Le candidat gagnant est Candidat ID %d avec %d votes.\n", winningCandidate, maxVotes);}
    while(candidateId==0);

   
}
int isElectionValid(int id);
void fcandidat(int idc) {
    
    int id=0;
    do{printf("Tapez le code de votre election \n");
    scanf("%d",id);}
    while(isElectionValid(id)==0);
    char filename[50];
    sprintf(filename, "files\\elections\\%d.csv", id);
    printf("%s\n",filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening election CSV file %d.csv.\n", idc);
        return;
    }

    char line[256];
    fgets(line, sizeof(line), file);

    int electorId, candidateId;
    
    if (id == 0) {
        printf("Tous les candidats d'election %d:\n",id);
        int electorId2;
        while (fscanf(file, "%d,%d", &electorId2, &candidateId) == 2) {
            if (electorId2==0){ printf("CANDIDAT ID: %d\n", candidateId);}
           
        }
    } else {
        printf("L'Electeur ID %d a voté pour :\n",electorId);
        while (fscanf(file, "%d,%d", &electorId, &candidateId) == 2) {
            if (electorId != 0) {
                printf("CANDIDAT ID: %d\n", candidateId);
            }
        }
    }

    fclose(file);
    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening election CSV file");
        return;
    }
    fgets(line, sizeof(line), file);
    int candidateVotes=0;
    while (fscanf(file, "%d,%d", &electorId, &candidateId) == 2) {
        if ((electorId != 0) && (candidateId==idc)) {
            candidateVotes++;
        }
    }

    fclose(file);

    printf("Vous avez %d votes",candidateVotes);
   
}

int isElectionValid(int electionId) {
    FILE *file = fopen("files/elections.txt", "r");
    if (!file) {
        perror("Error opening elections file");
        return 0; 
    }

    int currentId;
    while (fscanf(file, "%d", &currentId) == 1) {
        if (currentId == electionId) {
            fclose(file);
            return 1; 
        }
    }

    fclose(file);
    return 0; 
}

void updateCandidateInfo(const char *filename,candidat *candidatList, int candidateId, int numcandidats) {

 FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erreur en ouvreant le fichier");
        return ; 
    }
    char line[256];
    fgets(line, sizeof(line), file);
     int i;
     char nom[20];
     char prenom[20];
     char mdp[20];
     int id;
    while (fscanf(file, "%[^,],%[^,],%[^,],%d,\n",
                  candidatList[i].nom,
                  candidatList[i].prenom,
                  candidatList[i].mdp,
                  &candidatList[i].id) == 4) {
        if (candidatList[i].id=candidateId){
            strcpy(nom,candidatList[i].nom);
                  strcpy(prenom,candidatList[i].prenom);
                  strcpy(mdp,candidatList[i].mdp);
                  id=candidatList[i].id;
        }
        (i)++;
        
    }
    if (id=candidateId){
    int choix;
    printf("Choisis l'attribut de candidat ID %d pour mettre a jour :\n", candidateId);
    printf("1- Nom\n");
    printf("2- Prenom\n");
    printf("3- Mot de passe\n");
    printf("0- Exit\n");

    do {
        scanf("%d", &choix);
    } while (0 > choix || choix > 3);

    switch (choix) {
        case 1:
            printf("Entrez le nouveau Nom: ");
            scanf("%s", nom);
                while (fscanf(file, "%[^,],%[^,],%[^,],%d,\n",
                  candidatList[i].nom,
                  candidatList[i].prenom,
                  candidatList[i].mdp,
                  &candidatList[i].id) == 4) {
        if (candidatList[i].id=candidateId){
             strcpy(candidatList[i].nom,nom);
        }
        (i)++;
        
    }
           
            break;
        case 2:
            printf("Entrez the new Prenom: ");
            scanf("%s", prenom);
                           while (fscanf(file, "%[^,],%[^,],%[^,],%d,\n",
                  candidatList[i].nom,
                  candidatList[i].prenom,
                  candidatList[i].mdp,
                  &candidatList[i].id) == 4) {
        if (candidatList[i].id=candidateId){
 strcpy(candidatList[i].prenom,prenom);
        }
        (i)++;
        
    }
            
            break;
        case 3:
            printf("Entrez the new Mot de passe: ");
            scanf("%s", mdp);
                                       while (fscanf(file, "%[^,],%[^,],%[^,],%d,\n",
                  candidatList[i].nom,
                  candidatList[i].prenom,
                  candidatList[i].mdp,
                  &candidatList[i].id) == 4) {
        if (candidatList[i].id=candidateId){
            strcpy(candidatList[i].mdp,mdp);
        }
        (i)++;
        
    }
            break;
        case 0:
            printf("Exit.\n");
            break;
        default:
            printf("Choix invalide.\n");
    }

    FILE *file = fopen("files\\candidat.csv", "w");
    if (file != NULL) {
        fprintf(file, "Nom,Prenom,Mot de passe,ID\n"); 
        for (int i = 0; i < numcandidats; ++i) {
            fprintf(file, "%s,%s,%s,%d,%d\n",
                    candidatList[i].nom,
                    candidatList[i].prenom,
                    candidatList[i].mdp,
                    candidatList[i].id);
        }
        fclose(file);
        printf("La mise a jour du l'information du candidat est reussite .\n");
    } else {
        perror("Erreur en mise a jour du fichier CSV candidat.csv.\n");
    }
}}
int isCandidateIdExists(int id, candidat *candidatList, int numCandidats) {
    for (int i = 0; i < numCandidats; ++i) {
        if (candidatList[i].id == id) {
            return 1; 
        }
    }
    return 0; 
}
void createNewAdmin(admin *adminList, int *numAdmins) {
    if (*numAdmins < 100) {
        int newAdminId;

        do {
            printf("ID : ");
            scanf("%d", &newAdminId);

            if (isAdminIdExists(newAdminId, adminList, *numAdmins)) {
                printf("ID deja utilisé. Choisis un autre ID.\n");
            }
        } while (isAdminIdExists(newAdminId, adminList, *numAdmins));

        printf("Mot de passe : ");
        scanf("%s", adminList[*numAdmins].mdp);

        adminList[*numAdmins].id = newAdminId;
        (*numAdmins)++;
        printf("Compte admin créé avec succès!\n");

        FILE *file = fopen("files\\admin.csv", "a");
        if (file != NULL) {
            fprintf(file, "%d,%s\n", adminList[*numAdmins - 1].id, adminList[*numAdmins - 1].mdp);
            fclose(file);
        } else {
            perror("Erreur en mise a jour fichier CSV admin.csv. \n");
        }
    } else {
        printf("Désolé, la capacité maximale d'admins est atteinte.\n");
    }
}
void createNewCandidate(candidat *candidatList, int *numCandidats) {
    if (*numCandidats < 100) {
        int newCandidateId=120;

        do {
            printf("ID : ");
            scanf("%d", &newCandidateId);

            if (isCandidateIdExists(newCandidateId, candidatList, *numCandidats)) {
                printf("ID deja utilisée. choisis un autre ID.\n");
            }
            if ((newCandidateId>=100 || newCandidateId<=0)){
                printf("ID doit etre compris entre 1 et 99");
            }
        } while (isCandidateIdExists(newCandidateId, candidatList, *numCandidats) && (newCandidateId>=100 || newCandidateId<=0));

        printf("Nom : ");
        scanf("%s", candidatList[*numCandidats].nom);

        printf("Prenom : ");
        scanf("%s", candidatList[*numCandidats].prenom);

        printf("Mot de passe : ");
        scanf("%s", candidatList[*numCandidats].mdp);

        candidatList[*numCandidats].id = newCandidateId;
        
        printf("Compte candidat créé avec succès!\n");

        FILE *file = fopen("files\\candidat.csv", "a");
        if (file != NULL) {
            fprintf(file, "%s,%s,%s,%d,%d\n",
                    candidatList[*numCandidats - 1].nom,
                    candidatList[*numCandidats - 1].prenom,
                    candidatList[*numCandidats - 1].mdp,
                    candidatList[*numCandidats - 1].id);
            fclose(file);
        } else {
            perror("Erreur en mise a jour le fichier CSV candidat.csv\n");
        }
    } else {
        printf("Désolé, la capacité maximale de candidats est atteinte.\n");
    }
    (*numCandidats)++;
}
void createElectionCSV(int electionCode, int numCandidats, candidat candidatList[]) {
    char filename[50];
    sprintf(filename, "files/elections/%d.csv", electionCode);
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erreur lors de creation de fichier CSV election.csv");
        return;
    }
      fprintf(file, "ElectorID,CandidateID\n");
    for (int i = 0; i < numCandidats; ++i) {
        fprintf(file, "0,%d\n", candidatList[i].id); 
    }
    fclose(file);

    printf("Creation reussite du fichier CSV files/elections/%d.csv pour l'election code  %d.\n", electionCode,electionCode);

    FILE *electionsFile = fopen("files/elections.txt", "a");
    if (electionsFile == NULL) {
        perror("Erreur lors du mise a jour du fichier TXT elections.txt.");
        return;
    }
    fprintf(electionsFile, "%d\n", electionCode);
    fclose(electionsFile);

    printf("L'Election code %d ajoutée to elections.txt.\n", electionCode);
}

int electeurReadCSV(const char *filename, electeur *electeurList, int *numElecteurs) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erreur");
        return -1; 
    }
    char line[256];
    fgets(line, sizeof(line), file);

    // Read data from file
    *numElecteurs = 0;
    while (fscanf(file, "%d,%s,%s\n",
                  &electeurList[*numElecteurs].id,
                  &electeurList[*numElecteurs].nom,
                  &electeurList[*numElecteurs].prenom) == 3) {
        (*numElecteurs)++;
    }

    fclose(file);
    return 0; 
}

int isElecteurValid(int id, electeur *electeurList, int numElecteurs) {
    for (int i = 0; i < numElecteurs; ++i) {
        if (electeurList[i].id == id) {
            return 1; 
        }
    }
    return 0; 
}

void creerelecteur(electeur *electeurList, int *numElecteurs) {
    if (*numElecteurs < 100) {
        printf("Creation d'un nouveau compte electeur :\n");

        printf("ID : ");
        scanf("%d", &electeurList[*numElecteurs].id);

        printf("Nom : ");
        scanf("%s", electeurList[*numElecteurs].nom);

        printf("Prenom : ");
        scanf("%s", electeurList[*numElecteurs].prenom);
        (*numElecteurs)++;
        printf("Compte électeur cree avec succes!\n");

        FILE *file = fopen("files\\electeur.csv", "a");
        if (file != NULL) {
            fprintf(file, "%d,%s,%s\n", electeurList[*numElecteurs - 1].id,
                    electeurList[*numElecteurs - 1].nom, electeurList[*numElecteurs - 1].prenom);
            fclose(file);
        } else {
            perror("Error lors du mise a jour du fichier CSV.");
        }
    } else {
        printf("Desole, la capacite maximale d'electeurs est atteinte.\n");
    }
}

int candidatReadCSV(const char *filename, candidat *candidatList, int *numCandidats) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erreur");
        return -1; 
    char line[256];
    fgets(line, sizeof(line), file);

    *numCandidats = 0;
    while (fscanf(file, "%[^,],%[^,],%[^,],%d,\n",
                  candidatList[*numCandidats].nom,
                  candidatList[*numCandidats].prenom,
                  candidatList[*numCandidats].mdp,
                  &candidatList[*numCandidats].id) == 4) {
        (*numCandidats)++;
    }

    fclose(file);
    return 0; 
}
}
int isCandidatValid(int id, char mdp[20], candidat *candidatList, int numCandidats) {
    for (int i = 0; i < numCandidats; ++i) {
        if (candidatList[i].id == id && strcmp(candidatList[i].mdp, mdp) == 0) {
            return 1; 
        }
    }
    return 0; 
}
int adminReadCSV(const char *filename, admin *adminList, int *numAdmins) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erreur");
        return -1; 
    }

    char line[256];
    fgets(line, sizeof(line), file);

    *numAdmins = 0;
    while (fscanf(file, "%d,%19s", &adminList[*numAdmins].id, adminList[*numAdmins].mdp) == 2) {
        (*numAdmins)++;
    }

    fclose(file);
    return 0; 
}

int isAdminValid(int id, char mdp[20], admin *adminList, int numAdmins) {
    for (int i = 0; i < numAdmins; ++i) {
        if (adminList[i].id == id && strcmp(adminList[i].mdp, mdp) == 0) {
            return 1; 
        }
    }
    return 0; 
}
int isElectionCodeExists(int electionCode) {
    FILE *electionsFile = fopen("files/elections.txt", "r");
    if (electionsFile == NULL) {
        perror("Erreur");
        return 0;  
    }

    int code;
    while (fscanf(electionsFile, "%d\n", &code) == 1) {
        if (code == electionCode) {
            fclose(electionsFile);
            return 1;  
        }
    }

    fclose(electionsFile);
    return 0;  
}
void printAllElectionCodes() {
    FILE *file = fopen("files/elections.txt", "r");
    if (file == NULL) {
        perror("Erreur");
        return;
    }
    int electionCode;
    while (fscanf(file, "%d", &electionCode) == 1) {
        printf("Election Code: %d\n", electionCode);
    }

    fclose(file);
}
void felector(int electorId) {
    int electionCode;
    printf("Entrez le code d'election dont vous voulez votez: ");
    scanf("%d", &electionCode);

    char electionFileName[50];
    sprintf(electionFileName, "files/elections/%d.csv", electionCode);

    FILE *electionFile = fopen(electionFileName, "r");
    if (!electionFile) {
        perror("Erreur");
        return;
    }
    int hasVoted = 0;
    int candidateId;
    while (fscanf(electionFile, "%d,%d", &electorId, &candidateId) == 2) {
        hasVoted = 1;
        break;  
    }

    fclose(electionFile);

    if (hasVoted) {
        printf("Vous avez deja vote. tu peux pas vote 2 fois.\n");
    } else {
   
        electionFile = fopen(electionFileName, "a");
        if (!electionFile) {
            perror("Erreur");
            return;
        }

        printf("La liste des candidats:\n");
        fseek(electionFile, 0, SEEK_SET);  
        while (fscanf(electionFile, "0,%d", &candidateId) == 2) {
            printf("Candidat ID: %d\n", candidateId);
        }

        printf("Entrez l'ID du Candidat que vous voulez voté: ");
        scanf("%d", &candidateId);

        fprintf(electionFile, "%d,%d\n", electorId, candidateId);

        fclose(electionFile);

        printf("VOTE ENREGISTREE!\n");
    }
}
void fadmin(admin *adminList,int *numAdmins) {
    
    int choix1=10;
    while (choix1!=0) {printf("\e[1;1H\e[2J");
    
                    printf("_*-Veuillez choisir une des options suivantes-*_ \n");
                    printf("1- Creer un nouveau compte admin\n");
                    printf("2- Creer un nouveau compte candidat\n");
                    printf("3- Creer une nouvelle election \n");
                    printf("4- Mise a jour  des informations des candidats\n");
                    printf("5- Afficher et gerer les elections \n");
                    printf("0- Exit\n");
                    do {
                            scanf("%d", &choix1);
                     } while (0 > choix1 || choix1 > 5);
                    printf("\e[1;1H\e[2J");
                    
                    switch (choix1) {
                                    case 1:
                                             printf("1- Creer un nouveau compte admin\n");
                                             createNewAdmin(adminList, numAdmins);
                                             break;
    case 2: printf("2- Creer un nouveau compte candidat\n");
            const char *filenameCandidat = "files\\candidat.csv";
        candidat candidatList[100];
        int numCandidats = 0;

        if (candidatReadCSV(filenameCandidat, candidatList, &numCandidats) == -1) {
            printf("ERROR");
            return; 
        }
            createNewCandidate(candidatList, &numCandidats);
            break;

    case 3:
        printf("3- Creer une nouvelle election\n");
        int codeE;
        int verif;
        do{printf("Ecrire le code d'election que vous voulez creer:\n");
        scanf("%d",&codeE);
        
        verif=isElectionCodeExists(codeE);
        if((verif==0)){ 
                int numCandidats;
                printf("Enter the number of candidates participating in the election: ");
                scanf("%d", &numCandidats);
                printf("Enter the IDs of candidates participating in the election:\n");
                for (int i = 0; i < numCandidats; ++i) {
                    do{scanf("%d", &candidatList[i].id);
                    if ((candidatList[i].id>=100)||(candidatList[i].id<=0)){
                        printf("ID de candidat doit etre entre 1 et 99");
                    };} while ((candidatList[i].id>=100)||(candidatList[i].id<=0));
                    
                }

                createElectionCSV(codeE, numCandidats, candidatList);}
        else {printf("Il ya une election avec ce code\n");}}
        while(verif!=0);
        break;
    case 4:
        printf("4- Mise a jour  des informations des candidats\n");
        int candidateIdToUpdate;
        printf("Enter the ID of the candidate to update: ");
        numCandidats = 0;
        const char *fileC = "files\\candidat.csv";
        if (candidatReadCSV(fileC, candidatList, &numCandidats) == -1) {
            printf("ERROR");
            return; 
        }
        scanf("%d", &candidateIdToUpdate);
        updateCandidateInfo(fileC,candidatList,candidateIdToUpdate, numCandidats );
        break;
        break;
    case 5:
        printf("5- Afficher et gerer les elections \n");
        printAllElectionCodes();
        int electionId,idel;
        while ( (getchar()) != '\n' );  
        do{printf("\n Veuillez choisir l' ID de l'election que vous voulez gerer ou 0 pour exit.");
        scanf("%d",&electionId);
        idel=electionId;
        if (electionId==0) {break;}}
        while(isElectionValid(electionId));
        if (electionId==0) {break;}
        felection(idel);
        break;
    case 0:
        printf("0- Exit\n");
        break;   
    }}
}


int main() {
    int id;
    int choix0;
    int pass = 0; 
    printf("\e[1;1H\e[2J");
    printf("_*-     BIENVENUE DANS E-ELECTION       -*_\n");
    printf("tapez le nombre convenable: \n");
    printf("1-Electeur \n2-Candidat\n3-Admin\n");
    do {
        scanf("%d", &choix0);
    } while (1 > choix0 || choix0 > 3);
    printf("\e[1;1H\e[2J");
    
    switch (choix0) {
    case 1: printf(" _*-MENU DES ELECTEURS-*_\n");
        const char *filenameElecteur = "files\\electeur.csv";
        electeur electeurList[100];
        int numElecteurs = 0;

        if (electeurReadCSV(filenameElecteur, electeurList, &numElecteurs) == -1) {
            return 1; 
        }
        do { printf("tapez votre ID: \n");
        scanf("%d", &id);
        pass=isElecteurValid(id, electeurList, numElecteurs);
        if (pass) {
            printf("ID is valid.\n");
            felector(id);}
        else {
            printf("ID is not valid.\n");
            creerelecteur(electeurList,&numElecteurs);
        }}while(pass==0);
       
        break;

    case 2:
        printf("_*-MENU DES CANDIDATS-*_\n");
        char mdp[20];
        const char *filenameCandidat = "files\\candidat.csv";
        candidat candidatList[100];
        int numCandidats = 0;
        if (candidatReadCSV(filenameCandidat, candidatList, &numCandidats) == -1) {
            return 1; 
        }
        do{
        printf("tapez votre ID: \n");
        scanf("%d", &id);
        printf("tapez votre Mot De Passe: \n");
        scanf("%s", mdp);
        pass =isCandidatValid(id, mdp, candidatList, numCandidats);
        if (pass) {
            printf("ID and password combination is valid.\n");
        } else {
            printf("ID and password combination is not valid.\n");
        }

        if (pass) {
            fcandidat(id);
        }}while(pass==0);
        break;

    case 3:
        printf("_*-LOGIN ADMIN-*_\n");
        do {
            char mdp[20];
            const char *filenameAdmin = "files\\admin.csv";
            admin adminList[100];
            int numAdmins = 0;

            if (adminReadCSV(filenameAdmin, adminList, &numAdmins) == -1) {
                return 1; 
            }

            printf("tapez votre ID: \n");
            scanf("%d", &id);
            printf("tapez votre Mot De Passe: \n");
            scanf("%s", mdp);
            pass =isAdminValid(id, mdp, adminList, numAdmins);
            if (pass) {
                printf("ID and password combination is valid.\n");
            } else {
                printf("ID and password combination is not valid.\n");
            }

            if (pass) {
                fadmin(adminList,&numAdmins);
            }
        } while (pass == 0);
        break;
    }

    return 0;
}
