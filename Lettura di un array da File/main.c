#include <stdio.h>
#include <stdlib.h>


/*Link Operazioni su file: https://www.diag.uniroma1.it//~liberato/struct/file/index.shtml*/


/*
Usando le funzioni di apertura, lettura e scrittura da file, e avendo visto come si scrive/legge in sequenza, possiamo ora vedere operazioni più complesse. Supponiamo quindi di avere un file di nome array.txt che viene usato per memorizzare un array.

Più precisamente, il file contiene una sequenza di numeri interi. Il primo numero rappresenta la dimensione dell'array, ossia il numero di elementi che contiene. Questi elementi sono memorizzati su file di seguito, in sequenza.

Vogliamo un programma che legga un file di questo genere, e memorizzi i dati che contiene in un vettore. Facciamo l'ipotesi che ci siano al massimo 50 elementi. Questo permette di usare un vettore dichiarato staticamente per contentere i dati scritti su file.
*/



int main()
{
    int vet[50];
    int n,i;

    FILE*df;

    df= fopen("File.txt","r");  /*Aperura file*/

    if(df == NULL){                                 /*Controllo errori nel apertura del file*/
        printf("ERRORE nel apertura del file\n");
        exit(1);}

    fscanf(df,"%d",&n);         /*Ora quello che serve è leggere il primo numero intero scritto su file, che è il numero di elementi successivi del file.
                                  Per memorizzare questo numero, dichiariamo una variabile intera n. Facciamo quindi una operazione di lettura di intero da file*/

    if(n>=50)                   /*Poichè la dimensione del array che abbiamo dichiarato è di 50, se il numero di elementi nel file è > di 50 non possono essere contenuti nel array vett.*/
        printf("Troppi elementi da leggere\n");
    else{
        for(i=0;i<=n-1;i++)             /*A questo punto sappiamo che sul file ci sono altri n interi, che vanno letti da file e messi in ordine in un vettore. Dichiariamo una variabile vett come vettore di 100 interi.
                                          Per leggere gli elementi del vettore da file, facciamo un ciclo, in cui leggiamo un elemento a ogni iterazione.*/
            fscanf(df,"%d\n",&vet[i]);

        for(i=0;i<=n-1;i++)             /*Dopo aver letto il vettore, stampa i suoi elementi su schermo.*/
            printf("%d\n",vet[i]);
    }

    fclose(df);     /*Chiusura file*/

    return 0;
}
