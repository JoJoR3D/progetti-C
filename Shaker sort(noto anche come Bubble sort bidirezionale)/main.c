#include <stdio.h>
#include <stdlib.h>
#include "Lib.c"
#include "Prot.h"


/*
Siti: https://it.wikipedia.org/wiki/Bubble_sort
      https://it.wikipedia.org/wiki/Shaker_sort#Shakersort

In informatica lo Shaker sort, noto anche come Bubble sort bidirezionale, Cocktail sort, Cocktail shaker sort, Ripple sort, Happy hour sort o Shuttle sort è
un algoritmo di ordinamento dei dati sviluppato dalla Sun Microsystems. Lo shaker sort è sostanzialmente una variante del bubble sort: si differenzia da
quest'ultimo per l'indice del ciclo più interno che, anziché scorrere dall'inizio alla fine, inverte la sua direzione ad ogni ciclo.
Pur mantenendo la stessa complessità, ovvero O(n²), lo shaker sort riduce la probabilità che l'ordinamento abbia un costo corrispondente al caso peggiore.


La struttura dell'algoritmo Bubble Sort porta ad avere elementi che si spostano verso la posizione corretta più velocemente di altri.
Tutti gli elementi che si spostano nella stessa direzione di scorrimento dell'indice avanzano più velocemente di quelli che lo fanno in senso contrario.
Esempio. Data la lista:

15 6 4 10 11 2
dopo la prima iterazione la disposizione dei numeri sarà:

6 4 10 11 2 15

Qui si osserva il "coniglio" 15 e la "tartaruga" 2: il primo numero, in una sola iterazione, ha attraversato tutta la lista posizionandosi nella sua
collocazione definitiva. Il secondo, invece, durante la stessa iterazione è avanzato di una sola posizione verso la sua collocazione corretta.

Ovviamente sono stati effettuati diversi tentativi per eliminare le tartarughe ed aumentare l'efficienza del Bubble sort: l'algoritmo shaker sort risolve molto
bene questo problema utilizzando un indice interno la cui direzione di scorrimento è invertita ad ogni passaggio; risulta più efficiente del Bubble sort ma
paga un dazio in termini di complessità O grande di (n al quadrato).
*/


/*In questo programma solo in ogni PRIMA CORSA, alla fine, viene ridimensionata la parte finale del array, diminuendo 'n'.*/




/*PASSAGGIO DEGLI ELEMENTI DEL ARRAY PER RIFERIMENTO. Invece per valore sarebbe: void shaker(int[], int)*/
void shaker(int*, int);



int main()
{
    int a[]={11,20,6,3,9,2,8,7};
    int n= 8, i;

    printf("Array NON ordianto\n");
    for(i=0;i<n;i++)                /*Uso la variabile 'z' poichè se usassi 'i' o 'j' questo for cambierebbe il loro valore alterando poi il risultato del ciclo while.*/
        printf("%d ",a[i]);

    printf("\n\n");

    shaker(a,n);

    printf("Array ordianto\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);         /*Posso scrivere anche: *(a+i). Essendo l'array passato per riferimento alla function shaker, a[i] oppure *(a+i),
                                      non fa altro che stampare il contenuto di 'a', ovvero l'elemento presente a quella posizione.*/
    return 0;
}

