#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct element element;
struct element {
    char* Nom;
    int Taille;
	short type;
	short modif;
    element* Suivant;
};
typedef element* ListElts;
ListElts TS=NULL;
ListElts inserer(char *s,short type) {
    ListElts p=malloc(sizeof(element));
    p->Nom=s; p->Taille=strlen(s); p->type=type%2; p->modif=type/2; p->Suivant=TS; TS=p;
}

void afficher(ListElts l) {
    while(l!=NULL) {
        printf("IDF: %s TYPE: %d MODIF: %d\n",l->Nom,l->type,l->modif);
        l=l->Suivant;
    }
}

int rechercher(char* s) {
	ListElts l=TS;
    while(l!=NULL) if(!strcmp(l->Nom,s)) return 1; else l=l->Suivant; return 0;
}

element get(char* s) {
	ListElts l=TS;
    while(l!=NULL) if(!strcmp(l->Nom,s)) return *l; else l=l->Suivant; return *l;
}