#include "pile.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void empiler(pile_t *p, char* s) {
    el_pile *e= malloc(sizeof(el_pile))  ;
    e->nom = malloc(strlen(s)+1);
    strcpy(e->nom,s);
    e->suiv = p->tete;
    p->tete = e;
}


char * depiler(pile_t *p){
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

void convert(int x,char num [2]){
    num[0]=x+'0';
    num[1]='\0';
}


void calculette(pile_t *p , char symb){
    char num[2];
    int i = atoi(depiler(p));
    int j = atoi(depiler(p));
    switch (symb){
        case '+':
            convert(i+j,num);
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