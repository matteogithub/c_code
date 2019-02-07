#include <stdio.h>
#include <stdlib.h>

struct valori {
  int val;
  struct valori *next;
};

struct valori *inser_lista(struct valori *,int);
void visualizza_lista(struct valori *);
void scrivi_file(struct valori *);
int check_unico(struct valori *,int,int);

int main() {
  int secret,number,count=1;
  FILE *fp1;
  struct valori *lista=NULL;

  fp1=fopen("/Users/matteo/Downloads/number.txt","r");
  if(fp1!=NULL) {
    printf("\nCarico numero segreto dal file...");
    fscanf(fp1,"%d",&secret);
    printf("\nNumero segreto caricato!\n");
    //printf("%d",secret);
    printf("INDOVINA IL NUMERO (0-99): ");
    scanf("%d", &number);
    lista=inser_lista(lista,number);
    while(number!=secret){
      printf("\nHAI SBAGLIATO!");
      if(number > secret) printf("\nHai inserito un numero troppo grande\n");
      else printf("\nHai inserito un numero troppo piccolo\n");
      printf("INDOVINA IL NUMERO (0-99): ");
      scanf("%d", &number);
      lista=inser_lista(lista,number);
      count++;
    }
    printf("\nBRAVO! Hai indovinato! Hai impiegato %d tentativi\n",count);
    printf("\nQuesti sono i valori da te inseriti: ");
    visualizza_lista(lista);
    scrivi_file(lista);
  }
  else printf("\nIl file non esiste\n");
}

struct valori *inser_lista(struct valori *p, int number) {
  struct valori *p1,*paux;
  p1=(struct valori *)malloc(sizeof(struct valori));
  p1->val=number;
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
    printf("%d ",p->val);
    p=p->next;
  }
}

void scrivi_file(struct valori *p) {
  FILE *fp1;
  int check,iter=0;
  struct valori *paux;
  paux=p;
  fp1=fopen("/Users/matteo/Downloads/attempts.txt","w");
  while(paux!=NULL) {
    iter++;
    check=check_unico(p,paux->val,iter);
    if(check==0) fprintf(fp1,"%d ",paux->val);
    paux=paux->next;
  }
  fclose(fp1);
}

int check_unico(struct valori *p, int n, int iter) {
  int check=0,i=0;

  while(i<iter) {
    if(n==p->val) check++;
    p=p->next;
    i++;
  }

  if(check>1) check=1;
  else check=0;
  return check;
}
