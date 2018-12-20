#include <stdio.h>
#include <stdlib.h>

struct lista {
    int num;
    struct lista *next;
};

struct lista *crea_intesta();
void visualizza_lista(struct lista *);

int main() {
    struct lista *punt_lista;

    punt_lista=crea_intesta();
    if(punt_lista!=NULL) visualizza_lista(punt_lista);
}

struct lista *crea_intesta() {
  int n,i;
  struct lista *p,*paux;

  printf("Quanti elementi vuoi inserire? ");
  scanf("%d",&n);
  if(n==0) p=NULL;
  else {
    p=(struct lista *)malloc(sizeof(struct lista));
    printf("Inserisci valore: ");
    scanf("%d",&p->num);
    p->next=NULL;
    for(i=2;i<=n;i++) {
      paux=(struct lista *)malloc(sizeof(struct lista));
      printf("Inserisci valore: ");
      scanf("%d",&paux->num);
      paux->next=p;
      p=paux;
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
