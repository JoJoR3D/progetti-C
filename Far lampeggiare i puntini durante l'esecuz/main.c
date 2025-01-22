#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>         /*Libreria che contiene il metodo sleep*/
#include <string.h>



int main()
{

    float secondi= 0.0;
    int tempo=5;

    char stringa[]="sto caricando";
    char punto[]=".";
    char*Punto=" ";



    clock_t inizio= clock();        /*calcola il tempo della CPU consumato da un'attività all'interno di un'applicazione C. Restituisce il clock_t type, che memorizza il numero totale di tick di clock.*/


    int a,b;

    printf("Inserisci il valore di a: ");
    scanf("%d", &a);

    printf("\n\nInserisci il valore di b: ");
    scanf("%d", &b);

    printf("\n\n");

    printf("%s",stringa);


    while(tempo >= 0){

    /*if(tempo >= 0)*/
        printf("%s ",punto);

    /*else{*/
        /*strcpy(punto,Punto);*/ /*Volevo cancellare i puntini stampati per ristamparli e così via, ma una volta stampati a schermo non si possono eliminare*/
        /*printf("%s ",punto);}*/

    sleep(1);                   /*Il metodo sleep() sospende l'implementazione del programma per un determinato numero di secondi*/
                                /*Nel ciclo while inserendo il metodo sleep, questo mi permette di interrompere il programa per un secondo permettendomi di mostrare
                                  a schermo la stampa di un puntino per volta, fin quando non termina il ciclo while
                                  Senza il metodo sleep, il programma verrebbe eseguito immediatamente non mostrando a schermo la stampa di un puntino per volta.*/
                                /*L'ho inserito tanto per. Questo da l'impressione che la CPU si sta prendendo del tempo per eseguire il calcolo, ma non è ovviamente
                                vero perchè è un programma che, senza il metodo sleep, la CPU eseguirebbe in un secondo.*/
    --tempo;
    }


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
