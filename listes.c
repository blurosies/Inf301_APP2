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
