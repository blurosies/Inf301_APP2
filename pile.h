struct elem {
    char *  nom;
    struct elem *suiv;
};
typedef struct elem el_pile;
struct pile {
    el_pile *tete;
};
typedef struct pile pile_t;

void empiler(pile_t *p, char * s) ;

char * depiler(pile_t *p);

void afficher_pile(pile_t *p);

void calculette(pile_t *p , char symb);

