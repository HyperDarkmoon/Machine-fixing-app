#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char refPanne[50];
    int etat;
}panne;

typedef struct {
    int ref;
    panne P[10];
}machine;

void saisir(machine *m);
void ajouter(machine Tm[],machine m,int * n);
int rechercherMach(machine Tm[],int n,int ref);
void saisirPanne(panne *p);
void ajouterPanne(int ref, machine Tm[],int n,panne p);
int totalPanne(int ref,machine Tm[],int n);
void modifier_etat_panne(int ref, machine Tm[],int n);
void afficher(int n, machine Tm[],int ref);
void trouver(machine Tm[],int n,int *n_rep, int *n_nrep,int ref);
void supprimer(machine Tm[],int *n);
