// Esercizio 3 (max 20 punti). Scrivere un programma in C che:
// 1. permetta all’utente di leggere da file n numeri interi e di caricarli in un array (max 12 punti)
// 2. stampi a video l’array in ordine crescente (max 8 punti)
//
//
// Esercizio 4 (max 10 punti). Estendere l’esercizio 3 con le seguenti funzionalità.
// Il programma dovrà consentire di:
// 1. creare una lista lineare concatenata (utilizzando l’allocazione dinamica della memoria) che contenga tutti gli elementi unici presenti nell’array (max 8 punti)
// 2. stampare a video gli elementi della lista solo se questa non è vuota (max 2 punti)

#include <stdio.h>
#include <stdlib.h>
#define DIM 50

struct valori {
  int num;
  struct valori *next;
};

void ordina_array(int *,int);
int check_unico(int *,int,int);
struct valori *inser_lista(struct valori *,int);
void visualizza_lista(struct valori *);

int main() {
  int v[DIM],i=0,j,check=0;
  FILE *fp1;
  struct valori *lista=NULL;

  fp1=fopen("/Users/matteo/Downloads/numbers.txt","r");
  if(fp1!=NULL) {
    printf("\nCarico dati dal file...\n");
    while(feof(fp1)==0 && i<DIM) {
          fscanf(fp1,"%d",&v[i]);
          i++;
    }

  printf("\nElenco dei %d numeri caricati dal file...\n",i);
  for(j=0;j<i;j++)
    printf("%d ",v[j]);


  ordina_array(v,i);
  printf("\nNumeri ordinati...\n");
  for(j=0;j<i;j++)
    printf("%d ",v[j]);


  for(j=0;j<i;j++) {
    check=check_unico(v,i,v[j]);
    if(check==0) lista=inser_lista(lista,v[j]);
    }
    
  if(lista!=NULL) {
    printf("\nNumeri inseriti nella lista...\n");
    visualizza_lista(lista);
  }
  }
  else printf("\nIl file non esiste\n");
}

void ordina_array(int *v,int n) {
  int i,j,tmp;
  for(i=0; i<n-1; i++)
        for(j=0; j<n-1; j++)
            if(*(v+j) > *(v+j+1)) {
                tmp = *(v+j);
                *(v+j) = *(v+j+1);
                *(v+j+1) = tmp;
            }
}

int check_unico(int *v,int n, int val) {
  int count=0,check,i;
  for(i=0;i<n;i++)
    if(v[i]==val) count++;
  if(count==1) check=0;
  else check=1;
  return check;
}

struct valori *inser_lista(struct valori *p, int val) {
  struct valori *p1,*paux;
  p1=(struct valori *)malloc(sizeof(struct valori));
  p1->num=val;
  if(p==NULL) {
    p=p1;
    p->next=NULL;
  }
  else {
    p1->next=NULL;
    paux=p;
    while(paux->next!=NULL) paux=paux->next;
    paux->next=p1;
  }
  return p;
}

void visualizza_lista(struct valori *p) {
  while(p!=NULL) {
    printf("%d ",p->num);
    p=p->next;
  }
}
