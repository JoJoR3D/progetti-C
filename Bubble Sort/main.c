#include <stdio.h>
#include <stdlib.h>


/*Sito: https://it.wikipedia.org/wiki/Bubble_sort

  In informatica il Bubble sort o ordinamento a bolla è un semplice algoritmo di ordinamento di liste di dati. In esso l'insieme di dati viene scansionato,
  ogni coppia di elementi adiacenti viene comparata ed i due elementi vengono invertiti di posizione se sono nell'ordine sbagliato.*/


/*COSTO del algoritmo:
  Il bubble sort effettua all'incirca N^2 fratto 2 confronti ed N^2 fratto 2 scambi sia in media che nel caso peggiore.
  Il tempo di esecuzione dell'algoritmo è (O grande) di N^2.
   Il caso particolare in cui il numero destinato alla prima posizione dell'array si trovi nell'ultima corrisponde a una situazione di "caso peggiore"
   del bubblesort, in cui saranno necessarie tutte le N-1 iterazioni dell'algoritmo per ottenere l'array ordinato.
*/



void swap(int*, int*);


int main()
{
    int a[]={11,10,6,3,9,2,8,7};
    int n= 8, i=0, z, cont=0;

    printf("Array NON ordianto\n");
    for(z=0;z<n;z++)                /*Uso la variabile 'z' poichè se usassi 'i' o 'j' questo for cambierebbe il loro valore alterando poi il risultato del ciclo while.*/
        printf("%d ",a[z]);

    printf("\n\n");


    while(1){                       /*while(1) indice che il ciclo si ripeterà al infinito a meno che non venga interrotto con il comando break.*/

        if(a[i] > a[i+1]){          /*Al primo ciclo: Se il primo elemento del array è > del secondo elemento questo viene scambiato tramite lo swap.*/
            swap(&a[i],&a[i+1]);
            cont++;}                /*Ogni volta che viene fatto lo swap, viene incrementato il contatore.*/

        i++;                        /*Incremento l'indice per puntare ai prossimi elementi del array.*/

        if(i+1>=n && cont != 0){    /*Se i+1 è >= n vuol dire che sono arrivato alla fine dell'array e quindi devo ripristinare gli indici per ricominciare dal inizio*/
            i=0;                    /*per poter eventualmente fare altri scambi per ordinare l'array.*/

            cont= 0;                /*cont != 0 vuol dire che in questo ciclo è stato eseguito almeno uno swap. Poi poichè sto ricominciando dal inizio del array, azzero il cont.*/

            n=n-1;                  /*Dopo il primo ciclo sicuramente al ultima posizione del array ci sarà l'elemento più grande, quindi al ciclo successivo sarà inutile
                                      fare il confronto con questo elemento perchè è il più grande e il suo posto è l'ultima posizione.
                                      Quindi dopo la prima iterazione il massimo si troverà in ultima posizione, quella sua definitiva; dopo la seconda iterazione il secondo massimo
                                      si troverà in penultima posizione, anch'essa la sua definitiva; dopo la terza iterazione il terzo massimo si troverà in terz'ultima posizione,
                                      anch'essa la sua definitiva e così via.
                                      Quindi ad ogni iterazione viene ridotta la dimensione del array, in questo modo si evita di riconfrontare gli elementi già ordinati.*/
        }

        else if(i+1>=n && cont == 0)  /*Invece se i+1 è >= n ma il cont è == 0, vuol dire che in questo ciclo non è stato eseguito nessuno swap,*/
            break;                    /*quindi l'array è ORDIANTO e posso quindi interrompere il ciclo while con il comando break.*/
    }

    n=8;                            /*Al fine di stampare l'array ordinato, ripristino il valore di 'n' che è stato modificato dal ciclo while*/
    printf("Array ordianto\n");
    for(z=0;z<n;z++)
        printf("%d ",a[z]);

    return 0;
}





void swap(int*a, int*b)         /* '*a': contiene l'indirizzo di un elemento del array; '*b': contiene l'indirizzo di un altro elemento del array;*/
{
    int t;
    t= *b;                      /* ad 't' assegno 'b' */
    *b= *a;                     /* ad '*b' assegno '*a' */
    *a= t;                      /* ad '*a' assegno 't' */
}
                                /*Ad esempio:
                                  il primo elem. del array è a[0]= 11 e supponiamo che la sua locazione di memoria (indirizzo) sia: 65789.
                                  Ora supponendo che ci troviamo al primo ciclo con i=0, perchè nella chiamata alla void swap ho messo: &a[i]? Perché:
                                  *a è un puntatore (un indirizzo) che contiene l'indirizzo di memoria di a[0], cioè: 65789.
                                  Quindi ad *a sto passando l'indirizzo del elemento del array a[0] cioè: 65789.
                                  Quindi con la void swap sto scambiando le LOCAZIONI DI MEMORIA.

                                  Quindi se:
                                  a[0] ha come locazione di memoria= 65789 (cha contiene il valore 11) e
                                  a[1] ha come locazione di memoria= 66890 (cha contiene il valore 10),

                                  facendo lo swap ora:
                                  a[0] ha come locazione di memoria 66890 (che contiene il valore 10), mentre
                                  a[1] ha come locazione di memoria 65789 (che contiene il valore 11).

                                  Cosa accade nella function SWAP?
                                  *a= 65789;
                                  *b= 66890;

                                  t= 66890;

                                  *b= 65789;
                                  *a= 66890;
                                */



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


