#include <stdio.h>
#define DIM 10

float calcola_media(int *, int);
void scrivi_file(int *, int, float);

int main() {
  int n,v[DIM],i;
  float media;

  do  {
    printf("Inserisci dimensione array: \n");
    scanf("%d", &n);
  } while(n<1 || n>DIM);

  printf("Inserisci i %d elementi:\n",n);
  for(i=0;i<n;i++)  {
      printf("elemento di indice - %d : ",i);
      scanf("%d",&v[i]);
  }

  media=calcola_media(v, n);
  printf("\nLa media vale: %.1f",media);

  for(i=0;i<n;i++)
      printf("\nelemento di indice - %d: %d ",i, v[i]);

  scrivi_file(v, n, media);
}

float calcola_media(int *v, int n) {
  int i;
  float media=0;

  for(i=0;i<n;i++)
    media+=*(v+i);
  return media/n;
}

void scrivi_file(int *v, int n, float media) {
  FILE *fileptr;
  int i;

  fileptr=fopen("/Users/matteo/Documents/perfile/file07","w");
  for(i=0;i<n;i++) {
    if(*(v+i)>media)
      fprintf(fileptr,"%d ",*(v+i));
  }
}
