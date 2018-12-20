#include <stdio.h>
#define DIM 100

int main() {

  FILE *fileptr;
  char vettore[DIM],invio;
  int n,i;

  fileptr=fopen("/Users/matteo/Documents/perfile/file06","w");
  printf("\nQuante linee vuoi scrivere: ");
  scanf("%d",&n);
  scanf("%c",&invio);

  for(i=1;i<=n;i++) {
    printf("\nInserisci linea %d: ", i);
    fgets(vettore,DIM,stdin);
    fputs(vettore,fileptr);
  }
  fclose(fileptr);
}
