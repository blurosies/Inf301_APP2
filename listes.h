#ifndef LISTES_H
#define LISTES_H

#include <stdbool.h>
#include "pile.h"

/*
 * Pour réaliser des tests de performance, désactiver tous les 
 * affichages.
 * Pour cela, le plus simple est de redefinir les fonctions principales 
 * en decommentant les 3 lignes suivantes et en commentant l'ancienne 
 * definition de 'eprintf' juste dessous.
 */

#ifdef SILENT

#define printf(fmt, ...) (0)
#define eprintf(fmt, ...) (0)
#define putchar(c) (0)

#else

#define eprintf(...) fprintf (stderr, __VA_ARGS__)

#endif

extern bool silent_mode;




struct cellule {
    char   command;
    /* vous pouvez rajouter d'autres champs ici */
    struct cellule *suivant;
};
typedef struct cellule cellule_t;

struct sequence {
    cellule_t *tete;
};
typedef struct sequence sequence_t;

cellule_t* nouvelleCellule (void);

void detruireCellule (cellule_t*);

void conversion (char *texte, sequence_t *seq);

void afficher (sequence_t* seq);

void ajout_cmd(pile_t *p , sequence_t *s);

void interroger(pile_t *p , sequence_t *s);

void echange(pile_t *p);

void exclam(pile_t *p, sequence_t *s);

void boucle(pile_t *p , sequence_t *s);

#endif
