#include "pile.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


el_pile* nouvelleCellule (void){
    el_pile *c;
    c = (el_pile *)malloc(sizeof(el_pile));
    return c;
}

void empiler(pile_t *p, char* s) {
    struct elem *e= malloc(sizeof(el_pile))  ;
    e->nom = s ;
    e->suiv = p->tete;
    p->tete = e;
    return;
}


char * depiler(pile_t *p){
    char *temp= p->tete->nom;
    p->tete = p->tete->suiv;  
    return temp;
}

void afficher_pile(pile_t *p) {
    if (p->tete == NULL) {
        printf("La pile est vide !\n");
    } else {
        printf("Contenu de la pile: ");
        while (p->tete != NULL){
            printf("%s", p->tete->nom);
            p->tete = p->tete->suiv;
        }
        }
    }