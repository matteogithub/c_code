#include <stdio.h>
#include <stdlib.h>

struct lista {
    int num;
    struct lista *next;
};

struct lista *crealista();
void visualizza_lista(struct lista *);

int main() {
    struct lista *punt_lista;

    punt_lista=crealista();
    if(punt_lista!=NULL) visualizza_lista(punt_lista);
}

struct lista *crealista() {
  int n,i;
  struct lista *p,*paux;

  printf("Quanti elementi vuoi inserire? ");
  scanf("%d",&n);
  if(n==0) p=NULL;
  else {
    p=(struct lista *)malloc(sizeof(struct lista));
    printf("Inserisci valore: ");
    scanf("%d",&p->num);
    paux=p;
    for(i=2;i<=n;i++) {
      paux->next=(struct lista *)malloc(sizeof(struct lista));
      paux=paux->next;
      printf("Inserisci valore: ");
      scanf("%d",&paux->num);
    }
    paux->next=NULL;
  }
  return p;
}

void visualizza_lista(struct lista *p) {
  while(p!=NULL) {
    printf("%d ",p->num);
    p=p->next;
  }

}
