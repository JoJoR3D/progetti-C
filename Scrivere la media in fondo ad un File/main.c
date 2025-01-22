#include <stdio.h>
#include <stdlib.h>


/*Link per operazioni su file: https://www.diag.uniroma1.it//~liberato/struct/file/index.shtml*/


/*Questo esercizio consiste nel leggere di un certo numero di interi da file, calcolare la loro media, e scrivere la media in coda al file.

  Il programma che risolve questo problema media.c, legge un vettore da file, e chiude il file. A questo punto il vettore contiene gli elementi del file.
  Possiamo quindi calcolare la loro media. Per scrivere questo valore in fondo al file, lo apriamo di nuovo in append mode, e scriviamo il valore della media. Dato che il file è stato aperto in append mode, le operazioni di scrittura aggiungono in fondo al file, lasciando inalterato il contenuto precedente.
*/


int main()
{
    int vet[100];
    int n,i;
    float media= 0.0;

    FILE*fd;

    fd= fopen("File.txt","r");      /*Apro il file in lettura*/

    if(fd == NULL){                 /*Se l'apertura del file ritorna NULL, vuol dire che il file indicato non è stato trovato*/
        printf("ERRORE nel apertura del file\n");
        exit(1);
    }

    fscanf(fd,"%d",&n);             /*Leggo il primo elemento del file che mi indica quanti sono gli elementi successivi presenti nel file*/

    if(n >= 100)                    /*E' un controllo per verificare che il numoro degli elementi presenti nel file non sia superiore alla dimensione dell'array vet che dovrà contenerli*/
        printf("Troppi elementi da leggere\n");
    else{
        for(i=0;i<=n-1;i++)         /*Se n è < di 100 allora leggo gli elementi presenti nel file per passarli al array vet*/
            fscanf(fd,"%d",&vet[i]);

        for(i=0;i<=n-1;i++){        /*Stampa gli elementi presenti nel array vet e calcolo la media degli elementi*/
            printf("%d ",vet[i]);
            media= media + vet[i];}
    }
    media= (media/n);

    printf("\nMedia: %.1f",media);

    fclose(fd);                 /*Chiusura del file*/




    /*Riapro il file in 'append mode' per poter inserire in coda al file il valore della media*/

    fd= fopen("File.txt","a");

    if(fd == NULL){
        printf("\nERRORE nel apertura del file\n");
        exit(1);
    }

    fprintf(fd,"\n%.1f",media);     /*Scrivo in coda al file il valore della media*/

    fclose(fd);     /*Chiusura del file*/


    return 0;
}
