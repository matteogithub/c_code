#include <stdio.h>
#define DIM 100

int main() {

  FILE *fileptr;
  char vettore[DIM];
  char *s;
  int i=0;

  fileptr=fopen("/Users/matteo/Documents/perfile/file01","r");
  if(fileptr==NULL)
    printf("\nFile inesistente\n");
  else {
    while(feof(fileptr)==0) {
      s=fgets(vettore,DIM,fileptr);
    }
  }
  printf("%s",vettore);
  fclose(fileptr);
}
