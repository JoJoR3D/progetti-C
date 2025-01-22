#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>         /*Libreria che contiene il metodo sleep*/



int main()
{

    float secondi= 0.0;


    clock_t inizio= clock();        /*calcola il tempo della CPU consumato da un'attività all'interno di un'applicazione C. Restituisce il clock_t type, che memorizza il numero totale di tick di clock.*/


    int a,b;

    printf("Inserisci il valore di a: ");
    scanf("%d", &a);

    printf("\n\nInserisci il valore di b: ");
    scanf("%d", &b);


    printf("\n\nsto calcolando");

    sleep(2);                       /*Il metodo sleep() sospende l'implementazione del programma per un determinato numero di secondi*/

    printf(".");

    sleep(2);                       /*Il metodo sleep() sospende l'implementazione del programma per un determinato numero di secondi*/

    printf(".");

    sleep(2);                       /*Il metodo sleep() sospende l'implementazione del programma per un determinato numero di secondi*/

    printf(".");

    if(a > b)
        printf("\n\n\nIl valore di 'a' e' maggiore");
    else if(a < b)
        printf("\n\n\nIl valore di 'b' e' maggiore");
    else
        printf("\n\n\nI valori di 'a' e di 'b' sono uguali");

    clock_t fine= clock();

    secondi= (float)(fine - inizio)/CLOCKS_PER_SEC;     /*Per calcolare il numero totale di secondi trascorsi, dobbiamo dividere il numero totale di tick di clock trascorsi per CLOCKS_PER_SEC macro (presente anche in <time.h>)*/

    printf("\n\nI secondi trascorsi sono: %.3f\n\n", secondi);  /*Poichè sleep è di 5 secondi, i secondi trascorsi saranno proprio 5*/

    return 0;
}
