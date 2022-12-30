#include "prototype.h"

void saisir(machine *m) {
    printf("Donner la reference du machine\n");
    scanf("%d",&(m->ref));
    for (int i=0;i<10;i++) {
        m->P[i].refPanne[0]='\0';
    }
}

void ajouter(machine Tm[],machine m,int *n) {
    if (rechercherMach(Tm,*n,m.ref)==-1) {
        Tm[*n]=m;
        (*n)++;
        printf("Machine ajoute avec success!\n");
    }
}

int rechercherMach(machine Tm[],int n,int ref) {
    int i;
    i = 0;
    int find=-1;
    do {
        if (Tm[i].ref==ref) {
            find=i;
        } else {
            i++;
        }
    } while ((find==-1)&&(i<n));
    return(find);
}

void saisirPanne(panne *p) {
    printf("Donner la reference de la panne et l'etat\n");
    scanf("%s",(p->refPanne));
    do {
        printf("Etat de la panne (0 ou 1)\n");
        scanf("%d",&(p->etat));
    } while ( (p->etat<0) || (p->etat>1) );
}

void ajouterPanne(int ref, machine Tm[], int n, panne p) {
    int x=rechercherMach(Tm,n,ref);
    int i=0;;
    int ajout=0;
    if (x!=-1) {
        do {
            if (Tm[x].P[i].refPanne[0]=='\0') {
                Tm[x].P[i]=p;
                ajout=1;
            } else {
                i++;
            }
        } while ((ajout==0)&&(i<10));
        if (ajout==1) {
            printf("Ajout avec success!\n");
        } else {
            printf("Pannes plein!\n");
        }
    } else {
        printf("Reference inexistant\n");
    }
}

int totalPanne(int ref, machine Tm[],int n) {
    int x=rechercherMach(Tm,n,ref);
    int count=0;
    int i=0;
    if (x!=-1) {
        do {
            if (Tm[x].P[i].refPanne[0]!='\0') {
                count++;
                i++;
            } else {
                i++;
            }
        } while ((Tm[x].P[i].refPanne[0]!='\0')&&(i<10));
    } else {
        printf("Reference inexistant\n");
    }
    return(count);
}

void modifier_etat_panne(int ref, machine Tm[],int n) {
    int x=rechercherMach(Tm,n,ref);
    if (x!=-1) {
        for (int i=0;i<totalPanne(ref,Tm,n);i++) {
            if (Tm[x].P[i].etat==0) {
                Tm[x].P[i].etat=1;
            }
        }
    } else {
        printf("Reference inexistant\n");
    }
}

void afficher(int n, machine Tm[],int ref) {
    int x=rechercherMach(Tm,n,ref);
    if (x!=-1) {
        printf("Nombre de panne = %d \n",totalPanne(ref,Tm,n));
        for (int i=0;i<totalPanne(ref,Tm,n);i++) {
            printf("Panne N°%d:\nRefPanne: %s \netat: %d\n",i+1,Tm[x].P[i].refPanne,Tm[x].P[i].etat);
        }
    } else {
        printf("Reference inexistant\n");
    }
}

void trouver(machine Tm[],int n,int *n_rep, int *n_nrep,int ref) {
    int x=rechercherMach(Tm,n,ref);
    *(n_rep)=0;
    *(n_nrep)=0;
    if (x!=-1) {
         for (int i=0;i<totalPanne(ref,Tm,n);i++) {
            if (Tm[x].P[i].etat==1) {
                *(n_rep)=*(n_rep)+1;
            } else {
                *(n_nrep)=*(n_nrep)+1;
            }
         }
    } else {
        printf("Reference inexistant\n");
    }
}


void supprimer(machine Tm[],int *n) {
    int i;
    int n_rep,n_nrep;
    int T[50];
    int j=0;
    for (i=0;i<*n;i++) {
        trouver(Tm,*n,&n_rep,&n_nrep,Tm[i].ref);
        if (n_rep==totalPanne(Tm[i].ref,Tm,*n)) {
            T[j]=i;
            j++;
            //on sauvegarde les cases pour supprimer apres la boucle
        }
    }

    for (i=0;i<j;i++) {
        printf("La machine dont lid est %d va etre supprime\n",Tm[T[i]].ref);
        for (int k=T[i];k<(*n)-1;k++) {
            Tm[k]=Tm[k+1];
        }
        (*n)--;
    }
}
