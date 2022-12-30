#include "prototype.h"

int main() {
    machine m;
    machine Tm[50];
    panne p;
    int n,ref,n_rep,n_nrep,x;
    do {
        printf("*******************\n");
        printf("1-Ajouter machine\n");
        printf("2-Ajouter Panne\n");
        printf("3-Rechercher une machine\n");
        printf("4-Modifier Etat panne\n");
        printf("5-Afficher panne\n");
        printf("6-Calculer les pannes reparee\n");
        printf("7-Supprimer les machines reparee\n");
        printf("0-Quitter\n");
        printf("*******************\n");
        scanf("%d",&x);
        switch (x) {
            case 1:
                saisir(&m);
                ajouter(Tm,m,&n);
                break;
            case 2:
                saisirPanne(&p);
                printf("Donner la reference de la machine\n");
                scanf("%d",&ref);
                ajouterPanne(ref,Tm,n,p);
                break;
            case 3:
                printf("Donner la reference de la machine\n");
                scanf("%d",&ref);
                printf("La position de cette machine est:%d\n",rechercherMach(Tm,n,ref)+1);
                break;
            case 4:
                printf("Donner la reference de la machine\n");
                scanf("%d",&ref);
                modifier_etat_panne(ref,Tm,n);
                break;
            case 5:
                printf("Donner la reference de la machine\n");
                scanf("%d",&ref);
                afficher(n,Tm,ref);
                break;
            case 6:
                printf("Donner la reference de la machine\n");
                scanf("%d",&ref);
                trouver(Tm,n,&n_rep,&n_nrep,ref);
                printf("Les machines reparee=%d, les machines non reparee=%d\n",n_rep,n_nrep);
                break;
            case 7:
                supprimer(Tm,&n);
                printf("Les ID des machines qui restent sont:\n");
                for (int i=0;i<n;i++) {
                    printf("ref = %d\n",Tm[i].ref);
                }
                break;
        }
    } while ( (x!=0) && (x>=1) && (x<=7) );
    system("cls");
    printf("Program fini!");
}
