#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "listes.h"


/*
 *  Auteur(s) : Sadek Mira, Nader Marie Ange
 *  Date : 09/10/2024
 *  Suivi des Modifications :
 *
 */

bool silent_mode = false;


cellule_t* nouvelleCellule (void){
    cellule_t *c;
    c = (cellule_t *)malloc(sizeof(cellule_t));
    return c;
}


void detruireCellule (cellule_t* cel){
    free(cel);
}

void ajoute_en_tete(sequence_t *l, int n) {
    struct cellule *c= malloc(sizeof(cellule_t))  ;
    c->command = n ;
    c->suivant = l->tete;
    l->tete = c;
    return;
}

void conversion (char *texte, sequence_t *seq){
    for (int i = strlen(texte) - 1; i >= 0; i--) {
    ajoute_en_tete(seq, texte[i]);
  }
}

void afficher (sequence_t* seq)
{
    assert (seq); 
    cellule_t *c = seq->tete;
    while (c != NULL) {
        printf("%c", c->command);
        c = c->suivant; }
}

void ajout_cmd(pile_t *p , sequence_t *s){
    char str2[512];
    int i=0;
    cellule_t* curr = s->tete;
    int cpt = 1;
    while (cpt != 0){
        if (curr->suivant->command == '{')
            cpt=cpt+1;
        else if (curr->suivant->command == '}')
            cpt=cpt-1;
        str2[i]=curr->command;
        curr=curr->suivant;
        i++;
    }
    str2[i]=curr->command;
    str2[i+1]='\0';
    empiler(p,str2);
    s->tete=curr;
}
 

void interroger(pile_t *p , sequence_t *s){
    s->tete = s->tete->suivant;
    char * libre = depiler(p);
    char * retenu = depiler(p);
    int n = atoi(depiler(p));
    if (n==0){
        for (int i=(int)strlen(libre)+1; i>=0; i--){
            ajoute_en_tete(s , libre[i]);
        }
    }
    else{
        for (int i=(int)strlen(retenu)+1; i>=0; i--){
            ajoute_en_tete(s , retenu[i]);
    }
}
}
