/*
Esercizio 3 (max 15 punti) -
Scrivere un programma in C che permetta di caricare in una lista concatenata lineare le coordinate (x e y) di N punti, con N scelto dall’utente.
La lista dovrà essere costituita da una successione di punti la cui distanza dall’origine sia strettamente crescente.
È richiesto l’utilizzo di una funzione che, prima di inserire un nuovo punto nella lista,
verifichi se la distanza del punto oggetto dell’inserimento è maggiore di quella del punto che lo precederebbe.
Nel caso questa condizione non fosse soddisfatta il punto non dovrà essere inserito nella lista.
Il programma, al termine del caricamento, dovrà stampare le coordinate dei (N) punti inseriti.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct punto_lista {
  int x;
  int y;
  struct punto_lista *next;
};

struct punto_lista *inser_lista(struct punto_lista *,int,int);
void visualizza_lista(struct punto_lista *);
float check_dist(struct punto_lista *);

int main() {
  int n_punti,i,x,y,n=1;
  struct punto_lista *lista=NULL;

  printf("\nQuanti punti vuoi inserire? ");
  scanf("%d",&n_punti);
  printf("\nInserisci le coordinate dei %d punti: ",n_punti);
  while(n<=n_punti) {
    printf("\nPunto %d x: ",n);
    scanf("%d",&x);
    printf("Punto %d y: ",n);
    scanf("%d",&y);
    if(lista==NULL) {
      lista=inser_lista(lista, x, y);
      n++;
    }
    else if(sqrt(x*x+y*y)>check_dist(lista)) {
      lista=inser_lista(lista, x, y);
      n++;
    }
    else printf("\nPunto non iserito!");
  }
  printf("Coordinate dei %d punti inseriti: ",n_punti);
  visualizza_lista(lista);
}

struct punto_lista *inser_lista(struct punto_lista *p, int x, int y) {
  struct punto_lista *p1,*paux;
  p1=(struct punto_lista *)malloc(sizeof(struct punto_lista));
  p1->x=x;
  p1->y=y;
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

void visualizza_lista(struct punto_lista *p) {
  while(p!=NULL) {
    printf("%d %d; ",p->x,p->y);
    p=p->next;
  }
}

float check_dist(struct punto_lista *p) {
  float dist;
  while(p->next!=NULL) p=p->next;
  dist=sqrt(p->x*p->x+p->y*p->y);
  return dist;
}
