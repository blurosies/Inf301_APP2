#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "listes.h"
#include "curiosity.h"


/*
 *  Auteur(s) : Mira Sadek , Marie Ange Nader
 *  Date : 09/10/2024
 *  Suivi des Modifications :
 *
 */

#define TAILLE_MAX 100 

// definir structure de la pile
typedef struct {
    char* tab[TAILLE_MAX];
    int nb_elem;
} pile;



void empiler(pile *p, char *x) {
    if (p->nb_elem < TAILLE_MAX) {
        p->tab[p->nb_elem++] = x;
    } else {
        fprintf(stderr, "Débordement de pile !\n");
        exit(EXIT_FAILURE);
    }
}

char *depiler(pile *p) {
    if (p->nb_elem > 0) {
        return p->tab[--p->nb_elem];
    } else {
        fprintf(stderr, "Dépassement de pile !\n");
        exit(EXIT_FAILURE);
    }
}

void afficher_pile(const pile *p) {
    if (p->nb_elem == 0) {
        printf("La pile est vide !\n");
    } else {
        printf("Contenu de la pile: ");
        for (int i = p->nb_elem - 1; i >= 0; i--) {
            printf("%s ", p->tab[i]);
        }
    }
}

void stop (void)
{
    char enter = '\0';
    printf ("Appuyer sur entrée pour continuer...\n");
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
}



int interprete (sequence_t* seq, bool debug)
{
    // Version temporaire a remplacer par une lecture des commandes dans la
    // liste chainee et leur interpretation.



    debug = true; /* À enlever par la suite et utiliser "-d" sur la ligne de commandes */

    printf ("Programme:");
    afficher(seq);
    printf ("\n");
    if (debug) stop();

    // À partir d'ici, beaucoup de choses à modifier dans la suite.
    // commande = seq->tete->command ; //à modifier: premiere commande de la sequence
    int ret;         //utilisée pour les valeurs de retour

    while ( seq->tete != NULL ) { //à modifier: condition de boucle

        switch (seq->tete->command) {
            /* Ici on avance tout le temps, à compléter pour gérer d'autres commandes */
            case 'A':
                ret = avance();
                if (ret == VICTOIRE) return VICTOIRE; /* on a atteint la cible */
                if (ret == RATE)     return RATE;     /* tombé dans l'eau ou sur un rocher */
                break; /* à ne jamais oublier !!! */
            case 'G':
                gauche();
                break; /* à ne jamais oublier !!! */
            case 'D':
                droite();
                break; /* à ne jamais oublier !!! */
            default:
                eprintf("Caractère inconnu: '%c'\n", seq->tete->command);
        }
        seq->tete = seq->tete->suivant;

        /* Affichage pour faciliter le debug */
        afficherCarte();
        printf ("Programme:");
        afficher(seq);
        printf ("\n");
        if (debug) stop();
    }

    /* Si on sort de la boucle sans arriver sur la cible,
     * c'est raté :-( */

    return CIBLERATEE;
}
