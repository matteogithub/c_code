#include <stdio.h>
#define DIM 5

int main() {
  int v[DIM],n,i;
  int num,pos;

  do  {
    printf("Dimensione array: \n");
    scanf("%d", &n);
  } while(n<1 || n>DIM);

  printf("Inserisci elementi:\n");
  for(i=0;i<n;i++)  {
      printf("elemento di indice - %d : ",i);
      scanf("%d",&v[i]);
  }

  printf("\nArray: ");
  for(i=0;i<n;i++)
      printf("%d ",v[i]);

  printf("\nIndice elem da cancellare ");
  scanf("%d",&pos);

  if(pos<0 || pos>n-1) {
    printf("\Indice non valido");
  }
  else {
    //sposta a sinistra
    for(i=pos;i<n;i++)
      v[i]=v[i+1];
    n--;
  }

  printf("\nArray dopo ins: ");
  for(i=0;i<n;i++)
      printf("%d ",v[i]);
}
