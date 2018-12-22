#include <stdio.h>
#include <stdlib.h>

struct lista {
    int num;
    struct lista *next;
};

struct lista *ins_coda(struct lista *,int);
void visualizza_lista(struct lista *);
struct lista *elimina_pari(struct lista *);

int main() {
    struct lista *punt_lista=NULL;
    int val=-1;

    while(val!=0) {
      printf("\nInserisci un intero, 0 per uscire\n");
      scanf("%d",&val);
      if(val!=0) punt_lista=ins_coda(punt_lista,val);
    }
    if(punt_lista!=NULL) visualizza_lista(punt_lista);
    else printf("\nLa lista e' vuota\n");
    if(punt_lista!=NULL) {
      punt_lista=elimina_pari(punt_lista);
      if(punt_lista!=NULL) visualizza_lista(punt_lista);
        else printf("\nLa lista ora e' vuota\n");
    }
}

struct lista *ins_coda(struct lista *p, int val) {
  struct lista *p1,*paux;

  p1=(struct lista *)malloc(sizeof(struct lista));
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

void visualizza_lista(struct lista *p) {
  while(p!=NULL) {
    printf("%d ",p->num);
    p=p->next;
  }
}

struct lista *elimina_pari(struct lista *p) {
  struct lista *paux,*p2;

  while(p!=NULL && p->num%2==0) {
        p2=p;
        p=p->next;
        free(p2);
    }
    if (p==NULL) return p;
    else {
      paux=p;
      while(paux->next!=NULL) {
          if(paux->next->num%2!=0) paux=paux->next;
          else {
              p2=paux->next;
              paux->next=paux->next->next;
              free(p2);
          }
      }
      return p;
    }
}
