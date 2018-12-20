#include <stdio.h>
#include <stdlib.h>

struct lista {
    int num;
    struct lista *next;
};

struct lista *ins_coda(struct lista *);
void visualizza_lista(struct lista *);
struct lista *elimina(struct lista *);

int main() {
    struct lista *punt_lista=NULL;
    int sel=-1;

    while(sel!=0) {
      printf("\n1- Inserisci elemento");
      printf("\n2- Visualizza elementi");
      printf("\n3- Elimina elemento");
      printf("\n0- Esci\n");
      scanf("%d",&sel);
      switch (sel) {
        case 1:
          punt_lista=ins_coda(punt_lista);
          break;
        case 2:
          if(punt_lista!=NULL) {
            printf("\nLista elementi: ");
            visualizza_lista(punt_lista);
          }
          else printf("\nLista vuota\n");
          break;
        case 3:
          if(punt_lista!=NULL)
          punt_lista=elimina(punt_lista);
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

struct lista *ins_coda(struct lista *p) {
  struct lista *p1,*paux;

  p1=(struct lista *)malloc(sizeof(struct lista));
  printf("Inserisci valore: ");
  scanf("%d",&p1->num);
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

struct lista *elimina(struct lista *p) {
    struct lista *p1=p,*p2;
    int el;
    int trovato=0;

    printf("Inserisci elemento da eliminare: \n");
    scanf("%d",&el);
    if(p1!=NULL)
    {
        if(p1->num == el)
        {
            p2=p1;
            p=p->next;
            free(p2);
            return p;
        }
        else
        {
            while(p1->next!=NULL && trovato!=1)
            {
                if(p1->next->num != el) p1=p1->next;
                else
                {
                    trovato=1;
                    p2=p1->next;
                    p1->next=p1->next->next;
                    free(p2);
                    return p;
                }
            }
        }
        if(!trovato) printf("Elemento non presente nella lista!\n");
    }
    else printf("La lista e' vuota!\n Nessun elemento da eliminare!\n\n");
    return p;
}
