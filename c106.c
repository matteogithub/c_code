#include <stdio.h>

int main() {
  FILE *fileptr;
  int i,num;

  fileptr=fopen("/Users/matteo/Documents/perfile/file03","r");
  while(feof(fileptr)==0) {
    fscanf(fileptr,"%d ",&num);
    printf("%d ",num);
  }
  fclose(fileptr);
}
