// Esercizio 4 (max 15 punti). Scrivere un programma in C che:
// 1. permetta all’utente di inserire da tastiera n numeri interi in un array (max 4 punti)
// 2. permetta di verificare, prima di inserire i numeri, che sia rispettata la dimensione massima dell’array (max 3 punti)
// 3. stampi a video l’array in ordine di inserimento se il primo elemento dell’array è pari, in ordine inverso se il primo elemento dell’array è dispari (max 8 punti)
//
// Esercizio 5 (max 15 punti). Estendere l’esercizio 4 con le seguenti funzionalità.
// Il programma dovrà consentire di:
// 1. copiare in un secondo array tutti gli elementi unici del primo array (cioè presenti una sola volta)  (max 12 punti)
// 2. stampare gli elementi del secondo array solo se questo contiene almeno un elemento (max 3 punti)
//
// 	Esempio:
// 	primo_array: 	5 2 3 1 4 3 1
// 	secondo_array: 	5 2 4

#include <stdio.h>
#define DIM 10

int main() {
  int v[DIM],s[DIM],n,i,j,ind,count=0;

  do  {
    printf("Inserisci dimensione array: \n");
    scanf("%d", &n);
  } while(n<1 || n>DIM);

  printf("Inserisci i %d elementi:\n",n);
  for(i=0;i<n;i++)  {
      printf("elemento di indice - %d : ",i);
      scanf("%d",&v[i]);
  }

  printf("\nElementi inseriti: ");
  if(v[0]%2==0)
      for(i=0;i<n;i++)
          printf("%d ",v[i]);
    else
      for(i=n-1;i>=0;i--)
          printf("%d ",v[i]);

  ind=0;
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++)
      if(v[i]==v[j]) count++;

    if(count==1) {
      s[ind]=v[i];
      ind++;
    }
    count=0;
  }

  printf("\nElementi unici: ");
  for(i=0;i<ind;i++)
      printf("%d ",s[i]);
}
