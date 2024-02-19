#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant {
    int IDE;
    char nom[50];
    char prenom[50];
    float note;
    struct Etudiant* suivant;
    struct Etudiant* precedent;
} Etudiant;

Etudiant* creerEtudiant(int IDE, const char* nom, const char* prenom, float note) {
    Etudiant* etudiant = (Etudiant*)malloc(sizeof(Etudiant));
    etudiant->IDE = IDE;
    strcpy(etudiant->nom, nom);
    strcpy(etudiant->prenom, prenom);
    etudiant->note = note;
    etudiant->suivant = NULL;
    etudiant->precedent = NULL;
    return etudiant;
}

void ajouterEtudiant(Etudiant** tete, int IDE, const char* nom, const char* prenom, float note) {
    Etudiant* etudiant = creerEtudiant(IDE, nom, prenom, note);

    if (*tete == NULL) {
        *tete = etudiant;
    } else {
        Etudiant* p = *tete;
        while (p->suivant != NULL) {
            p = p->suivant;
        }
        p->suivant = etudiant;
        etudiant->precedent = ;
    }
}

void supprimerEtudiant(Etudiant** tete, const char* nom) {
    if (*tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Etudiant* courant = *tete;
    while (courant != NULL) {
        if (strcmp(courant->nom, nom) == 0) {
            if (courant->precedent != NULL) {
                courant->precedent->suivant = courant->suivant;
            } else {
                *tete = courant->suivant;
            }
            if (courant->suivant != NULL) {
                courant->suivant->precedent = courant->precedent;
            }
            free(courant);
            printf("L'etudiant %s a ete supprime.\n", nom);
            return;
        }
        courant = courant->suivant;
    }

    printf("L'etudiant %s n'a pas ete trouve.\n", nom);
}

void modifierNote(Etudiant* tete, const char* nom, float nouvelleNote) {
    Etudiant* courant = tete;
    while (courant != NULL) {
        if (strcmp(courant->nom, nom) == 0) {
            courant->note = nouvelleNote;
            printf("La note de l'etudiant %s a ete modifiee.\n", nom);
            return;
        }
        courant = courant->suivant;
    }

    
}

void afficherListe(Etudiant* tete) {
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Etudiant* courant = tete;
    printf("Liste des etudiants :\n");
    while (courant != NULL) {
        printf("IDE: %d, Nom: %s, Prenom: %s, Note: %.2f\n", courant->IDE, courant->nom, courant->prenom, courant->note);
        courant = courant->suivant;
    }
}

float calculerMoyenne(Etudiant* tete) {
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return 0.0;
    }

    int count = 0;
    float sum = 0.0;
    Etudiant* courant = tete;
    while (courant != NULL) {
        sum += courant->note;
        count++;
        courant = courant->suivant;
    }

    return sum / count;
}


int main() {
    Etudiant* tete = NULL;
              
    ajouterEtudiant(&tete, 1, "belmoubarik", "merouane", 19.0);//koul etudiant kan instaciewh b id nom prenom w moyenne dyalou
    ajouterEtudiant(&tete, 2, "MJALI", "abdellah", 19.0);
    ajouterEtudiant(&tete, 3, "NOM3", "PRENOM3", 15.0);

    afficherListe(tete);

    printf("Moyenne des notes: %.2f\n\n\n", calculerMoyenne(tete)); //calcul de la moyenne generale de tout les étudiant

//changements dans la liste 
    supprimerEtudiant(&tete, "Merouane"); 
    modifierNote(tete, "MJALI", 18.0);//modif de la note d'un étudiant
printf("apres modification\n");
    afficherListe(tete);/*on va avoir l'étudiant merouane n'a pas été trouvé car on lui a supprimer 
    de la liste et note abdellah est changée*/

    
system("PAUSE");
    return 0;
}
