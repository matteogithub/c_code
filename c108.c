#include <stdio.h>
#define DIM 100

int main() {

  FILE *fileptr;
  char vettore[DIM];
  char *s;
  int i=0;

  fileptr=fopen("/Users/matteo/Documents/perfile/file05","w");

  if(fileptr==NULL)
    printf("\nFile inesistente\n");
  else {
    printf("Inserisci del testo: ");
    fgets(vettore,DIM,stdin);
    fprintf(fileptr,"%s",vettore);
    fclose(fileptr);
    }
  }
