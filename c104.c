#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fileptr;
  int i;

  fileptr=fopen("/Users/matteo/Documents/perfile/file04","w");
  for(i=1;i<=5;i++)
    fprintf(fileptr,"%d ",rand()%10);
  fclose(fileptr);
}
