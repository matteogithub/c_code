/*
Esercizio 4 (max 15 punti) –
Scrivere un programma in C che permetta, tramite chiamate ad una specifica funzione,
di inserire in due array N numeri interi (gli array avranno la stessa lunghezza, N) (max 6 punti).
Il programma dovrà visualizzare i due array tramite la chiamata ad una specifica funzione (max 3 punti).
Tramite un’ultima funzione, il programma dovrà confrontare ogni numero di un array con il corrispondente numero dell’altro array,
calcolare il quadrato del valore assoluto della differenza tra ogni coppia di numeri e fornire la media dei quadrati precedentemente calcolati (max 6 punti).

	Esempio:
	array1: 1, 2, 3 	array2: 4, 5, 6 	media: 9

- Nota: abs(x) restituisce il valore assoluto di x e richiede l’inserimento della libreria <stdlib.h>.
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 100

void carica_array(int *,int);
void visualizza_array(int *,int);
float quadrati(int *,int *,int);

int main() {
  int n,a1[DIM],a2[DIM];
  float media;

  printf("Carica due array di dimensione N");
  printf("\nDefinisci N: ");
  do {
    scanf("%d", &n);
  } while(n<1 || n>DIM);

  printf("\nRiempi il primo array...");
  carica_array(a1,n);
  printf("\nRiempi il secondo array...");
  carica_array(a2,n);
  printf("\nPrimo array...");
  visualizza_array(a1,n);
  printf("\nSecondo array...");
  visualizza_array(a2,n);
  media=quadrati(a1,a2,n);
  printf("\nLa media dei quadrati del val ass delle diff vale %.2f",media);
}

void carica_array(int *a,int n) {
  int i;

  for(i=0;i<n;i++) {
    printf("\nInserisci elemento di indice %d ",i);
    scanf("%d",a+i);
  }
}

void visualizza_array(int *a,int n) {
  int i;

  for(i=0;i<n;i++) {
    printf("\nElemento di indice %d ",i);
    printf("%d",*(a+i));
  }
}

float quadrati(int *a1,int *a2,int n) {
  int i;
  float media=0;

  for(i=0;i<n;i++) {
    media+=abs(*(a1+i)-*(a2+i))*abs(*(a1+i)-*(a2+i));
  }
  return (float)media/n;
}
