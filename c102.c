#include <stdio.h>
#include <string.h>
#define DIM 100

int main() {

  FILE *fileptr;
  char vettore[DIM];
  int size=1,n,i,len;

  printf("Inserisci del testo: ");
  scanf("%s",vettore);
  len=strlen(vettore);

  fileptr=fopen("/Users/matteo/Documents/perfile/file02","w");
  n=fwrite(vettore,size,len,fileptr);
  printf("%d",n);
  fclose(fileptr);
}
