#include "pile.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void empiler(pile_t *p, char* s) { //empile au sommet de la pile
    el_pile *e= malloc(sizeof(el_pile)) ;
    e->nom = malloc(strlen(s)+1); // puisque c'est un str et no un char on alloue de la memoire de la taille du string.
    strcpy(e->nom,s);
    e->suiv = p->tete;
    p->tete = e;
}


char * depiler(pile_t *p){  //depile le sommet de la pile
    char *temp= p->tete->nom;
    p->tete = p->tete->suiv;  
    return temp;
}

void afficher_pile(pile_t *p) {
    if(p!=NULL){
    el_pile *current = p->tete;
    if (p->tete == NULL) {
        printf("La pile est vide !\n");
    } else {
        while (current != NULL){
            printf("Contenu de la pile: %s\n", current->nom);
            current=current->suiv;
        }
        }
    }
    else{
        printf("PILE VIDE");
    }
}


void calculette(pile_t *p , char symb){
    char num[1000]; 
    int i = atoi(depiler(p));
    int j = atoi(depiler(p));
    switch (symb){
        case '+':
            sprintf(num,"%d",i+j); //stock dans num
            empiler(p,num);
            break;
        case '*':
            sprintf(num,"%d",i*j);
            empiler(p, num);
            break;
        case '-':
            sprintf(num,"%d",j-i);
            empiler(p,num);
            break;
    }
}