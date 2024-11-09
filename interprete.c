#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "pile.h"
#include "listes.h"
#include "curiosity.h"


/*
 *  Auteur(s) : Mira Sadek , Marie Ange Nader
 *  Date : 09/10/2024
 *  Suivi des Modifications :
 *
 */

void stop (void)
{
    char enter = '\0';
    printf ("Appuyer sur entrée pour continuer...\n");
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
}



int interprete (sequence_t* seq, bool debug,pile_t *p)
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
                break;
            case 'G':
                gauche();
                break;
            case 'D':
                droite();
                break;
            case '0'...'9':
                empiler(p,&seq->tete->command);
                break;
            case '+':
            case '-':
            case '*':
                calculette(p,seq->tete->command);
                break;
            case 'P':
                pose(atoi(depiler(p)));
                break;
            case 'M':
                ;
                char mes[2];
                sprintf(mes,"%d",mesure(atoi(depiler(p)))); //Convertir le int dans la chaine mes
                empiler(p,mes);
            default:
                eprintf("Caractère inconnu: '%c'\n", seq->tete->command);
        }
        seq->tete = seq->tete->suivant;

        /* Affichage pour faciliter le debug */
        afficherCarte();
        afficher_pile(p);
        printf ("Programme:");
        afficher(seq);
        printf ("\n");
        if (debug) stop();
    }

    /* Si on sort de la boucle sans arriver sur la cible,
     * c'est raté :-( */

    return CIBLERATEE;
}
