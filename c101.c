#include <stdio.h>
#define DIM 100

int main() {

  FILE *fileptr;
  char vettore[DIM];
  int size=1,n,i;

  fileptr=fopen("/Users/matteo/Documents/perfile/file01","r");
  if(fileptr==NULL)
    printf("\nFile inesistente\n");
  else {
    n=fread(vettore,size,DIM,fileptr);
  }

  printf("%d",n);

  for(i=0;i<n;i++)
    printf("%c",vettore[i]);

  n=fread(vettore,size,DIM,fileptr);
  printf("%d",n);
  fclose(fileptr);
}
