#include <stdio.h>
#include <stdlib.h>
/*f "c" b typedef kancreer les noued walakin 
bash ncreer les arbres khaani fonction li
 katakhdli douk les noueud li creet w 
 katjme3houm f arbre*/
 
 //exo 1   define node 
    typedef struct Noeud {
    int valeur;
    struct Noeud* sous_arbreGauche;
    struct Noeud* sous_arbreDroit;
} Noeud;
//exo2
Noeud* creerarbre(int valeur, Noeud* noeud1, Noeud* noeud2)
{
    Noeud* arbre = (Noeud*)malloc(sizeof(Noeud));
    arbre->valeur = valeur;
    arbre->sous_arbreGauche = noeud1;
    arbre->sous_arbreDroit = noeud2;
    return arbre;
}


//exo3
Noeud* detruitarbre(Noeud* racine)
{
       if(racine==NULL)
       {
        return racine;
       }
       else
       {
          detruitarbre(racine->sous_arbreGauche);
          detruitarbre(racine->sous_arbreDroit);
          free(racine);
          
       }
}

//exo 4

int nbrenoeud(Noeud* racine)
{
    if(racine==NULL){return 0;}
    else 
    {
    
     int g=nbrenoeud(racine->sous_arbreGauche);  
     //g fiha nombre de noueud dyal gauche
     int d=nbrenoeud(racine->sous_arbreDroit);
     //d fiha nbre noeud droit
     return 1+g+d;// 1 hit makenash 7assbin ta racine
    }
    

}
//exo 5
//parcous prefixe , li dewnah kan afficheweh men racine l gauche l droite
void afficher_arbre(Noeud* racine) {
    if (racine != NULL) {
                printf("%d ", racine->valeur);
        afficher_arbre(racine->sous_arbreGauche);
       
        afficher_arbre(racine->sous_arbreDroit);
         
    }

//exo 6 affichage infixe ousymetrique gauche racine droite
}
void afficher2(Noeud* racine)
{
     if(racine != NULL){
    
        afficher2(racine->sous_arbreGauche);
        printf("%d ", racine->valeur);
        afficher2(racine->sous_arbreDroit);
         
    }
}
//exo 6-1
void minmax(Noeud* racine, int* max, int* min) {
    if (racine == NULL) {
        return ;
    }

    if (racine->valeur > *max) {
        *max = racine->valeur;
    }

    if (racine->valeur < *min) {
        *min = racine->valeur;
    }

    minmax(racine->sous_arbreGauche, max, min);
    minmax(racine->sous_arbreDroit, max, min);
}
//exo 6-2
int longueur(Noeud* racine,int c)
{
       if (racine == NULL) {
        return 0 ;
    }
       c++;
     if (racine->sous_arbreGauche== NULL&& racine->sous_arbreDroit == NULL )//feuilles
     {
               return c;//ca donne a si les premiers noeuds sont des feuilles 
               }     
int g= longueur(racine->sous_arbreGauche,c);
int d= longueur(racine->sous_arbreDroit,c);
  
 int maxi=g;

 if(d>maxi) 
 {
      maxi=d;

 }
   return maxi;
  
     
}
//exo 7
int compare(Noeud* racine1, Noeud* racine2) {
    if (racine1 == NULL && racine2 == NULL) {
        return 1;  // Les deux arbres sont vides, ils ont la même structure
    }

    if (racine1 == NULL || racine2 == NULL) {
        return 0;  // Les arbres n'ont pas la même structure
    }

    if (racine1->valeur != racine2->valeur) {
        return 0;  // Les valeurs des racines sont différentes
    }
//parcours de l'arbre
    int sousrbresidentiques = compare(racine1->sous_arbreGauche, racine2->sous_arbreGauche) &&
                              compare(racine1->sous_arbreDroit, racine2->sous_arbreDroit);

    return sousrbresidentiques;
}

//exo8
Noeud* insere(Noeud* racine, int valeur) {
    if (racine == NULL) {
        //valeur sera premier noeud
        return creerarbre( valeur,NULL, NULL);
    }

    if (valeur < racine->valeur) {
        
        racine->sous_arbreGauche = insere(racine->sous_arbreGauche, valeur);
    } else if (valeur > racine->valeur) {
        
        racine->sous_arbreDroit = insere(racine->sous_arbreDroit, valeur);
    }

    // Si la valeur est égale à la valeur du nœud courant, on ne fait rien (les doublons ne sont pas autorisés dans un ABR)

    return racine;
}
//exo9
Noeud* trouve_noeud(Noeud* racine, int valeur) {
    if (racine == NULL || racine->valeur == valeur) {
        return racine;
    }

    if (valeur < racine->valeur) {
        return trouve_noeud(racine->sous_arbreGauche, valeur);
    } else {
        return trouve_noeud(racine->sous_arbreDroit, valeur);
    }
}

int main(int argc, char *argv[])
{ 
    Noeud* feuille3 = creerarbre(3, NULL, NULL);
    Noeud* feuille4 = creerarbre(4, NULL, NULL);
    Noeud* feuille5 = creerarbre(6, NULL, NULL);
    Noeud* feuille6 = creerarbre(7, NULL, NULL);
    Noeud* noeud1 = creerarbre(2, feuille3, feuille4);
    Noeud* noeud2 = creerarbre(5, feuille5, feuille6);
    
     Noeud* noeud3 = creerarbre(4, NULL, NULL);
    Noeud* noeud4 = creerarbre(1, NULL, NULL);
    
    Noeud* racine = creerarbre(1, noeud1, noeud2);
     Noeud* racine2 = creerarbre(1, noeud3, noeud4);
    afficher_arbre(racine);
   
    int nbnoeud = nbrenoeud(racine);
    printf("\n\nL'arbre contient %d noeud\n\n", nbnoeud);
    
   afficher2(racine);
     
   int max = racine->valeur;
   int min = racine->valeur;
    minmax(racine, &max, &min);

    printf("\n\nvaleur max: %d\n", max);
    printf("valeur min: %d\n", min);
    
    int c=0;
    printf("longueur = %d\n", longueur(racine,c));
     
     
     if (compare(racine,racine2)){printf("identiques\n");}
     else{printf("non identiques\n");}
     
     racine=insere(racine,18);
  afficher_arbre(racine); /*18 va etre en sous arbre
  droit car 18>racine*/
  
   int valeur_cherchee = 5 ;
    Noeud* resultat = trouve_noeud(racine, valeur_cherchee);

    if (resultat != NULL) {
        printf("\nNoeud trouve a l'adresse : %p \n", (void*)resultat);
    } else {
        printf("\nNoeud non trouvé \n");
    }
  
     system("PAUSE");
    return 0;
}
                                                                                                                                             
