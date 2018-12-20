#include <stdio.h>

int main() {
  FILE *fileptr;
  int i;

  fileptr=fopen("/Users/matteo/Documents/perfile/file03","w");
  for(i=1;i<=10;i++)
    fprintf(fileptr,"%d ",i);
  fclose(fileptr);
}
