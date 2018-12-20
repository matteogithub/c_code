#include <stdio.h>
#include <stdlib.h>

struct lista {
    int num;
    struct lista *next;
};

struct lista *ins_ord(struct lista *);
void visualizza_lista(struct lista *);

int main() {
    struct lista *punt_lista=NULL;
    int sel=-1;

    while(sel!=0) {
      printf("\n1- Inserisci elemento\n");
      printf("\n2- Visualizza elementi\n");
      printf("\n0- Esci\n");
      scanf("%d",&sel);
      switch (sel) {
        case 1:
          punt_lista=ins_ord(punt_lista);
          break;
        case 2:
          if(punt_lista!=NULL) {
            printf("\nLista elementi: ");
            visualizza_lista(punt_lista);
          }
          else printf("\nLista vuota\n");
          break;
        case 0:
          printf("\nProgramma terminato\n");
          break;
        default:
          printf("\nScelta non valida\n");
      }
    }
}

struct lista *ins_ord(struct lista *p) {
  struct lista *p1,*paux;

  p1=(struct lista *)malloc(sizeof(struct lista));
  printf("Inserisci valore: ");
  scanf("%d",&p1->num);
  if(p==NULL) {
    p=p1;
    p->next=NULL;
  }
  else {
    if(p1->num<p->num) {
      p1->next=p;
      p=p1;
    }
    else {
      paux=p;
      while(paux->next != NULL && p1->num > paux->next->num)
        paux=paux->next;
      p1->next=paux->next;
      paux->next=p1;
    }
  }
  return p;
}

void visualizza_lista(struct lista *p) {
  while(p!=NULL) {
    printf("%d ",p->num);
    p=p->next;
  }
}
