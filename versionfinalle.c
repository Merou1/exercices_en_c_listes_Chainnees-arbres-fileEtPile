#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//exo1
typedef struct salle {
    int id;
    struct salle* suivant;
    struct salle* precedent;
} salle;

typedef struct prof {
    char nom[50];
    bool dispo;
    struct prof* suivant;
    struct prof* precedent;
} prof;

typedef struct graphe {
    salle* salle;
    struct graphe* suivant;
    struct graphe* precedent;
} graphe;
//exo2
void ajoutersalle(salle** tete, int id) {
    salle* nouvelle_salle = (salle*)malloc(sizeof(salle));
    nouvelle_salle->id = id;
    nouvelle_salle->suivant = NULL;
    nouvelle_salle->precedent = NULL;

    if (*tete == NULL) {
        *tete = nouvelle_salle;
    } else {
        salle* temp = *tete;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = nouvelle_salle;
        nouvelle_salle->precedent = temp;
    }
}
/*
          p kaypointe l salle jdida, w hiya katpointe l shnu kan kaypointelou p
          psa p khdablasst tete donc p kaypointe l awel elt db wlat nouvelle heya awel elt
          
          */



    //exo3
typedef struct Noeud{
        salle* salle;//blasst int valeur derna pointeur l salle li mennou anakhdou id d kul salle
        struct Noeud* gauche;
        struct Noeud* droite;
        }Noeud;
        
void liersalles(salle* salle1, salle* salle2) {
    graphe* nouveau_graphe1 = (graphe*)malloc(sizeof(graphe));
    nouveau_graphe1->salle = salle1;
    nouveau_graphe1->suivant = NULL;

    graphe* nouveau_graphe2 = (graphe*)malloc(sizeof(graphe));
    nouveau_graphe2->salle = salle2;
    nouveau_graphe2->suivant = NULL;

    graphe* p = salle1->suivant;
    if (p == NULL) {
        salle1->suivant = nouveau_graphe1;
    } else {
        while (p->suivant != NULL) {
            p = p->suivant;
        }
        p->suivant = nouveau_graphe1;
    }

    p = salle2->suivant;
    if (p == NULL) {
        salle2->suivant = nouveau_graphe2;
    } else {
        while (p->suivant != NULL) {
            p = p->suivant;
        }
        p->suivant = nouveau_graphe2;
    }
}

void ajouterprofesseur(prof** tete, const char* nom, bool dispo) {
    prof* nouveau_prof = (prof*)malloc(sizeof(prof));
    strcpy(nouveau_prof->nom, nom);
    nouveau_prof->dispo = dispo;
    nouveau_prof->suivant = NULL;
    nouveau_prof->precedent = NULL;

    if (*tete == NULL) {
        *tete = nouveau_prof;
    } else {
        prof* temp = *tete;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = nouveau_prof;
        nouveau_prof->precedent = temp;
    }
}

salle* trouversalledisponible(salle* tete, prof* professeur) {
    salle* temp = tete;
    while (temp != NULL) {
        if (professeur->dispo) {
            graphe* p = temp->suivant;
            bool salle_disponible = true;
            while (p != NULL) {
                if (!p->salle->precedent->dispo) {
                    salle_disponible = false;
                    break;
                }
                p = p->suivant;
            }
            if (salle_disponible) {
                return temp;
            }
        }
        temp = temp->suivant;
    }
    return NULL;
}

int main() {
    salle* listesalles = NULL;
    prof* listeprofesseurs = NULL;

    
    ajoutersalle(&liste_salles, 1);
    ajoutersalle(&liste_salles, 2);
    ajoutersalle(&liste_salles, 3);
    ajoutersalle(&liste_salles, 4);

  
    liersalles(listesalles, liste_salles->suivant);
    liersalles(listesalles->suivant, liste_salles->suivant->suivant);
    liersalles(listesalles->suivant->suivant, liste_salles->suivant->suivant->suivant);

    // nzidou profs avec disponibilt2
    ajouterprofesseur(&liste_professeurs, "Professeur 1", true);
    ajouterprofesseur(&liste_professeurs, "Professeur 2", false);
    ajouterprofesseur(&liste_professeurs, "Professeur 3", true);

    // prof l kula salle 3lq 7ssab dispo
    salle* salleattribuee = trouversalledisponible(listesalles, listeprofesseurs);
    if (salleattribuee != NULL) {
        printf("La salle d'examen attribuée est : %d\n", salleattribuee->id);
    } else {
        printf("Aucune salle d'examen disponible.\n");
    }

    return 0;
}
