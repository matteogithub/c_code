#include <stdio.h>
#define DIM 20

void scrivi_file(int *, int *, int, int);

int main() {
  FILE *fileptr1,*fileptr2;
  int v1[DIM],v2[DIM],i,j;

  fileptr1=fopen("/Users/matteo/Documents/perfile/file_01","r");
  if(fileptr1==NULL) printf("\nFile inesistente\n");
  else {
    i=0;
    while(feof(fileptr1)==0) {
      fscanf(fileptr1, "%d", &v1[i]);
      i++;
    }
  }

  fileptr2=fopen("/Users/matteo/Documents/perfile/file_02","r");
  if(fileptr2==NULL) printf("\nFile inesistente\n");
  else {
    j=0;
    while(feof(fileptr2)==0) {
      fscanf(fileptr2, "%d", &v2[j]);
      j++;
    }
  }

  if(fileptr1!=NULL && fileptr2!=NULL)
    scrivi_file(v1, v2, i, j);
}

void scrivi_file(int *v1, int *v2, int d1, int d2) {
  FILE *fileptr;
  int i;

  fileptr=fopen("/Users/matteo/Documents/perfile/file_03","w");
  if(d1>d2) d1=d2;
  for(i=0;i<d1;i++) {
    if(*(v1+i)==*(v2+i)) fprintf(fileptr,"%d ",1);
    else fprintf(fileptr,"%d ",0);
  }
}
