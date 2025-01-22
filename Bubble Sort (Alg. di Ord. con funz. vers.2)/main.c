#include <stdio.h>
#include <stdlib.h>
#include "Libreria.c"
#include "Prototipo.h"


/*In informatica il Bubble sort o ordinamento a bolla è un semplice algoritmo di ordinamento di liste di dati. In esso l'insieme di dati viene scansionato,
  ogni coppia di elementi adiacenti viene comparata ed i due elementi vengono invertiti di posizione se sono nell'ordine sbagliato.*/


/*COSTO del algoritmo:
  Il bubble sort effettua all'incirca N^2 fratto 2 confronti ed N^2 fratto 2 scambi sia in media che nel caso peggiore.
  Il tempo di esecuzione dell'algoritmo è (O grande) di N^2.
   Il caso particolare in cui il numero destinato alla prima posizione dell'array si trovi nell'ultima corrisponde a una situazione di "caso peggiore"
   del bubblesort, in cui saranno necessarie tutte le N-1 iterazioni dell'algoritmo per ottenere l'array ordinato.
*/




int main()
{
    int a[]={11,1,12,3,9,2,8,7};
    int n= 8, i;

    printf("Array NON ordianto\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\n\n");

    ord(a,n);                       /*'a' è l'indirizzo base del array che però può essere scritto anche come: &a[0]*/

    printf("Array ordianto\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);         /*Posso scrivere anche: *(a+i). Essendo l'array passato per riferimento alla function shaker, a[i] oppure *(a+i),
                                      non fa altro che stampare il contenuto di 'a', ovvero l'elemento presente a quella posizione.*/

    return 0;
}



/*ESEMPIO FUNZIONAMENTO del PROGRAMMA:

Array NON ordinato
11,10,6,3,9,2,8,7




I iterazione (ciclo)
10,6,3,9,2,8,7,11

n-1; cont !=0;
Nuovo array:
10,6,3,9,2,8,7




II iterazione
6,3,9,2,8,7,10

n-1; cont !=0;
nuovo array:
6,3,9,2,8,7




III iterazione
3,6,2,8,7,9

n-1; cont !=0;
Nuovo array:
3,6,2,8,7




IV iterazione
3,2,6,7,8

n-1; cont !=0;
Nuovo array:
3,2,6,7




V iterazione
2,3,6,7

n-1; cont !=0;
Nuovo array:
2,3,6




VI iterazione
2,3,6
Nessuno scambio da eseguire (cont= 0)
break;


Array ordinato:
2,3,6,7,8,9,10,11
*/
