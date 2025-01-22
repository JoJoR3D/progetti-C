#include <stdio.h>
#include <stdlib.h>
#include "File1.c"


/*Sito da dove ho visto queste operazioni su file: https://www.diag.uniroma1.it//~liberato/struct/file/index.shtml*/


void visualizza(int*, int);



int main()
{
    int a[]={1,2,3,4,5};
    int n= 5;
    int x,m;

    visualizza(a,n);                /*Semplice Funzione per visualizzare l'array*/

    FILE*fd;                        /*La chiamata alla funzione fopen viene detta apertura del file. Il valore che viene ritornato da questa funzione è di tipo FILE *, e viene detto descrittore di file.
                                      Il descrittore di file è un valore che viene usato dalle successive funzioni di accesso al file, per indicare di quale file si sta parlando.*/

    fd= fopen("cacca.txt","r");     /*Apertura file. "r" indica che apro il file per leggerlo.*/


    if(fd == NULL){                 /*Controllo apertura file. Se l'apertura non va a buon fine allora ritorna NULL.*/
        printf("\nSi e' verificato un errore\n");
        exit(1);                    /*La funzione exit con il valore dell'argomento 1 viene utilizzata per indicare la terminazione con errore.*/
    }


    fscanf(fd," %d ",&x);             /*Lettura contenuto del file*/

    fclose(fd);                     /*Chiusura file*/

    printf("\n\nIl numero letto dal file e': %d", x);






    /*Scrittura su File*/

    int z= 22;          /*22 è il numero che srà scritto sul file*/

    FILE*v;

    v= fopen("Puzza.txt", "w");     /* "w" indica che apro il file per scrivere*/

    if(v == NULL){                  /*Controllo apertura file*/
        printf("\nSi e' verificato un errore nel apertura del file\n");
        exit(1);
    }

    fprintf(v," %d\n ", z);             /*Scrittura sul file*/

    fclose(v);


    /*La funzione fopen si comporta in modo diverso a seconda se il file che si sta aprendo in scrittura esiste oppure no.

    Il file non esiste:
    è chiaro che non si deve generare nessun errore (altrimenti non si potrebbero mai creare nuovi file);
    il file viene creato di dimensione zero (la dimensione aumenta quando si fanno le successive operazioni di scrittura);
    Ad esempio il file Puzza non l'ho creato io, lo ha creato in automatico.

    Il file esiste già:
    in questo caso il contenuto del file viene azzerato; in altre parole, è come se il file venisse cancellato e ricreato vuoto.

    In entrambi i casi, se si apre un file in scrittura e poi lo si chiude subito dopo, quello che si ottiene è un file di dimensione zero.*/





    /*Scrittura IN CODA (append) su File*/

    int y= 97;

    FILE*c;

    c= fopen("cacca.txt","a");      /* "a": append permette appunto di aprire un file in maniera che sia possibile scrivere in coda al contentuto attuale del file*/

    if(c == NULL){
        printf("\nSi e' verificato un errore nel apertura del file\n");
        exit(1);
    }

    fprintf(c," \n%d ",y);

    fclose(c);






    /*Lettura di due valori presenti nel file*/

    FILE*d;

    d= fopen("cacca.txt","r");     /*Apertura file. "r" indica che apro il file per leggerlo.*/


    if(d == NULL){                 /*Controllo apertura file. Se l'apertura non va a buon fine allora ritorna NULL.*/
        printf("\nSi e' verificato un errore\n");
        exit(1);                    /*La funzione exit con il valore dell'argomento 1 viene utilizzata per indicare la terminazione con errore.*/
    }


    fscanf(d," %d ",&x);             /*Legge il primo intero del file*/

    fscanf(d," %d ",&m);            /*Legge il secondo intero del file*/

    fclose(d);                     /*Chiusura file*/

    printf("\n\nI numeroi letti dal file sono: %d, %d", x,m);

    return 0;
}
