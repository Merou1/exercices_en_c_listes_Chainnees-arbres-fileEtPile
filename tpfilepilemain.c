#include <stdio.h>
#include <stdlib.h>
//pile me3kousa kanparcourewha b precedent mashy suivant : tete = tete->precedent;
typedef  struct pile
{
   int info;
   struct pile *precedent ;     
}pile;
void pilepush(pile **tete,int info)
{
    pile *pnouveau=malloc(sizeof *pnouveau) ;
    if(pnouveau!=NULL)
    {
     pnouveau->info=info;
     pnouveau->precedent=*tete;
     *tete = pnouveau; //tete point maintenant sur pnouveau
    }
}
int pilepop(pile *tete)
{
    int ret=-1;
    if(tete!=NULL)
    {
     pile *temporaire =(*tete)->precedent;
     ret=(*tete)->info;
     free(*tete);
     //ghayt7eyed elt lewel li mpointeyalou tete
     *tete=temporaire;//tetekatreje3 db adresse dyalha 
    }
    return ret;
}
int pilepeek(pile *tete) {
    if (tete == NULL) {
        return -1;
    }

    while (tete->precedent != NULL) {
        tete = tete->precedent;
    }

    return tete->info;
}

    
    
   
   
}
void clearpile(pile **tete)
{
 while(*tete!=NULL)
 {
  pilepop(tete);
 }
}
int main(int argc, char *argv[])
{
  
    
    
    
  
  system("PAUSE");	
  return 0;
}
