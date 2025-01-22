#include <stdio.h>
#include <stdlib.h>


/*LINK Operazione tra file: https://www.diag.uniroma1.it//~liberato/struct/file/index.shtml

  SOTTRAZIONE FILE:
  Lo scopo di questo esercizio è quello di leggere due file che contengono degli interi, e scrivere un file che contiene le differenza fra elementi del primo e
  del secondo.

  Per essere più precisi, i due file contengono ognuno una sequenza di numeri interi. Supponiamo che i nomi di questo due file siano uno e due.
  Si vuole fare in modo che il file risultato, di nome ris, contenga anch'esso una sequenza di interi, di cui il primo è ottenuto facendo la sottrazione fra
  il primo intero di uno e il primo intero di due. Il secondo intero deve essere ottenuto per sottrazione fra il secondo di uno e il secondo di due, ecc.

  Questo esercizio si potrebbe risolvere usando i vettori, ossia leggendo tutti gli interi del primo file e mettendoli in un vettore, e lo stesso per il secondo
  file. Facendo la sottrazione elemento per elemento, e scrivendo il risultato su file, si ottiene il risultato voluto

  Vediamo ora una soluzione che non usa vettore, ed è quindi più efficiente come occupazione di memoria.
  Usiamo questo algoritmo: dopo aver aperto i due file, leggiamo un intero dal primo file e uno dal secondo; facciamo la sottrazione e scriviamo il risultato
  sul terzo file.

  Per implementare questo algoritmo, dobbiamo aprire tutti e tre i file, i primi due in lettura e il terzo in scrittura. Infatti, per poter accedere a un file,
  occorre prima aprirlo. Le successive operazioni di lettura e scrittura usano il valore del descrittore di file per capire su quale file occorre leggere o scrivere.
  Quindi, ci servono tre variabili per memorizzare i tre descrittori di file che si ottengono dall'apertura dei tre file.

  Definiamo quindi le tre variabili:

  FILE *piu, *meno, *out;

  Quando apriamo il primo file, assegnamo a piu il risultato della apertura del file uno, ossia il descrittore di questo file. Facendo lo stesso per gli altri file,
  le tre variabili piu, meno e out possono venire usate per dire alle funzioni fscanf e fprintf su quali file operare. Per esempio, per leggere un intero dal
  file uno passiamo a fscanf il descrittore del primo file, cioè piu:

  fscanf(piu, "%d", &x);

  Il programma è riportato qui sotto. Quando uno dei due file di input (piu e meno) è terminato, si smette di leggere e si chiudono tutti e tre i file.
  Quindi, il terzo file contiene un numero di interi che è il minimo fra il numero di elementi del primo e del secondo file.
*/


int main()
{
    int x,y,res,res1,i,ciclo;

    FILE*piu,*meno,*out;         /*Dichiatro tre descrittori per ogni file*/

    piu=fopen("uno.txt","r");    /*Apro tutti e tre i file ed eseguo un controllo per verificare che esistano.*/

    if(piu == NULL){
        printf("ERRORE!\n");
        exit(1);
    }


    meno=fopen("due.txt","r");

    if(meno == NULL){
        printf("ERRORE2!\n");
        exit(1);
    }


    out=fopen("ris.txt","w");   /*Sul apertura di questo file posso anche non mettere nessun controllo perchè anche se il file "ris.txt" non esiste, aprendolo in scrittura
                                  "w", viene creato automaticamente.*/


    fscanf(piu,"%d\n",&x);      /*Leggo il primo elemento del file "uno" e "due" che mi indica quanti elementi sono presenti in ciuascun file*/
    fscanf(meno,"%d\n",&y);

    if(x < y)                   /*Mi serve per capire quali dei due file ha più elementi oppure se entrami hanno lo stesso numero di elementi.*/
        ciclo=y;
    else if(x > y)
        ciclo=x;
    else if(x == y)
        ciclo=x;


    for(i=0;i<ciclo;i++){           /*Il ciclo for viene eseguito fino al file con più elementi. Ad esempio: se il file "uno" ha 4 elem. mentre il file "due" ne ha 3,
                                      allora il ciclo andrà da i=0 a i<4 (elem. file "uno" > di elem. file "due)*/

    res=fscanf(piu,"%d\n",&x);      /*Leggo gli elementi dei due file*/
    res1=fscanf(meno,"%d\n",&y);

    if(res != 1)                    /*Se res è != 1 vuol dire che il file "uno" non ha più elementi quindi irestanti elementi del file "due" saranno scritti nel file "ris".*/
        fprintf(out,"%d\n",y);
    else if(res1 != 1)              /*Se res1 è != 1 vuol dire che il file "due" non ha più elementi quindi irestanti elementi del file "uno" saranno scritti nel file "ris".*/
        fprintf(out,"%d\n",x);
    else if(res == 1 && res1 == 1){ /*Se res e res1 sono == 1 vuol dire che i due file ("uno" e "due") contengono ancora elementi da dover leggere.*/
        fprintf(out,"%d\n",x-y);}   /*Esegue la sottrazione tra l'elem. letto dal file "uno" con quello letto dal file "due" e lo scrive nel file "ris"*/


    }

    /*Terminato il ciclo for i tre file vengono chiusi*/

    fclose(piu);
    fclose(meno);
    fclose(out);


    return 0;
}








/*VERSIONE del esercizio presente sul sito

int main()
{
    int x,y,res;

    FILE*piu,*meno,*out;


    piu=fopen("uno1.txt","r");

    if(piu == NULL){
        printf("ERRORE!\n");
        exit(1);
    }


    meno=fopen("due2.txt","r");

    if(meno == NULL){
        printf("ERRORE2!\n");
        exit(1);
    }


    out=fopen("ris3.txt","w");

    if(out == NULL){
        printf("ERRORE3!\n");
        exit(1);
    }


    while(1){                               while(1) significa che il ciclo si ripete al infinito, però terminerà quando uno dei due file "uno1" o "due2" non ha
                                            più elementi da leggere. L'interruzione del ciclo avviene mediante il comando break.
        res=fscanf(piu,"%d\n",&x);

        if(res != 1)
            break;

        res=fscanf(meno,"%d\n",&y);

        if(res != 1)
            break;

        fprintf(out,"%d\n",x-y);
    }

    fclose(piu);
    fclose(meno);
    fclose(out);

    return 0;
}
*/
