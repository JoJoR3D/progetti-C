#include <stdio.h>
#include <stdlib.h>
#include "lib.c"
#include "Prot.h"


/*
Link Sito: https://it.wikipedia.org/wiki/Comb_sort

Il Comb sort migliora l'algoritmo bubble sort e compete in velocità con algoritmi storicamente veloci come il Merge sort. L'idea basilare dell'algoritmo è quella
di eliminare le cosiddette "tartarughe", ovvero valori piccoli vicini alla fine della lista, essendo provato che in un bubble sort questi valori tendono spessissimo
a scendere nella loro posizione in modo tremendamente lento. (i "conigli", ovvero grandi valori all'inizio della lista, non rappresentano un problema nel
bubble sort perché generalmente vengono spostati molto velocemente).

Nel bubble sort, quando vengono confrontati due elementi, essi hanno sempre un passo (distanza reciproca) pari ad 1. L'idea alla base del comb sort è che il passo
possa essere anche maggiore (anche lo Shell sort è basato su questa idea, ma esso rappresenta una modifica dell'insertion sort piuttosto che del bubble sort).


FUNZIONAMENTO:
Il passo, o intervallo del confronto, è impostato inizialmente alla lunghezza dell'array da ordinare divisa per il fattore di riduzione (generalmente 1,3), e
la lista viene ordinata con tale intervallo (arrotondato per difetto all'intero, se necessario). Terminato il primo passaggio il passo viene diviso nuovamente
per il fattore di riduzione (arrotondato all'intero), e la lista viene ordinata con questo nuovo intervallo. Il processo si ripete finché il passo è pari a 1.
A questo punto, il Comb sort continua ad usare un passo di 1 finché non si ha un ordinamento totale. Il passaggio finale dell'algoritmo è quindi equivalente ad
un bubble sort, ma in questo modo molte "tartarughe" sono scomparse, ed in tal modo il bubble sort è molto più efficiente.


Il FATTORE DI RIDUZIONE ha un grande peso sull'efficienza del Comb sort. Ai tempi della sua creazione, gli autori suggerirono di usare il valore di 1,3 in base a delle prove sperimentali basate sulla casualità. Un valore troppo piccolo degrada le prestazioni dell'algoritmo perché si rendono necessari più confronti, mentre con valore troppo alto non si riuscirebbe ad eliminare un numero di "tartarughe" tale da rendere il comb sort un miglioramento sostanziale del bubble sort.

Il valore consigliato come fattore è: 1.247330950103979 (approssimato: 1.25).
*/






int main()
{
    int a[]={10,9,15,5};
    int n= 4, i;

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




/*
ESEMPIO FUNZIONAMENTO:

Array da ordianre: 10,9,15,5
i=0; n=4; gap=n;




PRIMO CICLO:

if(gap != 1)? SI
    gap= 4/1.25= 3 (parte intera);

i=0;
cont=0;


while(0+3<n)? Si! {

	if(a[0] > a[0+3]) allora puoi scambiare: a[0]=10, a[3]=5, 10>5? SI, allora scambia. {
	cont=1;

	array: 5,9,15,10

	i++; i=1
	}
}
Verifico di nuovo la condizione del while più interno: i+3<n? NO! ALLORA ESCO DAL WHILE PIU' INTERNO.

if(i+gap>=n => 1+3>=4? SI; cont==0? NO!; gap==1? NO!). Continuo!






SECONDO CICLO:

Array: 5,9,15,10


if(gap != 1)? SI
    gap= 3/1.25= 2 (parte intera);

i=0;
cont=0;


while(0+2<n)? Si! {

	if(a[0] > a[0+2]) allora puoi scambiare: a[0]=5, a[2]=15, 5>15? NO, allora NON scambia. {
	cont=0;

	array: 5,9,15,10

	i++; i=1
	}
}
Verifico di nuovo la condizione del while più interno: i+2<n? SI! ALLORA RIMANGO NEL WHILE PIU' INTERNO.




while(1+2<n){

	if(a[1] > a[1+2]) allora puoi scambiare: a[1]=9, a[3]=10, 9>10? NO, allora NON scambia. {
	cont= 0;

	i++; i=2
	}
}
Verifico di nuovo la condizione del while più interno: 2+2<n? NO! ALLORA ESCO DAL WHILE PIU' INTERNO.

if(i+gap>=n => 2+2>=4? SI; cont==0? SI!; gap==1? NO!). Continuo!






TERZO CICLO:

Array: 5,9,15,10


if(gap != 1)? SI
    gap= 2/1.25= 1 (parte intera);

i=0;
cont=0;


while(0+1<n)? Si! {

	if(a[0] > a[0+1]) allora puoi scambiare: a[0]=5, a[1]=9, 5>9? NO, allora NON scambia. {
	cont= 0;

	array: 5,9,15,10

	i++; i=1
	}
}
Verifico di nuovo la condizione del while più interno: 1+1<n? SI! ALLORA RIMANGO NEL WHILE PIU' INTERNO.




while(1+1<n){

	if(a[1] > a[1+1]) allora puoi scambiare: a[1]=9, a[2]=15, 9>15? NO, allora NON scambia. {
	cont= 0;

	array: 5,9,15,10

	i++; i=2
	}
}
Verifico di nuovo la condizione del while più interno: 2+1<n? SI! ALLORA RIMANGO NEL WHILE PIU' INTERNO.




while(2+1<n){

	if(a[2] > a[2+1]) allora puoi scambiare: a[2]=15, a[3]=10, 15>10? SI, allora scambia. {
	cont= 1;

	array: 5,9,10,15

	i++; i=3
	}
}
Verifico di nuovo la condizione del while più interno: 3+1<n? NO! ALLORA ESCO DAL WHILE PIU' INTERNO.

if(i+gap>=n => 3+1>=4? SI; cont==0? NO!; gap==1? SI!). Continuo!






QUARTO CICLO:

Array: 5,9,10,15


if(gap != 1)? No perchè gap, per effetto del ciclo precedente è == 1. Da ora in avanti gap SARA' SEMPRE 1.

i=0;
cont=0;


while(0+1<n)? Si! {

	if(a[0] > a[0+1]) allora puoi scambiare: a[0]=5, a[1]=9, 5>9? NO, allora NON scambia. {
	cont= 0;

	array: 5,9,10,15

	i++; i=1
	}
}
Verifico di nuovo la condizione del while più interno: 1+1<n? SI! ALLORA RIMANGO NEL WHILE PIU' INTERNO.




while(1+1<n){

	if(a[1] > a[1+1]) allora puoi scambiare: a[1]=9, a[2]=10, 9>10? NO, allora NON scambia. {
	cont=0;

	array: 5,9,10,15

	i++; i=2
	}
}
Verifico di nuovo la condizione del while più interno: 2+1<n? SI! ALLORA RIMANGO NEL WHILE PIU' INTERNO.




while(2+1<n){

	if(a[2] > a[2+1]) allora puoi scambiare: a[2]=10, a[3]=15, 10>15? NO, allora NON scambia. {
	cont= 0;

	array: 5,9,10,15

	i++; i=3

	i+gap>=n => 3+1>=4? SI ed essendo cont= 0 (cioè cont=0 indica che in questo ciclo non sono stati fatti scambi, ciò significa che l'array è ordinato)
        	            allora termina il ciclo while.

	}
}
Verifico di nuovo la condizione del while più interno: 3+1<n? NO! ALLORA ESCO DAL WHILE PIU' INTERNO.

if(i+gap>=n => 3+1>=4? SI; cont==0? SI!; gap==1? SI!). BREAK! TERMINA IL CICLO WHILE PIU' ESTERNO (CIOE' TERMINA IL PROGRAMMA).



L'ARRAY ORDINATO è: 5,9,10,15
*/















