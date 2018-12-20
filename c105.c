#include <stdio.h>

int main() {
  FILE *fileptr;
  int i,num;

  fileptr=fopen("/Users/matteo/Documents/perfile/file03","r");
  for(i=1;i<=5;i++) {
    fscanf(fileptr,"%d ",&num);
    printf("%d ",num);
  }
  fclose(fileptr);
}
