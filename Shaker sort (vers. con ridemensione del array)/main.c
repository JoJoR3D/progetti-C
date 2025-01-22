#include <stdio.h>
#include <stdlib.h>


/*
Siti: https://it.wikipedia.org/wiki/Bubble_sort
      https://it.wikipedia.org/wiki/Shaker_sort#Shakersort

In informatica lo Shaker sort, noto anche come Bubble sort bidirezionale, Cocktail sort, Cocktail shaker sort, Ripple sort, Happy hour sort o Shuttle sort �
un algoritmo di ordinamento dei dati sviluppato dalla Sun Microsystems. Lo shaker sort � sostanzialmente una variante del bubble sort: si differenzia da
quest'ultimo per l'indice del ciclo pi� interno che, anzich� scorrere dall'inizio alla fine, inverte la sua direzione ad ogni ciclo.
Pur mantenendo la stessa complessit�, ovvero O(n�), lo shaker sort riduce la probabilit� che l'ordinamento abbia un costo corrispondente al caso peggiore.


La struttura dell'algoritmo Bubble Sort porta ad avere elementi che si spostano verso la posizione corretta pi� velocemente di altri.
Tutti gli elementi che si spostano nella stessa direzione di scorrimento dell'indice avanzano pi� velocemente di quelli che lo fanno in senso contrario.
Esempio. Data la lista:

15 6 4 10 11 2
dopo la prima iterazione la disposizione dei numeri sar�:

6 4 10 11 2 15

Qui si osserva il "coniglio" 15 e la "tartaruga" 2: il primo numero, in una sola iterazione, ha attraversato tutta la lista posizionandosi nella sua
collocazione definitiva. Il secondo, invece, durante la stessa iterazione � avanzato di una sola posizione verso la sua collocazione corretta.

Ovviamente sono stati effettuati diversi tentativi per eliminare le tartarughe ed aumentare l'efficienza del Bubble sort: l'algoritmo shaker sort risolve molto
bene questo problema utilizzando un indice interno la cui direzione di scorrimento � invertita ad ogni passaggio; risulta pi� efficiente del Bubble sort ma
paga un dazio in termini di complessit� O grande di (n al quadrato).
*/



/*In questo programma solo in ogni PRIMA CORSA, alla fine, viene ridimensionata la parte finale del array, diminuendo 'n'.
  Mentre nella SECONDA CORSA, alla fine, viene ridimensionata la parte iniziale del array diminuendo l'indice 'i' (passandolo alla variabile 'y' e poi a 'Inizio'.*/



void swap(int*, int*);



int main()
{
    int a[]={11,10,6,3,9,2,8,7};
    int n= 8, i=0, z, cont=0, flag=0, y= 0, Inizio= 0;  /*inizio contiene il valore di 'y', ovvero l'indice del ultimo elemento verso sinistra del array
                                                          dal quale si deve iniziare per eseguire i confronti per ordinare l'array.
                                                          Quelli precedenti a questo valore sono gi� ordinati.*/

    printf("Array NON ordianto\n");
    for(z=0;z<n;z++)                /*Uso la variabile 'z' poich� se usassi 'i' o 'j' questo for cambierebbe il loro valore alterando poi il risultato del ciclo while.*/
        printf("%d ",a[z]);

    printf("\n\n");


    while(1){                       /*while(1) indice che il ciclo si ripeter� al infinito a meno che non venga interrotto con il comando break.*/

        /*flag= n%2;*/              /*Modulo della divisione per 2. Se il 'n � pari il resto della divisione sar� 0, altrimenti se 'n' � dispari il resto sar�
                                      diverso da 0. Quando il resto � 0 viene eseguito il PRIMO ciclo; quando il rsto della divisione � diverso da 0, viene
                                      eseguito il SECONDO ciclo.*/


        /*PRIMA CORSA*/
        if(flag == 0){

            printf("\nIndici PRIMA CORSA\n");

            for(i=Inizio;i<n-1;i++){            /*Questo primo ciclo (PRIMA CORSA) verso destra spostera l'elemento pi� grande nella sua posizione corretta alla fine della lista.*/
            printf("%d %d\n",i,i+1);
                if(a[i] > a[i+1]){              /*Al primo ciclo: Se il primo elemento del array � > del secondo elemento questo viene scambiato tramite lo swap.*/
                    swap(&a[i],&a[i+1]);
                    cont++;
                }                               /*Ogni volta che viene fatto lo swap, viene incrementato il contatore.*/
            }printf("\n");
            flag= 1;                            /*Impostando il flag= 1 ci� mi permette al successivo ciclo di eseguire la SECONDA CORSA*/

            n=n-1;                              /*Solo in questo ciclo viene ridimensionato l'array per poter evitare, ai successivi cicli, di riconfrontare gli elementi gi� ordinati.
                                                Questo perch� nel primo ciclo (PRIMA CORSA) sicuramente al ultima posizione del array ci sar� l'elemento pi� grande, quindi al ciclo successivo sar� inutile
                                                fare il confronto con questo elemento perch� � il pi� grande e il suo posto � l'ultima posizione.
                                                Quindi dopo la prima iterazione il massimo si trover� in ultima posizione, quella sua definitiva; dopo la seconda iterazione il secondo massimo
                                                si trover� in penultima posizione, anch'essa la sua definitiva; dopo la terza iterazione il terzo massimo si trover� in terz'ultima posizione,
                                                anch'essa la sua definitiva e cos� via.
                                                Quindi ad ogni iterazione viene ridotta la dimensione del array, in questo modo si evita di riconfrontare gli elementi gi� ordinati.*/
        }



        /*SECONDA CORSA che inverte l'esecuzione del ciclo for (anche qui se uso un while) permettendo di analizzare l'array da destra verso sinistra,
          invece che da sinistra verso destra come avviene nelle PRIMA CORSA.*/
        else if(flag != 0){

            i=n-1;

            printf("\nIndici SECONDA CORSA\n");

            while(i>Inizio){                   /*Invece questo SECONDO ciclo verso sinistra sposter� l'elemento pi� piccolo nella sua posizione corretta all'inizio della lista.*/
            printf("%d %d\n",i,i-1);
                if(a[i] < a[i-1]){

                    swap(&a[i],&a[i-1]);
                    cont++;
                    y= i;                      /*Eseguito l'ultimo swap di questo ciclo, l'indice dello swap sar� salvato nelle variabile 'y'.
                                                 Questo indicher� la posizione del valore pi� piccolo verso sinistra del array, ovvero l'indice del ultimo elemento verso sinistra del array
                                                 dal quale si deve iniziare per eseguire i confronti per ordinare l'array. Quelli precedenti a questo valore sono gi� ordinati, quindi
                                                 non dovranno pi� essere considerati per i confronti dei cicli successivi.*/
                }
                i--;
            }flag= 0;                          /*Impostando il flag= 0 ci� mi permette al successivo ciclo di eseguire la PRIMA CORSA*/
            Inizio= y;                         /*Salva il valore di 'y'. Quindi i prossimi cicli inizieranno proprio da 'y'.*/

            printf("\n");                      /*In questo SECONDO ciclo (SECONDA CORSA) invece l'array non viene ridimensionato perch�, il ciclo scorrendo verso sinistra, non colloca
                                                 gli elementi pi� grandi alla fine del array ma, posizioner� in ordine, gli elementi pi� piccoli al inizio dell'array.*/
        }






        if(/*(i+1>=n || i<=0) &&*/ cont != 0){      /*Se i+1 � >= n vuol dire che sono arrivato alla fine dell'array e quindi devo ripristinare gli indici per ricominciare dal inizio*/
                                                    /*per poter eventualmente fare altri scambi per ordinare l'array.*/

            cont= 0;                                /*cont != 0 vuol dire che in questo ciclo � stato eseguito almeno uno swap. Poi poich� sto ricominciando dal inizio del array, azzero il cont.*/
            /*if(flag == 0)
                n=n-1;*/
        }

        else if(/*(i+1>=n || i<=0) &&*/ cont == 0)  /*Invece se i+1 � >= n ma il cont � == 0, vuol dire che in questo ciclo non � stato eseguito nessuno swap,*/
            break;                                  /*quindi l'array � ORDIANTO e posso quindi interrompere il ciclo while con il comando break.*/


    }

    n=8;                                        /*Al fine di stampare l'array ordinato, ripristino il valore di 'n' che � stato modificato dal ciclo while*/
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

